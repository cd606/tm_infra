private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT2 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT2(F &&f) : f_(std::move(f)) {}
        ~KleisliT2() {}
    };
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli2 = ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly,KleisliT2<A0,A1,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto kleisli2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT3 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT3(F &&f) : f_(std::move(f)) {}
        ~KleisliT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli3 = ActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly,KleisliT3<A0,A1,A2,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto kleisli3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT4 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT4(F &&f) : f_(std::move(f)) {}
        ~KleisliT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli4 = ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly,KleisliT4<A0,A1,A2,A3,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto kleisli4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT5 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT5(F &&f) : f_(std::move(f)) {}
        ~KleisliT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli5 = ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly,KleisliT5<A0,A1,A2,A3,A4,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto kleisli5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT6 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT6(F &&f) : f_(std::move(f)) {}
        ~KleisliT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli6 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly,KleisliT6<A0,A1,A2,A3,A4,A5,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto kleisli6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT7 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT7(F &&f) : f_(std::move(f)) {}
        ~KleisliT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli7 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly,KleisliT7<A0,A1,A2,A3,A4,A5,A6,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto kleisli7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT8 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT8(F &&f) : f_(std::move(f)) {}
        ~KleisliT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli8 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly,KleisliT8<A0,A1,A2,A3,A4,A5,A6,A7,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto kleisli8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT9 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT9(F &&f) : f_(std::move(f)) {}
        ~KleisliT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli9 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly,KleisliT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto kleisli9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT10 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT10(F &&f) : f_(std::move(f)) {}
        ~KleisliT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli10 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly,KleisliT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto kleisli10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT11 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT11(F &&f) : f_(std::move(f)) {}
        ~KleisliT11() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli11 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, B, Threaded, FireOnceOnly,KleisliT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class F>
    static auto kleisli11(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType>> ( new Kleisli11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType>> ( new Kleisli11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType>> ( new Kleisli11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType>> ( new Kleisli11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT12 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT12(F &&f) : f_(std::move(f)) {}
        ~KleisliT12() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli12 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, B, Threaded, FireOnceOnly,KleisliT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class F>
    static auto kleisli12(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType>> ( new Kleisli12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType>> ( new Kleisli12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType>> ( new Kleisli12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType>> ( new Kleisli12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT13 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT13(F &&f) : f_(std::move(f)) {}
        ~KleisliT13() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli13 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, B, Threaded, FireOnceOnly,KleisliT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class F>
    static auto kleisli13(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType>> ( new Kleisli13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType>> ( new Kleisli13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType>> ( new Kleisli13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType>> ( new Kleisli13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT14 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT14(F &&f) : f_(std::move(f)) {}
        ~KleisliT14() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli14 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, B, Threaded, FireOnceOnly,KleisliT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class F>
    static auto kleisli14(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType>> ( new Kleisli14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType>> ( new Kleisli14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType>> ( new Kleisli14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType>> ( new Kleisli14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT15 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT15(F &&f) : f_(std::move(f)) {}
        ~KleisliT15() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli15 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, B, Threaded, FireOnceOnly,KleisliT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class F>
    static auto kleisli15(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType>> ( new Kleisli15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType>> ( new Kleisli15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType>> ( new Kleisli15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType>> ( new Kleisli15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT16 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT16(F &&f) : f_(std::move(f)) {}
        ~KleisliT16() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli16 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, B, Threaded, FireOnceOnly,KleisliT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class F>
    static auto kleisli16(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType>> ( new Kleisli16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType>> ( new Kleisli16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType>> ( new Kleisli16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType>> ( new Kleisli16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT17 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT17(F &&f) : f_(std::move(f)) {}
        ~KleisliT17() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli17 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, B, Threaded, FireOnceOnly,KleisliT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class F>
    static auto kleisli17(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType>> ( new Kleisli17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType>> ( new Kleisli17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType>> ( new Kleisli17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType>> ( new Kleisli17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT18 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT18(F &&f) : f_(std::move(f)) {}
        ~KleisliT18() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli18 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, B, Threaded, FireOnceOnly,KleisliT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class F>
    static auto kleisli18(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType>> ( new Kleisli18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType>> ( new Kleisli18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType>> ( new Kleisli18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType>> ( new Kleisli18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT19 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT19(F &&f) : f_(std::move(f)) {}
        ~KleisliT19() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli19 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, B, Threaded, FireOnceOnly,KleisliT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class F>
    static auto kleisli19(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType>> ( new Kleisli19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType>> ( new Kleisli19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType>> ( new Kleisli19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType>> ( new Kleisli19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliT20 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliT20(F &&f) : f_(std::move(f)) {}
        ~KleisliT20() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool Threaded, bool FireOnceOnly>
    using Kleisli20 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, B, Threaded, FireOnceOnly,KleisliT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class F>
    static auto kleisli20(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType>> ( new Kleisli20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType>> ( new Kleisli20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType>> ( new Kleisli20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType>> ( new Kleisli20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType,F,false,false>(std::move(f)) );
            }
        }
    }
public:
    template <class A, class F>
    static auto kleisli(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((InnerData<A> *) nullptr))))::value_type::ValueType>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return kleisli1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return kleisli2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return kleisli3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return kleisli4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return kleisli5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return kleisli6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return kleisli7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return kleisli8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return kleisli9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return kleisli10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 11) {
            return kleisli11<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 12) {
            return kleisli12<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 13) {
            return kleisli13<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 14) {
            return kleisli14<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 15) {
            return kleisli15<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 16) {
            return kleisli16<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 17) {
            return kleisli17<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 18) {
            return kleisli18<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 19) {
            return kleisli19<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 20) {
            return kleisli20<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, std::variant_alternative_t<19,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("kleisli: bad template parameter");
        }
    }