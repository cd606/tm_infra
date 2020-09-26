This is unstable software, with absolutely no warranty or guarantee whatsoever, whether express or implied, including but not limited to those of merchantability, fitness for specific purpose, or non-infringement.

This package aims to provide a set of C++ helper classes that enable the writing of data-flow code in a functional way, which can be easily adapted between a "real time" mode and a "single pass" test mode.

The basic concept is that, a data-flow code can be visualized as a graph, in which there are three types of nodes: 

* "importers": nodes that do not take any input from any other nodes (usually because they have inputs from a source not shown inside the data-flow graph), but provide results that can be used as inputs by other nodes. These nodes "import" data from the outside world into the graph.

* "exporters": the dual of importers, nodes that do not take inputs from other nodes, but do not provide any results to be used as inputs by other nodes. Usually these nodes do something that has side-effects outside the data-flow graph, e.g. print the input data. So, these nodes "export" data from the graph to the outside world.

* "actions": nodes that take inputs from other nodes and provide results to other nodes.

An exporter or an action that takes multiple inputs are modelled internally as taking a <code>std::variant</code> input (which means if you **actually** wants to pass <code>std::variant</code> between two nodes, you need to wrap it in some outer data structure), the underlying thought is that in reality, different inputs from such multiplitude arrive at **different times**, therefore any actual processing always faces one input among such multiplitude only, so <code>std::variant</code> is a proper way to model that.

Such internal modelling is mostly abstracted away through the package, but the abstraction is leaky in the sense that if you actually wants to pass <code>std::variant</code> between two nodes, you need to take some additional measure. This hopefully is not a very big problem.

For producing multiple outputs, the situation is different, since such outputs are generally produced at **the same time**. Therefore, a structure or a <code>std::tuple</code> is perfectly suitable. For multiple outputs of the same type, the package also provides some facilities wherein you can write code that produces a <code>std::vector</code> and the downstream nodes will receive the items one by one. Of course, you don't have to use those facilities, and can always let the nodes directly produce and consume <code>std::vector</code> or other containers.

While these theoretically cover all the possibilities of node types in a general data-flow graph, this package also introduces a set of specialized node types that might facilitate the writing of data-flow code:

* "on-order facilities": nodes that take one *tagged* input (which cannot be <code>std::variant</code>) and for each instance of such tagged input, produce zero, one or more output with the same tag. This can be thought of as a "production facility" that responds to non-fungible incoming production orders, therefore the name. In this package, on-order facilities are connected to other nodes with a different syntax than actions, which permits loops in the graph as long as each loop contains at least one on-order facility. 

* "local on-order facilities": considering that on-order facilities normally needs some other inputs than the "order" (the tagged input) to help it process the order, it would be nice to have some way to pass these inputs to the facilities. Since this package does not aim to make every node pure, it is perfectly acceptable to have the on-order facility node contain a pointer to another node and share data. Such another node is likely an "exporter" since it receives the other inputs but does not produce any on-graph output (since it is actually receives the other inputs on behalf of the on-order facility only). In this package, it is possible to bundle a pointer to an on-order facility and a pointer to an exporter together (in fact, the two pointers may point to one same object which implements the two interfaces), and call such bundle a "local on-order facility". 

* "on-order facilities with external effects": this is the dual of the local on-order facilities, it is a bundle of a pointer to an on-order facility and a pointer to an importer.

* "VIE on-order facilities": this is the combination of the two above: a bundle of a pointer to an on-order facility, a pointer to an importer, and a pointer to an exporter. To expand on the trade-and-production simile, this name comes from the "variable interest entity" business structure.

All these nodes may be constructed through various static methods provided by RealTimeApp or SinglePassIterationApp, and then connected toghether through a AppRunner instance in a "natural" methodology completely expressed in C++, with all attending type checks (which also means that if there is some type mismatch, the compiler will generate lengthy compilation error messages). The AppRunner instance can then output a Graphviz® visualization of the graph, or run the graph.

This particular package (tm_infra) only provides the basic node and graph definition functionalities. To make the graph useful, please refer to other related packages, also publicly available at github.com.

INSTALLATION NOTES:

The requirements of tm_infra are:

* gcc >= 9.3.1, clang >= 10.0.1, or MSVC Build Tools 2019 (these versions have been tested to work, old version might work)

* meson

No third party library is required