template <class A0, class A1>
static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<A0,A1>>> merge2(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1) -> std::tuple<A0,A1> {
        return {std::move(a0), std::move(a1)};
    };
    return std::make_shared<Action<std::variant<A0,A1>,std::tuple<A0,A1>>>(
        new PureActionCore<std::variant<A0,A1>,std::tuple<A0,A1>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2>
static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>> merge3(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2) -> std::tuple<A0,A1,A2> {
        return {std::move(a0), std::move(a1), std::move(a2)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>>(
        new PureActionCore<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>> merge4(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3) -> std::tuple<A0,A1,A2,A3> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>> merge5(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3, A4 &&a4) -> std::tuple<A0,A1,A2,A3,A4> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3), std::move(a4)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>> merge6(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3, A4 &&a4, A5 &&a5) -> std::tuple<A0,A1,A2,A3,A4,A5> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3), std::move(a4), std::move(a5)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> merge7(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3, A4 &&a4, A5 &&a5, A6 &&a6) -> std::tuple<A0,A1,A2,A3,A4,A5,A6> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3), std::move(a4), std::move(a5), std::move(a6)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> merge8(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3, A4 &&a4, A5 &&a5, A6 &&a6, A7 &&a7) -> std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3), std::move(a4), std::move(a5), std::move(a6), std::move(a7)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> merge9(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3, A4 &&a4, A5 &&a5, A6 &&a6, A7 &&a7, A8 &&a8) -> std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3), std::move(a4), std::move(a5), std::move(a6), std::move(a7), std::move(a8)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> merge10(FanInParamMask const &requireMask=FanInParamMask()) {
    auto f = [](int which, A0 &&a0, A1 &&a1, A2 &&a2, A3 &&a3, A4 &&a4, A5 &&a5, A6 &&a6, A7 &&a7, A8 &&a8, A9 &&a9) -> std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {
        return {std::move(a0), std::move(a1), std::move(a2), std::move(a3), std::move(a4), std::move(a5), std::move(a6), std::move(a7), std::move(a8), std::move(a9)};
    };
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f)>(
            std::move(f), requireMask
        )
    );
}