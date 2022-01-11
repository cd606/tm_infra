private:
    template <class A0, class A1,bool Threaded, bool FireOnceOnly>
    class MergeT2 {
    private:
        std::bitset<2> mask_, requireMask_;
        std::tuple<A0,A1> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1>>> action(InnerData<std::variant<A0,A1>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT2(std::bitset<2> const &requireMask=std::bitset<2> {}) : mask_(), requireMask_(requireMask) {}
        MergeT2(MergeT2 &&) = default;
        ~MergeT2() {}
    };
    template <class A0, class A1,bool Threaded, bool FireOnceOnly>
    using Merge2 = ActionCore<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>,Threaded,FireOnceOnly,MergeT2<A0,A1,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> merge2(std::bitset<2> const &requireMask=std::bitset<2> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> ( new Merge2<A0,A1,true,true>(MergeT2<A0,A1,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> ( new Merge2<A0,A1,true,false>(MergeT2<A0,A1,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> ( new Merge2<A0,A1,false,true>(MergeT2<A0,A1,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,std::tuple<std::size_t,std::tuple<A0,A1>>>> ( new Merge2<A0,A1,false,false>(MergeT2<A0,A1,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2,bool Threaded, bool FireOnceOnly>
    class MergeT3 {
    private:
        std::bitset<3> mask_, requireMask_;
        std::tuple<A0,A1,A2> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2>>> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT3(std::bitset<3> const &requireMask=std::bitset<3> {}) : mask_(), requireMask_(requireMask) {}
        MergeT3(MergeT3 &&) = default;
        ~MergeT3() {}
    };
    template <class A0, class A1, class A2,bool Threaded, bool FireOnceOnly>
    using Merge3 = ActionCore<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>,Threaded,FireOnceOnly,MergeT3<A0,A1,A2,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> merge3(std::bitset<3> const &requireMask=std::bitset<3> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> ( new Merge3<A0,A1,A2,true,true>(MergeT3<A0,A1,A2,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> ( new Merge3<A0,A1,A2,true,false>(MergeT3<A0,A1,A2,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> ( new Merge3<A0,A1,A2,false,true>(MergeT3<A0,A1,A2,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<std::size_t,std::tuple<A0,A1,A2>>>> ( new Merge3<A0,A1,A2,false,false>(MergeT3<A0,A1,A2,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3,bool Threaded, bool FireOnceOnly>
    class MergeT4 {
    private:
        std::bitset<4> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT4(std::bitset<4> const &requireMask=std::bitset<4> {}) : mask_(), requireMask_(requireMask) {}
        MergeT4(MergeT4 &&) = default;
        ~MergeT4() {}
    };
    template <class A0, class A1, class A2, class A3,bool Threaded, bool FireOnceOnly>
    using Merge4 = ActionCore<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>,Threaded,FireOnceOnly,MergeT4<A0,A1,A2,A3,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> merge4(std::bitset<4> const &requireMask=std::bitset<4> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> ( new Merge4<A0,A1,A2,A3,true,true>(MergeT4<A0,A1,A2,A3,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> ( new Merge4<A0,A1,A2,A3,true,false>(MergeT4<A0,A1,A2,A3,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> ( new Merge4<A0,A1,A2,A3,false,true>(MergeT4<A0,A1,A2,A3,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3>>>> ( new Merge4<A0,A1,A2,A3,false,false>(MergeT4<A0,A1,A2,A3,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4,bool Threaded, bool FireOnceOnly>
    class MergeT5 {
    private:
        std::bitset<5> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT5(std::bitset<5> const &requireMask=std::bitset<5> {}) : mask_(), requireMask_(requireMask) {}
        MergeT5(MergeT5 &&) = default;
        ~MergeT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4,bool Threaded, bool FireOnceOnly>
    using Merge5 = ActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>,Threaded,FireOnceOnly,MergeT5<A0,A1,A2,A3,A4,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> merge5(std::bitset<5> const &requireMask=std::bitset<5> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> ( new Merge5<A0,A1,A2,A3,A4,true,true>(MergeT5<A0,A1,A2,A3,A4,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> ( new Merge5<A0,A1,A2,A3,A4,true,false>(MergeT5<A0,A1,A2,A3,A4,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> ( new Merge5<A0,A1,A2,A3,A4,false,true>(MergeT5<A0,A1,A2,A3,A4,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4>>>> ( new Merge5<A0,A1,A2,A3,A4,false,false>(MergeT5<A0,A1,A2,A3,A4,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5,bool Threaded, bool FireOnceOnly>
    class MergeT6 {
    private:
        std::bitset<6> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT6(std::bitset<6> const &requireMask=std::bitset<6> {}) : mask_(), requireMask_(requireMask) {}
        MergeT6(MergeT6 &&) = default;
        ~MergeT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5,bool Threaded, bool FireOnceOnly>
    using Merge6 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>,Threaded,FireOnceOnly,MergeT6<A0,A1,A2,A3,A4,A5,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> merge6(std::bitset<6> const &requireMask=std::bitset<6> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> ( new Merge6<A0,A1,A2,A3,A4,A5,true,true>(MergeT6<A0,A1,A2,A3,A4,A5,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> ( new Merge6<A0,A1,A2,A3,A4,A5,true,false>(MergeT6<A0,A1,A2,A3,A4,A5,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> ( new Merge6<A0,A1,A2,A3,A4,A5,false,true>(MergeT6<A0,A1,A2,A3,A4,A5,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5>>>> ( new Merge6<A0,A1,A2,A3,A4,A5,false,false>(MergeT6<A0,A1,A2,A3,A4,A5,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6,bool Threaded, bool FireOnceOnly>
    class MergeT7 {
    private:
        std::bitset<7> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT7(std::bitset<7> const &requireMask=std::bitset<7> {}) : mask_(), requireMask_(requireMask) {}
        MergeT7(MergeT7 &&) = default;
        ~MergeT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6,bool Threaded, bool FireOnceOnly>
    using Merge7 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>,Threaded,FireOnceOnly,MergeT7<A0,A1,A2,A3,A4,A5,A6,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> merge7(std::bitset<7> const &requireMask=std::bitset<7> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6,true,true>(MergeT7<A0,A1,A2,A3,A4,A5,A6,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6,true,false>(MergeT7<A0,A1,A2,A3,A4,A5,A6,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6,false,true>(MergeT7<A0,A1,A2,A3,A4,A5,A6,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6>>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6,false,false>(MergeT7<A0,A1,A2,A3,A4,A5,A6,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,bool Threaded, bool FireOnceOnly>
    class MergeT8 {
    private:
        std::bitset<8> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT8(std::bitset<8> const &requireMask=std::bitset<8> {}) : mask_(), requireMask_(requireMask) {}
        MergeT8(MergeT8 &&) = default;
        ~MergeT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7,bool Threaded, bool FireOnceOnly>
    using Merge8 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>,Threaded,FireOnceOnly,MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> merge8(std::bitset<8> const &requireMask=std::bitset<8> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7,true,true>(MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7,true,false>(MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7,false,true>(MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7,false,false>(MergeT8<A0,A1,A2,A3,A4,A5,A6,A7,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8,bool Threaded, bool FireOnceOnly>
    class MergeT9 {
    private:
        std::bitset<9> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT9(std::bitset<9> const &requireMask=std::bitset<9> {}) : mask_(), requireMask_(requireMask) {}
        MergeT9(MergeT9 &&) = default;
        ~MergeT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8,bool Threaded, bool FireOnceOnly>
    using Merge9 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>,Threaded,FireOnceOnly,MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> merge9(std::bitset<9> const &requireMask=std::bitset<9> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8,true,true>(MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8,true,false>(MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8,false,true>(MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8,false,false>(MergeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,bool Threaded, bool FireOnceOnly>
    class MergeT10 {
    private:
        std::bitset<10> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT10(std::bitset<10> const &requireMask=std::bitset<10> {}) : mask_(), requireMask_(requireMask) {}
        MergeT10(MergeT10 &&) = default;
        ~MergeT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9,bool Threaded, bool FireOnceOnly>
    using Merge10 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>,Threaded,FireOnceOnly,MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> merge10(std::bitset<10> const &requireMask=std::bitset<10> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,true,true>(MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,true,false>(MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,false,true>(MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,false,false>(MergeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10,bool Threaded, bool FireOnceOnly>
    class MergeT11 {
    private:
        std::bitset<11> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT11(std::bitset<11> const &requireMask=std::bitset<11> {}) : mask_(), requireMask_(requireMask) {}
        MergeT11(MergeT11 &&) = default;
        ~MergeT11() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10,bool Threaded, bool FireOnceOnly>
    using Merge11 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>,Threaded,FireOnceOnly,MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> merge11(std::bitset<11> const &requireMask=std::bitset<11> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> ( new Merge11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,true,true>(MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> ( new Merge11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,true,false>(MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> ( new Merge11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,false,true>(MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>>>> ( new Merge11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,false,false>(MergeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11,bool Threaded, bool FireOnceOnly>
    class MergeT12 {
    private:
        std::bitset<12> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT12(std::bitset<12> const &requireMask=std::bitset<12> {}) : mask_(), requireMask_(requireMask) {}
        MergeT12(MergeT12 &&) = default;
        ~MergeT12() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11,bool Threaded, bool FireOnceOnly>
    using Merge12 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>,Threaded,FireOnceOnly,MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> merge12(std::bitset<12> const &requireMask=std::bitset<12> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> ( new Merge12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,true,true>(MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> ( new Merge12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,true,false>(MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> ( new Merge12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,false,true>(MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>>>> ( new Merge12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,false,false>(MergeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12,bool Threaded, bool FireOnceOnly>
    class MergeT13 {
    private:
        std::bitset<13> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT13(std::bitset<13> const &requireMask=std::bitset<13> {}) : mask_(), requireMask_(requireMask) {}
        MergeT13(MergeT13 &&) = default;
        ~MergeT13() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12,bool Threaded, bool FireOnceOnly>
    using Merge13 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>,Threaded,FireOnceOnly,MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> merge13(std::bitset<13> const &requireMask=std::bitset<13> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> ( new Merge13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,true,true>(MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> ( new Merge13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,true,false>(MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> ( new Merge13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,false,true>(MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>>>> ( new Merge13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,false,false>(MergeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13,bool Threaded, bool FireOnceOnly>
    class MergeT14 {
    private:
        std::bitset<14> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT14(std::bitset<14> const &requireMask=std::bitset<14> {}) : mask_(), requireMask_(requireMask) {}
        MergeT14(MergeT14 &&) = default;
        ~MergeT14() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13,bool Threaded, bool FireOnceOnly>
    using Merge14 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>,Threaded,FireOnceOnly,MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> merge14(std::bitset<14> const &requireMask=std::bitset<14> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> ( new Merge14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,true,true>(MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> ( new Merge14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,true,false>(MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> ( new Merge14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,false,true>(MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>>>> ( new Merge14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,false,false>(MergeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14,bool Threaded, bool FireOnceOnly>
    class MergeT15 {
    private:
        std::bitset<15> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>> {data.environment, {data.timedData.timePoint, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT15(std::bitset<15> const &requireMask=std::bitset<15> {}) : mask_(), requireMask_(requireMask) {}
        MergeT15(MergeT15 &&) = default;
        ~MergeT15() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14,bool Threaded, bool FireOnceOnly>
    using Merge15 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>,Threaded,FireOnceOnly,MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> merge15(std::bitset<15> const &requireMask=std::bitset<15> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> ( new Merge15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,true,true>(MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> ( new Merge15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,true,false>(MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> ( new Merge15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,false,true>(MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>>>> ( new Merge15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,false,false>(MergeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15,bool Threaded, bool FireOnceOnly>
    class MergeT16 {
    private:
        std::bitset<16> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>> {data.environment, {data.timedData.timePoint, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT16(std::bitset<16> const &requireMask=std::bitset<16> {}) : mask_(), requireMask_(requireMask) {}
        MergeT16(MergeT16 &&) = default;
        ~MergeT16() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15,bool Threaded, bool FireOnceOnly>
    using Merge16 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>,Threaded,FireOnceOnly,MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> merge16(std::bitset<16> const &requireMask=std::bitset<16> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> ( new Merge16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,true,true>(MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> ( new Merge16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,true,false>(MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> ( new Merge16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,false,true>(MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>>>> ( new Merge16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,false,false>(MergeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16,bool Threaded, bool FireOnceOnly>
    class MergeT17 {
    private:
        std::bitset<17> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>> {data.environment, {data.timedData.timePoint, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT17(std::bitset<17> const &requireMask=std::bitset<17> {}) : mask_(), requireMask_(requireMask) {}
        MergeT17(MergeT17 &&) = default;
        ~MergeT17() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16,bool Threaded, bool FireOnceOnly>
    using Merge17 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>,Threaded,FireOnceOnly,MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> merge17(std::bitset<17> const &requireMask=std::bitset<17> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> ( new Merge17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,true,true>(MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> ( new Merge17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,true,false>(MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> ( new Merge17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,false,true>(MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>>>> ( new Merge17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,false,false>(MergeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17,bool Threaded, bool FireOnceOnly>
    class MergeT18 {
    private:
        std::bitset<18> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 17:
                std::get<17>(val_) = std::move(std::get<17>(data.timedData.value));
                mask_.set(17);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>> {data.environment, {data.timedData.timePoint, {17, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT18(std::bitset<18> const &requireMask=std::bitset<18> {}) : mask_(), requireMask_(requireMask) {}
        MergeT18(MergeT18 &&) = default;
        ~MergeT18() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17,bool Threaded, bool FireOnceOnly>
    using Merge18 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>,Threaded,FireOnceOnly,MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> merge18(std::bitset<18> const &requireMask=std::bitset<18> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> ( new Merge18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,true,true>(MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> ( new Merge18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,true,false>(MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> ( new Merge18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,false,true>(MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>>>> ( new Merge18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,false,false>(MergeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18,bool Threaded, bool FireOnceOnly>
    class MergeT19 {
    private:
        std::bitset<19> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 17:
                std::get<17>(val_) = std::move(std::get<17>(data.timedData.value));
                mask_.set(17);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {17, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 18:
                std::get<18>(val_) = std::move(std::get<18>(data.timedData.value));
                mask_.set(18);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>> {data.environment, {data.timedData.timePoint, {18, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT19(std::bitset<19> const &requireMask=std::bitset<19> {}) : mask_(), requireMask_(requireMask) {}
        MergeT19(MergeT19 &&) = default;
        ~MergeT19() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18,bool Threaded, bool FireOnceOnly>
    using Merge19 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>,Threaded,FireOnceOnly,MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> merge19(std::bitset<19> const &requireMask=std::bitset<19> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> ( new Merge19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,true,true>(MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> ( new Merge19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,true,false>(MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> ( new Merge19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,false,true>(MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>>>> ( new Merge19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,false,false>(MergeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,false,false>(requireMask)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19,bool Threaded, bool FireOnceOnly>
    class MergeT20 {
    private:
        std::bitset<20> mask_, requireMask_;
        std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> val_;
    public:
        Data<std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
            switch (data.timedData.value.index()) {
            case 0:
                std::get<0>(val_) = std::move(std::get<0>(data.timedData.value));
                mask_.set(0);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {0, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 1:
                std::get<1>(val_) = std::move(std::get<1>(data.timedData.value));
                mask_.set(1);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {1, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 2:
                std::get<2>(val_) = std::move(std::get<2>(data.timedData.value));
                mask_.set(2);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {2, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 3:
                std::get<3>(val_) = std::move(std::get<3>(data.timedData.value));
                mask_.set(3);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {3, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 4:
                std::get<4>(val_) = std::move(std::get<4>(data.timedData.value));
                mask_.set(4);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {4, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 5:
                std::get<5>(val_) = std::move(std::get<5>(data.timedData.value));
                mask_.set(5);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {5, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 6:
                std::get<6>(val_) = std::move(std::get<6>(data.timedData.value));
                mask_.set(6);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {6, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 7:
                std::get<7>(val_) = std::move(std::get<7>(data.timedData.value));
                mask_.set(7);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {7, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 8:
                std::get<8>(val_) = std::move(std::get<8>(data.timedData.value));
                mask_.set(8);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {8, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 9:
                std::get<9>(val_) = std::move(std::get<9>(data.timedData.value));
                mask_.set(9);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {9, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 10:
                std::get<10>(val_) = std::move(std::get<10>(data.timedData.value));
                mask_.set(10);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {10, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 11:
                std::get<11>(val_) = std::move(std::get<11>(data.timedData.value));
                mask_.set(11);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {11, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 12:
                std::get<12>(val_) = std::move(std::get<12>(data.timedData.value));
                mask_.set(12);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {12, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 13:
                std::get<13>(val_) = std::move(std::get<13>(data.timedData.value));
                mask_.set(13);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {13, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 14:
                std::get<14>(val_) = std::move(std::get<14>(data.timedData.value));
                mask_.set(14);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {14, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 15:
                std::get<15>(val_) = std::move(std::get<15>(data.timedData.value));
                mask_.set(15);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {15, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 16:
                std::get<16>(val_) = std::move(std::get<16>(data.timedData.value));
                mask_.set(16);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {16, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 17:
                std::get<17>(val_) = std::move(std::get<17>(data.timedData.value));
                mask_.set(17);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {17, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 18:
                std::get<18>(val_) = std::move(std::get<18>(data.timedData.value));
                mask_.set(18);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {18, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            case 19:
                std::get<19>(val_) = std::move(std::get<19>(data.timedData.value));
                mask_.set(19);
                if ((mask_ & requireMask_) == requireMask_) {
                    return InnerData<std::tuple<std::size_t, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>> {data.environment, {data.timedData.timePoint, {19, withtime_utils::makeValueCopy(val_)}, data.timedData.finalFlag}};
                } else {
                    return std::nullopt;
                }
                break;
            default:
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return nullptr;
        }
    public:
        MergeT20(std::bitset<20> const &requireMask=std::bitset<20> {}) : mask_(), requireMask_(requireMask) {}
        MergeT20(MergeT20 &&) = default;
        ~MergeT20() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19,bool Threaded, bool FireOnceOnly>
    using Merge20 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>,Threaded,FireOnceOnly,MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> merge20(std::bitset<20> const &requireMask=std::bitset<20> {}, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
        if (liftParam.suggestThreaded) {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> ( new Merge20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,true,true>(MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,true,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> ( new Merge20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,true,false>(MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,true,false>(requireMask)) );
            }
        } else {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> ( new Merge20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,false,true>(MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,false,true>(requireMask)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,std::tuple<std::size_t,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>>>> ( new Merge20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,false,false>(MergeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,false,false>(requireMask)) );
            }
        }
    }