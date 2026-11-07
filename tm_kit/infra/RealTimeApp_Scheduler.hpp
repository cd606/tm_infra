#ifndef TM_KIT_INFRA_REALTIME_APP_SCHEDULER_HPP_
#define TM_KIT_INFRA_REALTIME_APP_SCHEDULER_HPP_

#include <condition_variable>
#include <deque>
#include <memory>
#include <algorithm>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <system_error>
#include <thread>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <vector>
#if defined(__linux__)
#include <pthread.h>
#include <sched.h>
#endif

namespace dev { namespace cd606 { namespace tm { namespace infra {
namespace real_time_app_detail {
    // All queues and their dispatch state are protected by the scheduler mutex.
    class Scheduler {
    public:
        class Batch;
        struct Queue {
            std::size_t pending = 0;
            bool enabled = true;
            bool active = false;
            virtual ~Queue() = default;
            // Called with the scheduler lock held. Implementations pop one
            // input, release the lock, and run the action before returning.
            virtual void dispatchOne(std::unique_lock<std::mutex> &lock) = 0;
            virtual void clear() = 0;
        };
        template <class Data>
        struct TypedQueue : Queue {
            std::deque<Data> inputs;
            void clear() override final { inputs.clear(); }
        };
        template <class Data, class Owner>
        class InputQueue final : public TypedQueue<Data> {
            Owner *owner_;
        public:
            explicit InputQueue(Owner *owner) : owner_(owner) {}
            void dispatchOne(std::unique_lock<std::mutex> &lock) override final {
                auto input = std::move(this->inputs.front());
                this->inputs.pop_front();
                lock.unlock();
                owner_->handleImmediately(std::move(input));
            }
        };
    private:
        std::mutex mutex_;
        std::mutex joinMutex_;
        std::condition_variable ready_;
        std::vector<Queue *> queues_;
        std::thread thread_;
        std::size_t pending_ = 0;
        std::size_t next_ = 0;
        bool stopped_ = false;
        bool started_ = false;
        bool dispatchEnabled_ = false;
        std::optional<unsigned int> cpu_;
        inline static thread_local Batch *activeBatch_ = nullptr;

        template <class Data>
        bool enqueueLocked(TypedQueue<Data> &queue, Data &&input) {
            if (stopped_ || !queue.enabled) { return false; }
            queue.inputs.push_back(std::move(input));
            ++queue.pending;
            ++pending_;
            return true;
        }

