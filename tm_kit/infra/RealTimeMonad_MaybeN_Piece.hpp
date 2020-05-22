private:
    template <class A0, class A1, class B, class F, bool Threaded>
    class Maybe2 final : public ActionCore<std::variant<A0,A1>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag)});
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
        Maybe2(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto liftMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> ( new Maybe2<A0,A1,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type>> ( new Maybe2<A0,A1,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded>
    class Maybe3 final : public ActionCore<std::variant<A0,A1,A2>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
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
        Maybe3(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto liftMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> ( new Maybe3<A0,A1,A2,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type>> ( new Maybe3<A0,A1,A2,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded>
    class Maybe4 final : public ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
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
        Maybe4(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> ( new Maybe4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type>> ( new Maybe4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded>
    class Maybe5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
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
        Maybe5(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> ( new Maybe5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type>> ( new Maybe5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded>
    class Maybe6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
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
        Maybe6(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> ( new Maybe6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type>> ( new Maybe6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded>
    class Maybe7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
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
        Maybe7(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> ( new Maybe7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type>> ( new Maybe7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded>
    class Maybe8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 7:
                {
                    auto ret = f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a7.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
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
        Maybe8(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> ( new Maybe8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type>> ( new Maybe8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded>
    class Maybe9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 7:
                {
                    auto ret = f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a7.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 8:
                {
                    auto ret = f_(8, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a8.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
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
        Maybe9(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> ( new Maybe9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type>> ( new Maybe9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded>
    class Maybe10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) override final {
            switch (which) {
            case 0:
                {
                    auto ret = f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 1:
                {
                    auto ret = f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 2:
                {
                    auto ret = f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 3:
                {
                    auto ret = f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 4:
                {
                    auto ret = f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 5:
                {
                    auto ret = f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 6:
                {
                    auto ret = f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 7:
                {
                    auto ret = f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a7.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 8:
                {
                    auto ret = f_(8, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a8.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
                    } else {
                        return std::nullopt;
                    }
                }
                break;
            case 9:
                {
                    auto ret = f_(9, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value));
                    if (ret) {
                        return pureInnerData(env, WithTime<B,TimePoint> {a9.timePoint, std::move(*ret), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
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
        Maybe10(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Maybe10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> ( new Maybe10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type>> ( new Maybe10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }