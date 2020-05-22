private:
    template <class A0, class A1, class B, class F, bool Threaded>
    class Pure2 final : public ActionCore<std::variant<A0,A1>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value)), (a0.finalFlag && a1.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value)), (a0.finalFlag && a1.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure2(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto liftPure2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded>
    class Pure3 final : public ActionCore<std::variant<A0,A1,A2>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure3(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto liftPure3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded>
    class Pure4 final : public ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure4(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftPure4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded>
    class Pure5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure5(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftPure5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded>
    class Pure6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure6(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftPure6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded>
    class Pure7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure7(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftPure7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded>
    class Pure8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 7:
                return pureInnerData(env, WithTime<B,TimePoint> {a7.timePoint, f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure8(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftPure8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded>
    class Pure9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 7:
                return pureInnerData(env, WithTime<B,TimePoint> {a7.timePoint, f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 8:
                return pureInnerData(env, WithTime<B,TimePoint> {a8.timePoint, f_(8, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure9(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftPure9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded>
    class Pure10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<B,TimePoint> {a0.timePoint, f_(0, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<B,TimePoint> {a1.timePoint, f_(1, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<B,TimePoint> {a2.timePoint, f_(2, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<B,TimePoint> {a3.timePoint, f_(3, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<B,TimePoint> {a4.timePoint, f_(4, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<B,TimePoint> {a5.timePoint, f_(5, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<B,TimePoint> {a6.timePoint, f_(6, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 7:
                return pureInnerData(env, WithTime<B,TimePoint> {a7.timePoint, f_(7, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 8:
                return pureInnerData(env, WithTime<B,TimePoint> {a8.timePoint, f_(8, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 9:
                return pureInnerData(env, WithTime<B,TimePoint> {a9.timePoint, f_(9, std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)), (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Pure10(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~Pure10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftPure10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr)))),F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(0,std::move(*((A0 *) nullptr)),std::move(*((A1 *) nullptr)),std::move(*((A2 *) nullptr)),std::move(*((A3 *) nullptr)),std::move(*((A4 *) nullptr)),std::move(*((A5 *) nullptr)),std::move(*((A6 *) nullptr)),std::move(*((A7 *) nullptr)),std::move(*((A8 *) nullptr)),std::move(*((A9 *) nullptr)))),F,false>(std::move(f), liftParam.requireMask) );
        }
    }