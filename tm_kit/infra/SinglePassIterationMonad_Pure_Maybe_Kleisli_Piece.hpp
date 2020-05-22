template <class A0, class A1, class F>
static auto liftPure2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class F>
static auto liftMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class F>
static auto enhancedMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class F>
static auto kleisli2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class F>
static auto liftPure3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class F>
static auto liftMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class F>
static auto enhancedMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class F>
static auto kleisli3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftPure4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto enhancedMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto kleisli4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftPure5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto enhancedMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto kleisli5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftPure6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto enhancedMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto kleisli6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftPure7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto enhancedMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto kleisli7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftPure8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto enhancedMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto kleisli8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftPure9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto enhancedMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto kleisli9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftPure10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>>(
        new PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr)))),F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>>(
        new MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto enhancedMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type>>(
        new EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type,F>(
            std::move(f), liftParam.requireMask
        )
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto kleisli10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>>(
        new KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType,F>(
            std::move(f), liftParam.requireMask
        )
    );
}