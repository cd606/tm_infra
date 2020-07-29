private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli2 final : public ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) });
        }
    public:
        Kleisli2(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto kleisli2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli3 final : public ActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) });
        }
    public:
        Kleisli3(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto kleisli3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli4 final : public ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) });
        }
    public:
        Kleisli4(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto kleisli4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) });
        }
    public:
        Kleisli5(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto kleisli5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) });
        }
    public:
        Kleisli6(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto kleisli6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) });
        }
    public:
        Kleisli7(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto kleisli7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) }, InnerData<A7> { env, std::move(a7) });
        }
    public:
        Kleisli8(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto kleisli8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) }, InnerData<A7> { env, std::move(a7) }, InnerData<A8> { env, std::move(a8) });
        }
    public:
        Kleisli9(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto kleisli9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class Kleisli10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) }, InnerData<A7> { env, std::move(a7) }, InnerData<A8> { env, std::move(a8) }, InnerData<A9> { env, std::move(a9) });
        }
    public:
        Kleisli10(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded,FireOnceOnly>(requireMask), f_(std::move(f)) {}
        virtual ~Kleisli10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto kleisli10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f), liftParam.requireMask) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f), liftParam.requireMask) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f), liftParam.requireMask) );
            }
        }
    }