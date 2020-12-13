template <class A0, class A1>
void connect_2_0(Source<std::variant<A0,A1>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_2_0<A0,A1>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1>
void connect_2_1(Source<std::variant<A0,A1>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_2_1<A0,A1>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2>
void connect_3_0(Source<std::variant<A0,A1,A2>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_3_0<A0,A1,A2>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2>
void connect_3_1(Source<std::variant<A0,A1,A2>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_3_1<A0,A1,A2>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2>
void connect_3_2(Source<std::variant<A0,A1,A2>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_3_2<A0,A1,A2>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3>
void connect_4_0(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_4_0<A0,A1,A2,A3>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3>
void connect_4_1(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_4_1<A0,A1,A2,A3>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3>
void connect_4_2(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_4_2<A0,A1,A2,A3>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3>
void connect_4_3(Source<std::variant<A0,A1,A2,A3>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_4_3<A0,A1,A2,A3>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_0(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_5_0<A0,A1,A2,A3,A4>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_1(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_5_1<A0,A1,A2,A3,A4>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_2(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_5_2<A0,A1,A2,A3,A4>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_3(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_5_3<A0,A1,A2,A3,A4>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4>
void connect_5_4(Source<std::variant<A0,A1,A2,A3,A4>> &&source, Sink<A4> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_5_4<A0,A1,A2,A3,A4>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_0(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_6_0<A0,A1,A2,A3,A4,A5>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_1(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_6_1<A0,A1,A2,A3,A4,A5>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_2(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_6_2<A0,A1,A2,A3,A4,A5>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_3(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_6_3<A0,A1,A2,A3,A4,A5>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_4(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A4> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_6_4<A0,A1,A2,A3,A4,A5>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
void connect_6_5(Source<std::variant<A0,A1,A2,A3,A4,A5>> &&source, Sink<A5> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_6_5<A0,A1,A2,A3,A4,A5>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_0<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_1<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_2<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_3<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A4> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_4<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A5> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_5<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
void connect_7_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&source, Sink<A6> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_7_6<A0,A1,A2,A3,A4,A5,A6>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_0<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_1<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_2<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_3<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A4> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_4<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A5> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_5<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A6> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_6<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
void connect_8_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&source, Sink<A7> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_8_7<A0,A1,A2,A3,A4,A5,A6,A7>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_0<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_1<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_2<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_3<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A4> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_4<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A5> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_5<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A6> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_6<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A7> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_7<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
void connect_9_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&source, Sink<A8> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_9_8<A0,A1,A2,A3,A4,A5,A6,A7,A8>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_0(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A0> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_0<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_1(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A1> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_1<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_2(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A2> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_2<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_3(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A3> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_3<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_4(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A4> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_4<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_5(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A5> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_5<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_6(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A6> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_6<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_7(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A7> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_7<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_8(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A8> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_8<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
void connect_10_9(Source<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&source, Sink<A9> const &sink) {
    innerConnect(sink.consumer, new ProviderAdapter_10_9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(getMultiplexerOutput(source.provider)));
}