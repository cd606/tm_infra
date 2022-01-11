template <class A0, class A1, class B>
Source<B> execute(Action<std::variant<A0,A1>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class B>
Source<B> execute(Action<std::variant<A0,A1>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> &action, Source<A14> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A14> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A14> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A14> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> &action, Source<A15> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A15> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A14> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A14> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A15> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A15> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> &action, Source<A16> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A16> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A14> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A14> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A15> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A15> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A16> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A16> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> &action, Source<A17> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A17> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A14> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A14> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A15> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A15> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A16> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A16> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A17> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A17> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> &action, Source<A18> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A18> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A0> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A1> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A2> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A3> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A4> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A5> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A6> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A7> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A8> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A9> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A10> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A10> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A11> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A11> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A12> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A12> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A13> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A13> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A14> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A14> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A15> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A15> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A16> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A16> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A17> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A17> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A18> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A18> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> &action, Source<A19> &&variable) {
    innerConnect(dynamic_cast<AbstractConsumer<A19> *>(action.core_.get()), variable.provider);
    return {dynamic_cast<Provider<B> *>(action.core_.get())};
}