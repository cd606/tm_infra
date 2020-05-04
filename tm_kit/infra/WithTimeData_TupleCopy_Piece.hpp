template <class TimePoint, class A0, class A1>
inline WithTime<std::tuple<A0, A1>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2>
inline WithTime<std::tuple<A0, A1, A2>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3>
inline WithTime<std::tuple<A0, A1, A2, A3>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3, class A4>
inline WithTime<std::tuple<A0, A1, A2, A3, A4>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value))}, a.finalFlag
    };
}
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value))}, a.finalFlag
    };
}