        static void bindCPU(std::thread::native_handle_type thread, unsigned int cpu) {
#if defined(__linux__)
            if (cpu >= CPU_SETSIZE) {
                throw std::out_of_range("RealTimeApp scheduler CPU exceeds CPU_SETSIZE");
            }
            cpu_set_t set;
            CPU_ZERO(&set);
            CPU_SET(cpu, &set);
            int error = pthread_setaffinity_np(thread, sizeof(set), &set);
            if (error) {
                throw std::system_error(error, std::generic_category(), "RealTimeApp scheduler CPU affinity");
            }
#else
            (void) thread;
            (void) cpu;
            throw std::runtime_error("RealTimeApp scheduler CPU affinity is unsupported on this platform");
#endif
        }
        void run() {
            std::unique_lock<std::mutex> lock(mutex_);
            for (;;) {
                ready_.wait(lock, [this] { return stopped_ || (dispatchEnabled_ && pending_ != 0); });
                if (stopped_) { return; }
                // Resume after the last queue served, including when it refills.
                Queue *queue = nullptr;
                for (std::size_t i = 0; i < queues_.size(); ++i) {
                    auto candidate = queues_[next_];
                    next_ = (next_+1) % queues_.size();
                    if (candidate->enabled && candidate->pending != 0) {
                        queue = candidate;
                        break;
                    }
                }
                --pending_;
                --queue->pending;
                queue->active = true;
                // As with dedicated threaded actions, an uncaught action exception
                // terminates the process rather than silently dropping an input.
                queue->dispatchOne(lock);
                lock.lock();
                queue->active = false;
                ready_.notify_all();
            }
        }
    public:
        // A publisher holds one scope for a contiguous group of listeners on
        // this scheduler. Their normal handle() paths reuse the held lock.
        class Batch {
            friend class Scheduler;
            Scheduler *scheduler_;
            Batch *previous_;
            std::unique_lock<std::mutex> lock_;
            bool notify_ = false;
        public:
            static Batch *currentFor(Scheduler const *scheduler) {
                for (auto *batch = activeBatch_; batch; batch = batch->previous_) {
                    if (batch->scheduler_ == scheduler && batch->lock_.owns_lock()) { return batch; }
                }
                return nullptr;
            }
            explicit Batch(Scheduler &scheduler)
                : scheduler_(&scheduler), previous_(activeBatch_), lock_(scheduler.mutex_, std::defer_lock) {
                if (!currentFor(&scheduler)) { lock_.lock(); }
                activeBatch_ = this;
            }
            Batch(Batch const &) = delete;
            Batch &operator=(Batch const &) = delete;
            ~Batch() {
                activeBatch_ = previous_;
                if (lock_.owns_lock()) {
                    lock_.unlock();
                    if (notify_) { scheduler_->ready_.notify_one(); }
                }
            }
        };
        ~Scheduler() { stop(); }
        void addQueue(Queue &queue) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (stopped_) { throw std::logic_error("RealTimeApp scheduler has stopped"); }
            queues_.push_back(&queue);
        }
        template <class Data>
        void enqueue(TypedQueue<Data> &queue, Data &&input) {
            if (auto *batch = Batch::currentFor(this)) {
                if (enqueueLocked(queue, std::move(input))) { batch->notify_ = true; }
                return;
            }
            {
                std::lock_guard<std::mutex> lock(mutex_);
                if (!enqueueLocked(queue, std::move(input))) { return; }
            }
            ready_.notify_one();
        }
        void removeQueue(Queue &queue) {
            std::unique_lock<std::mutex> lock(mutex_);
            queue.enabled = false;
            pending_ -= queue.pending;
            queue.pending = 0;
            queue.clear();
            // Stop scanning this queue immediately, but keep its owner alive
            // until any dispatch already in progress has returned.
            auto entry = std::find(queues_.begin(), queues_.end(), &queue);
            if (entry != queues_.end()) {
                auto index = static_cast<std::size_t>(entry-queues_.begin());
                queues_.erase(entry);
                if (index < next_) { --next_; }
                if (next_ >= queues_.size()) { next_ = 0; }
            }
            ready_.wait(lock, [&queue] { return !queue.active; });
        }
        void setCPU(unsigned int cpu) {
            std::lock_guard<std::mutex> lock(mutex_);
#if defined(__linux__)
            if (cpu >= CPU_SETSIZE) {
                throw std::out_of_range("RealTimeApp scheduler CPU exceeds CPU_SETSIZE");
            }
#else
            throw std::runtime_error("RealTimeApp scheduler CPU affinity is unsupported on this platform");
#endif
            if (stopped_) { throw std::logic_error("RealTimeApp scheduler has stopped"); }
            if (started_) { bindCPU(thread_.native_handle(), cpu); }
            cpu_ = cpu;
        }
        void start() {
            std::unique_lock<std::mutex> lock(mutex_);
            if (stopped_) { throw std::logic_error("RealTimeApp scheduler has stopped"); }
            if (started_) { return; }
            thread_ = std::thread([this] { run(); });
            started_ = true;
            try {
                if (cpu_) { bindCPU(thread_.native_handle(), *cpu_); }
                dispatchEnabled_ = true;
            } catch (...) {
                stopped_ = true;
                lock.unlock();
                ready_.notify_all();
                thread_.join();
                throw;
            }
            lock.unlock();
            ready_.notify_all();
        }
        // Stop discards queued work and waits for any current dispatch to finish.
        void stop() {
            std::lock_guard<std::mutex> joinLock(joinMutex_);
            {
                std::lock_guard<std::mutex> lock(mutex_);
                stopped_ = true;
                for (auto *q : queues_) { q->clear(); q->pending = 0; }
                pending_ = 0;
            }
            ready_.notify_all();
            if (thread_.joinable()) { thread_.join(); }
        }
    };

