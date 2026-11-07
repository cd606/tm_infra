#include <tm_kit/infra/RealTimeApp.hpp>
#include <tm_kit/infra/SynchronousRunner.hpp>
#include "TestSupport.hpp"
#include <chrono>
#include <future>
#include <numeric>

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
using Params = infra::LiftParameters<Env::TimePointType>;

// One callback per test queue; production queues store only typed input data.
struct Probe {
    std::function<void(int)> callback;
    void handleImmediately(int &&value) { callback(value); }
};
using ProbeQueue = detail::Scheduler::InputQueue<int,Probe>;

template <class T>
auto data(Env &env, T value) { return M::pureInnerData(&env, std::move(value)); }

template <class F>
auto core(F f, Params params = Params().Scheduler()) {
    using Core = M::PureActionCore<int,int,F,false,false>;
    auto raw = new Core(std::move(f));
    auto action = std::make_shared<M::Action<int,int>>(raw, params);
    return std::make_pair(action, raw);
}
template <class T>
T get(std::future<T> &future) {
    if (future.wait_for(5s) != std::future_status::ready) {
        throw std::runtime_error("timed out waiting for scheduler dispatch");
    }
    return future.get();
}
void fairnessAndFIFO() {
    Env env;
    std::vector<int> order;
    std::vector<std::thread::id> threads;
    std::promise<void> done;
    auto completion = done.get_future();
    // The runner attaches these two distinct action queues to scheduler zero.
    auto first = core([&](int x) {
        order.push_back(x); threads.push_back(std::this_thread::get_id());
        return x;
    });
    auto second = core([&](int x) {
        order.push_back(x); threads.push_back(std::this_thread::get_id());
        if (order.size() == 6) { done.set_value(); }
        return x;
    });
    infra::AppRunner<M> runner(&env);
    runner.registerAction("a", first.first);
    runner.registerAction("b", second.first);
    for (int i = 0; i < 3; ++i) {
        first.second->handle(data(env, i));
        second.second->handle(data(env, 10+i));
    }
    CHECK(order.empty()); // No execution on the caller or before finalization.
    runner.finalize();
    get(completion);
    runner.stopSchedulers();
    CHECK((order == std::vector<int>{0,10,1,11,2,12}));
    CHECK(std::all_of(threads.begin(), threads.end(), [&](auto t) { return t == threads[0]; }));
    CHECK(threads[0] != std::this_thread::get_id());
    CHECK(!M::actionIsThreaded(first.first));
    CHECK(M::actionSchedulerID(first.first) == 0);
}
void parallelSchedulersAndIsolation() {
    Env env;
    std::promise<void> release;
    auto gate = release.get_future().share();
    std::promise<std::thread::id> enteredA, enteredB, enteredOtherApp;
    auto aFuture = enteredA.get_future(), bFuture = enteredB.get_future(), otherFuture = enteredOtherApp.get_future();
    auto a = core([&](int x) { enteredA.set_value(std::this_thread::get_id()); gate.wait(); return x; });
    auto b = core([&](int x) { enteredB.set_value(std::this_thread::get_id()); return x; }, Params().Scheduler(1));
    auto other = core([&](int x) { enteredOtherApp.set_value(std::this_thread::get_id()); return x; });
    infra::AppRunner<M> runner(&env), otherRunner(&env);
    runner.registerAction("a", a.first); runner.registerAction("b", b.first);
    otherRunner.registerAction("other", other.first);
    runner.finalize(); otherRunner.finalize();
    a.second->handle(data(env, 1));
    auto aThread = get(aFuture);
    b.second->handle(data(env, 2)); other.second->handle(data(env, 3));
    // Release even on test failure, so runner teardown cannot hang.
    bool independent = bFuture.wait_for(5s) == std::future_status::ready && otherFuture.wait_for(5s) == std::future_status::ready;
    release.set_value();
    CHECK(independent);
    CHECK(aThread != get(bFuture));
    CHECK(aThread != get(otherFuture));
    bool rejected = false;
    try { otherRunner.registerAction("reuse", a.first); }
    catch (std::logic_error const &e) { rejected = std::string(e.what()).find("multiple RealTimeApp") != std::string::npos; }
    CHECK(rejected);
    runner.stopSchedulers(); otherRunner.stopSchedulers();
}
void concurrentProducers() {
    Env env;
    constexpr int producers = 4, inputs = 200;
    std::vector<int> received;
    std::atomic<int> active {0}, maximum {0};
    std::promise<void> done; auto completion = done.get_future();
    auto action = core([&](int x) {
        int count = ++active;
        maximum.store(std::max(maximum.load(), count));
        received.push_back(x);
        --active;
        if (received.size() == producers*inputs) { done.set_value(); }
        return x;
    });
    infra::AppRunner<M> runner(&env); runner.registerAction("action", action.first); runner.finalize();
    std::vector<std::thread> callers;
    for (int p = 0; p < producers; ++p) {
        callers.emplace_back([&,p] { for (int i = 0; i < inputs; ++i) { action.second->handle(data(env, p*inputs+i)); } });
    }
    for (auto &caller : callers) { caller.join(); }
    get(completion); runner.stopSchedulers();
    CHECK(maximum == 1);
    for (int p = 0; p < producers; ++p) {
        int next = 0;
        for (int x : received) { if (x/inputs == p) { CHECK(x%inputs == next++); } }
        CHECK(next == inputs);
    }
}
void liftedVariantAndMulti() {
    Env env;
    std::promise<int> done; auto completion = done.get_future();
    auto variant = M::liftPure2<int,std::string>([](std::variant<int,std::string> x) {
        return std::visit([](auto const &v) -> int {
            if constexpr (std::is_same_v<std::decay_t<decltype(v)>,int>) { return v; }
            else { return static_cast<int>(v.size()); }
        }, x);
    }, Params().Scheduler(2));
    auto multi = M::liftMulti2<int,double>([](std::variant<int,double> input) {
        int x = std::visit([](auto value) { return static_cast<int>(value); }, input);
        return std::vector<int>{x,x+1};
    }, Params().Scheduler(2));
    auto sum = std::make_shared<int>(0);
    auto sink = M::pureExporter<int>([&,sum](int x) { *sum += x; if (*sum == 13) { done.set_value(*sum); } });
    auto trigger = M::triggerImporter<int,false>();
    auto stringTrigger = M::triggerImporter<std::string,false>();
    auto doubleTrigger = M::triggerImporter<double,false>();
    infra::AppRunner<M> runner(&env);
    runner.registerAction("variant", variant);
    runner.registerAction("multi", multi);
    runner.connect(runner.importerAsSource("input", std::get<0>(trigger)), runner.actionAsSink_2_0(variant));
    runner.connect(runner.importerAsSource("string", std::get<0>(stringTrigger)), runner.actionAsSink_2_1(variant));
    auto output = runner.execute(multi, runner.actionAsSource(variant),
        runner.importerAsSource("double", std::get<0>(doubleTrigger)));
    runner.exportItem("sink", sink, std::move(output));
    runner.finalize();
    std::get<1>(trigger)(1); // outputs 1,2
    std::get<1>(stringTrigger)(std::string("ab")); // outputs 2,3
    std::get<1>(doubleTrigger)(2.0); // outputs 2,3 through the second multi-input branch
    CHECK(get(completion) == 13);
    runner.stopSchedulers();
    CHECK(M::actionSchedulerID(variant) == 2);
}
void modesAndAffinity() {
    Env env;
    auto caller = std::this_thread::get_id();
    std::thread::id executing;
    auto sync = core([&](int x) { executing = std::this_thread::get_id(); return x; }, Params());
    sync.second->handle(data(env, 1));
    CHECK(executing == caller);
    CHECK(!M::actionSchedulerID(sync.first));
    CHECK(Params().Scheduler().schedulerID == 0);
    CHECK(!Params().Scheduler().SuggestThreaded(true).schedulerID);
    bool rejected = false;
    Params invalid; invalid.suggestThreaded = true; invalid.schedulerID = 0;
    try { M::liftPure1<int>([](int x) { return x; }, invalid); } catch (std::invalid_argument const &) { rejected = true; }
    CHECK(rejected);
#if defined(__linux__)
    cpu_set_t allowed;
    CHECK(pthread_getaffinity_np(pthread_self(), sizeof(allowed), &allowed) == 0);
    int cpu = 0; while (cpu < CPU_SETSIZE && !CPU_ISSET(cpu, &allowed)) { ++cpu; }
    CHECK(cpu < CPU_SETSIZE);
    std::array<std::promise<int>,2> done;
    auto firstCPU = done[0].get_future(), secondCPU = done[1].get_future();
    auto action = core([&](int x) { done[x].set_value(sched_getcpu()); return x; });
    infra::AppRunner<M> runner(&env);
    runner.setSchedulerCPU(0, cpu);
    runner.registerAction("bound", action.first);
    runner.finalize(); action.second->handle(data(env, 0));
    CHECK(get(firstCPU) == cpu);
    int nextCPU = cpu+1;
    while (nextCPU < CPU_SETSIZE && !CPU_ISSET(nextCPU, &allowed)) { ++nextCPU; }
    if (nextCPU == CPU_SETSIZE) { nextCPU = cpu; }
    runner.setSchedulerCPU(0, nextCPU);
    action.second->handle(data(env, 1));
    CHECK(get(secondCPU) == nextCPU);
    rejected = false;
    try { runner.setSchedulerCPU(0, CPU_SETSIZE); } catch (std::out_of_range const &) { rejected = true; }
    CHECK(rejected);
    runner.stopSchedulers();

    int unavailable = 0;
    while (unavailable < CPU_SETSIZE && CPU_ISSET(unavailable, &allowed)) { ++unavailable; }
    if (unavailable != CPU_SETSIZE) {
        detail::Scheduler invalidCPU;
        bool ran = false; Probe owner {[&](int) { ran = true; }};
        ProbeQueue queue(&owner); invalidCPU.addQueue(queue);
        invalidCPU.enqueue(queue, 0);
        invalidCPU.setCPU(unavailable);
        rejected = false;
        try { invalidCPU.start(); } catch (std::system_error const &) { rejected = true; }
        invalidCPU.stop(); invalidCPU.removeQueue(queue);
        CHECK(rejected && !ran);
    }
#endif
}
void compositionsAndMoveOnlyInputs() {
    Env env;
    std::promise<int> done; auto completion = done.get_future();
    std::vector<std::thread::id> threads(4);
    auto trigger = M::triggerImporter<int,false>();
    auto post = M::liftPure1<int>([&](int x) { threads[0] = std::this_thread::get_id(); return x+1; }, Params().Scheduler());
    auto importer = M::composeImporter(std::move(*std::get<0>(trigger)), std::move(*post));
    auto f = M::liftPure1<int>([&](int x) { threads[1] = std::this_thread::get_id(); return x*2; }, Params().Scheduler(1));
    auto g = M::liftPure1<int>([&](int x) { threads[2] = std::this_thread::get_id(); return x+3; }, Params().Scheduler());
    auto composition = M::compose(std::move(*f), std::move(*g));
    auto pre = M::liftPure1<int>([&](int x) { threads[3] = std::this_thread::get_id(); return x*5; }, Params().Scheduler(2));
    auto sink = M::pureExporter<int>([&](int x) { done.set_value(x); });
    auto exporter = M::composeExporter(std::move(*pre), std::move(*sink));
    infra::AppRunner<M> runner(&env);
    runner.exportItem("output", exporter, runner.execute("composed", composition, runner.importerAsSource("input", importer)));
    runner.finalize(); std::get<1>(trigger)(7);
    CHECK(get(completion) == 95);
    runner.stopSchedulers();
    CHECK(threads[0] == threads[2]);
    CHECK(threads[0] != threads[1] && threads[0] != threads[3]);

    std::promise<std::pair<int,int *>> moved; auto moveCompletion = moved.get_future();
    auto moveTrigger = M::triggerImporter<std::unique_ptr<int>,false>();
    auto moveAction = M::liftPure1<std::unique_ptr<int>>([&](std::unique_ptr<int> x) {
        moved.set_value({*x, x.get()}); return *x;
    }, Params().Scheduler());
    infra::AppRunner<M> moveRunner(&env);
    moveRunner.execute("move", moveAction, moveRunner.importerAsSource("input", std::get<0>(moveTrigger)));
    moveRunner.finalize();
    auto value = std::make_unique<int>(42); auto address = value.get();
    std::get<1>(moveTrigger)(std::move(value));
    auto result = get(moveCompletion);
    moveRunner.stopSchedulers();
    CHECK(result.first == 42 && result.second == address);
    CHECK(!value);
}
void fireOnceAndContinuation() {
    Env env;
    std::atomic<int> calls {0};
    auto trigger = M::triggerImporter<int,false>();
    auto once = M::liftPure1<int>([&](int x) { ++calls; return x; }, Params().Scheduler().FireOnceOnly(true));
    std::vector<std::pair<int,bool>> outputs;
    auto sink = M::simpleExporter<int>([&](M::InnerData<int> &&x) { outputs.emplace_back(x.timedData.value, x.timedData.finalFlag); });
    std::promise<int> done; auto completion = done.get_future();
    infra::TimedAppModelContinuation<int,int,int,Env> continuation = [&](M::InnerData<int> &&x, int &state, auto publish) {
        state += x.timedData.value;
        if (state == 6) { done.set_value(state); }
        publish(data(env, state));
    };
    auto continued = M::continuationAction<int,int,int>(continuation, 0, Params().Scheduler());
    infra::AppRunner<M> runner(&env);
    auto input = runner.importerAsSource("input", std::get<0>(trigger));
    runner.exportItem("once-output", sink, runner.execute("once", once, input.clone()));
    runner.execute("continued", continued, input.clone());
    runner.finalize();
    for (int x : {1,2,3}) { std::get<1>(trigger)(int(x)); }
    CHECK(get(completion) == 6);
    runner.stopSchedulers();
    CHECK(calls == 1);
    CHECK((outputs == std::vector<std::pair<int,bool>>{{1,true}}));
}
void queueRemovalAndShutdownWaitForDispatch() {
    auto scheduler = std::make_shared<detail::Scheduler>();
    std::promise<void> entered, release;
    auto started = entered.get_future(); auto gate = release.get_future().share();
    Probe owner {[&](int) { entered.set_value(); gate.wait(); }};
    ProbeQueue queue(&owner); scheduler->addQueue(queue);
    scheduler->enqueue(queue, 0);
    scheduler->start(); get(started);
    auto stopping = std::async(std::launch::async, [&] { scheduler->stop(); });
    bool waited = stopping.wait_for(20ms) == std::future_status::timeout;
    release.set_value(); get(stopping);
    CHECK(waited);
    scheduler->removeQueue(queue);
    bool ran = false;
    owner.callback = [&](int) { ran = true; };
    scheduler->enqueue(queue, 0);
    CHECK(!ran);

    auto context = std::make_shared<detail::SchedulerContext>();
    Env env;
    std::promise<void> actionEntered, actionRelease;
    auto actionStarted = actionEntered.get_future(); auto actionGate = actionRelease.get_future().share();
    auto action = core([&](int x) { actionEntered.set_value(); actionGate.wait(); return x; });
    action.second->attachScheduler(context); context->start();
    action.second->handle(data(env, 1)); get(actionStarted);
    auto deleting = std::async(std::launch::async, [holder=std::move(action.first)]() mutable { holder.reset(); });
    waited = deleting.wait_for(20ms) == std::future_status::timeout;
    actionRelease.set_value(); get(deleting);
    CHECK(waited);
    context->stop();
}
void applicationTakeover() {
    Env env;
    std::promise<int> done; auto completion = done.get_future();
    auto action = core([&](int x) { done.set_value(x); return x; });
    infra::SynchronousRunner<M> receiver(&env);
    {
        infra::AppRunner<M> runner(&env);
        runner.registerAction("transferred", action.first);
        runner.finalize();
        runner.moveToAnotherRunner(receiver);
    }
    // Destruction of the moved-from application must leave transferred threads running.
    action.second->handle(data(env, 17));
    CHECK(get(completion) == 17);
}
void callsFromSchedulerStillEnqueue() {
    Env env;
    std::vector<int> order;
    std::promise<void> done; auto completion = done.get_future();
    auto b = core([&](int x) { order.push_back(3); done.set_value(); return x; });
    auto a = core([&](int x) {
        order.push_back(1); b.second->handle(data(env, x)); order.push_back(2); return x;
    });
    infra::AppRunner<M> runner(&env);
    runner.registerAction("a", a.first); runner.registerAction("b", b.first);
    runner.finalize(); a.second->handle(data(env, 0));
    get(completion); runner.stopSchedulers();
    CHECK((order == std::vector<int>{1,2,3}));
}
void shutdownDiscardsPending() {
    auto scheduler = std::make_shared<detail::Scheduler>();
    bool ran = false; Probe owner {[&](int) { ran = true; }};
    ProbeQueue queue(&owner); scheduler->addQueue(queue);
    scheduler->enqueue(queue, 0);
    scheduler->stop(); scheduler->removeQueue(queue);
    CHECK(!ran);
}
int main() {
    return runTests([] {
        fairnessAndFIFO(); parallelSchedulersAndIsolation(); concurrentProducers();
        liftedVariantAndMulti(); modesAndAffinity(); compositionsAndMoveOnlyInputs();
        fireOnceAndContinuation(); queueRemovalAndShutdownWaitForDispatch(); applicationTakeover(); callsFromSchedulerStillEnqueue(); shutdownDiscardsPending();
    });
}
