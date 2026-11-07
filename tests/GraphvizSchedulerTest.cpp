#include <tm_kit/infra/RealTimeApp.hpp>
#include <tm_kit/infra/BasicWithTimeApp.hpp>
#include "TestSupport.hpp"
#include <fstream>
#include <sstream>

namespace infra = dev::cd606::tm::infra;
struct Env : infra::graph_check_components::DontCheckConnections {
    using TimePointType = std::chrono::system_clock::time_point;
    using IDType = int;
    using IDHash = std::hash<int>;
    static constexpr bool CheckTime = false;
    static TimePointType resolveTime() { return std::chrono::system_clock::now(); }
    static TimePointType resolveTime(TimePointType value) { return value; }
    static int new_id() { return 1; }
    static bool less_comparison_id(int a, int b) { return a < b; }
    void finalizeEnvironment() {}
    void log(infra::LogLevel, std::string const &) {}
};
using M = infra::RealTimeApp<Env>;
using Params = infra::LiftParameters<M::TimePoint>;
// The graph renderer consumes metadata only; this fixture declares the threaded
// property without starting a worker in a test that never executes the graph.
struct ThreadedMetadataAction : M::AbstractAction<int,int> {
    void handle(M::InnerData<int> &&) override {}
    bool isThreaded() const override { return true; }
    bool isOneTimeOnly() const override { return false; }
    void setIdleWorker(std::function<void(void *)>) override {}
    void setStartWaiter(std::function<void()>) override {}
};
std::string nodeLine(std::string const &dot, std::string const &name) {
    std::istringstream lines(dot);
    std::string line;
    while (std::getline(lines, line)) {
        if (line.find(name) != std::string::npos && line.find("label=") != std::string::npos) { return line; }
    }
    throw std::runtime_error("Missing Graphviz node: "+name);
}
std::string annotatedGraph() {
    Env env;
    infra::AppRunner<M> runner(&env);
    runner.registerAction("default-scheduler", M::liftPure1<int>([](int value) { return value; }, Params().Scheduler()));
    runner.registerAction("group/numbered-scheduler", M::liftPure1<int>([](int value) { return value; }, Params().Scheduler(7)));
    runner.registerAction("multi-input", M::liftPure2<int,std::string>([](auto) { return 0; }, Params().Scheduler(3)));
    runner.registerAction("multi-output", M::liftPure1<int>([](int value) -> std::variant<int,std::string> { return value; }, Params().Scheduler(6)));
    runner.registerAction("one-time", M::liftPure1<int>([](int value) { return value; }, Params().Scheduler(4).FireOnceOnly(true)));
    runner.registerAction("synchronous", M::liftPure1<int>([](int value) { return value; }));
    runner.registerExporter("scheduled-exporter", M::pureExporter<int>([](int) {}, Params().Scheduler()));
    runner.registerExporter("plain-exporter", M::pureExporter<int>([](int) {}));
    runner.registerAction("dedicated", M::fromAbstractAction<int,int>(new ThreadedMetadataAction));
    std::ostringstream dot;
    runner.writeGraphVizDescription(dot, "scheduler_annotations");
    return dot.str();
}
int main(int argc, char **argv) {
    return runTests([&] {
        auto dot = annotatedGraph();
        CHECK(dot.find("\tcolor=blue;") != std::string::npos);
        for (auto const &item : std::vector<std::pair<std::string,int>>{
            {"default-scheduler",0}, {"numbered-scheduler",7}, {"multi-input",3}, {"multi-output",6}, {"one-time",4}, {"scheduled-exporter",0}
        }) {
            auto line = nodeLine(dot, item.first);
            CHECK(line.find("[scheduler: "+std::to_string(item.second)+"]") != std::string::npos);
            CHECK(line.find("color=darkviolet") != std::string::npos);
            CHECK(line.find("color=red") == std::string::npos);
        }
        CHECK(nodeLine(dot,"multi-input").find("label=<<TABLE") != std::string::npos);
        CHECK(nodeLine(dot,"multi-input").find("PORT=\"arg1\"") != std::string::npos);
        CHECK(nodeLine(dot,"one-time").find("style=\"dotted\"") != std::string::npos);
        CHECK(nodeLine(dot,"dedicated").find("color=red") != std::string::npos);
        for (auto const &name : {"synchronous", "dedicated", "plain-exporter"}) {
            auto line = nodeLine(dot,name);
            CHECK(line.find("scheduler:") == std::string::npos);
            CHECK(line.find("color=darkviolet") == std::string::npos);
        }
        using Basic = infra::BasicWithTimeApp<Env>;
        Env env;
        infra::AppRunner<Basic> basic(&env);
        basic.registerAction("basic-action", Basic::liftPure<int>([](int value) { return value; }, Params().Scheduler(9)));
        basic.registerExporter("basic-exporter", Basic::pureExporter<int>([](int) {}, Params().Scheduler(2)));
        std::ostringstream basicDot;
        basic.writeGraphVizDescription(basicDot,"basic_graph");
        CHECK(basicDot.str().find("scheduler:") == std::string::npos);
        CHECK(basicDot.str().find("color=darkviolet") == std::string::npos);
        if (argc > 1) { std::ofstream(argv[1]) << dot; }
    });
}
