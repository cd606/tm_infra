private:
    template <class A0, class A1, bool FireOnceOnly>
    class MergeT2 {
    private:
        std::bitset<2> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1>>> action(InnerData<std::variant<A0,A1>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT2(std::bitset<2> const &requireMask=std::bitset<2> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT2(MergeT2 &&) = default;
        ~MergeT2() {}
    };
    template <class A0, class A1, bool FireOnceOnly>
    using Merge2 = ActionCore<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>,FireOnceOnly,MergeT2<A0,A1, FireOnceOnly>>;
public:
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> merge2(std::bitset<2> const &requireMask=std::bitset<2> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> ( new Merge2<A0,A1,true>(MergeT2<A0,A1,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> ( new Merge2<A0,A1,false>(MergeT2<A0,A1,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, bool FireOnceOnly>
    class MergeT3 {
    private:
        std::bitset<3> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2>>> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT3(std::bitset<3> const &requireMask=std::bitset<3> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT3(MergeT3 &&) = default;
        ~MergeT3() {}
    };
    template <class A0, class A1, class A2, bool FireOnceOnly>
    using Merge3 = ActionCore<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>,FireOnceOnly,MergeT3<A0,A1,A2, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> merge3(std::bitset<3> const &requireMask=std::bitset<3> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> ( new Merge3<A0,A1,A2,true>(MergeT3<A0,A1,A2,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> ( new Merge3<A0,A1,A2,false>(MergeT3<A0,A1,A2,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, bool FireOnceOnly>
    class MergeT4 {
    private:
        std::bitset<4> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT4(std::bitset<4> const &requireMask=std::bitset<4> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT4(MergeT4 &&) = default;
        ~MergeT4() {}
    };
    template <class A0, class A1, class A2, class A3, bool FireOnceOnly>
    using Merge4 = ActionCore<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>,FireOnceOnly,MergeT4<A0,A1,A2,A3, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> merge4(std::bitset<4> const &requireMask=std::bitset<4> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> ( new Merge4<A0,A1,A2,A3,true>(MergeT4<A0,A1,A2,A3,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> ( new Merge4<A0,A1,A2,A3,false>(MergeT4<A0,A1,A2,A3,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, bool FireOnceOnly>
    class MergeT5 {
    private:
        std::bitset<5> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT5(std::bitset<5> const &requireMask=std::bitset<5> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT5(MergeT5 &&) = default;
        ~MergeT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, bool FireOnceOnly>
    using Merge5 = ActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>,FireOnceOnly,MergeT5<A0,A1,A2,A3,A4, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> merge5(std::bitset<5> const &requireMask=std::bitset<5> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> ( new Merge5<A0,A1,A2,A3,A4,true>(MergeT5<A0,A1,A2,A3,A4,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> ( new Merge5<A0,A1,A2,A3,A4,false>(MergeT5<A0,A1,A2,A3,A4,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, bool FireOnceOnly>
    class MergeT6 {
    private:
        std::bitset<6> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT6(std::bitset<6> const &requireMask=std::bitset<6> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT6(MergeT6 &&) = default;
        ~MergeT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, bool FireOnceOnly>
    using Merge6 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>,FireOnceOnly,MergeT6<A0,A1,A2,A3,A4,A5, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> merge6(std::bitset<6> const &requireMask=std::bitset<6> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> ( new Merge6<A0,A1,A2,A3,A4,A5,true>(MergeT6<A0,A1,A2,A3,A4,A5,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> ( new Merge6<A0,A1,A2,A3,A4,A5,false>(MergeT6<A0,A1,A2,A3,A4,A5,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, bool FireOnceOnly>
    class MergeT7 {
    private:
        std::bitset<7> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT7(std::bitset<7> const &requireMask=std::bitset<7> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT7(MergeT7 &&) = default;
        ~MergeT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, bool FireOnceOnly>
    using Merge7 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>,FireOnceOnly,MergeT7<A0,A1,A2,A3,A4,A5,A6, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> merge7(std::bitset<7> const &requireMask=std::bitset<7> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6,true>(MergeT7<A0,A1,A2,A3,A4,A5,A6,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6,false>(MergeT7<A0,A1,A2,A3,A4,A5,A6,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool FireOnceOnly>
    class MergeT8 {
    private:
        std::bitset<8> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT8(std::bitset<8> const &requireMask=std::bitset<8> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT8(MergeT8 &&) = default;
        ~MergeT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool FireOnceOnly>
    using Merge8 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>,FireOnceOnly,MergeT8<A0,A1,A2,A3,A4,A5,A6,A7, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> merge8(std::bitset<8> const &requireMask=std::bitset<8> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7,true>(MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7,false>(MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool FireOnceOnly>
    class MergeT9 {
    private:
        std::bitset<9> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT9(std::bitset<9> const &requireMask=std::bitset<9> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT9(MergeT9 &&) = default;
        ~MergeT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool FireOnceOnly>
    using Merge9 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>,FireOnceOnly,MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> merge9(std::bitset<9> const &requireMask=std::bitset<9> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8,true>(MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8,false>(MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool FireOnceOnly>
    class MergeT10 {
    private:
        std::bitset<10> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT10(std::bitset<10> const &requireMask=std::bitset<10> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT10(MergeT10 &&) = default;
        ~MergeT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool FireOnceOnly>
    using Merge10 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>,FireOnceOnly,MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> merge10(std::bitset<10> const &requireMask=std::bitset<10> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,true>(MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,false>(MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool FireOnceOnly>
    class MergeT11 {
    private:
        std::bitset<11> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT11(std::bitset<11> const &requireMask=std::bitset<11> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT11(MergeT11 &&) = default;
        ~MergeT11() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool FireOnceOnly>
    using Merge11 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>,FireOnceOnly,MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> merge11(std::bitset<11> const &requireMask=std::bitset<11> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> ( new Merge11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,true>(MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> ( new Merge11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,false>(MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool FireOnceOnly>
    class MergeT12 {
    private:
        std::bitset<12> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT12(std::bitset<12> const &requireMask=std::bitset<12> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT12(MergeT12 &&) = default;
        ~MergeT12() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool FireOnceOnly>
    using Merge12 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>,FireOnceOnly,MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> merge12(std::bitset<12> const &requireMask=std::bitset<12> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> ( new Merge12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,true>(MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> ( new Merge12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,false>(MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool FireOnceOnly>
    class MergeT13 {
    private:
        std::bitset<13> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT13(std::bitset<13> const &requireMask=std::bitset<13> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT13(MergeT13 &&) = default;
        ~MergeT13() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool FireOnceOnly>
    using Merge13 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>,FireOnceOnly,MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> merge13(std::bitset<13> const &requireMask=std::bitset<13> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> ( new Merge13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,true>(MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> ( new Merge13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,false>(MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool FireOnceOnly>
    class MergeT14 {
    private:
        std::bitset<14> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT14(std::bitset<14> const &requireMask=std::bitset<14> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT14(MergeT14 &&) = default;
        ~MergeT14() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool FireOnceOnly>
    using Merge14 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>,FireOnceOnly,MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> merge14(std::bitset<14> const &requireMask=std::bitset<14> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> ( new Merge14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,true>(MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> ( new Merge14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,false>(MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool FireOnceOnly>
    class MergeT15 {
    private:
        std::bitset<15> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(14, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {tp, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT15(std::bitset<15> const &requireMask=std::bitset<15> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT15(MergeT15 &&) = default;
        ~MergeT15() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool FireOnceOnly>
    using Merge15 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>,FireOnceOnly,MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> merge15(std::bitset<15> const &requireMask=std::bitset<15> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> ( new Merge15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,true>(MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> ( new Merge15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,false>(MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, bool FireOnceOnly>
    class MergeT16 {
    private:
        std::bitset<16> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(14, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(15, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {tp, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT16(std::bitset<16> const &requireMask=std::bitset<16> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT16(MergeT16 &&) = default;
        ~MergeT16() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, bool FireOnceOnly>
    using Merge16 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>,FireOnceOnly,MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> merge16(std::bitset<16> const &requireMask=std::bitset<16> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> ( new Merge16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,true>(MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> ( new Merge16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,false>(MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, bool FireOnceOnly>
    class MergeT17 {
    private:
        std::bitset<17> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(14, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(15, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(16, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {tp, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT17(std::bitset<17> const &requireMask=std::bitset<17> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT17(MergeT17 &&) = default;
        ~MergeT17() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, bool FireOnceOnly>
    using Merge17 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>,FireOnceOnly,MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> merge17(std::bitset<17> const &requireMask=std::bitset<17> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> ( new Merge17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,true>(MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> ( new Merge17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,false>(MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, bool FireOnceOnly>
    class MergeT18 {
    private:
        std::bitset<18> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(14, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(15, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(16, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 17:
                std::get<17>(val_) = std::move(std::get<17>(data.timedData.value));
                mask_.set(17);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(17, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {tp, {17, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT18(std::bitset<18> const &requireMask=std::bitset<18> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT18(MergeT18 &&) = default;
        ~MergeT18() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, bool FireOnceOnly>
    using Merge18 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>,FireOnceOnly,MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> merge18(std::bitset<18> const &requireMask=std::bitset<18> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> ( new Merge18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,true>(MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> ( new Merge18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,false>(MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, bool FireOnceOnly>
    class MergeT19 {
    private:
        std::bitset<19> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(14, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(15, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(16, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 17:
                std::get<17>(val_) = std::move(std::get<17>(data.timedData.value));
                mask_.set(17);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(17, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {17, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 18:
                std::get<18>(val_) = std::move(std::get<18>(data.timedData.value));
                mask_.set(18);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(18, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {tp, {18, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT19(std::bitset<19> const &requireMask=std::bitset<19> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT19(MergeT19 &&) = default;
        ~MergeT19() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, bool FireOnceOnly>
    using Merge19 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>,FireOnceOnly,MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> merge19(std::bitset<19> const &requireMask=std::bitset<19> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> ( new Merge19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,true>(MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> ( new Merge19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,false>(MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,false>(requireMask,liftParam.delaySimulator)) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, bool FireOnceOnly>
    class MergeT20 {
    private:
        std::bitset<20> mask_, requireMask_;
        DelaySimulator delaySimulator_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(0, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(1, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(2, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(3, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(4, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(5, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(6, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(7, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(8, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(9, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(10, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(11, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(12, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(13, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(14, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(15, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(16, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 17:
                std::get<17>(val_) = std::move(std::get<17>(data.timedData.value));
                mask_.set(17);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(17, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {17, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 18:
                std::get<18>(val_) = std::move(std::get<18>(data.timedData.value));
                mask_.set(18);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(18, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {18, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 19:
                std::get<19>(val_) = std::move(std::get<19>(data.timedData.value));
                mask_.set(19);
                if ((mask_ & requireMask_) == requireMask_) {
                    auto tp = data.timedData.timePoint;
                    if (delaySimulator_) {
                        tp += (*delaySimulator_)(19, tp);
                    }
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {tp, {19, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        MergeT20(std::bitset<20> const &requireMask=std::bitset<20> {}, DelaySimulator const &delaySimulator=std::nullopt) : delaySimulator_(delaySimulator), val_() {}
        MergeT20(MergeT20 &&) = default;
        ~MergeT20() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, bool FireOnceOnly>
    using Merge20 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>,FireOnceOnly,MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> merge20(std::bitset<20> const &requireMask=std::bitset<20> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> ( new Merge20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,true>(MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,true>(requireMask,liftParam.delaySimulator)) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> ( new Merge20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,false>(MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,false>(requireMask,liftParam.delaySimulator)) );
        }
    }