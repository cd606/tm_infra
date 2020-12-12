template <class A0, class A1>
static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<std::size_t,A0,A1>>> merge2(std::bitset<2> const &requireMask = std::bitset<2> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1> &&data) -> std::optional<std::tuple<std::size_t,A0,A1>> {
        static std::bitset<2> mask;
        static std::tuple<A0,A1> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1>,std::tuple<A0,A1>>>(
        new MaybeActionCore<std::variant<A0,A1>,std::tuple<A0,A1>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2>
static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,A0,A1,A2>>> merge3(std::bitset<3> const &requireMask = std::bitset<3> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2>> {
        static std::bitset<3> mask;
        static std::tuple<A0,A1,A2> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>>(
        new MaybeActionCore<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,A0,A1,A2,A3>>> merge4(std::bitset<4> const &requireMask = std::bitset<4> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3>> {
        static std::bitset<4> mask;
        static std::tuple<A0,A1,A2,A3> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,A0,A1,A2,A3,A4>>> merge5(std::bitset<5> const &requireMask = std::bitset<5> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3,A4>> {
        static std::bitset<5> mask;
        static std::tuple<A0,A1,A2,A3,A4> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<0>(val) = 4;
            std::get<5>(val) = std::move(std::get<4>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5>>> merge6(std::bitset<6> const &requireMask = std::bitset<6> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3,A4,A5>> {
        static std::bitset<6> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<0>(val) = 4;
            std::get<5>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<0>(val) = 5;
            std::get<6>(val) = std::move(std::get<5>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6>>> merge7(std::bitset<7> const &requireMask = std::bitset<7> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6>> {
        static std::bitset<7> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<0>(val) = 4;
            std::get<5>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<0>(val) = 5;
            std::get<6>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<0>(val) = 6;
            std::get<7>(val) = std::move(std::get<6>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7>>> merge8(std::bitset<8> const &requireMask = std::bitset<8> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7>> {
        static std::bitset<8> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<0>(val) = 4;
            std::get<5>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<0>(val) = 5;
            std::get<6>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<0>(val) = 6;
            std::get<7>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<0>(val) = 7;
            std::get<8>(val) = std::move(std::get<7>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8>>> merge9(std::bitset<9> const &requireMask = std::bitset<9> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
        static std::bitset<9> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<0>(val) = 4;
            std::get<5>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<0>(val) = 5;
            std::get<6>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<0>(val) = 6;
            std::get<7>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<0>(val) = 7;
            std::get<8>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<0>(val) = 8;
            std::get<9>(val) = std::move(std::get<8>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> merge10(std::bitset<10> const &requireMask = std::bitset<10> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
    auto f = [requireMask](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&data) -> std::optional<std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
        static std::bitset<10> mask;
        static std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> val;
        switch (data.index()) {
        case 0:
            mask.set(0);
            std::get<0>(val) = 0;
            std::get<1>(val) = std::move(std::get<0>(data));
            break;
        case 1:
            mask.set(1);
            std::get<0>(val) = 1;
            std::get<2>(val) = std::move(std::get<1>(data));
            break;
        case 2:
            mask.set(2);
            std::get<0>(val) = 2;
            std::get<3>(val) = std::move(std::get<2>(data));
            break;
        case 3:
            mask.set(3);
            std::get<0>(val) = 3;
            std::get<4>(val) = std::move(std::get<3>(data));
            break;
        case 4:
            mask.set(4);
            std::get<0>(val) = 4;
            std::get<5>(val) = std::move(std::get<4>(data));
            break;
        case 5:
            mask.set(5);
            std::get<0>(val) = 5;
            std::get<6>(val) = std::move(std::get<5>(data));
            break;
        case 6:
            mask.set(6);
            std::get<0>(val) = 6;
            std::get<7>(val) = std::move(std::get<6>(data));
            break;
        case 7:
            mask.set(7);
            std::get<0>(val) = 7;
            std::get<8>(val) = std::move(std::get<7>(data));
            break;
        case 8:
            mask.set(8);
            std::get<0>(val) = 8;
            std::get<9>(val) = std::move(std::get<8>(data));
            break;
        case 9:
            mask.set(9);
            std::get<0>(val) = 9;
            std::get<10>(val) = std::move(std::get<9>(data));
            break;
        default:
            break;
        }
        if ((mask & requireMask) == requireMask) {
            return withtime_utils::makeValueCopy(val);
        } else {
            return std::nullopt;
        }
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f)>(
            std::move(f), liftParam
        )
    );
}