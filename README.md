This is unstable software, with absolutely no warranty or guarantee whatsoever, whether express or implied, including but not limited to those of merchantability, fitness for specific purpose, or non-infringement.

This package aims to provide a set of C++ helper classes that enable the writing of data-flow code in a functional way, which can be easily adapted between a "real time" mode and a "single pass" test mode.

The basic concept is that, a data-flow code can be visualized as a graph, in which there are three types of nodes: 

* "importers": nodes that do not take any input from any other nodes (usually because they have inputs from a source not shown inside the data-flow graph), but provide results that can be used as inputs by other nodes. These nodes "import" data from the outside world into the graph.

* "exporters": the dual of importers, nodes that take inputs from other nodes, but do not provide any results to be used as inputs by other nodes. Usually these nodes do something that has side-effects outside the data-flow graph, e.g. print the input data. So, these nodes "export" data from the graph to the outside world.

* "actions": nodes that take inputs from other nodes and provide results to other nodes.

An exporter or an action that takes multiple inputs are modelled internally as taking a <code>std::variant</code> input (which means if you **actually** want to pass <code>std::variant</code> between two nodes, you need to wrap it in some outer data structure), the underlying thought is that in reality, different inputs from such multiplitude arrive at **different times**, therefore any actual processing always faces one input among such multiplitude only, so <code>std::variant</code> is a proper way to model that.

Such internal modelling is mostly abstracted away through the package, but the abstraction is leaky in the sense that if you actually wants to pass <code>std::variant</code> between two nodes, you need to take some additional measure. This hopefully is not a very big problem.

For producing multiple outputs, the situation is different, since such outputs are generally produced at **the same time**. Therefore, a structure or a <code>std::tuple</code> is perfectly suitable. For multiple outputs of the same type, the package also provides some facilities wherein you can write code that produces a <code>std::vector</code> and the downstream nodes will receive the items one by one. Of course, you don't have to use those facilities, and can always let the nodes directly produce and consume <code>std::vector</code> or other containers.

While these theoretically cover all the possibilities of node types in a general data-flow graph, this package also introduces a set of specialized node types that might facilitate the writing of data-flow code:

* "on-order facilities": nodes that take one *tagged* input (which cannot be <code>std::variant</code>) and for each instance of such tagged input, produce zero, one or more output with the same tag. This can be thought of as a "production facility" that responds to non-fungible incoming production orders, therefore the name. In this package, on-order facilities are connected to other nodes with a different syntax than actions, which permits loops in the graph as long as each loop contains at least one on-order facility. 

* "local on-order facilities": considering that on-order facilities normally needs some other inputs than the "order" (the tagged input) to help it process the order, it would be nice to have some way to pass these inputs to the facilities. Since this package does not aim to make every node pure, it is perfectly acceptable to have the on-order facility node contain a pointer to another node and share data. Such another node is likely an "exporter" since it receives the other inputs but does not produce any on-graph output (since it is actually receives the other inputs on behalf of the on-order facility only). In this package, it is possible to bundle a pointer to an on-order facility and a pointer to an exporter together (in fact, the two pointers may point to one same object which implements the two interfaces), and call such bundle a "local on-order facility". 

* "on-order facilities with external effects": this is the dual of the local on-order facilities, it is a bundle of a pointer to an on-order facility and a pointer to an importer.

* "VIE on-order facilities": this is the combination of the two above: a bundle of a pointer to an on-order facility, a pointer to an importer, and a pointer to an exporter. To expand on the trade-and-production simile, this name comes from the "variable interest entity" business structure.

All these nodes may be constructed through various static methods provided by RealTimeApp or SinglePassIterationApp, and then connected together through an AppRunner instance in a "natural" methodology completely expressed in C++, with all attending type checks (which also means that if there is some type mismatch, the compiler will generate lengthy compilation error messages). The AppRunner instance can then output a Graphviz® visualization of the graph, or run the graph.

This particular package (tm_infra) only provides the basic node and graph definition functionalities. To make the graph useful, please refer to other related packages, also publicly available at github.com.

Some Typescript codes that aim at providing a small subset of the C++ functionality are also provided, so that if it is desirable to write some Typescript codes for interacting with C++ code, they can be written in a similar fashion to the C++ code.

Some C# codes, similar in functionalities to the Typescript codes, are also provided.

INSTALLATION NOTES:

The requirements of tm_infra are:

* gcc >= 9.3.1, clang >= 10.0.1, or MSVC Build Tools 2019 (these versions have been tested to work, old version might work)

* meson

No third party library is required

Typescript codes have been tested with Typescript 4.0.2 and NodeJS 14.13.1.

C# codes have been tested with .NET Core 3.1.403.

## C++ RealTimeApp action and exporter scheduling

Actions lifted with default `LiftParameters` execute synchronously on their
caller's thread. `SuggestThreaded(true)` retains the existing dedicated thread
and input queue per action. `Scheduler(id)` selects a shared scheduler thread;
omitting `id` selects scheduler `0`:

