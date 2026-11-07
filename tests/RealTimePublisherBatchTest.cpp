#include <tm_kit/infra/RealTimeApp.hpp>
#include "TestSupport.hpp"
#include <chrono>

namespace infra = dev::cd606::tm::infra;
namespace detail = infra::real_time_app_detail;
using namespace std::chrono_literals;
struct Env : infra::graph_check_components::DontCheckConnections {
    using TimePointType = std::chrono::system_clock::time_point;
    using IDType = int;
    using IDHash = std::hash<int>;
    static constexpr bool CheckTime = false;
    static TimePointType resolveTime() { return std::chrono::system_clock::now(); }
    static TimePointType resolveTime(TimePointType t) { return t; }
    static int new_id() { return 1; }
    static bool less_comparison_id(int a, int b) { return a < b; }
    void finalizeEnvironment() {}
    void log(infra::LogLevel, std::string const &) {}
};
using M = infra::RealTimeApp<Env>;
using Components = infra::RealTimeAppComponents<Env>;
using Params = infra::LiftParameters<M::TimePoint>;
struct Delivery {
    std::string label;
    detail::Scheduler::Batch const *batch;
};
struct Completion {
    int target;
    std::atomic<int> count {0};
    std::promise<void> promise;
    std::future<void> future = promise.get_future();
    explicit Completion(int n) : target(n) {}
    void record() { if (++count == target) { promise.set_value(); } }
    bool wait() { return future.wait_for(5s) == std::future_status::ready; }
};
template <class T>
struct RecordingAction final : M::AbstractAction<T,int> {
    std::string label;
    std::vector<Delivery> &deliveries;
    Completion &completion;
    bool fail = false;
    RecordingAction(std::string name, std::vector<Delivery> &log, Completion &done)
        : label(std::move(name)), deliveries(log), completion(done) {}
    std::unique_ptr<detail::Scheduler::Queue> makeSchedulerQueue() override {
        return std::make_unique<detail::Scheduler::InputQueue<M::InnerData<T>,RecordingAction>>(this);
    }
    void handle(M::InnerData<T> &&input) override {
        deliveries.push_back({label, detail::Scheduler::Batch::currentFor(this->schedulerInstance())});
        if (fail) { throw std::runtime_error("test delivery failure"); }
        if (!this->enqueueScheduled(std::move(input))) { handleImmediately(std::move(input)); }
    }
    void handleImmediately(M::InnerData<T> &&) { completion.record(); }
    bool isThreaded() const override { return false; }
    bool isOneTimeOnly() const override { return false; }
    void setIdleWorker(std::function<void(void *)>) override {}
    void setStartWaiter(std::function<void()>) override {}
};
template <class T>
auto makeAction(std::string label, std::vector<Delivery> &log, Completion &done, Params params = Params()) {
    auto *raw = new RecordingAction<T>(std::move(label), log, done);
    return std::make_pair(M::fromAbstractAction<T,int>(raw, params), raw);
}
// Record the publisher's input-delivery order while processing independently on
// a real dedicated thread, so the test distinguishes delivery from execution.
class DedicatedHandler final : public Components::IHandler<int>, public infra::IRealTimeAppPossiblyThreadedNode {
    std::string label_;
    std::vector<Delivery> &log_;
    Completion &completion_;
    std::mutex mutex_;
    std::condition_variable ready_;
    std::deque<M::InnerData<int>> inputs_;
    bool stopped_ = false;
    std::thread worker_;
    void run() {
        std::unique_lock<std::mutex> lock(mutex_);
        for (;;) {
            ready_.wait(lock, [&] { return stopped_ || !inputs_.empty(); });
            if (stopped_) { return; }
            inputs_.pop_front();
            lock.unlock(); completion_.record(); lock.lock();
        }
    }
public:
    DedicatedHandler(std::string label, std::vector<Delivery> &log, Completion &done)
        : label_(std::move(label)), log_(log), completion_(done), worker_([this] { run(); }) {}
    ~DedicatedHandler() {
        { std::lock_guard<std::mutex> lock(mutex_); stopped_ = true; }
        ready_.notify_one(); worker_.join();
    }
    std::optional<std::thread::native_handle_type> threadHandle() override { return worker_.native_handle(); }
    void handle(M::InnerData<int> &&input) override {
        log_.push_back({label_, nullptr});
        { std::lock_guard<std::mutex> lock(mutex_); inputs_.push_back(std::move(input)); }
        ready_.notify_one();
    }
};
std::vector<std::string> labels(std::vector<Delivery> const &deliveries) {
    std::vector<std::string> result;
    for (auto const &delivery : deliveries) { result.push_back(delivery.label); }
    return result;
}
void stableOrderAndBatching() {
    Env env;
    auto context = std::make_shared<detail::SchedulerContext>();
    std::vector<Delivery> log;
    Completion done(9);
    auto zeroB = makeAction<int>("zero-b", log, done, Params().Scheduler());
    auto zeroA = makeAction<int>("zero-a", log, done, Params().Scheduler());
    auto oneA = makeAction<int>("one-a", log, done, Params().Scheduler(1));
    auto oneB = makeAction<int>("one-b", log, done, Params().Scheduler(1));
    auto two = makeAction<int>("two", log, done, Params().Scheduler(2));
    auto syncA = makeAction<int>("sync-a", log, done);
    auto syncB = makeAction<int>("sync-b", log, done);
    DedicatedHandler threadA("thread-a", log, done), threadB("thread-b", log, done);
    Components::Producer<int> publisher;
    publisher.addHandler(two.second);
    publisher.addHandler(syncA.second);
    publisher.addHandler(oneA.second);
    publisher.addHandler(&threadA);
    publisher.addHandler(zeroB.second);
    publisher.addHandler(syncB.second);
    publisher.addHandler(zeroA.second);
    publisher.addHandler(&threadB);
    publisher.addHandler(oneB.second);
    publisher.addHandler(zeroA.second); // Duplicate subscriptions remain suppressed.
    // Bind after connecting, as happens inside action composition.
    for (auto *node : {zeroB.second, zeroA.second, oneA.second, oneB.second, two.second}) { node->attachScheduler(context); }
    publisher.publish(&env, 7);
    CHECK((labels(log) == std::vector<std::string>{"sync-a","thread-a","sync-b","thread-b","zero-b","zero-a","one-a","one-b","two"}));
    for (std::size_t i = 0; i < 4; ++i) { CHECK(log[i].batch == nullptr); }
    for (std::size_t i = 4; i < log.size(); ++i) { CHECK(log[i].batch != nullptr); }
    CHECK(log[4].batch == log[5].batch);
    CHECK(log[6].batch == log[7].batch);
    // No scheduler action body ran inline or before the scheduler started.
    CHECK(done.count <= 4);
    context->start(); bool completed = done.wait(); context->stop(); CHECK(completed);
}
void variantBranchesAndDifferentContexts() {
    Env env;
    auto first = std::make_shared<detail::SchedulerContext>();
    auto second = std::make_shared<detail::SchedulerContext>();
    std::vector<Delivery> log;
    Completion done(5);
    auto a = makeAction<int>("a", log, done, Params().Scheduler(1));
    auto b = makeAction<int>("b", log, done, Params().Scheduler());
    auto c = makeAction<int>("other-app", log, done, Params().Scheduler());
    auto synchronous = makeAction<int>("sync", log, done);
    auto text = makeAction<std::string>("text", log, done, Params().Scheduler());
    a.second->attachScheduler(first); b.second->attachScheduler(first);
    c.second->attachScheduler(second); text.second->attachScheduler(first);
    Components::Producer<std::variant<int,std::string>> publisher;
    publisher.addHandler_0(a.second); publisher.addHandler_0(b.second);
    publisher.addHandler_0(synchronous.second); publisher.addHandler_0(c.second);
    publisher.addHandler_1(text.second);
    publisher.publish(&env, std::variant<int,std::string>{7});
    publisher.publish(&env, std::variant<int,std::string>{std::string("hello")});
    CHECK((labels(log) == std::vector<std::string>{"sync","b","other-app","a","text"}));
    CHECK(log[0].batch == nullptr);
    for (std::size_t i = 1; i < 4; ++i) { CHECK(log[i].batch != nullptr); }
    first->start(); second->start(); bool completed = done.wait();
    first->stop(); second->stop(); CHECK(completed);
}
void exceptionReleasesBatch() {
    Env env;
    auto context = std::make_shared<detail::SchedulerContext>();
    std::vector<Delivery> log;
    Completion done(3);
    auto a = makeAction<int>("a", log, done, Params().Scheduler());
    auto b = makeAction<int>("b", log, done, Params().Scheduler());
    a.second->attachScheduler(context); b.second->attachScheduler(context);
    Components::Producer<int> publisher;
    publisher.addHandler(a.second); publisher.addHandler(b.second);
    context->start(); b.second->fail = true;
    bool threw = false;
    try { publisher.publish(&env, 1); } catch (std::runtime_error const &) { threw = true; }
    CHECK(threw);
    CHECK(detail::Scheduler::Batch::currentFor(a.second->schedulerInstance()) == nullptr);
    b.second->fail = false;
    publisher.publish(&env, 2);
    bool completed = done.wait(); context->stop(); CHECK(completed);
}
void anyAdaptersParticipate() {
    Env env;
    std::vector<Delivery> log;
    Completion done(2);
    auto first = makeAction<std::any>("first", log, done, Params().Scheduler());
    auto second = makeAction<std::any>("second", log, done, Params().Scheduler());
    auto input = M::triggerImporter<int,false>();
    infra::AppRunner<M> runner(&env);
    auto source = runner.importerAsSource("input", std::get<0>(input));
    runner.connectAny(source.clone(), runner.actionAsSink("first", first.first));
    runner.connectAny(source.clone(), runner.actionAsSink("second", second.first));
    runner.finalize(); std::get<1>(input)(3);
    bool completed = done.wait(); runner.stopSchedulers();
    CHECK(completed);
    CHECK(log.size() == 2 && log[0].batch && log[0].batch == log[1].batch);
}
int main() {
    return runTests([] {
        stableOrderAndBatching(); variantBranchesAndDifferentContexts();
        exceptionReleasesBatch(); anyAdaptersParticipate();
    });
}
