#include <tm_kit/infra/SynchronousRunner.hpp>
#include "TestSupport.hpp"
#include <chrono>
#include <future>

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
using Params = infra::LiftParameters<M::TimePoint>;
template <class T>
T get(std::future<T> &future) {
    if (future.wait_for(5s) != std::future_status::ready) { throw std::runtime_error("exporter dispatch timed out"); }
    return future.get();
}
void sharedSchedulerAndFIFO() {
    Env env;
    std::vector<int> a, b, c, synchronous;
    std::vector<std::thread::id> threads;
    std::thread::id syncThread;
    std::promise<void> done;
    auto complete = done.get_future();
    int received = 0;
    auto record = [&](std::vector<int> &values, int value) {
        values.push_back(value); threads.push_back(std::this_thread::get_id());
        if (++received == 12) { done.set_value(); }
    };
    auto first = M::simpleExporter<int>([&](M::InnerData<int> &&input) { record(a, input.timedData.value); }, Params().Scheduler());
    auto second = M::pureExporter<int>([&](int value) { record(b,value); }, Params().Scheduler());
    auto action = M::liftPure1<int>([&](int value) { record(c,value); return value; }, Params().Scheduler());
    auto sync = M::pureExporter<int>([&](int value) { syncThread = std::this_thread::get_id(); synchronous.push_back(value); });
    auto input = M::triggerImporter<int,false>();
    infra::AppRunner<M> runner(&env);
    auto source = runner.importerAsSource("input", std::get<0>(input));
    runner.exportItem("first", first, source.clone());
    runner.execute("action", action, source.clone());
    runner.exportItem("second", second, source.clone());
    runner.exportItem("synchronous", sync, source.clone());
    runner.finalize();
    for (int value : {1,2,3,4}) { std::get<1>(input)(int(value)); }
    get(complete); runner.stopSchedulers();
    CHECK((a == std::vector<int>{1,2,3,4}));
    CHECK(a == b && b == c && c == synchronous);
    CHECK(syncThread == std::this_thread::get_id());
    CHECK(threads[0] != syncThread);
    CHECK(std::all_of(threads.begin(), threads.end(), [&](auto id) { return id == threads[0]; }));
    CHECK(M::exporterSchedulerID(first) == 0);
    CHECK(M::exporterSchedulerID(second) == 0);
    CHECK(!M::exporterSchedulerID(sync));
}
void independentSchedulersAndMoveOnlyComposition() {
    Env env;
    std::promise<std::pair<int,std::thread::id>> done;
    auto complete = done.get_future();
    std::thread::id actionThread;
    auto pre = M::liftPure1<int>([&](int value) {
        actionThread = std::this_thread::get_id();
        return std::make_unique<int>(value+1);
    }, Params().Scheduler(1));
    auto sink = M::pureExporter<std::unique_ptr<int>>([&](std::unique_ptr<int> value) {
        done.set_value({*value, std::this_thread::get_id()});
    }, Params().Scheduler(2));
    auto exporter = M::composeExporter(std::move(*pre), std::move(*sink));
    auto input = M::triggerImporter<int,false>();
    infra::AppRunner<M> runner(&env);
    runner.exportItem("composed", exporter, runner.importerAsSource("input", std::get<0>(input)));
    runner.finalize(); std::get<1>(input)(41);
    auto result = get(complete); runner.stopSchedulers();
    CHECK(result.first == 42);
    CHECK(result.second != actionThread);
    CHECK(result.second != std::this_thread::get_id());
}
void synchronousRunnerAndModeValidation() {
    Env env;
    std::promise<std::pair<int,std::thread::id>> done;
    auto complete = done.get_future();
    auto exporter = M::pureExporter<int>([&](int value) { done.set_value({value, std::this_thread::get_id()}); }, Params().Scheduler(5));
    {
        infra::SynchronousRunner<M> runner(&env);
        runner.exportItem<int>(exporter, M::pureInnerData(&env, 19));
        auto result = get(complete);
        CHECK(result.first == 19);
        CHECK(result.second != std::this_thread::get_id());
    }
    CHECK(M::exporterSchedulerID(exporter) == 5);
    Params invalid; invalid.suggestThreaded = true; invalid.schedulerID = 0;
    bool rejected = false;
    try { M::pureExporter<int>([](int) {}, invalid); } catch (std::invalid_argument const &) { rejected = true; }
    CHECK(rejected);
    std::thread::id executing;
    auto synchronous = M::pureExporter<int>([&](int) { executing = std::this_thread::get_id(); }, Params().SuggestThreaded(false));
    infra::SynchronousRunner<M> caller(&env);
    caller.exportItem<int>(synchronous, M::pureInnerData(&env, 1));
    CHECK(executing == std::this_thread::get_id());
}
struct ProbeExporter final : M::AbstractExporter<int> {
    std::function<void(int)> callback;
    std::vector<detail::Scheduler::Batch const *> *batches = nullptr;
    explicit ProbeExporter(std::function<void(int)> f) : callback(std::move(f)) {}
    std::unique_ptr<detail::Scheduler::Queue> makeSchedulerQueue() override {
        return std::make_unique<detail::Scheduler::InputQueue<M::InnerData<int>,ProbeExporter>>(this);
    }
    void handle(M::InnerData<int> &&input) override {
        if (batches) { batches->push_back(detail::Scheduler::Batch::currentFor(this->schedulerInstance())); }
        if (!this->enqueueScheduled(std::move(input))) { handleImmediately(std::move(input)); }
    }
    void handleImmediately(M::InnerData<int> &&input) { callback(input.timedData.value); }
    void start(Env *) override {}
};
void publisherBatchAndHolderCleanup() {
    Env env;
    auto context = std::make_shared<detail::SchedulerContext>();
    std::promise<void> done; auto complete = done.get_future();
    int count = 0;
    auto *a = new ProbeExporter([&](int) { if (++count == 2) { done.set_value(); } });
    auto *b = new ProbeExporter([&](int) { if (++count == 2) { done.set_value(); } });
    auto first = M::exporter<int>(a, Params().Scheduler());
    auto second = M::exporter<int>(b, Params().Scheduler());
    a->attachScheduler(context); b->attachScheduler(context);
    std::vector<detail::Scheduler::Batch const *> batches;
    a->batches = &batches; b->batches = &batches;
    infra::RealTimeAppComponents<Env>::Producer<int> publisher;
    publisher.addHandler(a); publisher.addHandler(b);
    publisher.publish(&env, 7);
    CHECK(count == 0);
    CHECK(batches.size() == 2 && batches[0] && batches[0] == batches[1]);
    context->start(); get(complete); context->stop();

    auto activeContext = std::make_shared<detail::SchedulerContext>();
    std::promise<void> entered, release;
    auto started = entered.get_future(); auto gate = release.get_future().share();
    auto *raw = new ProbeExporter([&](int) { entered.set_value(); gate.wait(); });
    auto holder = M::exporter<int>(raw, Params().Scheduler());
    raw->attachScheduler(activeContext); activeContext->start(); raw->handle(M::pureInnerData(&env, 0)); get(started);
    auto deleting = std::async(std::launch::async, [holder=std::move(holder)]() mutable { holder.reset(); });
    bool waited = deleting.wait_for(20ms) == std::future_status::timeout;
    release.set_value(); get(deleting); activeContext->stop();
    CHECK(waited);
}
void crossApplicationReuseIsRejected() {
    Env env;
    auto exporter = M::pureExporter<int>([](int) {}, Params().Scheduler());
    infra::AppRunner<M> first(&env), second(&env);
    first.registerExporter("sink", exporter);
    bool rejected = false;
    try { second.registerExporter("reuse", exporter); }
    catch (std::logic_error const &error) { rejected = std::string(error.what()).find("multiple RealTimeApp") != std::string::npos; }
    CHECK(rejected);
}
int main() {
    return runTests([] {
        sharedSchedulerAndFIFO(); independentSchedulersAndMoveOnlyComposition();
        synchronousRunnerAndModeValidation(); publisherBatchAndHolderCleanup(); crossApplicationReuseIsRejected();
    });
}
