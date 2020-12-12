    template <class A0, class A1, class F>
    static auto variant2(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1>, typename decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1>, typename decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<std::size_t,A0,A1>>> merge2(std::bitset<2> const &requireMask=std::bitset<2> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,A0,A1>>>(liftParam);
    }
    template <class A0, class A1, class A2, class F>
    static auto variant3(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,A0,A1,A2>>> merge3(std::bitset<3> const &requireMask=std::bitset<3> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,A0,A1,A2>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class F>
    static auto variant4(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,A0,A1,A2,A3>>> merge4(std::bitset<4> const &requireMask=std::bitset<4> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,A0,A1,A2,A3>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto variant5(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,A0,A1,A2,A3,A4>>> merge5(std::bitset<5> const &requireMask=std::bitset<5> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,A0,A1,A2,A3,A4>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto variant6(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5>>> merge6(std::bitset<6> const &requireMask=std::bitset<6> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto variant7(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6>>> merge7(std::bitset<7> const &requireMask=std::bitset<7> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto variant8(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7>>> merge8(std::bitset<8> const &requireMask=std::bitset<8> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto variant9(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8>>> merge9(std::bitset<9> const &requireMask=std::bitset<9> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8>>>(liftParam);
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto variant10(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type::ValueType>>();
    }
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> merge10(std::bitset<10> const &requireMask=std::bitset<10> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>(liftParam);
    }