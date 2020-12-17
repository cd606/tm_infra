template <class TimePoint, class A0, class A1>
inline WithTime<std::tuple<A0, A1>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2>
struct ValueCopier<std::tuple<A0, A1, A2>> {
    inline static std::tuple<A0, A1, A2> copy(std::tuple<A0, A1, A2> const &x) {
        return std::tuple<A0, A1, A2> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2>
inline WithTime<std::tuple<A0, A1, A2>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3>
struct ValueCopier<std::tuple<A0, A1, A2, A3>> {
    inline static std::tuple<A0, A1, A2, A3> copy(std::tuple<A0, A1, A2, A3> const &x) {
        return std::tuple<A0, A1, A2, A3> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3>
inline WithTime<std::tuple<A0, A1, A2, A3>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4>> {
    inline static std::tuple<A0, A1, A2, A3, A4> copy(std::tuple<A0, A1, A2, A3, A4> const &x) {
        return std::tuple<A0, A1, A2, A3, A4> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4>
inline WithTime<std::tuple<A0, A1, A2, A3, A4>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5> copy(std::tuple<A0, A1, A2, A3, A4, A5> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value))}, a.finalFlag
    };
}