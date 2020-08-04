    template <class A0, class A1, class F>
    static auto variant2(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1())))::value_type::ValueType>>();
    }
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<A0,A1>>> merge2(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1>,std::tuple<A0,A1>>>();
    }
    template <class A0, class A1, class A2, class F>
    static auto variant3(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>> merge3(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>>();
    }
    template <class A0, class A1, class A2, class A3, class F>
    static auto variant4(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>> merge4(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto variant5(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>> merge5(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto variant6(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>> merge6(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto variant7(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> merge7(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto variant8(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> merge8(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto variant9(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> merge9(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto variant10(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8()),pureInnerData<A9>(nullptr,A9())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8()),pureInnerData<A9>(nullptr,A9())))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> merge10(FanInParamMask const &notUsed=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>();
    }