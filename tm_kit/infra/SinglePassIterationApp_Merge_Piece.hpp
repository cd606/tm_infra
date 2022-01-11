template <class A0, class A1>
static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> merge2(std::bitset<2> const &requireMask = std::bitset<2> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1>>> {
        static std::bitset<2> mask;
        static std::tuple<A0,A1> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>>(
        new MaybeActionCore<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2>
static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> merge3(std::bitset<3> const &requireMask = std::bitset<3> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2>>> {
        static std::bitset<3> mask;
        static std::tuple<A0,A1,A2> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> merge4(std::bitset<4> const &requireMask = std::bitset<4> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>> {
        static std::bitset<4> mask;
        static std::tuple<A0,A1,A2,A3> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> merge5(std::bitset<5> const &requireMask = std::bitset<5> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>> {
        static std::bitset<5> mask;
        static std::tuple<A0,A1,A2,A3,A4> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> merge6(std::bitset<6> const &requireMask = std::bitset<6> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>> {
        static std::bitset<6> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> merge7(std::bitset<7> const &requireMask = std::bitset<7> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {
        static std::bitset<7> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> merge8(std::bitset<8> const &requireMask = std::bitset<8> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {
        static std::bitset<8> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> merge9(std::bitset<9> const &requireMask = std::bitset<9> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {
        static std::bitset<9> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> merge10(std::bitset<10> const &requireMask = std::bitset<10> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {
        static std::bitset<10> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> merge11(std::bitset<11> const &requireMask = std::bitset<11> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {
        static std::bitset<11> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> merge12(std::bitset<12> const &requireMask = std::bitset<12> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {
        static std::bitset<12> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> merge13(std::bitset<13> const &requireMask = std::bitset<13> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {
        static std::bitset<13> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> merge14(std::bitset<14> const &requireMask = std::bitset<14> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {
        static std::bitset<14> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> merge15(std::bitset<15> const &requireMask = std::bitset<15> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {
        static std::bitset<15> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        case 14:
            mask.set(14);
            std::get<14>(val) = std::move(std::get<14>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> merge16(std::bitset<16> const &requireMask = std::bitset<16> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {
        static std::bitset<16> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        case 14:
            mask.set(14);
            std::get<14>(val) = std::move(std::get<14>(data));
            break;
        case 15:
            mask.set(15);
            std::get<15>(val) = std::move(std::get<15>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> merge17(std::bitset<17> const &requireMask = std::bitset<17> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {
        static std::bitset<17> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        case 14:
            mask.set(14);
            std::get<14>(val) = std::move(std::get<14>(data));
            break;
        case 15:
            mask.set(15);
            std::get<15>(val) = std::move(std::get<15>(data));
            break;
        case 16:
            mask.set(16);
            std::get<16>(val) = std::move(std::get<16>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> merge18(std::bitset<18> const &requireMask = std::bitset<18> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {
        static std::bitset<18> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        case 14:
            mask.set(14);
            std::get<14>(val) = std::move(std::get<14>(data));
            break;
        case 15:
            mask.set(15);
            std::get<15>(val) = std::move(std::get<15>(data));
            break;
        case 16:
            mask.set(16);
            std::get<16>(val) = std::move(std::get<16>(data));
            break;
        case 17:
            mask.set(17);
            std::get<17>(val) = std::move(std::get<17>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> merge19(std::bitset<19> const &requireMask = std::bitset<19> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {
        static std::bitset<19> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        case 14:
            mask.set(14);
            std::get<14>(val) = std::move(std::get<14>(data));
            break;
        case 15:
            mask.set(15);
            std::get<15>(val) = std::move(std::get<15>(data));
            break;
        case 16:
            mask.set(16);
            std::get<16>(val) = std::move(std::get<16>(data));
            break;
        case 17:
            mask.set(17);
            std::get<17>(val) = std::move(std::get<17>(data));
            break;
        case 18:
            mask.set(18);
            std::get<18>(val) = std::move(std::get<18>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> merge20(std::bitset<20> const &requireMask = std::bitset<20> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&data) -> std::optional<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {
        static std::bitset<20> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<1>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<2>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<3>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<4>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<5>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<6>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<7>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<8>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<9>(val) = std::move(std::get<9>(data));
            break;
        case 10:
            mask.set(10);
            std::get<10>(val) = std::move(std::get<10>(data));
            break;
        case 11:
            mask.set(11);
            std::get<11>(val) = std::move(std::get<11>(data));
            break;
        case 12:
            mask.set(12);
            std::get<12>(val) = std::move(std::get<12>(data));
            break;
        case 13:
            mask.set(13);
            std::get<13>(val) = std::move(std::get<13>(data));
            break;
        case 14:
            mask.set(14);
            std::get<14>(val) = std::move(std::get<14>(data));
            break;
        case 15:
            mask.set(15);
            std::get<15>(val) = std::move(std::get<15>(data));
            break;
        case 16:
            mask.set(16);
            std::get<16>(val) = std::move(std::get<16>(data));
            break;
        case 17:
            mask.set(17);
            std::get<17>(val) = std::move(std::get<17>(data));
            break;
        case 18:
            mask.set(18);
            std::get<18>(val) = std::move(std::get<18>(data));
            break;
        case 19:
            mask.set(19);
            std::get<19>(val) = std::move(std::get<19>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> {data.index(), withtime_utils::makeValueCopy(val)};
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}