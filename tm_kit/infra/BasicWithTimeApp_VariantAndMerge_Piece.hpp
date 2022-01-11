    template <class A0, class A1, class F>
    static auto variant2(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1>, typename decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1>, typename decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> merge2(std::bitset<2> const &requireMask=std::bitset<2> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class F>
    static auto variant3(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> merge3(std::bitset<3> const &requireMask=std::bitset<3> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class F>
    static auto variant4(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> merge4(std::bitset<4> const &requireMask=std::bitset<4> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto variant5(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> merge5(std::bitset<5> const &requireMask=std::bitset<5> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto variant6(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> merge6(std::bitset<6> const &requireMask=std::bitset<6> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto variant7(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> merge7(std::bitset<7> const &requireMask=std::bitset<7> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto variant8(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> merge8(std::bitset<8> const &requireMask=std::bitset<8> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto variant9(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> merge9(std::bitset<9> const &requireMask=std::bitset<9> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto variant10(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> merge10(std::bitset<10> const &requireMask=std::bitset<10> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class F>
    static auto variant11(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> merge11(std::bitset<11> const &requireMask=std::bitset<11> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class F>
    static auto variant12(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> merge12(std::bitset<12> const &requireMask=std::bitset<12> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class F>
    static auto variant13(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> merge13(std::bitset<13> const &requireMask=std::bitset<13> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class F>
    static auto variant14(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> merge14(std::bitset<14> const &requireMask=std::bitset<14> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class F>
    static auto variant15(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> merge15(std::bitset<15> const &requireMask=std::bitset<15> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class F>
    static auto variant16(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> merge16(std::bitset<16> const &requireMask=std::bitset<16> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class F>
    static auto variant17(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> merge17(std::bitset<17> const &requireMask=std::bitset<17> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class F>
    static auto variant18(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> merge18(std::bitset<18> const &requireMask=std::bitset<18> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class F>
    static auto variant19(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> merge19(std::bitset<19> const &requireMask=std::bitset<19> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class F>
    static auto variant20(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> merge20(std::bitset<20> const &requireMask=std::bitset<20> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>>(liftParam);
    }