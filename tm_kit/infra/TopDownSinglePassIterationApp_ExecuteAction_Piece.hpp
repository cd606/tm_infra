template <class A0, class A1, class B>
Source<B> execute(Action<std::variant<A0,A1>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class B>
Source<B> execute(Action<std::variant<A0,A1>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class B>
Source<B> execute(Action<std::variant<A0,A1,A2>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<IHandler<A4> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<IHandler<A4> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<IHandler<A5> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<IHandler<A4> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<IHandler<A5> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<IHandler<A6> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<IHandler<A4> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<IHandler<A5> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<IHandler<A6> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<IHandler<A7> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<IHandler<A4> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<IHandler<A5> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<IHandler<A6> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<IHandler<A7> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<IHandler<A8> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A0> &&variable) {
    innerConnect(dynamic_cast<IHandler<A0> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A1> &&variable) {
    innerConnect(dynamic_cast<IHandler<A1> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A2> &&variable) {
    innerConnect(dynamic_cast<IHandler<A2> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A3> &&variable) {
    innerConnect(dynamic_cast<IHandler<A3> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A4> &&variable) {
    innerConnect(dynamic_cast<IHandler<A4> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A5> &&variable) {
    innerConnect(dynamic_cast<IHandler<A5> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A6> &&variable) {
    innerConnect(dynamic_cast<IHandler<A6> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A7> &&variable) {
    innerConnect(dynamic_cast<IHandler<A7> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A8> &&variable) {
    innerConnect(dynamic_cast<IHandler<A8> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
Source<B> execute(Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> &action, Source<A9> &&variable) {
    innerConnect(dynamic_cast<IHandler<A9> *>(action.core_.get()), variable.producer);
    return {dynamic_cast<Producer<B> *>(action.core_.get())};
}