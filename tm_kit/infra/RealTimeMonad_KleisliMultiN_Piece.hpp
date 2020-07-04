private:
    template <class A0, class A1, class B, class F, bool Threaded>
    class KleisliMulti2 final : public MultiActionCore<std::variant<A0,A1>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) });
        }
    public:
        KleisliMulti2(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto kleisliMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded>
    class KleisliMulti3 final : public MultiActionCore<std::variant<A0,A1,A2>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) });
        }
    public:
        KleisliMulti3(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto kleisliMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded>
    class KleisliMulti4 final : public MultiActionCore<std::variant<A0,A1,A2,A3>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) });
        }
    public:
        KleisliMulti4(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto kleisliMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded>
    class KleisliMulti5 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) });
        }
    public:
        KleisliMulti5(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto kleisliMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded>
    class KleisliMulti6 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) });
        }
    public:
        KleisliMulti6(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto kleisliMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded>
    class KleisliMulti7 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) });
        }
    public:
        KleisliMulti7(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto kleisliMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded>
    class KleisliMulti8 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) }, InnerData<A7> { env, std::move(a7) });
        }
    public:
        KleisliMulti8(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto kleisliMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded>
    class KleisliMulti9 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) }, InnerData<A7> { env, std::move(a7) }, InnerData<A8> { env, std::move(a8) });
        }
    public:
        KleisliMulti9(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto kleisliMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded>
    class KleisliMulti10 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) override final {
            return f_(which, InnerData<A0> { env, std::move(a0) }, InnerData<A1> { env, std::move(a1) }, InnerData<A2> { env, std::move(a2) }, InnerData<A3> { env, std::move(a3) }, InnerData<A4> { env, std::move(a4) }, InnerData<A5> { env, std::move(a5) }, InnerData<A6> { env, std::move(a6) }, InnerData<A7> { env, std::move(a7) }, InnerData<A8> { env, std::move(a8) }, InnerData<A9> { env, std::move(a9) });
        }
    public:
        KleisliMulti10(F &&f, FanInParamMask const &requireMask=FanInParamMask()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded>(requireMask), f_(std::move(f)) {}
        virtual ~KleisliMulti10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto kleisliMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.suggestThreaded) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.requireMask) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(0,std::move(*((InnerData<A0> *) nullptr)),std::move(*((InnerData<A1> *) nullptr)),std::move(*((InnerData<A2> *) nullptr)),std::move(*((InnerData<A3> *) nullptr)),std::move(*((InnerData<A4> *) nullptr)),std::move(*((InnerData<A5> *) nullptr)),std::move(*((InnerData<A6> *) nullptr)),std::move(*((InnerData<A7> *) nullptr)),std::move(*((InnerData<A8> *) nullptr)),std::move(*((InnerData<A9> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.requireMask) );
        }
    }