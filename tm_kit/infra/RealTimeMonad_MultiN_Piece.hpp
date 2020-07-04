private:
    template <class A0, class A1, class B, class F, bool Threaded>
    class Multi2 final : public MultiActionCore<std::variant<A0,A1>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi2(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto liftMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded>
    class Multi3 final : public MultiActionCore<std::variant<A0,A1,A2>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi3(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto liftMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded>
    class Multi4 final : public MultiActionCore<std::variant<A0,A1,A2,A3>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi4(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded>
    class Multi5 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a4.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi5(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded>
    class Multi6 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a4.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a5.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi6(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded>
    class Multi7 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a4.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a5.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a6.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi7(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded>
    class Multi8 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a4.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a5.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a6.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 7:
                {
                    auto ret = f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a7.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi8(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded>
    class Multi9 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a4.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a5.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a6.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 7:
                {
                    auto ret = f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a7.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 8:
                {
                    auto ret = f_(8, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a8.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi9(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded>
    class Multi10 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a0.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a1.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a2.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a3.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a4.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a5.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a6.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 7:
                {
                    auto ret = f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a7.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 8:
                {
                    auto ret = f_(8, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a8.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 9:
                {
                    auto ret = f_(9, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (!ret.empty()) {
                        return pureInnerData(env, WithTime<std::vector<B>,TimePoint> {a9.timePoint, std::move(ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            default:
                return std::nullopt;
            }
        }
    public:
        Multi10(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Multi10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }