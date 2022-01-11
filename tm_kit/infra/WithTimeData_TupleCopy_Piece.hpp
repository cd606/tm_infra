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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x)), ValueCopier<A14>::copy(std::get<14>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value)), makeValueCopy(std::get<14>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x)), ValueCopier<A14>::copy(std::get<14>(x)), ValueCopier<A15>::copy(std::get<15>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value)), makeValueCopy(std::get<14>(a.value)), makeValueCopy(std::get<15>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x)), ValueCopier<A14>::copy(std::get<14>(x)), ValueCopier<A15>::copy(std::get<15>(x)), ValueCopier<A16>::copy(std::get<16>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value)), makeValueCopy(std::get<14>(a.value)), makeValueCopy(std::get<15>(a.value)), makeValueCopy(std::get<16>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x)), ValueCopier<A14>::copy(std::get<14>(x)), ValueCopier<A15>::copy(std::get<15>(x)), ValueCopier<A16>::copy(std::get<16>(x)), ValueCopier<A17>::copy(std::get<17>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value)), makeValueCopy(std::get<14>(a.value)), makeValueCopy(std::get<15>(a.value)), makeValueCopy(std::get<16>(a.value)), makeValueCopy(std::get<17>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x)), ValueCopier<A14>::copy(std::get<14>(x)), ValueCopier<A15>::copy(std::get<15>(x)), ValueCopier<A16>::copy(std::get<16>(x)), ValueCopier<A17>::copy(std::get<17>(x)), ValueCopier<A18>::copy(std::get<18>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value)), makeValueCopy(std::get<14>(a.value)), makeValueCopy(std::get<15>(a.value)), makeValueCopy(std::get<16>(a.value)), makeValueCopy(std::get<17>(a.value)), makeValueCopy(std::get<18>(a.value))}, a.finalFlag
    };
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
struct ValueCopier<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19>> {
    inline static std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19> copy(std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19> const &x) {
        return std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19> {ValueCopier<A0>::copy(std::get<0>(x)), ValueCopier<A1>::copy(std::get<1>(x)), ValueCopier<A2>::copy(std::get<2>(x)), ValueCopier<A3>::copy(std::get<3>(x)), ValueCopier<A4>::copy(std::get<4>(x)), ValueCopier<A5>::copy(std::get<5>(x)), ValueCopier<A6>::copy(std::get<6>(x)), ValueCopier<A7>::copy(std::get<7>(x)), ValueCopier<A8>::copy(std::get<8>(x)), ValueCopier<A9>::copy(std::get<9>(x)), ValueCopier<A10>::copy(std::get<10>(x)), ValueCopier<A11>::copy(std::get<11>(x)), ValueCopier<A12>::copy(std::get<12>(x)), ValueCopier<A13>::copy(std::get<13>(x)), ValueCopier<A14>::copy(std::get<14>(x)), ValueCopier<A15>::copy(std::get<15>(x)), ValueCopier<A16>::copy(std::get<16>(x)), ValueCopier<A17>::copy(std::get<17>(x)), ValueCopier<A18>::copy(std::get<18>(x)), ValueCopier<A19>::copy(std::get<19>(x))};
    }
};
template <class TimePoint, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
inline WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19>, TimePoint> makeCopy(WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19>, TimePoint> const &a) {
    return WithTime<std::tuple<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19>, TimePoint> {
        a.timePoint, {makeValueCopy(std::get<0>(a.value)), makeValueCopy(std::get<1>(a.value)), makeValueCopy(std::get<2>(a.value)), makeValueCopy(std::get<3>(a.value)), makeValueCopy(std::get<4>(a.value)), makeValueCopy(std::get<5>(a.value)), makeValueCopy(std::get<6>(a.value)), makeValueCopy(std::get<7>(a.value)), makeValueCopy(std::get<8>(a.value)), makeValueCopy(std::get<9>(a.value)), makeValueCopy(std::get<10>(a.value)), makeValueCopy(std::get<11>(a.value)), makeValueCopy(std::get<12>(a.value)), makeValueCopy(std::get<13>(a.value)), makeValueCopy(std::get<14>(a.value)), makeValueCopy(std::get<15>(a.value)), makeValueCopy(std::get<16>(a.value)), makeValueCopy(std::get<17>(a.value)), makeValueCopy(std::get<18>(a.value)), makeValueCopy(std::get<19>(a.value))}, a.finalFlag
    };
}