template <class A0, class A1, class F>
static auto liftPure2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static bool flag0;
            static bool flag1;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class F>
static auto liftMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static bool flag0;
            static bool flag1;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class F>
static auto enhancedMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static bool flag0;
            static bool flag1;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class F>
static auto kleisli2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class F>
static auto liftPure3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class F>
static auto liftMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class F>
static auto enhancedMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class F>
static auto kleisli3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftPure4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto liftMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto enhancedMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class F>
static auto kleisli4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftPure5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto liftMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto enhancedMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class F>
static auto kleisli5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static TimedDataType<A4> a4;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) });
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = {x.timedData.timePoint, std::move(std::get<4>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    return f(4, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftPure6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto liftMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto enhancedMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
static auto kleisli6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static TimedDataType<A4> a4;
            static TimedDataType<A5> a5;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) });
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = {x.timedData.timePoint, std::move(std::get<4>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    return f(4, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) });
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = {x.timedData.timePoint, std::move(std::get<5>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    return f(5, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftPure7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto liftMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto enhancedMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
static auto kleisli7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static TimedDataType<A4> a4;
            static TimedDataType<A5> a5;
            static TimedDataType<A6> a6;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = {x.timedData.timePoint, std::move(std::get<4>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    return f(4, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = {x.timedData.timePoint, std::move(std::get<5>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    return f(5, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = {x.timedData.timePoint, std::move(std::get<6>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    return f(6, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftPure8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto liftMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto enhancedMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
static auto kleisli8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static TimedDataType<A4> a4;
            static TimedDataType<A5> a5;
            static TimedDataType<A6> a6;
            static TimedDataType<A7> a7;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = {x.timedData.timePoint, std::move(std::get<4>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    return f(4, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = {x.timedData.timePoint, std::move(std::get<5>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    return f(5, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = {x.timedData.timePoint, std::move(std::get<6>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    return f(6, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = {x.timedData.timePoint, std::move(std::get<7>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    return f(7, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftPure9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static A8 a8;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static bool flag8;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = std::get<8>(std::move(x.timedData.value));
                flag8 = x.timedData.finalFlag;
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(8, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto liftMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static A8 a8;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static bool flag8;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = std::get<8>(std::move(x.timedData.value));
                flag8 = x.timedData.finalFlag;
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(8, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto enhancedMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static A8 a8;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static bool flag8;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = std::get<8>(std::move(x.timedData.value));
                flag8 = x.timedData.finalFlag;
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(8, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
static auto kleisli9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static TimedDataType<A4> a4;
            static TimedDataType<A5> a5;
            static TimedDataType<A6> a6;
            static TimedDataType<A7> a7;
            static TimedDataType<A8> a8;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = {x.timedData.timePoint, std::move(std::get<4>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    return f(4, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = {x.timedData.timePoint, std::move(std::get<5>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    return f(5, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = {x.timedData.timePoint, std::move(std::get<6>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    return f(6, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = {x.timedData.timePoint, std::move(std::get<7>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    return f(7, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = {x.timedData.timePoint, std::move(std::get<8>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    return f(8, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftPure10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&x) -> Data<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static A8 a8;
            static A9 a9;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static bool flag8;
            static bool flag9;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = std::get<8>(std::move(x.timedData.value));
                flag8 = x.timedData.finalFlag;
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(8, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                a9 = std::get<9>(std::move(x.timedData.value));
                flag9 = x.timedData.finalFlag;
                mask.set(9);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(9, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    return { InnerData<decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))> {x.environment, { x.timedData.timePoint, std::move(b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto liftMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&x) -> Data<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static A8 a8;
            static A9 a9;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static bool flag8;
            static bool flag9;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = std::get<8>(std::move(x.timedData.value));
                flag8 = x.timedData.finalFlag;
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(8, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                a9 = std::get<9>(std::move(x.timedData.value));
                flag9 = x.timedData.finalFlag;
                mask.set(9);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(9, withtime_utils::makeValueCopy(a0), withtime_utils::makeValueCopy(a1), withtime_utils::makeValueCopy(a2), withtime_utils::makeValueCopy(a3), withtime_utils::makeValueCopy(a4), withtime_utils::makeValueCopy(a5), withtime_utils::makeValueCopy(a6), withtime_utils::makeValueCopy(a7), withtime_utils::makeValueCopy(a8), withtime_utils::makeValueCopy(a9));
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto enhancedMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&x) -> Data<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {
            static A0 a0;
            static A1 a1;
            static A2 a2;
            static A3 a3;
            static A4 a4;
            static A5 a5;
            static A6 a6;
            static A7 a7;
            static A8 a8;
            static A9 a9;
            static bool flag0;
            static bool flag1;
            static bool flag2;
            static bool flag3;
            static bool flag4;
            static bool flag5;
            static bool flag6;
            static bool flag7;
            static bool flag8;
            static bool flag9;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = std::get<0>(std::move(x.timedData.value));
                flag0 = x.timedData.finalFlag;
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(0, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = std::get<1>(std::move(x.timedData.value));
                flag1 = x.timedData.finalFlag;
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(1, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = std::get<2>(std::move(x.timedData.value));
                flag2 = x.timedData.finalFlag;
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(2, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = std::get<3>(std::move(x.timedData.value));
                flag3 = x.timedData.finalFlag;
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(3, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = std::get<4>(std::move(x.timedData.value));
                flag4 = x.timedData.finalFlag;
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(4, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = std::get<5>(std::move(x.timedData.value));
                flag5 = x.timedData.finalFlag;
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(5, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = std::get<6>(std::move(x.timedData.value));
                flag6 = x.timedData.finalFlag;
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(6, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = std::get<7>(std::move(x.timedData.value));
                flag7 = x.timedData.finalFlag;
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(7, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = std::get<8>(std::move(x.timedData.value));
                flag8 = x.timedData.finalFlag;
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(8, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                a9 = std::get<9>(std::move(x.timedData.value));
                flag9 = x.timedData.finalFlag;
                mask.set(9);
                if ((mask & requireMask) == requireMask) {
                    auto b = f(9, std::tuple<TimePoint, A0>{x.timedData.timePoint, withtime_utils::makeValueCopy(a0)}, std::tuple<TimePoint, A1>{x.timedData.timePoint, withtime_utils::makeValueCopy(a1)}, std::tuple<TimePoint, A2>{x.timedData.timePoint, withtime_utils::makeValueCopy(a2)}, std::tuple<TimePoint, A3>{x.timedData.timePoint, withtime_utils::makeValueCopy(a3)}, std::tuple<TimePoint, A4>{x.timedData.timePoint, withtime_utils::makeValueCopy(a4)}, std::tuple<TimePoint, A5>{x.timedData.timePoint, withtime_utils::makeValueCopy(a5)}, std::tuple<TimePoint, A6>{x.timedData.timePoint, withtime_utils::makeValueCopy(a6)}, std::tuple<TimePoint, A7>{x.timedData.timePoint, withtime_utils::makeValueCopy(a7)}, std::tuple<TimePoint, A8>{x.timedData.timePoint, withtime_utils::makeValueCopy(a8)}, std::tuple<TimePoint, A9>{x.timedData.timePoint, withtime_utils::makeValueCopy(a9)});
                    if (b) {
                        return { InnerData<typename decltype(f(0,std::move(*((std::tuple<TimePoint, A0> *) nullptr)),std::move(*((std::tuple<TimePoint, A1> *) nullptr)),std::move(*((std::tuple<TimePoint, A2> *) nullptr)),std::move(*((std::tuple<TimePoint, A3> *) nullptr)),std::move(*((std::tuple<TimePoint, A4> *) nullptr)),std::move(*((std::tuple<TimePoint, A5> *) nullptr)),std::move(*((std::tuple<TimePoint, A6> *) nullptr)),std::move(*((std::tuple<TimePoint, A7> *) nullptr)),std::move(*((std::tuple<TimePoint, A8> *) nullptr)),std::move(*((std::tuple<TimePoint, A9> *) nullptr))))::value_type> {x.environment, { x.timedData.timePoint, std::move(*b), flag0 && flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8 && flag9 } } };
                    } else {
                        return std::nullopt;
                    }
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
static auto kleisli10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> {
    return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>>(
        [f=std::move(f),requireMask=liftParam.requireMask](InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&x) -> Data<typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType> {
            static TimedDataType<A0> a0;
            static TimedDataType<A1> a1;
            static TimedDataType<A2> a2;
            static TimedDataType<A3> a3;
            static TimedDataType<A4> a4;
            static TimedDataType<A5> a5;
            static TimedDataType<A6> a6;
            static TimedDataType<A7> a7;
            static TimedDataType<A8> a8;
            static TimedDataType<A9> a9;
            static FanInParamMask mask;
            switch (x.timedData.value.index()) {
            case 0:
                a0 = {x.timedData.timePoint, std::move(std::get<0>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(0);
                if ((mask & requireMask) == requireMask) {
                    return f(0, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                a1 = {x.timedData.timePoint, std::move(std::get<1>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(1);
                if ((mask & requireMask) == requireMask) {
                    return f(1, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                a2 = {x.timedData.timePoint, std::move(std::get<2>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(2);
                if ((mask & requireMask) == requireMask) {
                    return f(2, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                a3 = {x.timedData.timePoint, std::move(std::get<3>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(3);
                if ((mask & requireMask) == requireMask) {
                    return f(3, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                a4 = {x.timedData.timePoint, std::move(std::get<4>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(4);
                if ((mask & requireMask) == requireMask) {
                    return f(4, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                a5 = {x.timedData.timePoint, std::move(std::get<5>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(5);
                if ((mask & requireMask) == requireMask) {
                    return f(5, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                a6 = {x.timedData.timePoint, std::move(std::get<6>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(6);
                if ((mask & requireMask) == requireMask) {
                    return f(6, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                a7 = {x.timedData.timePoint, std::move(std::get<7>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(7);
                if ((mask & requireMask) == requireMask) {
                    return f(7, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                a8 = {x.timedData.timePoint, std::move(std::get<8>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(8);
                if ((mask & requireMask) == requireMask) {
                    return f(8, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                a9 = {x.timedData.timePoint, std::move(std::get<9>(x.timedData.value)), x.timedData.finalFlag};
                mask.set(9);
                if ((mask & requireMask) == requireMask) {
                    return f(9, InnerData<A0> { x.environment, withtime_utils::makeCopy(a0) }, InnerData<A1> { x.environment, withtime_utils::makeCopy(a1) }, InnerData<A2> { x.environment, withtime_utils::makeCopy(a2) }, InnerData<A3> { x.environment, withtime_utils::makeCopy(a3) }, InnerData<A4> { x.environment, withtime_utils::makeCopy(a4) }, InnerData<A5> { x.environment, withtime_utils::makeCopy(a5) }, InnerData<A6> { x.environment, withtime_utils::makeCopy(a6) }, InnerData<A7> { x.environment, withtime_utils::makeCopy(a7) }, InnerData<A8> { x.environment, withtime_utils::makeCopy(a8) }, InnerData<A9> { x.environment, withtime_utils::makeCopy(a9) });
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
    );
}