```cpp
using M = dev::cd606::tm::infra::RealTimeApp<MyEnvironment>;
using Params = dev::cd606::tm::infra::LiftParameters<M::TimePoint>;

auto action = M::liftPure1<int>(
    [](int value) { return value + 1; },
    Params().Scheduler() // equivalent to Scheduler(0)
);

dev::cd606::tm::infra::AppRunner<M> runner(&environment);
runner.setSchedulerCPU(0, 3); // optional: bind scheduler 0 to logical CPU 3
// Register and connect the graph as usual, then runner.finalize().
```

`simpleExporter` and `pureExporter` accept the same `Scheduler(id)` option.
`M::exporterSchedulerID(exporter)` returns the optional ID. Exporters share
scheduler threads and publisher batches with actions using the same ID, and
`SynchronousRunner::exportItem` also supports scheduled exporters.

Scheduler IDs are local to each application instance. Each ID owns one thread
and each assigned action or exporter has one FIFO input queue, including actions
with multiple input types. Queues store typed inputs directly, without per-input
callbacks or shared ownership. One virtual dispatch per selected queue pops an
input and calls the concrete action logic. Callers enqueue inputs and wake the scheduler through a
condition variable. The scheduler visits nonempty queues in round-robin order,
processing one input per queue per turn. Nodes sharing an ID execute
serially; different IDs can execute concurrently. Synchronous downstream actions
run on the scheduler thread of their caller. A blocking action delays every
other action on that scheduler; dispatch does not preempt an action.

Publishers arrange listeners when each connection is added. Synchronous and
dedicated-thread listeners retain their original relative order; scheduler
listeners follow them, sorted by scheduler ID, with stable order within each ID.
Each contiguous group on the same scheduler instance shares one enqueue lock
and sends one notification after the group has been enqueued. Equal IDs from
different applications use separate locks. This applies to ordinary and variant
outputs, including adapters that deliver typed data to `std::any` actions.
Scheduler delivery therefore happens after all non-scheduler deliveries;
relative execution timing across asynchronous listeners is not guaranteed.

Scheduler threads start during finalization, before importers start. Composition
of actions, importers, exporters, and wrapped facilities preserves the scheduler
choices of contained actions and exporters. A scheduled node cannot use schedulers
from multiple application instances. `M::actionSchedulerID(action)` returns its optional ID;
`M::actionIsThreaded(action)` continues to identify dedicated-thread actions.
Graphviz output marks scheduled actions and exporters dark violet and appends
`[scheduler: N]` to their labels, including scheduler `0`. Dedicated-thread actions remain red, and
one-time actions retain their dotted style.

CPU affinity is implemented on Linux with `pthread_setaffinity_np`. Unconfigured
schedulers inherit normal OS scheduling. `setSchedulerCPU` can configure affinity
before finalization or update a running scheduler. Invalid or unavailable CPUs
raise an exception when affinity is applied (during finalization for a deferred
binding). Requesting affinity on an unsupported platform raises an exception;
scheduler execution itself remains portable.

`runner.stopSchedulers()` stops dispatch, discards pending inputs, and waits for
current dispatches to finish. Call it from outside the scheduler threads. It is
also called automatically before the runner releases its graph. Stopping is
idempotent, and stopped schedulers cannot be restarted. As with dedicated
threaded actions, uncaught exceptions in scheduled action logic terminate the
process.

`Scheduler(id)` clears `suggestThreaded`; `SuggestThreaded(true)` clears the
scheduler ID. Setting both fields directly is rejected by action and exporter
lifting factories. Other application models ignore the scheduler setting;
importer and facility lifting modes retain their previous behavior.

Custom `AbstractAction` subclasses can use
`fromAbstractAction(action, Params().Scheduler(id))`. Their `handle` implementation
must use the inherited `enqueueScheduled` hook before running its synchronous
body, following the built-in action cores:

```cpp
void handle(InnerData<A> &&data) override {
    if (this->enqueueScheduled(std::move(data))) {
        return;
    }
    handleImmediately(std::move(data));
}
```

The custom action must also create its typed queue once when attached:

```cpp
std::unique_ptr<real_time_app_detail::Scheduler::Queue> makeSchedulerQueue() override {
    return std::make_unique<
        real_time_app_detail::Scheduler::InputQueue<InnerData<A>, MyAction>
    >(this);
}
```

Here `MyAction` is the custom class, `real_time_app_detail` is in the `infra`
namespace, `handleImmediately` is public and contains its execution logic, and
`isThreaded()` returns `false`. Without a scheduler ID the hook leaves the input
untouched and execution remains synchronous.

Custom `AbstractExporter` subclasses can likewise use
`M::exporter(exporter, Params().Scheduler(id))` with the same typed queue and
`enqueueScheduled` hook. They retain their existing `start` implementation.
