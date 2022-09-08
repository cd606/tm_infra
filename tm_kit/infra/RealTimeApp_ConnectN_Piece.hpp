template <class A0, class A1>
void connect_2_0(Source<std::variant<A0,A1>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1>
void connectAny_2_0(Source<std::variant<A0,A1>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1>
void connect_2_1(Source<std::variant<A0,A1>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1>
void connectAny_2_1(Source<std::variant<A0,A1>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2>
void connect_3_0(Source<std::variant<A0,A1,A2>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2>
void connectAny_3_0(Source<std::variant<A0,A1,A2>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2>
void connect_3_1(Source<std::variant<A0,A1,A2>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2>
void connectAny_3_1(Source<std::variant<A0,A1,A2>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2>
void connect_3_2(Source<std::variant<A0,A1,A2>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2>
void connectAny_3_2(Source<std::variant<A0,A1,A2>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3>
void connect_4_0(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3>
void connectAny_4_0(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3>
void connect_4_1(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3>
void connectAny_4_1(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3>
void connect_4_2(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3>
void connectAny_4_2(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3>
void connect_4_3(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3>
void connectAny_4_3(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_0(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_0(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_1(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_1(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_2(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_2(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_3(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_3(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_4(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4>
void connectAny_5_4(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_0(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_0(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_1(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_1(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_2(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_2(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_3(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_3(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_4(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_4(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_5(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connectAny_6_5(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connectAny_7_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connectAny_8_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connectAny_9_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connectAny_10_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connect_11_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
void connectAny_11_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connect_12_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
void connectAny_12_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connect_13_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
void connectAny_13_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connect_14_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
void connectAny_14_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connect_15_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<A14> const &sink) {
    source.producer->addHandler_14(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
void connectAny_15_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_14(new AnyHandlerAdapter<A14>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A14> const &sink) {
    source.producer->addHandler_14(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_14(new AnyHandlerAdapter<A14>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connect_16_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<A15> const &sink) {
    source.producer->addHandler_15(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
void connectAny_16_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_15(new AnyHandlerAdapter<A15>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A14> const &sink) {
    source.producer->addHandler_14(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_14(new AnyHandlerAdapter<A14>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A15> const &sink) {
    source.producer->addHandler_15(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_15(new AnyHandlerAdapter<A15>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connect_17_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<A16> const &sink) {
    source.producer->addHandler_16(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
void connectAny_17_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_16(new AnyHandlerAdapter<A16>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A14> const &sink) {
    source.producer->addHandler_14(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_14(new AnyHandlerAdapter<A14>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A15> const &sink) {
    source.producer->addHandler_15(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_15(new AnyHandlerAdapter<A15>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A16> const &sink) {
    source.producer->addHandler_16(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_16(new AnyHandlerAdapter<A16>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connect_18_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<A17> const &sink) {
    source.producer->addHandler_17(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
void connectAny_18_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_17(new AnyHandlerAdapter<A17>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A14> const &sink) {
    source.producer->addHandler_14(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_14(new AnyHandlerAdapter<A14>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A15> const &sink) {
    source.producer->addHandler_15(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_15(new AnyHandlerAdapter<A15>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A16> const &sink) {
    source.producer->addHandler_16(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_16(new AnyHandlerAdapter<A16>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A17> const &sink) {
    source.producer->addHandler_17(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_17(new AnyHandlerAdapter<A17>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connect_19_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<A18> const &sink) {
    source.producer->addHandler_18(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
void connectAny_19_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_18(new AnyHandlerAdapter<A18>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A0> const &sink) {
    source.producer->addHandler_0(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_0(new AnyHandlerAdapter<A0>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A1> const &sink) {
    source.producer->addHandler_1(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_1(new AnyHandlerAdapter<A1>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A2> const &sink) {
    source.producer->addHandler_2(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_2(new AnyHandlerAdapter<A2>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A3> const &sink) {
    source.producer->addHandler_3(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_3(new AnyHandlerAdapter<A3>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A4> const &sink) {
    source.producer->addHandler_4(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_4(new AnyHandlerAdapter<A4>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A5> const &sink) {
    source.producer->addHandler_5(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_5(new AnyHandlerAdapter<A5>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A6> const &sink) {
    source.producer->addHandler_6(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_6(new AnyHandlerAdapter<A6>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A7> const &sink) {
    source.producer->addHandler_7(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_7(new AnyHandlerAdapter<A7>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A8> const &sink) {
    source.producer->addHandler_8(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_8(new AnyHandlerAdapter<A8>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A9> const &sink) {
    source.producer->addHandler_9(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_9(new AnyHandlerAdapter<A9>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A10> const &sink) {
    source.producer->addHandler_10(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_10(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_10(new AnyHandlerAdapter<A10>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A11> const &sink) {
    source.producer->addHandler_11(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_11(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_11(new AnyHandlerAdapter<A11>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A12> const &sink) {
    source.producer->addHandler_12(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_12(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_12(new AnyHandlerAdapter<A12>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A13> const &sink) {
    source.producer->addHandler_13(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_13(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_13(new AnyHandlerAdapter<A13>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A14> const &sink) {
    source.producer->addHandler_14(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_14(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_14(new AnyHandlerAdapter<A14>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A15> const &sink) {
    source.producer->addHandler_15(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_15(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_15(new AnyHandlerAdapter<A15>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A16> const &sink) {
    source.producer->addHandler_16(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_16(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_16(new AnyHandlerAdapter<A16>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A17> const &sink) {
    source.producer->addHandler_17(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_17(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_17(new AnyHandlerAdapter<A17>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A18> const &sink) {
    source.producer->addHandler_18(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_18(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_18(new AnyHandlerAdapter<A18>(sink.consumer));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connect_20_19(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<A19> const &sink) {
    source.producer->addHandler_19(sink.consumer);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
void connectAny_20_19(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&source, Sink<std::any> const &sink) {
    source.producer->addHandler_19(new AnyHandlerAdapter<A19>(sink.consumer));
}