    class SchedulerContext {
        std::mutex mutex_;
        std::unordered_map<std::size_t, std::shared_ptr<Scheduler>> schedulers_;
        bool started_ = false;
        bool stopped_ = false;
    public:
        ~SchedulerContext() { stop(); }
        std::shared_ptr<Scheduler> get(std::size_t id) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (stopped_) { throw std::logic_error("RealTimeApp schedulers have stopped"); }
            auto &scheduler = schedulers_[id];
            if (!scheduler) {
                scheduler = std::make_shared<Scheduler>();
                if (started_) { scheduler->start(); }
            }
            return scheduler;
        }
        void start() {
            std::lock_guard<std::mutex> lock(mutex_);
            if (stopped_) { throw std::logic_error("RealTimeApp schedulers have stopped"); }
            for (auto const &entry : schedulers_) { entry.second->start(); }
            started_ = true;
        }
        void stop() {
            std::vector<std::shared_ptr<Scheduler>> schedulers;
            {
                std::lock_guard<std::mutex> lock(mutex_);
                stopped_ = true;
                for (auto const &entry : schedulers_) { schedulers.push_back(entry.second); }
            }
            for (auto const &scheduler : schedulers) { scheduler->stop(); }
        }
    };

    class SchedulerContainer {
    public:
        virtual ~SchedulerContainer() = default;
        virtual void attachScheduler(std::shared_ptr<SchedulerContext> const &) {}
    };

    class ScheduledNode : public SchedulerContainer {
        std::optional<std::size_t> schedulerID_;
        std::shared_ptr<Scheduler> scheduler_;
        std::unique_ptr<Scheduler::Queue> queue_;
    protected:
        virtual std::unique_ptr<Scheduler::Queue> makeSchedulerQueue() {
            throw std::logic_error("Custom scheduler node must provide a typed input queue");
        }
        template <class Data>
        bool enqueueScheduled(Data &&data) {
            if (!schedulerID_) { return false; }
            if (!scheduler_) {
                throw std::logic_error("Scheduler node must be attached to a RealTimeApp before receiving input");
            }
            // The action creates this queue once, with its declared input type.
            // Only typed data is stored per input; dispatch is erased per queue.
            auto &queue = static_cast<Scheduler::TypedQueue<std::decay_t<Data>> &>(*queue_);
            scheduler_->enqueue(queue, std::move(data));
            return true;
        }
    public:
        virtual ~ScheduledNode() { detachScheduler(); }
        void configureScheduler(std::optional<std::size_t> id) { schedulerID_ = id; }
        std::optional<std::size_t> schedulerID() const { return schedulerID_; }
        Scheduler *schedulerInstance() const { return scheduler_.get(); }
        void attachScheduler(std::shared_ptr<SchedulerContext> const &context) override {
            if (!schedulerID_) { return; }
            auto scheduler = context->get(*schedulerID_);
            if (scheduler_) {
                if (scheduler_ != scheduler) {
                    throw std::logic_error("A scheduler node cannot belong to multiple RealTimeApp instances");
                }
                return;
            }
            auto queue = makeSchedulerQueue();
            scheduler->addQueue(*queue);
            queue_ = std::move(queue);
            scheduler_ = std::move(scheduler);
        }
        virtual void detachScheduler() {
            if (scheduler_) {
                scheduler_->removeQueue(*queue_);
                scheduler_.reset();
                queue_.reset();
            }
        }
    };
}
}}}}
#endif
