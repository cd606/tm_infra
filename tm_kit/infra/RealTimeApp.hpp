#ifndef TM_KIT_INFRA_REALTIME_APP_HPP_
#define TM_KIT_INFRA_REALTIME_APP_HPP_

#include <tm_kit/infra/WithTimeData.hpp>
#include <tm_kit/infra/ControllableNode.hpp>
#include <tm_kit/infra/ObservableNode.hpp>
#include <tm_kit/infra/StoppableProducer.hpp>

#include <vector>
#include <list>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <any>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    class OutputRealTimeThreadBufferSizeComponent {};

    class RealTimeAppException : public std::runtime_error {
    public:
        RealTimeAppException(std::string const &s) : std::runtime_error(s) {}
    };

    class IRealTimeAppPossiblyThreadedNode {
    public:
        virtual ~IRealTimeAppPossiblyThreadedNode() = default;
        virtual std::optional<std::thread::native_handle_type> threadHandle() = 0;
    };
    
    template <uint8_t N>
    using IStoppableRealTimeProducer = IStoppableProducer<N>;
    
    template <class StateT>
    class RealTimeAppComponents {
    public:
        template <class T>
        using Key = Key<T,StateT>;
        template <class A, class B>
        using KeyedData = KeyedData<A,B,StateT>;

        template <class T>
        class IHandler {
        public:
            virtual ~IHandler() {}
            virtual void handle(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) = 0;
        };

        template <bool MutexProtected, class T>
        class TimeChecker {};
        template <class T>
        class TimeChecker<false, T> {
        private:
            bool hasData_;
            typename StateT::TimePointType lastTime_;
            VersionChecker<T> versionChecker_;
        public:
            TimeChecker() : hasData_(false), lastTime_(), versionChecker_() {}
            inline bool operator()(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> const &data) {
                if (!versionChecker_.checkVersion(data.timedData.value)) {
                    return false;
                }
                if (StateT::CheckTime) {
                    if (hasData_ && data.timedData.timePoint < lastTime_) {
                        return false;
                    }
                }
                hasData_ = true;
                lastTime_ = data.timedData.timePoint;
                return true;
            }
            inline bool good() const {
                return hasData_;
            }
        };
        template <class T>
        class TimeChecker<true, T> {
        private:
            std::atomic<bool> hasData_;
            std::mutex mutex_;
            typename StateT::TimePointType lastTime_;
            VersionChecker<T> versionChecker_;
        public:
            TimeChecker() : hasData_(false), mutex_(), lastTime_(), versionChecker_() {}
            inline bool operator()(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> const &data) {
                std::lock_guard<std::mutex> _(mutex_);
                if (!versionChecker_.checkVersion(data.timedData.value)) {
                    return false;
                }
                if (StateT::CheckTime) {
                    if (hasData_ && data.timedData.timePoint < lastTime_) {
                        return false;
                    }
                }
                hasData_ = true;
                lastTime_ = data.timedData.timePoint;
                return true;
            }
            inline bool good() const {
                return hasData_;
            }
        };

        #include <tm_kit/infra/RealTimeApp_TimeChecker_Piece.hpp>

    private:
        template <class T>
        class ThreadedHandlerBase : public IRealTimeAppPossiblyThreadedNode {
        private:
            TimeChecker<false, T> timeChecker_;
            std::mutex mutex_;
            std::condition_variable cond_;
            std::thread th_;
            std::atomic<bool> running_;
            std::list<TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType>> incoming_, processing_;  

            void stopThread() {
                running_ = false;
            }
            void runThread() {
                while (running_) {
                    {
                        std::unique_lock<std::mutex> lock(mutex_);
                        cond_.wait_for(lock, std::chrono::milliseconds(1));
                        if (!running_) {
                            lock.unlock();
                            return;
                        }
                        if (incoming_.empty()) {
                            lock.unlock();
                            this->idleWork();
                            continue;
                        }
                        processing_.splice(processing_.end(), incoming_);
                        lock.unlock();
                        if constexpr (std::is_convertible_v<StateT *, OutputRealTimeThreadBufferSizeComponent *>) {
                            std::ostringstream oss;
                            oss << "Thread buffer for " << std::this_thread::get_id() << " size: " << processing_.size();
                            processing_.front().environment->log(LogLevel::Debug, oss.str());
                        }
                    }
                    while (!processing_.empty()) {
                        auto &data = processing_.front();
                        actuallyHandle(std::move(data));
                        processing_.pop_front();
                    }
                }  
            }
        protected:
            bool timeCheckGood(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> const &data) {
                return timeChecker_(data);
            }
            bool timeCheckGood(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) {
                return timeChecker_(std::move(data));
            }
            virtual void idleWork() {}
            virtual void actuallyHandle(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) = 0;
        public:
            ThreadedHandlerBase() : timeChecker_(), mutex_(), cond_(), th_(), running_(false), incoming_(), processing_() {
                running_ = true;
                th_ = std::thread(&ThreadedHandlerBase::runThread, this);
                th_.detach();
            }
            virtual ~ThreadedHandlerBase() {
                stopThread();
            }
            virtual std::optional<std::thread::native_handle_type> threadHandle() override final {
                return th_.native_handle();
            }
        protected:
            void putData(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) {
                if (running_) {
                    {
                        std::lock_guard<std::mutex> _(mutex_);
                        incoming_.push_back(std::move(data));
                    }
                    cond_.notify_one();
                }                    
            }
            TimeChecker<false, T> const &timeChecker() const {
                return timeChecker_;
            }
            void stop() {
                stopThread();
            }
        };

    public:
        template <class T>
        class ThreadedHandler : public virtual IHandler<T>, public ThreadedHandlerBase<T> {
        public:
            ThreadedHandler() : ThreadedHandlerBase<T>() {
            }
            virtual ~ThreadedHandler() {
            }
            virtual void handle(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) override final {
                ThreadedHandlerBase<T>::putData(std::move(data));                
            }
        };

        #include <tm_kit/infra/RealTimeApp_ThreadedHandler_Piece.hpp>

    private:
        //busy loop can only be used to handle one kind of input
        template <class T>
        class BusyLoopThreadedHandlerBase : public IRealTimeAppPossiblyThreadedNode {
        private:
            bool noYield_;
            TimeChecker<false, T> timeChecker_;
            std::mutex mutex_;
            std::thread th_;
            std::atomic<bool> running_;
            std::list<TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType>> incoming_, processing_;  

            void stopThread() {
                running_ = false;
            }
            void runThread() {
                while (running_) {
                    idleWork();
                    {
                        std::lock_guard<std::mutex> _(mutex_);
                        if (!incoming_.empty()) {
                            processing_.splice(processing_.end(), incoming_);
                        }
                    }
                    if constexpr (std::is_convertible_v<StateT *, OutputRealTimeThreadBufferSizeComponent *>) {
                        if (!processing_.empty()) {
                            std::ostringstream oss;
                            oss << "Thread buffer for " << std::this_thread::get_id() << " size: " << processing_.size();
                            processing_.front().environment->log(LogLevel::Debug, oss.str());
                        }
                    }
                    while (!processing_.empty()) {
                        auto &data = processing_.front();
                        actuallyHandle(std::move(data));
                        processing_.pop_front();
                    }
                    if (!noYield_) {
                        std::this_thread::yield();
                    }
                }  
            }
        protected:
            bool timeCheckGood(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> const &data) {
                return timeChecker_(data);
            }
            bool timeCheckGood(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) {
                return timeChecker_(std::move(data));
            }
            virtual void idleWork() {}
            virtual void actuallyHandle(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) = 0;
        public:
            BusyLoopThreadedHandlerBase(bool noYield=false) : noYield_(noYield), timeChecker_(), mutex_(), th_(), running_(false), incoming_(), processing_() {
                running_ = true;
                th_ = std::thread(&BusyLoopThreadedHandlerBase::runThread, this);
                th_.detach();
            }
            virtual ~BusyLoopThreadedHandlerBase() {
                stopThread();
            }
            virtual std::optional<std::thread::native_handle_type> threadHandle() override final {
                return th_.native_handle();
            }
        protected:
            void putData(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) {
                if (running_) {
                    std::lock_guard<std::mutex> _(mutex_);
                    incoming_.push_back(std::move(data));
                }                    
            }
            TimeChecker<false, T> const &timeChecker() const {
                return timeChecker_;
            }
            void stop() {
                stopThread();
            }
        };

    public:
        template <class T>
        class BusyLoopThreadedHandler : public virtual IHandler<T>, public BusyLoopThreadedHandlerBase<T> {
        public:
            BusyLoopThreadedHandler(bool noYield=false) : BusyLoopThreadedHandlerBase<T>(noYield) {
            }
            virtual ~BusyLoopThreadedHandler() {
            }
            virtual void handle(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) override final {
                BusyLoopThreadedHandlerBase<T>::putData(std::move(data));                
            }
        };

        template <class T>
        class Producer : public virtual IStoppableRealTimeProducer<1> {
        private:
            std::vector<IHandler<T> *> handlers_;
            std::unordered_set<IHandler<T> *> handlerSet_;
            std::mutex mutex_;
        public:
            Producer() : handlers_(), handlerSet_(), mutex_() {}
            Producer(Producer const &) = delete;
            Producer &operator=(Producer const &) = delete;
            Producer(Producer &&) = default;
            Producer &operator=(Producer &&) = default;
            virtual ~Producer() {}
            void addHandler(IHandler<T> *h) {
                if (h == nullptr) {
                    return;
                }
                std::lock_guard<std::mutex> _(mutex_);
                if (handlerSet_.find(h) == handlerSet_.end()) {
                    handlers_.push_back(h);
                    handlerSet_.insert(h);
                }               
            }
            void publish(StateT *env, T &&data) {
                publish(withtime_utils::pureTimedDataWithEnvironment<T, StateT, typename StateT::TimePointType>(env, std::move(data)));
            }
            void publish(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) {
                if (this->producerIsStopped()) {
                    return;
                }
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers_.size();
                switch (s) {
                    case 0:
                        return;
                    case 1:
                        handlers_.front()->handle(std::move(data));
                        break;
                    default:
                        {
                            for (auto ii=0; ii<s-1; ++ii) {
                                handlers_[ii]->handle(data.clone());
                            }
                            handlers_[s-1]->handle(std::move(data));
                            /*
                            TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> ownedCopy { std::move(data) };
                            for (auto *h : handlers_) {
                                h->handle(ownedCopy.clone());
                            }
                            */
                        }
                        break;
                }
            }
        };

        #include <tm_kit/infra/RealTimeApp_ProducerN_Piece.hpp>

        //In OnOrderFacility, it is NOT ALLOWED to directly publish a KeyedData<A,B> in its base producer
        //The reason is that the produced KeyedData<A,B> must come from a **STORED** Key<A>. So, the producer is 
        //only allowed to calculate and publish Key<B>'s, and the logic here will automatically
        //lookup the correct Key<A> to match with it and combine them into KeyedData<A,B>.
        //This is why this specialization is a completely separate implemention from the generic 
        //Producer<T>.
        template <class T>
        class OnOrderFacilityProducer {};
        template <class A, class B>
        class OnOrderFacilityProducer<KeyedData<A,B>> {
        private:
            std::unordered_map<typename StateT::IDType, std::tuple<Key<A>, IHandler<KeyedData<A,B>> *>, typename StateT::IDHash> theMap_;
            std::recursive_mutex mutex_;
        public:
            OnOrderFacilityProducer() : theMap_(), mutex_() {}
            OnOrderFacilityProducer(OnOrderFacilityProducer const &) = delete;
            OnOrderFacilityProducer &operator=(OnOrderFacilityProducer const &) = delete;
            OnOrderFacilityProducer(OnOrderFacilityProducer &&) = default;
            OnOrderFacilityProducer &operator=(OnOrderFacilityProducer &&) = default;
            virtual ~OnOrderFacilityProducer() {}
            void registerKeyHandler(Key<A> const &k, IHandler<KeyedData<A,B>> *handler) {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                if (handler != nullptr) {
                    if (theMap_.find(k.id()) == theMap_.end()) {
                        theMap_.insert(std::make_pair(k.id(), std::tuple<Key<A>, IHandler<KeyedData<A,B>> *> {k, handler}));
                    }
                }
            }
            void publish(StateT *env, Key<B> &&data, bool isFinal) {
                auto ret = withtime_utils::pureTimedDataWithEnvironment<Key<B>, StateT, typename StateT::TimePointType>(env, std::move(data), isFinal);
                publish(std::move(ret));
            }
            void publish(TimedDataWithEnvironment<Key<B>, StateT, typename StateT::TimePointType> &&data) {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                auto iter = theMap_.find(data.timedData.value.id());
                if (iter == theMap_.end()) {
                    return;
                }
                auto *h = std::get<1>(iter->second);
                if (h == nullptr) {  
                    return;
                }
                bool isFinal = data.timedData.finalFlag;
                KeyedData<A,B> outputD {std::get<0>(iter->second), std::move(data.timedData.value.key())};
                //There is a slight difference in how RealTimeApp and SinglePassIterationApp
                //handles the "final" reply message in an OnOrderFacility
                //For SinglePassIterationApp, when the message goes to the consumer, it will be marked as
                //"final" ONLY IF this message is the last one ever in the OnOrderFacility (meaning that the
                //key is a "final" one too). This makes sense because otherwise we will terminate the
                //OnOrderFacility too early in that monad.
                //However, here, for RealTimeApp, the final flag will be preserved when it gets into the consumer
                //The reason is that in RealTimeApp, the final flag is only used to release 
                //internal key records of OnOrderFacility, so we pass the final flag in case that the consumer
                //is actually somehow passing it to another OnOrderFacility which will release its internal key
                //object. Since RealTimeApp does not really terminate the logic of OnOrderFacility based
                //on final flag, this is harmless
                WithTime<KeyedData<A,B>,typename StateT::TimePointType> outputT {data.timedData.timePoint, std::move(outputD), isFinal};                                  
                h->handle(withtime_utils::pureTimedDataWithEnvironment<KeyedData<A,B>, StateT, typename StateT::TimePointType>(data.environment, std::move(outputT)));    
                if (isFinal) {
                    theMap_.erase(iter);
                }  
            }
            void publishResponse(TimedDataWithEnvironment<Key<B>, StateT, typename StateT::TimePointType> &&data) {
                this->publish(std::move(data));
            }
            void markEndHandlingRequest(typename StateT::IDType const &id) {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                theMap_.erase(id);
            }
        };

        class IExternalComponent {
        public:
            virtual ~IExternalComponent() {}
            virtual void start(StateT *environment) = 0;
        };

        template <class A, class B>
        class AbstractAction : public virtual IHandler<A>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
        public:
            virtual bool isThreaded() const = 0;
            virtual bool isOneTimeOnly() const = 0;
            virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
                if (command == "stop") {
                    if (params.empty()) {
                        this->stopProducer();
                    } else {
                        this->stopProducer((uint8_t) std::stoi(params[0]));
                    }
                } else if (command == "restart") {
                    if (params.empty()) {
                        this->restartProducer();
                    } else {
                        this->restartProducer((uint8_t) std::stoi(params[0]));
                    }
                }
            }
            std::vector<std::string> observe(StateT *env) const override final {
                return this->producerStoppedStatus();
            }
        };

        #include <tm_kit/infra/RealTimeApp_AbstractAction_Piece.hpp>

        //We don't allow importer to manufacture keyed data "out of the blue"
        template <class T, typename=std::enable_if_t<!is_keyed_data_v<T>>>
        class AbstractImporter : public virtual IExternalComponent, public Producer<T> {
        protected:
            static constexpr AbstractImporter *nullptrToInheritedImporter() {return nullptr;}
        };

        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        class AbstractExporter : public virtual IExternalComponent, public virtual IHandler<T> {
        protected:
            static constexpr AbstractExporter *nullptrToInheritedExporter() {return nullptr;}
        public:
            virtual bool isTrivialExporter() const {return false;}
        };

        template <class A, class B>
        class AbstractOnOrderFacility: public virtual IHandler<Key<A>>, public OnOrderFacilityProducer<KeyedData<A,B>> {
        protected:
            static constexpr AbstractOnOrderFacility *nullptrToInheritedFacility() {return nullptr;}
        };
        
        template <class A, class B>
        class OneLevelDownKleisli {
        protected:
            virtual ~OneLevelDownKleisli() {}
            virtual TimedAppData<B, StateT> action(StateT *env, WithTime<A, typename StateT::TimePointType> &&data) = 0;
            virtual void *getIdleHandlerParam() {return nullptr;}
        };

        template <class A, class B, class F, bool ForceFinal>
        class PureOneLevelDownKleisli : public virtual OneLevelDownKleisli<A,B> {
        private:
            F f_;
            virtual TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) override final {
                if constexpr (ForceFinal) {
                    auto ret = withtime_utils::pureTimedDataWithEnvironmentLift(env, f_, std::move(data));
                    ret.timedData.finalFlag = true;
                    return ret;
                } else {
                    return withtime_utils::pureTimedDataWithEnvironmentLift(env, f_, std::move(data));
                }               
            }
            virtual void *getIdleHandlerParam() override final {
                return (void *) &f_;
            }
        public:
            PureOneLevelDownKleisli(F &&f) : f_(std::move(f)) {}
            PureOneLevelDownKleisli(PureOneLevelDownKleisli const &) = delete;
            PureOneLevelDownKleisli &operator=(PureOneLevelDownKleisli const &) = delete;
            PureOneLevelDownKleisli(PureOneLevelDownKleisli &&) = default;
            PureOneLevelDownKleisli &operator=(PureOneLevelDownKleisli &&) = default;
            virtual ~PureOneLevelDownKleisli() {}
        };
        //This is only used for multi action. For regular action
        //, if the "enhanced" input data is needed, just use EnhancedMaybe
        template <class A, class B, class F, bool ForceFinal>
        class EnhancedPureOneLevelDownKleisli : public virtual OneLevelDownKleisli<A, B> {
        private:
            F f_;
            virtual TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) override final {
                auto b = f_(std::tuple<typename StateT::TimePointType, A> {data.timePoint, std::move(data.value)});
                return withtime_utils::pureTimedDataWithEnvironment(env, WithTime<B, typename StateT::TimePointType> {
                    data.timePoint,
                    std::move(b),
                    (ForceFinal?true:data.finalFlag)
                });
            }
            virtual void *getIdleHandlerParam() override final {
                return (void *) &f_;
            }
        public:
            EnhancedPureOneLevelDownKleisli(F &&f) : f_(std::move(f)) {}
            EnhancedPureOneLevelDownKleisli(EnhancedPureOneLevelDownKleisli const &) = delete;
            EnhancedPureOneLevelDownKleisli &operator=(EnhancedPureOneLevelDownKleisli const &) = delete;
            EnhancedPureOneLevelDownKleisli(EnhancedPureOneLevelDownKleisli &&) = default;
            EnhancedPureOneLevelDownKleisli &operator=(EnhancedPureOneLevelDownKleisli &&) = default;
            virtual ~EnhancedPureOneLevelDownKleisli() {}
        };
        template <class A, class B, class F, bool ForceFinal>
        class MaybeOneLevelDownKleisli : public virtual OneLevelDownKleisli<A, B> {
        private:
            F f_;
            virtual TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) override final {
                auto b = f_(std::move(data.value));
                if (b) {
                    return withtime_utils::pureTimedDataWithEnvironment(env, WithTime<B, typename StateT::TimePointType> {
                        data.timePoint,
                        std::move(*b),
                        (ForceFinal?true:data.finalFlag)
                    });
                } else {
                    return std::nullopt;
                }
            }
            virtual void *getIdleHandlerParam() override final {
                return (void *) &f_;
            }
        public:
            MaybeOneLevelDownKleisli(F &&f) : f_(std::move(f)) {}
            MaybeOneLevelDownKleisli(MaybeOneLevelDownKleisli const &) = delete;
            MaybeOneLevelDownKleisli &operator=(MaybeOneLevelDownKleisli const &) = delete;
            MaybeOneLevelDownKleisli(MaybeOneLevelDownKleisli &&) = default;
            MaybeOneLevelDownKleisli &operator=(MaybeOneLevelDownKleisli &&) = default;
            virtual ~MaybeOneLevelDownKleisli() {}
        };
        template <class A, class B, class F, bool ForceFinal>
        class EnhancedMaybeOneLevelDownKleisli : public virtual OneLevelDownKleisli<A, B> {
        private:
            F f_;
            virtual TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) override final {
                auto b = f_(std::tuple<typename StateT::TimePointType, A> {data.timePoint, std::move(data.value)});
                if (b) {
                    return withtime_utils::pureTimedDataWithEnvironment(env, WithTime<B, typename StateT::TimePointType> {
                        data.timePoint,
                        std::move(*b),
                        (ForceFinal?true:data.finalFlag)
                    });
                } else {
                    return std::nullopt;
                }
            }
            virtual void *getIdleHandlerParam() override final {
                return (void *) &f_;
            }
        public:
            EnhancedMaybeOneLevelDownKleisli(F &&f) : f_(std::move(f)) {}
            EnhancedMaybeOneLevelDownKleisli(EnhancedMaybeOneLevelDownKleisli const &) = delete;
            EnhancedMaybeOneLevelDownKleisli &operator=(EnhancedMaybeOneLevelDownKleisli const &) = delete;
            EnhancedMaybeOneLevelDownKleisli(EnhancedMaybeOneLevelDownKleisli &&) = default;
            EnhancedMaybeOneLevelDownKleisli &operator=(EnhancedMaybeOneLevelDownKleisli &&) = default;
            virtual ~EnhancedMaybeOneLevelDownKleisli() {}
        };
        template <class A, class B, class F, bool ForceFinal>
        class DirectOneLevelDownKleisli : public virtual OneLevelDownKleisli<A, B> {
        private:
            F f_;
            virtual TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) override final {
                if (ForceFinal) {
                    auto ret = f_(TimedDataWithEnvironment<A, StateT, typename StateT::TimePointType> {
                        env
                        , std::move(data)
                    });
                    if (!ret) {
                        return ret;
                    } else {
                        ret->timedData.finalFlag = true;
                        return ret;
                    }
                } else {
                    return f_(TimedDataWithEnvironment<A, StateT, typename StateT::TimePointType> {
                        env
                        , std::move(data)
                    });
                }               
            }
            virtual void *getIdleHandlerParam() override final {
                return (void *) &f_;
            }
        public:
            DirectOneLevelDownKleisli(F &&f) : f_(std::move(f)) {}
            DirectOneLevelDownKleisli(DirectOneLevelDownKleisli const &) = delete;
            DirectOneLevelDownKleisli &operator=(DirectOneLevelDownKleisli const &) = delete;
            DirectOneLevelDownKleisli(DirectOneLevelDownKleisli &&) = default;
            DirectOneLevelDownKleisli &operator=(DirectOneLevelDownKleisli &&) = default;
            virtual ~DirectOneLevelDownKleisli() {}
        };

        template <class A, class B, class F, class KleisliImpl, class Main, std::enable_if_t<std::is_base_of_v<OneLevelDownKleisli<A,B>,KleisliImpl>,int> = 0>
        class OneLevelDownKleisliMixin : public virtual KleisliImpl, public Main {
        public:
            template <typename... Args>
            OneLevelDownKleisliMixin(F &&f, Args&&... args) 
                : KleisliImpl(std::move(f)), Main(std::forward<Args>(args)...) {}
            virtual ~OneLevelDownKleisliMixin() {}
            OneLevelDownKleisliMixin(OneLevelDownKleisliMixin const &) = delete;
            OneLevelDownKleisliMixin &operator=(OneLevelDownKleisliMixin const &) = delete;
            OneLevelDownKleisliMixin(OneLevelDownKleisliMixin &&) = default;
            OneLevelDownKleisliMixin &operator=(OneLevelDownKleisliMixin &&) = default;
        };
        template <class A, class B, class F, class StartF, class KleisliImpl, class Main, std::enable_if_t<std::is_base_of_v<OneLevelDownKleisli<A,B>,KleisliImpl>,int> = 0>
        class OneLevelDownKleisliMixinWithStart : public virtual IExternalComponent, public virtual KleisliImpl, public Main {
        private:
            StartF startF_;
        public:
            template <typename... Args>
            OneLevelDownKleisliMixinWithStart(F &&f, StartF &&startF, Args&&... args) 
                : IExternalComponent(), KleisliImpl(std::move(f)), Main(std::forward<Args>(args)...), startF_(std::move(startF)) {}
            virtual ~OneLevelDownKleisliMixinWithStart() {}
            OneLevelDownKleisliMixinWithStart(OneLevelDownKleisliMixinWithStart const &) = delete;
            OneLevelDownKleisliMixinWithStart &operator=(OneLevelDownKleisliMixinWithStart const &) = delete;
            OneLevelDownKleisliMixinWithStart(OneLevelDownKleisliMixinWithStart &&) = default;
            OneLevelDownKleisliMixinWithStart &operator=(OneLevelDownKleisliMixinWithStart &&) = default;
            virtual void start(StateT *environment) override final {
                startF_(environment);
            }
        };
        template <class A, class B, class F, class MultiKleisliImpl, class Main, std::enable_if_t<std::is_base_of_v<OneLevelDownKleisli<A,std::vector<B>>,MultiKleisliImpl>,int> = 0>
        class OneLevelDownMultiKleisliMixin : public virtual MultiKleisliImpl, public Main {
        public:
            template <typename... Args>
            OneLevelDownMultiKleisliMixin(F &&f, Args&&... args) 
                : MultiKleisliImpl(std::move(f)), Main(std::forward<Args>(args)...) {}
            virtual ~OneLevelDownMultiKleisliMixin() {}
            OneLevelDownMultiKleisliMixin(OneLevelDownMultiKleisliMixin const &) = delete;
            OneLevelDownMultiKleisliMixin &operator=(OneLevelDownMultiKleisliMixin const &) = delete;
            OneLevelDownMultiKleisliMixin(OneLevelDownMultiKleisliMixin &&) = default;
            OneLevelDownMultiKleisliMixin &operator=(OneLevelDownMultiKleisliMixin &&) = default;
        };
    };
    
    template <class StateT>
    class RealTimeApp {
    private:  
        friend class AppRunner<RealTimeApp>;

    public:
        static constexpr bool PossiblyMultiThreaded = true;
        static constexpr bool CannotHaveLoopEvenWithFacilities = false;

        //The data definition part
        //This part is of course best put into a common code, however, 
        //because of template inheritance issues, it is actually easier
        //just to include it in each monad
        using TimePoint = typename StateT::TimePointType;
        using Duration = decltype(TimePoint{} - TimePoint{});
        using StateType = StateT;
        using EnvironmentType = StateT;
        template <class T>
        using TimedDataType = WithTime<T, TimePoint>;
        template <class T>
        using Key = Key<T,StateT>;
        template <class A, class B>
        using KeyedData = KeyedData<A,B,StateT>;

        template <class T>
        static Key<T> keyify(T &&t) {
            return withtime_utils::keyify<T,StateT>(std::move(t));
        }

        template <class T>
        using InnerData = TimedDataWithEnvironment<T, StateType, TimePoint>;

        template <class T>
        static InnerData<T> pureInnerData(StateT *env, T &&t, bool finalFlag = false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(env, std::move(t), finalFlag);
        }
        template <class T>
        static InnerData<T> pureInnerData(StateT *env, TimedDataType<T> &&t, bool preserveTime=false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(env, std::move(t), preserveTime);
        }
        template <class T>
        static InnerData<T> pureInnerData(InnerData<T> &&t, bool preserveTime=false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(std::move(t), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(StateT *environment, F &f, TimedDataType<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(F &f, InnerData<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(StateT *environment, F const &f, TimedDataType<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(F const &f, InnerData<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime);
        }

        template <class T>
        using IHandler = typename RealTimeAppComponents<StateT>::template IHandler<T>;
        template <class T>
        using Producer = typename RealTimeAppComponents<StateT>::template Producer<T>;

        using IExternalComponent = typename RealTimeAppComponents<StateT>::IExternalComponent;

        template <class T>
        using Data = TimedAppData<T,StateT>;

        template <class T>
        using MultiData = TimedAppMultiData<T,StateT>;
    
    private:
        template <class T, class Input, class Output>
        class TwoWayHolder {
        private:
            friend class RealTimeApp;
            std::unique_ptr<T> core_;
            IRealTimeAppPossiblyThreadedNode *threadInfo_;
            IControllableNode<StateT> *controlInfo_;
            IObservableNode<StateT> *observeInfo_;
            void release() {
                core_.release();
                threadInfo_ = nullptr;
                controlInfo_ = nullptr;
                observeInfo_ = nullptr;
            }
        public:
            using InputType = Input;
            using OutputType = Output;

            TwoWayHolder(std::unique_ptr<T> &&p) : threadInfo_(dynamic_cast<IRealTimeAppPossiblyThreadedNode *>(p.get())), controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p.get())), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p.get())), core_(std::move(p)) {}
            template <class A>
            TwoWayHolder(A *p) : threadInfo_(dynamic_cast<IRealTimeAppPossiblyThreadedNode *>(p)), controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p)), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p)), core_(std::unique_ptr<T>(static_cast<T *>(p))) {}
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core_.get()};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                std::vector<IControllableNode<StateT> *> ret;
                if (controlInfo_) {
                    ret.push_back(controlInfo_);
                }
                return ret;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                std::vector<IObservableNode<StateT> *> ret;
                if (observeInfo_) {
                    ret.push_back(observeInfo_);
                }
                return ret;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                if (controlInfo_) {
                    controlInfo_->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                if (observeInfo_) {
                    return observeInfo_->observe(env);
                } else {
                    return {};
                }
            }
        };
        template <class T, class Data>
        class OneWayHolder {
        private:
            friend class RealTimeApp;
            IRealTimeAppPossiblyThreadedNode *threadInfo_;
            IControllableNode<StateT> *controlInfo_;
            IObservableNode<StateT> *observeInfo_;
            std::unique_ptr<T> core_;
            void release() {
                core_.release();
                threadInfo_ = nullptr;
                controlInfo_ = nullptr;
                observeInfo_ = nullptr;
            }
        public:
            using DataType = Data;

            OneWayHolder(std::unique_ptr<T> &&p) : threadInfo_(dynamic_cast<IRealTimeAppPossiblyThreadedNode *>(p.get())), controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p.get())), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p.get())), core_(std::move(p)) {}
            template <class A>
            OneWayHolder(A *p) : threadInfo_(dynamic_cast<IRealTimeAppPossiblyThreadedNode *>(p)), controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p)), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p)), core_(std::unique_ptr<T>(dynamic_cast<T *>(p))) {}
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core_.get()};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                std::vector<IControllableNode<StateT> *> ret;
                if (controlInfo_) {
                    ret.push_back(controlInfo_);
                }
                return ret;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                std::vector<IObservableNode<StateT> *> ret;
                if (observeInfo_) {
                    ret.push_back(observeInfo_);
                }
                return ret;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                if (controlInfo_) {
                    controlInfo_->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                if (observeInfo_) {
                    return observeInfo_->observe(env);
                } else {
                    return {};
                }
            }
        };
        template <class T1, class Input, class Output, class T2, class Data>
        class ThreeWayHolder {
        private:
            friend class RealTimeApp;
            //The reason why we use raw pointers here is that
            //the two pointers may well be pointing to the same
            //object (through different base classes). Therefore
            //we give up on managing the memory for this special
            //case
            T1 *core1_;
            T2 *core2_;
            std::vector<IControllableNode<StateT> *> controlInfo_;
            std::vector<IObservableNode<StateT> *> observeInfo_;
            void release() {
                core1_ = nullptr;
                core2_ = nullptr;
                controlInfo_.clear();
                observeInfo_.clear();
            }
        public:
            using InputType = Input;
            using OutputType = Output;
            using DataType = Data;

            template <class A, class B>
            ThreeWayHolder(A *p1, B*p2) : core1_(static_cast<T1 *>(p1)), core2_(static_cast<T2 *>(p2)), controlInfo_() {
                auto *q1 = dynamic_cast<IControllableNode<StateT> *>(p1);
                if (q1) {
                    controlInfo_.push_back(q1);
                }
                auto *q2 = dynamic_cast<IControllableNode<StateT> *>(p2);
                if (q2 && (q2 != q1)) {
                    controlInfo_.push_back(q2);
                }
                auto *o1 = dynamic_cast<IObservableNode<StateT> *>(p1);
                if (o1) {
                    observeInfo_.push_back(o1);
                }
                auto *o2 = dynamic_cast<IObservableNode<StateT> *>(p2);
                if (o2 && (o2 != o1)) {
                    observeInfo_.push_back(o2);
                }
            }
            ThreeWayHolder(ThreeWayHolder const &) = delete;
            ThreeWayHolder &operator=(ThreeWayHolder const &) = delete;
            ThreeWayHolder(ThreeWayHolder &&) = default;
            ThreeWayHolder &operator=(ThreeWayHolder &&) = default;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core1_, core2_};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                return controlInfo_;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                return observeInfo_;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                for (auto *p : controlInfo_) {
                    p->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                std::vector<std::string> ret;
                for (auto *p : observeInfo_) {
                    auto r = p->observe(env);
                    std::copy(r.begin(), r.end(), std::back_inserter(ret));
                }
                return ret;
            }
        };
        template <class T1, class Input, class Output, class T2, class ExtraInput, class T3, class ExtraOutput>
        class FourWayHolder {
        private:
            friend class RealTimeApp;
            //The reason why we use raw pointers here is that
            //the three pointers may well be pointing to the same
            //object (through different base classes). Therefore
            //we give up on managing the memory for this special
            //case
            T1 *core1_;
            T2 *core2_;
            T3 *core3_;
            std::vector<IControllableNode<StateT> *> controlInfo_;
            std::vector<IObservableNode<StateT> *> observeInfo_;
            void release() {
                core1_ = nullptr;
                core2_ = nullptr;
                core3_ = nullptr;
                controlInfo_.clear();
                observeInfo_.clear();
            }
        public:
            using InputType = Input;
            using OutputType = Output;
            using ExtraInputType = ExtraInput;
            using ExtraOutputType = ExtraOutput;

            template <class A, class B, class C>
            FourWayHolder(A *p1, B *p2, C *p3) : core1_(static_cast<T1 *>(p1)), core2_(static_cast<T2 *>(p2)), core3_(static_cast<T3 *>(p3)) {
                auto *q1 = dynamic_cast<IControllableNode<StateT> *>(p1);
                if (q1) {
                    controlInfo_.push_back(q1);
                }
                auto *q2 = dynamic_cast<IControllableNode<StateT> *>(p2);
                if (q2 && (q2 != q1)) {
                    controlInfo_.push_back(q2);
                }
                auto *q3 = dynamic_cast<IControllableNode<StateT> *>(p3);
                if (q3 && (q3 != q1) && (q3 != q2)) {
                    controlInfo_.push_back(q3);
                }
                auto *o1 = dynamic_cast<IObservableNode<StateT> *>(p1);
                if (o1) {
                    observeInfo_.push_back(o1);
                }
                auto *o2 = dynamic_cast<IObservableNode<StateT> *>(p2);
                if (o2 && (o2 != o1)) {
                    observeInfo_.push_back(o2);
                }
                auto *o3 = dynamic_cast<IObservableNode<StateT> *>(p3);
                if (o3 && (o3 != o1) && (o3 != o2)) {
                    observeInfo_.push_back(o3);
                }
            }
            FourWayHolder(FourWayHolder const &) = delete;
            FourWayHolder &operator=(FourWayHolder const &) = delete;
            FourWayHolder(FourWayHolder &&) = default;
            FourWayHolder &operator=(FourWayHolder &&) = default;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core1_, core2_, core3_};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                return controlInfo_;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                return observeInfo_;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                for (auto *p : controlInfo_) {
                    p->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                std::vector<std::string> ret;
                for (auto *p : observeInfo_) {
                    auto r = p->observe(env);
                    std::copy(r.begin(), r.end(), std::back_inserter(ret));
                }
                return ret;
            }
        };
    
    public:
        template <class A, class B, bool Threaded, bool FireOnceOnly>
        class ActionCore {};
        template <class A, class B, bool FireOnceOnly>
        class ActionCore<A,B,true,FireOnceOnly> : public virtual RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,B>, public RealTimeAppComponents<StateT>::template AbstractAction<A,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<A> {
        private:
            bool done_;
            std::function<void(void *)> idleWorker_;
            std::mutex idleWorkerMutex_;
        protected:
            virtual void actuallyHandle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (!this->timeCheckGood(data)) {
                    return;
                }
                TraceNodesComponentWrapper<StateT,typename RealTimeAppComponents<StateT>::template AbstractAction<A,B>> tracer(
                    data.environment 
                    , this
                );
                auto res = this->action(data.environment, std::move(data.timedData));
                if (res) {
                    if constexpr (FireOnceOnly) {
                        res->timedData.finalFlag = true;
                    }
                    Producer<B>::publish(std::move(*res));
                    if constexpr (FireOnceOnly) {
                        done_ = true;
                        this->stop();
                    }
                }
            }
        public:
            ActionCore() : RealTimeAppComponents<StateT>::template AbstractAction<A,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<A>(), done_(false), idleWorker_(), idleWorkerMutex_() {
            }
            virtual ~ActionCore() {
            }
            virtual bool isThreaded() const override final {
                return true;
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
            virtual void setIdleWorker(std::function<void(void *)> worker) override final {
                std::lock_guard<std::mutex> _(idleWorkerMutex_);
                idleWorker_ = worker;
            }
            virtual void idleWork() override final {
                std::lock_guard<std::mutex> _(idleWorkerMutex_);
                if (idleWorker_) {
                    idleWorker_(this->getIdleHandlerParam());
                }
            }
        };
        template <class A, class B, bool FireOnceOnly>
        class ActionCore<A,B,false,FireOnceOnly> : public virtual RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,B>, public RealTimeAppComponents<StateT>::template AbstractAction<A,B> {
        private:
            typename RealTimeAppComponents<StateT>::template TimeChecker<true, A> timeChecker_;
            std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
        public:
            ActionCore() : RealTimeAppComponents<StateT>::template AbstractAction<A,B>(), timeChecker_(), done_(false) {
            }
            virtual ~ActionCore() {
            }
            virtual void handle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (timeChecker_(data)) {
                    TraceNodesComponentWrapper<StateT,typename RealTimeAppComponents<StateT>::template AbstractAction<A,B>> tracer(
                        data.environment 
                        , this
                    );
                    auto res = this->action(data.environment, std::move(data.timedData));
                    if (res) {
                        if constexpr (FireOnceOnly) {
                            res->timedData.finalFlag = true;
                        }
                        Producer<B>::publish(std::move(*res));
                        if constexpr (FireOnceOnly) {
                            done_ = true;
                        }
                    }
                }
            }
            virtual bool isThreaded() const override final {
                return false;
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
            virtual void setIdleWorker(std::function<void(void *)> worker) override final {
            }
        };
        //PureActionCore will be specialized so it is not defined with mixin
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        class PureActionCore final : public virtual RealTimeAppComponents<StateT>::template PureOneLevelDownKleisli<A,B,F,false>, public ActionCore<A,B,Threaded,FireOnceOnly> {
        public:
            PureActionCore(F &&f) : RealTimeAppComponents<StateT>::template PureOneLevelDownKleisli<A,B,F,false>(std::move(f)), ActionCore<A,B,Threaded,FireOnceOnly>() {}
            PureActionCore(PureActionCore const &) = delete;
            PureActionCore &operator=(PureActionCore const &) = delete;
            PureActionCore(PureActionCore &&) = default;
            PureActionCore &operator=(PureActionCore &&) = default;
            virtual ~PureActionCore() {}
        };
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        using MaybeActionCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template MaybeOneLevelDownKleisli<A,B,F,false>,
                                ActionCore<A,B,Threaded, FireOnceOnly>
                                >;
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        using EnhancedMaybeActionCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template EnhancedMaybeOneLevelDownKleisli<A,B,F,false>,
                                ActionCore<A,B,Threaded, FireOnceOnly>
                                >;
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        using KleisliActionCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template DirectOneLevelDownKleisli<A,B,F,false>,
                                ActionCore<A,B,Threaded, FireOnceOnly>
                                >;

        #include <tm_kit/infra/RealTimeApp_ActionCore_Piece.hpp>

    public:
        //We don't allow any action to manufacture KeyedData "out of the blue"
        //, but it is ok to manipulate Keys, so the check is one-sided
        //Moreover, we allow manipulation of KeyedData
        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A>, int> = 0>
        using AbstractAction = typename RealTimeAppComponents<StateT>::template AbstractAction<A,B>;

        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A>, int> = 0>
        using Action = TwoWayHolder<typename RealTimeAppComponents<StateT>::template AbstractAction<A,B>,A,B>;

        template <class A, class B>
        static bool actionIsThreaded(std::shared_ptr<Action<A,B>> const &a) {
            return a->core_->isThreaded(); 
        }
        template <class A, class B>
        static bool actionIsOneTimeOnly(std::shared_ptr<Action<A,B>> const &a) {
            return a->core_->isOneTimeOnly(); 
        }
        template <class A, class B>
        static void setIdleWorkerForAction(std::shared_ptr<Action<A,B>> const &a, std::function<void(void *)> idleWorker) {
            a->core_->setIdleWorker(idleWorker);
        }
        
        template <class A, class F>
        static auto liftPure1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,decltype(f(A()))>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F,true,true>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F,false,true>(std::move(f)));
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F,true,false>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F,false,false>(std::move(f)));
                }
            }
        }     
        template <class A, class F>
        static auto liftMaybe1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F,true,true>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F,false,true>(std::move(f)));
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F,true,false>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F,false,false>(std::move(f)));
                }
            }
        }
        template <class A, class F>
        static auto enhancedMaybe1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true,true>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false,true>(std::move(f)));
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true,false>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false,false>(std::move(f)));
                }
            }  
        }
        template <class A, class F>
        static auto kleisli1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                        new KleisliActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, true, true>(std::move(f))
                    );
                } else {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                        new KleisliActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, false, true>(std::move(f))
                    );
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                        new KleisliActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, true, false>(std::move(f))
                    );
                } else {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                        new KleisliActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, false, false>(std::move(f))
                    );
                }
            }
        }
    private:
        template <class A, class B, bool Threaded, bool FireOnceOnly>
        class MultiActionCore {};
        template <class A, class B, bool FireOnceOnly>
        class MultiActionCore<A,B,true,FireOnceOnly> : public virtual RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,std::vector<B>>, public RealTimeAppComponents<StateT>::template AbstractAction<A,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<A> {
        private:
            bool done_;
            std::function<void(void *)> idleWorker_;
            std::mutex idleWorkerMutex_;
        protected:
            virtual void actuallyHandle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (!this->timeCheckGood(data)) {
                    return;
                }
                auto res = this->action(data.environment, std::move(data.timedData));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                        this->stop();
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        public:
            MultiActionCore() : RealTimeAppComponents<StateT>::template AbstractAction<A,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<A>(), done_(false), idleWorker_(), idleWorkerMutex_() {
            }
            virtual ~MultiActionCore() {
            }
            virtual bool isThreaded() const override final {
                return true;
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
            virtual void setIdleWorker(std::function<void(void *)> worker) override final {
                std::lock_guard<std::mutex> _(idleWorkerMutex_);
                idleWorker_ = worker;
            }
            virtual void idleWork() override final {
                std::lock_guard<std::mutex> _(idleWorkerMutex_);
                if (idleWorker_) {
                    idleWorker_(this->getIdleHandlerParam());
                }
            }
        };
        template <class A, class B, bool FireOnceOnly>
        class MultiActionCore<A,B,false,FireOnceOnly> : public virtual RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,std::vector<B>>, public RealTimeAppComponents<StateT>::template AbstractAction<A,B> {
        private:
            typename RealTimeAppComponents<StateT>::template TimeChecker<true, A> timeChecker_;
            bool fireOnceOnly_;
            std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
        public:
            MultiActionCore() : RealTimeAppComponents<StateT>::template AbstractAction<A,B>(), timeChecker_(), done_(false) {
            }
            virtual ~MultiActionCore() {
            }
            virtual void handle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (timeChecker_(data)) {
                    auto res = this->action(data.environment, std::move(data.timedData));
                    if (res && !res->timedData.value.empty()) {
                        if constexpr (FireOnceOnly) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(res->timedData.value[0])
                                    , true
                                }
                            });
                            done_ = true;
                        } else {
                            size_t l = res->timedData.value.size();
                            size_t ii = l-1;
                            for (auto &&item : res->timedData.value) {
                                Producer<B>::publish(InnerData<B> {
                                    res->environment
                                    , {
                                        res->timedData.timePoint
                                        , std::move(item)
                                        , ((ii==0)?res->timedData.finalFlag:false)
                                    }
                                });
                                --ii;
                            }
                        }
                    }
                }
            }
            virtual bool isThreaded() const override final {
                return false;
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
            virtual void setIdleWorker(std::function<void(void *)> worker) override final {
            }
        };
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        using SimpleMultiActionCore = typename RealTimeAppComponents<StateT>::template OneLevelDownMultiKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template PureOneLevelDownKleisli<A,std::vector<B>,F,false>,
                                MultiActionCore<A,B,Threaded,FireOnceOnly>
                                >;
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        using EnhancedMultiActionCore = typename RealTimeAppComponents<StateT>::template OneLevelDownMultiKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template EnhancedPureOneLevelDownKleisli<A,std::vector<B>,F,false>,
                                MultiActionCore<A,B,Threaded,FireOnceOnly>
                                >;
        template <class A, class B, class F, bool Threaded, bool FireOnceOnly>
        using KleisliMultiActionCore = typename RealTimeAppComponents<StateT>::template OneLevelDownMultiKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template DirectOneLevelDownKleisli<A,std::vector<B>,F,false>,
                                MultiActionCore<A,B,Threaded,FireOnceOnly>
                                >;
        
        #include <tm_kit/infra/RealTimeApp_MultiActionCore_Piece.hpp>
    public:
        template <class A, class F>
        static auto liftMulti1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(A()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F,true,true>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F,false,true>(std::move(f)));
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F,true,false>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F,false,false>(std::move(f)));
                }
            }
        }     
        template <class A, class F>
        static auto enhancedMulti1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true,true>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false,true>(std::move(f)));
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true,false>(std::move(f)));
                } else {
                    return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false,false>(std::move(f)));
                }
            }
        }
        template <class A, class F>
        static auto kleisliMulti1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>> {
            if (liftParam.fireOnceOnly) {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>>(
                        new KleisliMultiActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type, F, true, true>(std::move(f))
                    );
                } else {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>>(
                        new KleisliMultiActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type, F, false, true>(std::move(f))
                    );
                }
            } else {
                if (liftParam.suggestThreaded) {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>>(
                        new KleisliMultiActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type, F, true, false>(std::move(f))
                    );
                } else {
                    return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>>(
                        new KleisliMultiActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type, F, false, false>(std::move(f))
                    );
                }
            }
        }
    private:
        template <class A, class B, class ContinuationStructure, bool Threaded, bool FireOnceOnly>
        class ContinuationActionCore {};
        template <class A, class B, class ContinuationStructure, bool FireOnceOnly>
        class ContinuationActionCore<A, B, ContinuationStructure, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<A,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<A> {
        private:
            TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> cont_;
            ContinuationStructure state_;
            bool done_;
        protected:
            virtual void actuallyHandle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (!this->timeCheckGood(data)) {
                    return;
                }
                cont_(std::move(data), state_, [this](InnerData<B> &&x) {
                    if constexpr (FireOnceOnly) {
                        done_ = true;
                    }
                    Producer<B>::publish(std::move(x));
                });
            }
        public:
            ContinuationActionCore(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state=ContinuationStructure()) : RealTimeAppComponents<StateT>::template AbstractAction<A,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<A>(), cont_(cont), state_(std::move(state)), done_(false) {
            }
            virtual ~ContinuationActionCore() {
            }
            virtual bool isThreaded() const override final {
                return true;
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
        };
        template <class A, class B, class ContinuationStructure, bool FireOnceOnly>
        class ContinuationActionCore<A,B,ContinuationStructure,false,FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<A,B> {
        private:
            typename RealTimeAppComponents<StateT>::template TimeChecker<true, A> timeChecker_;
            TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> cont_;
            ContinuationStructure state_;
            std::atomic<bool> done_;
        public:
            ContinuationActionCore(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state=ContinuationStructure()) : RealTimeAppComponents<StateT>::template AbstractAction<A,B>(), timeChecker_(), cont_(cont), state_(std::move(state)), done_(false) {
            }
            virtual ~ContinuationActionCore() {
            }
            virtual void handle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (timeChecker_(data)) {
                    cont_(std::move(data), state_, [this](InnerData<B> &&x) {
                        if constexpr (FireOnceOnly) {
                            done_ = true;
                        }
                        Producer<B>::publish(std::move(x));
                    });
                }
            }
            virtual bool isThreaded() const override final {
                return false;
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
        };
    public:
        template <class A, class B, class ContinuationStructure>
        static auto continuationAction(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state=ContinuationStructure(), LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, B>> {
            if (liftParam.suggestThreaded) {
                if (liftParam.fireOnceOnly) {
                    return std::make_shared<Action<A,B>>(
                        new ContinuationActionCore<A,B,ContinuationStructure,true,true>(cont,std::move(state))
                    );
                } else {
                    return std::make_shared<Action<A,B>>(
                        new ContinuationActionCore<A,B,ContinuationStructure,true,false>(cont,std::move(state))
                    );
                }
            } else {
                if (liftParam.fireOnceOnly) {
                    return std::make_shared<Action<A,B>>(
                        new ContinuationActionCore<A,B,ContinuationStructure,false,true>(cont,std::move(state))
                    );
                } else {
                    return std::make_shared<Action<A,B>>(
                        new ContinuationActionCore<A,B,ContinuationStructure,false,false>(cont,std::move(state))
                    );
                }
            }
        }
    public:
        template <class A, class B, bool Threaded>
        class OnOrderFacilityCore {};
        template <class A, class B>
        class OnOrderFacilityCore<A,B,true> : public virtual RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,B>, public virtual RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<Key<A>> {
        protected:
            virtual void actuallyHandle(InnerData<Key<A>> &&data) override final {  
                if (!this->timeCheckGood(data)) {
                    return;
                }    
                TM_INFRA_FACILITY_TRACER(data.environment);
                auto id = data.timedData.value.id();
                WithTime<A,TimePoint> a {data.timedData.timePoint, data.timedData.value.key()};
                auto res = this->action(data.environment, std::move(a));
                if (res) {
                    RealTimeAppComponents<StateT>::template OnOrderFacilityProducer<KeyedData<A,B>>::publish(
                        pureInnerDataLift([id=std::move(id)](B &&b) -> Key<B> {
                            return {std::move(id), std::move(b)};
                        }, std::move(*res))
                    );
                }
            }
        public:
            OnOrderFacilityCore() : RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,B>(), RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<Key<A>>() {
            }
            virtual ~OnOrderFacilityCore() {
            }
        };
        template <class A, class B>
        class OnOrderFacilityCore<A,B,false> : public virtual RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,B>, public virtual RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B> {
        private:
            typename RealTimeAppComponents<StateT>::template TimeChecker<true, Key<A>> timeChecker_;
        public:
            OnOrderFacilityCore() : RealTimeAppComponents<StateT>::template OneLevelDownKleisli<A,B>(), RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B>(), timeChecker_() {
            }
            virtual ~OnOrderFacilityCore() {
            }
            virtual void handle(InnerData<Key<A>> &&data) override final {
                if (timeChecker_(data)) {
                    TM_INFRA_FACILITY_TRACER(data.environment);
                    auto id = data.timedData.value.id();
                    WithTime<A,TimePoint> a {data.timedData.timePoint, data.timedData.value.key()};
                    auto res = this->action(data.environment, std::move(a));
                    if (res) {
                        RealTimeAppComponents<StateT>::template OnOrderFacilityProducer<KeyedData<A,B>>::publish(
                            pureInnerDataLift([id=std::move(id)](B &&b) -> Key<B> {
                                return {std::move(id), std::move(b)};
                            }, std::move(*res))
                        );
                    }
                }
            }
        };
        template <class A, class B, class F, bool Threaded>
        using PureOnOrderFacilityCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template PureOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                                >;
        template <class A, class B, class F, bool Threaded>
        using MaybeOnOrderFacilityCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template MaybeOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                                >;
        template <class A, class B, class F, bool Threaded>
        using EnhancedMaybeOnOrderFacilityCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template EnhancedMaybeOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                                >;
        template <class A, class B, class F, bool Threaded>
        using KleisliOnOrderFacilityCore = typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixin<
                                A, B, F,
                                typename RealTimeAppComponents<StateT>::template DirectOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                                >;

        template <class A, class B, class F, class StartF, bool Threaded>
        using PureOnOrderFacilityCoreWithStart = 
                        typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixinWithStart<
                                A, B, F, StartF,
                                typename RealTimeAppComponents<StateT>::template PureOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                        >;
        template <class A, class B, class F, class StartF, bool Threaded>
        using MaybeOnOrderFacilityCoreWithStart = 
                        typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixinWithStart<
                                A, B, F, StartF,
                                typename RealTimeAppComponents<StateT>::template MaybeOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                        >;
        template <class A, class B, class F, class StartF, bool Threaded>
        using EnhancedMaybeOnOrderFacilityCoreWithStart = 
                        typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixinWithStart<
                                A, B, F, StartF,
                                typename RealTimeAppComponents<StateT>::template EnhancedMaybeOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                        >;
        template <class A, class B, class F, class StartF, bool Threaded>
        using KleisliOnOrderFacilityCoreWithStart = 
                        typename RealTimeAppComponents<StateT>::template OneLevelDownKleisliMixinWithStart<
                                A, B, F, StartF,
                                typename RealTimeAppComponents<StateT>::template DirectOneLevelDownKleisli<A,B,F,true>,
                                OnOrderFacilityCore<A,B,Threaded>
                        >;
    public:
        template <class A, class B>
        using AbstractOnOrderFacility = typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B>;
        template <class A, class B>
        using OnOrderFacility = TwoWayHolder<AbstractOnOrderFacility<A,B>,A,B>;

        template <class A, class F>
        static auto liftPureOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A,decltype(f(A()))>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A,decltype(f(A()))>>(new PureOnOrderFacilityCore<A,decltype(f(A())),F,true>(std::move(f)));
            } else {
                return std::make_shared<OnOrderFacility<A,decltype(f(A()))>>(new PureOnOrderFacilityCore<A,decltype(f(A())),F,false>(std::move(f)));
            }
        }     
        template <class A, class F>
        static auto liftMaybeOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCore<A,typename decltype(f(A()))::value_type,F,true>(std::move(f)));
            } else {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCore<A,typename decltype(f(A()))::value_type,F,false>(std::move(f)));
            }
        }
        template <class A, class F>
        static auto enhancedMaybeOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true>(std::move(f)));
            } else {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false>(std::move(f)));
            }
        }
        template <class A, class F>
        static auto kleisliOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                    new KleisliOnOrderFacilityCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, true>(std::move(f))
                );
            } else {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                    new KleisliOnOrderFacilityCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, false>(std::move(f))
                );
            }
        }

        template <class A, class F, class StartF>
        static auto liftPureOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A,decltype(f(A()))>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A,decltype(f(A()))>>(new PureOnOrderFacilityCoreWithStart<A,decltype(f(A())),F,StartF,true>(std::move(f), std::move(startF)));
            } else {
                return std::make_shared<OnOrderFacility<A,decltype(f(A()))>>(new PureOnOrderFacilityCoreWithStart<A,decltype(f(A())),F,StartF,false>(std::move(f), std::move(startF)));
            }
        }     
        template <class A, class F, class StartF>
        static auto liftMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(A()))::value_type,F,StartF,true>(std::move(f),std::move(startF)));
            } else {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(A()))::value_type,F,StartF,false>(std::move(f),std::move(startF)));
            }
        }
        template <class A, class F, class StartF>
        static auto enhancedMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,StartF,true>(std::move(f),std::move(startF)));
            } else {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,StartF,false>(std::move(f),std::move(startF)));
            }
        }
        template <class A, class F, class StartF>
        static auto kleisliOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>> {
            if (liftParam.suggestThreaded) {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                    new KleisliOnOrderFacilityCoreWithStart<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, StartF, true>(std::move(f), std::move(startF))
                );
            } else {
                return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                    new KleisliOnOrderFacilityCoreWithStart<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, StartF, false>(std::move(f), std::move(startF))
                );
            }
        }

        template <class A, class B>
        static std::shared_ptr<Action<A,B>> fromAbstractAction(typename RealTimeAppComponents<StateT>::template AbstractAction<A,B> *t) {
            return std::make_shared<Action<A,B>>(t);
        }
        template <class A, class B>
        static std::shared_ptr<OnOrderFacility<A,B>> fromAbstractOnOrderFacility(typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B> *t) {
            return std::make_shared<OnOrderFacility<A,B>>(t);
        }
    private:
        template <class I0, class O0, class I1, class O1>
        class WrappedOnOrderFacility final : public IExternalComponent, public RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<I0,O0> {
        private:
            OnOrderFacility<I1,O1> toWrap_;
            Action<Key<I0>,Key<I1>> inputT_;
            Action<Key<O1>,Key<O0>> outputT_;
            class Conduit1 final : public RealTimeAppComponents<StateT>::template IHandler<Key<I1>> {
            private:
                typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<I1,O1> *toWrap_;
                typename RealTimeAppComponents<StateT>::template IHandler<KeyedData<I1,O1>> *nextConduit_;
            public:
                Conduit1(
                    typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<I1,O1> *toWrap,
                    typename RealTimeAppComponents<StateT>::template IHandler<KeyedData<I1,O1>> *nextConduit
                ) : toWrap_(toWrap), nextConduit_(nextConduit) {}
                void handle(InnerData<Key<I1>> &&i1) override final {
                    toWrap_->registerKeyHandler(i1.timedData.value, nextConduit_);
                    toWrap_->handle(std::move(i1));
                }
            };
            class Conduit2 final : public RealTimeAppComponents<StateT>::template IHandler<KeyedData<I1,O1>> {
            private:
                typename RealTimeAppComponents<StateT>::template AbstractAction<Key<O1>,Key<O0>> *outputT_;
            public:
                Conduit2(typename RealTimeAppComponents<StateT>::template AbstractAction<Key<O1>,Key<O0>> *outputT)
                    : outputT_(outputT) {}
                void handle(InnerData<KeyedData<I1,O1>> &&o1) override final {
                    auto x = pureInnerDataLift([](KeyedData<I1,O1> &&a) -> Key<O1> {
                        return {a.key.id(), std::move(a.data)};
                    }, std::move(o1));
                    outputT_->handle(std::move(x));
                }
            }; 
            class Conduit3 final : public RealTimeAppComponents<StateT>::template IHandler<Key<O0>> {
            private:
                WrappedOnOrderFacility *parent_;
            public:
                Conduit3(WrappedOnOrderFacility *parent)
                    : parent_(parent) {}
                void handle(InnerData<Key<O0>> &&o0) override final {
                    parent_->publish(std::move(o0));
                }
            };        
            Conduit3 c3_;   
            Conduit2 c2_;
            Conduit1 c1_;
        public:
            WrappedOnOrderFacility(
                OnOrderFacility<I1,O1> &&toWrap,
                Action<Key<I0>,Key<I1>> &&inputT,
                Action<Key<O1>,Key<O0>> &&outputT
            ) : toWrap_(std::move(toWrap)), inputT_(std::move(inputT)), outputT_(std::move(outputT)),
                c3_(this), c2_(outputT_.core_.get()), c1_(toWrap_.core_.get(), &c2_) {
                outputT_.core_->addHandler(&c3_);
                inputT_.core_->addHandler(&c1_);
            }
            virtual void start(StateT *env) override final {
                auto *p = dynamic_cast<IExternalComponent *>(toWrap_.core_.get());
                if (p != nullptr) {
                    p->start(env);
                }
            }
            virtual void handle(InnerData<Key<I0>> &&i0) override final {
                inputT_.core_->handle(std::move(i0));
            }
        };
    public:
        template <class I0, class O0, class I1, class O1>
        static std::shared_ptr<OnOrderFacility<I0,O0>> wrappedOnOrderFacility(OnOrderFacility<I1,O1> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) {
            return std::make_shared<OnOrderFacility<I0,O0>>(
                new WrappedOnOrderFacility<I0,O0,I1,O1>(std::move(toWrap),std::move(inputT),std::move(outputT))
            );
        };
    private:
        template <class A, class B, class C>
        class Compose final : public RealTimeAppComponents<StateT>::template AbstractAction<A,C> {
        private:
            std::unique_ptr<typename RealTimeAppComponents<StateT>::template AbstractAction<A,B>> f_;
            std::unique_ptr<typename RealTimeAppComponents<StateT>::template AbstractAction<B,C>> g_;
            class InnerHandler : public IHandler<C> {
            private:
                Producer<C> *p_;
            public:
                InnerHandler(Producer<C> *p) : p_(p) {}
                virtual void handle(InnerData<C> &&data) override final {
                    p_->publish(std::move(data));
                }
            };
            InnerHandler innerHandler_;
        protected:
            virtual void handle(InnerData<A> &&data) override final {
                f_->handle(std::move(data));
            }
        public:
            Compose() : f_(), g_(), innerHandler_(this) {}
            Compose(std::unique_ptr<typename RealTimeAppComponents<StateT>::template AbstractAction<A,B>> &&f, std::unique_ptr<typename RealTimeAppComponents<StateT>::template AbstractAction<B,C>> &&g) : f_(std::move(f)), g_(std::move(g)), innerHandler_(this) {
                f_->addHandler(g_.get());
                g_->addHandler(&innerHandler_);
            }
            virtual bool isThreaded() const override final {
                return f_->isThreaded() || g_->isThreaded();
            }
            virtual bool isOneTimeOnly() const override final {
                return f_->isOneTimeOnly() || g_->isOneTimeOnly();
            }
            virtual void setIdleWorker(std::function<void(void *)> worker) override final {}
        };
    public:   
        template <class A, class B, class C>
        static std::shared_ptr<Action<A,C>> compose(Action<A,B> &&f, Action<B,C> &&g) {
            return std::make_shared<Action<A,C>>(new Compose<A,B,C>(std::move(f.core_), std::move(g.core_)));
        }

    #include <tm_kit/infra/RealTimeApp_Merge_Piece.hpp>
    #include <tm_kit/infra/RealTimeApp_PureN_Piece.hpp>
    #include <tm_kit/infra/RealTimeApp_MaybeN_Piece.hpp>  
    #include <tm_kit/infra/RealTimeApp_EnhancedMaybeN_Piece.hpp>  
    #include <tm_kit/infra/RealTimeApp_KleisliN_Piece.hpp>  
    #include <tm_kit/infra/RealTimeApp_MultiN_Piece.hpp>  
    #include <tm_kit/infra/RealTimeApp_EnhancedMultiN_Piece.hpp>  
    #include <tm_kit/infra/RealTimeApp_KleisliMultiN_Piece.hpp>  

    public:
        template <class T>
        using AbstractImporter = typename RealTimeAppComponents<StateT>::template AbstractImporter<T>;
        template <class T>
        using Importer = OneWayHolder<AbstractImporter<T>,T>;
        template <class T>
        class PublisherCall {
        private:
            Producer<T> *pub_;
            StateT *env_;
        public:
            PublisherCall(Producer<T> *p, StateT *env) : pub_(p), env_(env) {}
            inline void operator()(T &&data) const {
                pub_->publish(env_, std::move(data));
            }
        };
    private:
        template <class T, class F>
        class SimpleImporter final : public IRealTimeAppPossiblyThreadedNode, public AbstractImporter<T> {
        private:
            F f_;
            bool threaded_;
            std::optional<std::thread::native_handle_type> thHandle_;
        public:
            SimpleImporter(F &&f, bool threaded) : f_(std::move(f)), threaded_(threaded), thHandle_(std::nullopt) {}
            virtual void start(StateT *env) override final {
                if (threaded_) {
                    auto pub = std::make_unique<PublisherCall<T>>(this, env);
                    std::thread th([this,pub=std::move(pub)]() {
                        f_(*(pub.get()));
                    });
                    th.detach();
                    thHandle_ = th.native_handle();
                } else {
                    auto pub = std::make_unique<PublisherCall<T>>(this, env);
                    f_(*(pub.get()));
                }
                
            }
            virtual std::optional<std::thread::native_handle_type> threadHandle() override final {
                return thHandle_;
            }
        };
    public:
        template <class T>
        static std::shared_ptr<Importer<T>> importer(AbstractImporter<T> *p) {
            return std::make_shared<Importer<T>>(p);
        }
        template <class T>
        static std::shared_ptr<Importer<T>> vacuousImporter() {
            class LocalI final : public AbstractImporter<T> {
            public:
                virtual void start(StateT *env) override final {
                }
            };
            return std::make_shared<Importer<T>>(new LocalI());
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> simpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Importer<T>>(std::make_unique<SimpleImporter<T,F>>(std::move(f), liftParam.suggestThreaded));
        }
    private:
        template <class T, class F>
        class UniformSimpleImporter final : public IRealTimeAppPossiblyThreadedNode, public AbstractImporter<T> {
        private:
            F f_;
            std::thread th_;
            std::optional<std::thread::native_handle_type> thHandle_;
            std::atomic<bool> running_;
            void run(StateT *env) {
                while (running_) {
                    auto x = f_(env);
                    if (std::get<1>(x)) {
                        bool final = std::get<1>(x)->timedData.finalFlag;
                        this->publish(std::move(*(std::get<1>(x))));
                        if (final) {
                            break;
                        }
                    }
                    if (!std::get<0>(x)) {
                        break;
                    }
                }
            }
        public:
            UniformSimpleImporter(F &&f) : f_(std::move(f)), th_(), thHandle_(std::nullopt), running_(false) {}
            ~UniformSimpleImporter() {
                if (running_) {
                    running_ = false;
                    try {
                        th_.join();
                    } catch (std::exception &) {}
                }
            }
            virtual void start(StateT *env) override final {
                running_ = true;
                th_ = std::thread ([this,env]() {
                    run(env);
                });
                th_.detach();
                thHandle_ = th_.native_handle();
            }
            virtual std::optional<std::thread::native_handle_type> threadHandle() override final {
                return thHandle_;
            }
        };
    public:
        template <class T, class F>
        static std::shared_ptr<Importer<T>> uniformSimpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Importer<T>>(std::make_unique<UniformSimpleImporter<T,F>>(std::move(f)));
        }
        template <class T>
        static std::shared_ptr<Importer<T>> constFirstPushImporter(T &&t = T()) {
            return simpleImporter<T>([t=std::move(t)](PublisherCall<T> &pub) {
                T t1 { std::move(t) };
                pub(std::move(t1));
            });
        }
        template <class T>
        static std::shared_ptr<Importer<Key<T>>> constFirstPushKeyImporter(T &&t = T()) {
            return constFirstPushImporter<Key<T>>(
                infra::withtime_utils::keyify<T,StateT>(std::move(t))
            );
        }
        template <class T, bool HasOwnThread=true>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void()>> constTriggerImporter(T &&t = T()) {
            if constexpr (HasOwnThread) {
                class LocalI final : public IRealTimeAppPossiblyThreadedNode, public AbstractImporter<T> {
                private:
                    T t_;
                    StateT *env_;
                    uint64_t count_;
                    std::condition_variable cond_;
                    std::mutex mutex_;
                    std::thread th_;
                    std::atomic<bool> running_;
                    void run() {
                        running_ = true;
                        while (running_) {
                            std::unique_lock<std::mutex> lock(mutex_);
                            cond_.wait(lock);
                            auto countCopy = count_;
                            count_ = 0;
                            lock.unlock();
                            if (!running_) {
                                break;
                            }
                            for (auto ii=0; ii<countCopy; ++ii) {
                                T oneCopy = infra::withtime_utils::makeValueCopy<T>(t_);
                                this->publish(env_, std::move(oneCopy));
                            }
                        }
                    }
                public:
                    LocalI(T &&t) : t_(std::move(t)), env_(nullptr), count_(0), cond_(), mutex_(), th_(), running_(false) {
                    }
                    ~LocalI() {
                        if (running_) {
                            running_ = false;
                            cond_.notify_one();
                            if (th_.joinable()) {
                                th_.join();
                            }
                        }
                    }
                    virtual void start(StateT *env) override final {
                        env_ = env;
                        th_ = std::thread(&LocalI::run, this);
                        th_.detach();
                    }
                    void trigger() {
                        if (running_) {
                            {
                                std::lock_guard<std::mutex> _(mutex_);
                                ++count_;
                            }
                            cond_.notify_one();
                        }
                    }
                    virtual std::optional<std::thread::native_handle_type> threadHandle() override final {
                        return th_.native_handle();
                    }
                };
                auto *p = new LocalI(std::move(t));
                return {
                    std::make_shared<Importer<T>>(p)
                    , [p]() {
                        p->trigger();
                    }
                };
            } else {
                class LocalI final : public AbstractImporter<T> {
                private:
                    T t_;
                    StateT *env_;
                public:
                    LocalI(T &&t) : t_(std::move(t)), env_(nullptr) {
                    }
                    ~LocalI() {
                    }
                    virtual void start(StateT *env) override final {
                        env_ = env;
                    }
                    void trigger() {
                        T oneCopy = infra::withtime_utils::makeValueCopy<T>(t_);
                        this->publish(env_, std::move(oneCopy));
                    }
                };
                auto *p = new LocalI(std::move(t));
                return {
                    std::make_shared<Importer<T>>(p)
                    , [p]() {
                        p->trigger();
                    }
                };
            }
        }
        template <class T, bool HasOwnThread=true>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void(T&&)>> triggerImporter() {
            if constexpr (HasOwnThread) {
                class LocalI final : public IRealTimeAppPossiblyThreadedNode, public AbstractImporter<T> {
                private:
                    std::list<T> incoming_, processing_;
                    StateT *env_;
                    std::condition_variable cond_;
                    std::mutex mutex_;
                    std::thread th_;
                    std::atomic<bool> running_;
                    void run() {
                        running_ = true;
                        while (running_) {
                            std::unique_lock<std::mutex> lock(mutex_);
                            cond_.wait(lock);
                            if (!running_) {
                                lock.unlock();
                                break;
                            }
                            if (incoming_.empty()) {
                                lock.unlock();
                                continue;
                            }
                            processing_.splice(processing_.end(), incoming_);
                            lock.unlock();
                            while (!processing_.empty()) {
                                T &data = processing_.front();
                                this->publish(env_, std::move(data));
                                processing_.pop_front();
                            }
                        }
                    }
                public:
                    LocalI() : incoming_(), processing_(), env_(nullptr), cond_(), mutex_(), th_(), running_(false) {
                    }
                    ~LocalI() {
                        if (running_) {
                            running_ = false;
                            cond_.notify_one();
                            if (th_.joinable()) {
                                th_.join();
                            }
                        }
                    }
                    virtual void start(StateT *env) override final {
                        env_ = env;
                        th_ = std::thread(&LocalI::run, this);
                        th_.detach();
                    }
                    void trigger(T &&t) {
                        if (!running_) {
                            return;
                        }
                        {
                            std::lock_guard<std::mutex> _(mutex_);
                            incoming_.push_back(std::move(t));
                        }
                        cond_.notify_one();
                    }
                    virtual std::optional<std::thread::native_handle_type> threadHandle() override final {
                        return th_.native_handle();
                    }
                };
                auto *p = new LocalI();
                return {
                    std::make_shared<Importer<T>>(p)
                    , [p](T &&t) {
                        p->trigger(std::move(t));
                    }
                };
            } else {
                class LocalI final : public AbstractImporter<T> {
                private:
                    StateT *env_;
                public:
                    LocalI() : env_(nullptr) {
                    }
                    ~LocalI() {
                    }
                    virtual void start(StateT *env) override final {
                        env_ = env;
                    }
                    void trigger(T &&t) {
                        this->publish(env_, std::move(t));
                    }
                };
                auto *p = new LocalI();
                return {
                    std::make_shared<Importer<T>>(p)
                    , [p](T &&t) {
                        p->trigger(std::move(t));
                    }
                };
            }
        }
        template <class T, bool HasOwnThread=true>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void(WithTime<T,TimePoint> &&)>> triggerImporterWithTime() {
            auto imp = triggerImporter<T,HasOwnThread>();
            auto f = std::get<1>(imp);
            return {
                std::get<0>(imp)
                , [f](WithTime<T,TimePoint> &&x) {
                    f(std::move(x.value));
                }
            };
        }
    public:
        template <class T>
        using AbstractExporter = typename RealTimeAppComponents<StateT>::template AbstractExporter<T>;
        template <class T>
        using Exporter = OneWayHolder<AbstractExporter<T>,T>;
    private:
        template <class T, class F, bool Threaded>
        class SimpleExporter {};
        template <class T, class F>
        class SimpleExporter<T,F,true> final : public virtual AbstractExporter<T>, public RealTimeAppComponents<StateT>::template ThreadedHandler<T> {
        private:
            F f_;  
            bool isTrivial_;
            virtual void actuallyHandle(InnerData<T> &&d) override final {
                if (!this->timeCheckGood(d)) {
                    return;
                }
                TM_INFRA_EXPORTER_TRACER(d.environment);
                f_(std::move(d));
            }    
        public:
        #ifdef _MSC_VER
            SimpleExporter(F &&f, bool isTrivial=false) : f_(std::move(f)), isTrivial_(isTrivial) {}
        #else
            SimpleExporter(F &&f, bool isTrivial=false) : AbstractExporter<T>(), RealTimeAppComponents<StateT>::template ThreadedHandler<T>(), f_(std::move(f)), isTrivial_(isTrivial) {}
        #endif            
            virtual ~SimpleExporter() {}
            virtual void start(StateT *) override final {}
            virtual bool isTrivialExporter() const override final {
                return isTrivial_;
            }
        };
        template <class T, class F>
        class SimpleExporter<T,F,false> final : public virtual AbstractExporter<T> {
        private:
            F f_;    
            typename RealTimeAppComponents<StateT>::template TimeChecker<true, T> timeChecker_; 
            bool isTrivial_;
        public:
        #ifdef _MSC_VER
            SimpleExporter(F &&f, bool isTrivial=false) : f_(std::move(f)), timeChecker_(), isTrivial_(isTrivial) {}
        #else
            SimpleExporter(F &&f, bool isTrivial=false) : AbstractExporter<T>(), f_(std::move(f)), timeChecker_(), isTrivial_(isTrivial) {}
        #endif
            virtual ~SimpleExporter() {}
            virtual void handle(InnerData<T> &&d) override final {
                if (timeChecker_(d)) {
                    TM_INFRA_EXPORTER_TRACER(d.environment);
                    f_(std::move(d));
                }
            } 
            virtual void start(StateT *) override final {}
            virtual bool isTrivialExporter() const override final {
                return isTrivial_;
            }
        };
    public:       
        template <class T>
        static std::shared_ptr<Exporter<T>> exporter(AbstractExporter<T> *p) {
            return std::make_shared<Exporter<T>>(p);
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> simpleExporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Exporter<T>>(std::make_unique<SimpleExporter<T,F,true>>(std::move(f)));
            } else {
                return std::make_shared<Exporter<T>>(std::make_unique<SimpleExporter<T,F,false>>(std::move(f)));
            }            
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> pureExporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            auto wrapper = [f=std::move(f)](InnerData<T> &&d) mutable {
                f(std::move(d.timedData.value));
            };
            return simpleExporter<T>(std::move(wrapper), liftParam);
        }
    private:
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> trivialExporter_internal(F &&f) {
            return std::make_shared<Exporter<T>>(std::make_unique<SimpleExporter<T,F,false>>(std::move(f), true));       
        }
    public:
        template <class T>
        static std::shared_ptr<Exporter<T>> trivialExporter() {
            return trivialExporter_internal<T>([](InnerData<T> &&) {});
        }

    public:
        template <class T1, class T2>
        static std::shared_ptr<Importer<T2>> composeImporter(Importer<T1> &&orig, Action<T1,T2> &&post) {
            class LocalI final : public AbstractImporter<T2> {
            private:
                Importer<T1> orig_;
                Action<T1,T2> post_;
                class LocalH final : public RealTimeAppComponents<StateT>::template IHandler<T2> {
                private:
                    LocalI *parent_;
                public:
                    LocalH(LocalI *parent) : parent_(parent) {}
                    virtual void handle(InnerData<T2> &&t2) override final {
                        parent_->publish(std::move(t2));
                    }
                };
                LocalH localH_;
            public:
                LocalI(Importer<T1> &&orig, Action<T1,T2> &&post)
                    : orig_(std::move(orig)), post_(std::move(post)), localH_(this)
                {
                    orig_.core_->addHandler(post_.core_.get());
                    post_.core_->addHandler(&localH_);
                }
                virtual ~LocalI() {}
                virtual void start(StateT *env) override final {
                    orig_.core_->start(env);
                }
            };
            return std::make_shared<Importer<T2>>(new LocalI(std::move(orig), std::move(post)));
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> composeExporter(Action<T1,T2> &&pre, Exporter<T2> &&orig) {
            class LocalE final : public AbstractExporter<T1> {
            private:
                Action<T1,T2> pre_;
                Exporter<T2> orig_;
            public:
                LocalE(Action<T1,T2> &&pre, Exporter<T2> &&orig)
                    : pre_(std::move(pre)), orig_(std::move(orig))
                {
                    pre_.core_->addHandler(orig_.core_.get());
                }
                virtual ~LocalE() {}
                virtual void start(StateT *env) override final {
                    orig_.core_->start(env);
                }
                virtual void handle(InnerData<T1> &&d) override final {
                    pre_.core_->handle(std::move(d));
                } 
            };
            return std::make_shared<Exporter<T1>>(new LocalE(std::move(pre), std::move(orig)));
        }

    public:
        //The reason why LocalOnOrderFacility is defined as essentially 
        //a tuple instead of an integrated object (as in AbstractIntegratedLocalOnOrderFacility)
        //is to facilitate the separate composition of the facility branch
        //and the exporter branch. 
        //The downside of this is that LocalOnOrderFacility cannot manage the 
        //memory pointed to by the two pointers, since it doesn't know whether
        //they point to the same object or to two different objects. However,
        //since all these objects are "functional" objects, and are supposed to
        //last the whole life of the program, this is a small price to pay. In
        //any case, even with the other types that use unique_ptr to manage their
        //inner objects, those pointers usually are either passed in from heap
        //(admittedly, the user can pass in a stack pointer, and then cause 
        //undefined behavior when the stack disappears, but we cannot control
        //everything the user does), or created internally, and still will last
        //the whole life of the program.
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using LocalOnOrderFacility = ThreeWayHolder<
            typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractExporter<DataInputType>,DataInputType
        >;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> localOnOrderFacility(
            typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractExporter<DataInputType> *e) {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>(t,e);
        }
        
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        class AbstractIntegratedLocalOnOrderFacility 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractExporter<DataInputType> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ExporterParent = AbstractExporter<DataInputType>;
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> localOnOrderFacility(
            AbstractIntegratedLocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType> *p) {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>(p,p);
        }
        
        template <class Fac, class Exp>
        static std::shared_ptr<LocalOnOrderFacility<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Exp::DataType>> localOnOrderFacility(
            Fac &&t, Exp &&e) {
            auto *p_t = t.core_.get();
            auto *p_e = e.core_.get();
            t.release();
            e.release();
            return std::make_shared<LocalOnOrderFacility<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Exp::DataType>>(p_t,p_e);
        }

        template <class Fac, class Action1, class Action2
            , std::enable_if_t<std::is_same_v<typename Action1::OutputType::KeyType, typename Fac::InputType>,int> = 0
            , std::enable_if_t<std::is_same_v<typename Action2::InputType::KeyType, typename Fac::OutputType>,int> = 0
            >
        static std::shared_ptr<LocalOnOrderFacility<
            typename Action1::InputType::KeyType
            , typename Action2::OutputType::KeyType
            , typename Fac::DataType>> wrappedLocalOnOrderFacility(Fac &&toWrap, Action1 &&inputT, Action2 &&outputT) {
            auto *t = toWrap.core1_;
            auto *e = toWrap.core2_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = wrappedOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Action1::OutputType::KeyType
                , typename Action2::InputType::KeyType
            >(std::move(*fac), std::move(inputT), std::move(outputT));
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<LocalOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::DataType>
            >(
                p, e
            );
        }

    public:
        //OnOrderFacilityWithExternalEffects is the dual of LocalOnOrderFacility
        //Basically, it is an importer and an on order facility glued
        //together. 
        //The name "DataInputType" is here viewed from outside, it is 
        //actually the "output" from OnOrderFacilityWithExternalEffects.
        //The reason this was not changed to "DataOutputType" is to avoid
        //too many code changes, and also it does make sense to call it
        //an "input" from outside view anyway.
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using OnOrderFacilityWithExternalEffects = ThreeWayHolder<
            typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractImporter<DataInputType>,DataInputType
        >;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractImporter<DataInputType> *i) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>(t,i);
        }
        
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        class AbstractIntegratedOnOrderFacilityWithExternalEffects 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractImporter<DataInputType> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ImporterParent = AbstractImporter<DataInputType>;
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using AbstractIntegratedOnOrderFacilityWithExternalEffectsWithPublish = AbstractIntegratedOnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            AbstractIntegratedOnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType> *p) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>(p,p);
        }
        
        template <class Fac, class Imp>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Imp::DataType>> onOrderFacilityWithExternalEffects(
            Fac &&t, Imp &&i) {
            auto *p_t = t.core_.get();
            auto *p_i = i.core_.get();
            t.release();
            i.release();
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Imp::DataType>>(p_t,p_i);
        }

        template <class Fac, class Action1, class Action2
            , std::enable_if_t<std::is_same_v<typename Action1::OutputType::KeyType, typename Fac::InputType>,int> = 0
            , std::enable_if_t<std::is_same_v<typename Action2::InputType::KeyType, typename Fac::OutputType>,int> = 0
            >
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<
            typename Action1::InputType::KeyType
            , typename Action2::OutputType::KeyType
            , typename Fac::DataType>> wrappedOnOrderFacilityWithExternalEffects(Fac &&toWrap, Action1 &&inputT, Action2 &&outputT) {
            auto *t = toWrap.core1_;
            auto *i = toWrap.core2_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = wrappedOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Action1::OutputType::KeyType
                , typename Action2::InputType::KeyType
            >(std::move(*fac), std::move(inputT), std::move(outputT));
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::DataType>
            >(
                p, i
            );
        }

    public:
        //VIEOnOrderFacility is the combination of LocalOnOrderFacility
        //and OnOrderFacilityWithExternalEffects. The name "VIE" comes from
        //the fact that it looks like a local facility but it has complex
        //offshore linkage
        //Here the "input" and "output" is viewed from the point of VIEOnOrderFacility
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        using VIEOnOrderFacility = FourWayHolder<
            typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractExporter<ExtraInputType>,ExtraInputType
            , AbstractImporter<ExtraOutputType>,ExtraOutputType
        >;
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractExporter<ExtraInputType> *i
            , AbstractImporter<ExtraOutputType> *o) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>(t,i,o);
        }
        
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        class AbstractIntegratedVIEOnOrderFacility 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractExporter<ExtraInputType>, public AbstractImporter<ExtraOutputType> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ExporterParent = AbstractExporter<ExtraInputType>;
            using ImporterParent = AbstractImporter<ExtraOutputType>;
        };
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        using AbstractIntegratedVIEOnOrderFacilityWithPublish = AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>; 
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType, bool NotUsed=false>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType> *p) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>(p,p,p);
        }
        
        template <class Fac, class Exp, class Imp>
        static std::shared_ptr<VIEOnOrderFacility<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Exp::DataType
            , typename Imp::DataType>> vieOnOrderFacility(
            Fac &&t, Exp &&i, Imp &&o) {
            auto *p_t = t.core_.get();
            auto *p_i = i.core_.get();
            auto *p_o = o.core_.get();
            t.release();
            i.release();
            o.release();
            return std::make_shared<VIEOnOrderFacility<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Exp::DataType
                , typename Imp::DataType>>(p_t,p_i,p_o);
        }

        template <class Fac, class Action1, class Action2
            , std::enable_if_t<std::is_same_v<typename Action1::OutputType::KeyType, typename Fac::InputType>,int> = 0
            , std::enable_if_t<std::is_same_v<typename Action2::InputType::KeyType, typename Fac::OutputType>,int> = 0
            >
        static std::shared_ptr<VIEOnOrderFacility<
            typename Action1::InputType::KeyType
            , typename Action2::OutputType::KeyType
            , typename Fac::ExtraInputType
            , typename Fac::ExtraOutputType>> wrappedVIEOnOrderFacility(Fac &&toWrap, Action1 &&inputT, Action2 &&outputT) {
            auto *t = toWrap.core1_;
            auto *i = toWrap.core2_;
            auto *o = toWrap.core3_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = wrappedOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Action1::OutputType::KeyType
                , typename Action2::InputType::KeyType
            >(std::move(*fac), std::move(inputT), std::move(outputT));
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<VIEOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::ExtraInputType
                , typename Fac::ExtraOutputType>
            >(
                p, i, o
            );
        }
    public:
        template<class T>
        static std::optional<std::thread::native_handle_type> threadHandle(
            std::shared_ptr<T> const &node
        ) {
            auto *p = node->threadInfo_;
            if (p) {
                return p->threadHandle();
            } else {
                return std::nullopt;
            }
        }

    public:
        template <class T>
        class Source {
        private:
            friend class RealTimeApp;
            Producer<T> *producer;
            Source(Producer<T> *p) : producer(p) {}
        public:
            Source clone() const {
                return Source {producer};
            }
        };
        template <class T>
        class Sink {
        private:
            friend class RealTimeApp;
            IHandler<T> *consumer;
            Sink(IHandler<T> *c) : consumer(c) {}
        };           
            
    private:  
        std::list<IExternalComponent *> externalComponents_[3];
        std::unordered_set<IExternalComponent *> externalComponentsSet_;
        std::mutex mutex_;
        RealTimeApp() : externalComponents_(), externalComponentsSet_(), mutex_() {}
        ~RealTimeApp() {}

        void registerExternalComponent(IExternalComponent *c, int idx) {
            if (c == nullptr) {
                throw RealTimeAppException(
                    "Cannot register an external component of null"
                );
            }
            std::lock_guard<std::mutex> _(mutex_);
            if (externalComponentsSet_.find(c) == externalComponentsSet_.end()) {
                externalComponents_[idx].push_back(c);
                externalComponentsSet_.insert(c);
            }
        }

        template <class A>
        static void innerConnect(IHandler<A> *handler, Producer<A> *producer) {
            producer->addHandler(handler);
        }
        template <class A>
        class AnyHandlerAdapter : public IHandler<A> {
        private:
            IHandler<std::any> *handler_;
        public:
            AnyHandlerAdapter(IHandler<std::any> *handler) : handler_(handler) {}
            virtual ~AnyHandlerAdapter() = default;
            virtual void handle(InnerData<A> &&x) override final {
                handler_->handle(std::move(x).moveToAny());
            }
        };
        template <class A, typename = std::enable_if_t<!withtime_utils::IsVariant<A>::Value>>
        static void innerConnectAny(IHandler<std::any> *handler, Producer<A> *producer) {
            if constexpr (std::is_same_v<A, std::any>) {
                innerConnect(handler, producer);
            } else {
                innerConnect(new AnyHandlerAdapter<A>(handler), producer);
            }
        }
        template <class A, class B>
        static void innerConnectFacility(Producer<Key<A>> *producer, typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B> *facility, IHandler<KeyedData<A,B>> *consumer) {
            class LocalC final : public virtual IHandler<Key<A>> {
            private:                    
                typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B> *p_;
                IHandler<KeyedData<A,B>> *h_;
            public:
                LocalC(typename RealTimeAppComponents<StateT>::template AbstractOnOrderFacility<A,B> *p, IHandler<KeyedData<A,B>> *h) : p_(p), h_(h) {}
                virtual void handle(InnerData<Key<A>> &&k) {
                    p_->registerKeyHandler(k.timedData.value, h_);
                    p_->handle(std::move(k));
                }
            } *localC = new LocalC(facility, consumer);
            producer->addHandler(localC);
        }
    private:
        template <class T>
        Source<T> importerAsSource(StateT *env, Importer<T> &importer) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(importer.core_.get()), 2);
            return {dynamic_cast<Producer<T> *>(importer.core_.get())};
        }
        template <class A, class B>
        Source<B> actionAsSource(StateT *env, Action<A,B> &action) {
            return {dynamic_cast<Producer<B> *>(action.core_.get())};
        }
        template <class A, class B>
        Source<B> execute(Action<A,B> &action, Source<A> &&variable) {
            innerConnect(dynamic_cast<IHandler<A> *>(action.core_.get()), variable.producer);
            return {dynamic_cast<Producer<B> *>(action.core_.get())};
        }
        template <class A, class B>
        Source<B> executeAny(Action<std::any,B> &action, Source<A> &&variable) {
            innerConnectAny(dynamic_cast<IHandler<std::any> *>(action.core_.get()), variable.producer);
            return {dynamic_cast<Producer<B> *>(action.core_.get())};
        }

        #include <tm_kit/infra/RealTimeApp_ExecuteAction_Piece.hpp>
 
        template <class T>
        Sink<T> exporterAsSink(Exporter<T> &exporter) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(exporter.core_.get()), 0);
            if (dynamic_cast<AbstractExporter<T> *>(exporter.core_.get())->isTrivialExporter()) {
                return {(IHandler<T> *) nullptr};
            } else {
                return {dynamic_cast<IHandler<T> *>(exporter.core_.get())};
            }
        }
        template <class A, class B>
        Sink<A> actionAsSink(Action<A,B> &action) {
            return {dynamic_cast<IHandler<A> *>(action.core_.get())};
        }

        #include <tm_kit/infra/RealTimeApp_VariantSink_Piece.hpp>

        template <class A, class B>
        void placeOrderWithFacility(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core_.get());
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core_.get(), sink.consumer);
        }  
        template <class A, class B>
        void placeOrderWithFacilityAndForget(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core_.get());
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core_.get(), (IHandler<KeyedData<A,B>> *) nullptr);
        }

        template <class A, class B, class C>
        void placeOrderWithLocalFacility(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C>
        void placeOrderWithLocalFacilityAndForget(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core1_, (IHandler<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C>
        Sink<C> localFacilityAsSink(LocalOnOrderFacility<A,B,C> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_), 0);
            return {dynamic_cast<IHandler<C> *>(facility.core2_)};
        }

        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffects(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffectsAndForget(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core1_, (IHandler<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C>
        Source<C> facilityWithExternalEffectsAsSource(OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_), 0);
            return {dynamic_cast<Producer<C> *>(facility.core2_)};
        }

        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacility(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacilityAndForget(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            innerConnectFacility(input.producer, facility.core1_, (IHandler<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C, class D>
        Source<D> vieFacilityAsSource(VIEOnOrderFacility<A,B,C,D> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core3_), 0);
            return {dynamic_cast<Producer<D> *>(facility.core3_)};
        }
        template <class A, class B, class C, class D>
        Sink<C> vieFacilityAsSink(VIEOnOrderFacility<A,B,C,D> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_), 0);
            return {dynamic_cast<IHandler<C> *>(facility.core2_)};
        }

        template <class T>
        void connect(Source<T> &&src, Sink<T> const &sink) {
            innerConnect(sink.consumer, src.producer);
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void connectAny(Source<T> &&src, Sink<std::any> const &sink) {
            innerConnectAny(sink.consumer, src.producer);
        }

        #include <tm_kit/infra/RealTimeApp_ConnectN_Piece.hpp>

        std::function<void(StateT *)> finalize() { 
            std::list<IExternalComponent *> aCopy;
            {
                std::lock_guard<std::mutex> _(mutex_);
                std::copy(externalComponents_[0].begin(), externalComponents_[0].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[1].begin(), externalComponents_[1].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[2].begin(), externalComponents_[2].end(), std::back_inserter(aCopy));
            }  
            return [aCopy=std::move(aCopy)](StateT *env) {
                for (auto c : aCopy) {
                    c->start(env);
                }
            };        
        }
        std::function<std::function<bool(StateT *)>(StateT *)> finalizeForInterleaving() { 
            std::list<IExternalComponent *> aCopy;
            {
                std::lock_guard<std::mutex> _(mutex_);
                std::copy(externalComponents_[0].begin(), externalComponents_[0].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[1].begin(), externalComponents_[1].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[2].begin(), externalComponents_[2].end(), std::back_inserter(aCopy));
            }  
            return [aCopy=std::move(aCopy)](StateT *env) -> std::function<bool(StateT *)> {
                for (auto c : aCopy) {
                    c->start(env);
                }
                return [](StateT *stepEnv) -> bool {
                    return false; //for real-time, the actions all happen on separate threads, so stepper can simply return false
                };
            };        
        }
    public:
        template <class X>
        struct GetDataType {
            using DataType = typename X::DataType;
        };
        template <class X>
        struct GetInputOutputType {
            using InputType = typename X::InputType;
            using OutputType = typename X::OutputType;
        };
        template <class X>
        struct GetExtraInputOutputType {
            using ExtraInputType = typename X::ExtraInputType;
            using ExtraOutputType = typename X::ExtraOutputType;
        };
    private:
        template <class T>
        struct TrueType : std::true_type {};

        template <class T>
        static auto hasDataType(int) -> TrueType<typename T::DataType>;
        template <class T>
        static auto hasDataType(long) -> std::false_type;

        template <class X>
        struct IsOneWayHolder {
            static constexpr bool Value = decltype(hasDataType<X>(0))::value;
        };
        template <class X, bool B>
        struct IsImporterImpl {
        };
        template <class X>
        struct IsImporterImpl<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, Importer<typename X::DataType>
            >;
        };
        template <class X>
        struct IsImporterImpl<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsExporterImpl {
        };
        template <class X>
        struct IsExporterImpl<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, Exporter<typename X::DataType>
            >;
        };
        template <class X>
        struct IsExporterImpl<X, false> {
            static constexpr bool Value = false;
        };
        template <class X, bool B>
        struct IsActionImpl {
        };
        template <class X>
        struct IsActionImpl<X, true> {
            static constexpr bool Value = std::is_same_v<
                X, Action<typename X::InputType, typename X::OutputType>
            >;
        };
        template <class X>
        struct IsActionImpl<X, false> {
            static constexpr bool Value = false;
        };
    public:
        template <class X>
        struct IsImporter {
            static constexpr bool Value = IsImporterImpl<X, IsOneWayHolder<X>::Value>::Value;
        };
        template <class X>
        struct IsExporter {
            static constexpr bool Value = IsExporterImpl<X, IsOneWayHolder<X>::Value>::Value;
        };
        template <class X>
        struct IsAction {
            static constexpr bool Value = IsActionImpl<X, !IsOneWayHolder<X>::Value>::Value;
        };
    };

    template <class T>
    using RealTimeApp_T = RealTimeApp<T>;

} } } }

#endif
