template <class A0, class A1, class F>
static auto liftPure2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class F>
static auto liftMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class F>
static auto enhancedMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class F>
static auto kleisli2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class F>
static auto liftMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(* ((std::variant<A0,A1> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class F>
static auto enhancedMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class F>
static auto kleisliMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto liftPure3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto liftMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto enhancedMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto kleisli3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto liftMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto enhancedMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class F>
static auto kleisliMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftPure4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto enhancedMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto kleisli4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto enhancedMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class F>
static auto kleisliMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftPure5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto enhancedMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto kleisli5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto enhancedMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto kleisliMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3,A4>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftPure6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto enhancedMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto kleisli6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto enhancedMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto kleisliMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3,A4,A5>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftPure7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto enhancedMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto kleisli7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto enhancedMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto kleisliMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3,A4,A5,A6>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftPure8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto enhancedMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto kleisli8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto enhancedMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto kleisliMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftPure9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto enhancedMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto kleisli9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto enhancedMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto kleisliMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftPure10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> {
    return liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> {
    return liftMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto enhancedMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> {
    return enhancedMaybe<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto kleisli10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> {
    return kleisli<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(* ((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> {
    return liftMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto enhancedMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint,std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> {
    return enhancedMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto kleisliMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> {
    return kleisliMulti<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(std::move(f), liftParam);
}