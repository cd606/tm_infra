private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT2 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT2(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT2() {}
    };
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti2 = MultiActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly,KleisliMultiT2<A0,A1,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto kleisliMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT3 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT3(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti3 = MultiActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly,KleisliMultiT3<A0,A1,A2,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto kleisliMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT4 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT4(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti4 = MultiActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly,KleisliMultiT4<A0,A1,A2,A3,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto kleisliMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT5 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT5(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti5 = MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly,KleisliMultiT5<A0,A1,A2,A3,A4,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto kleisliMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT6 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT6(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti6 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly,KleisliMultiT6<A0,A1,A2,A3,A4,A5,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto kleisliMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT7 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT7(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti7 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly,KleisliMultiT7<A0,A1,A2,A3,A4,A5,A6,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto kleisliMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT8 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT8(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti8 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly,KleisliMultiT8<A0,A1,A2,A3,A4,A5,A6,A7,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto kleisliMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT9 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT9(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti9 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly,KleisliMultiT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto kleisliMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT10 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT10(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti10 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly,KleisliMultiT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto kleisliMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT11 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT11(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT11() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti11 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, B, Threaded, FireOnceOnly,KleisliMultiT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class F>
    static auto kleisliMulti11(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT12 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT12(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT12() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti12 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, B, Threaded, FireOnceOnly,KleisliMultiT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class F>
    static auto kleisliMulti12(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT13 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT13(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT13() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti13 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, B, Threaded, FireOnceOnly,KleisliMultiT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class F>
    static auto kleisliMulti13(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT14 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT14(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT14() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti14 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, B, Threaded, FireOnceOnly,KleisliMultiT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class F>
    static auto kleisliMulti14(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT15 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT15(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT15() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti15 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, B, Threaded, FireOnceOnly,KleisliMultiT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class F>
    static auto kleisliMulti15(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT16 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT16(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT16() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti16 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, B, Threaded, FireOnceOnly,KleisliMultiT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class F>
    static auto kleisliMulti16(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT17 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT17(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT17() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti17 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, B, Threaded, FireOnceOnly,KleisliMultiT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class F>
    static auto kleisliMulti17(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT18 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT18(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT18() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti18 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, B, Threaded, FireOnceOnly,KleisliMultiT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class F>
    static auto kleisliMulti18(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT19 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT19(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT19() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti19 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, B, Threaded, FireOnceOnly,KleisliMultiT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class F>
    static auto kleisliMulti19(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool Threaded, bool FireOnceOnly>
    class KleisliMultiT20 {
    private:
        F f_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
            return f_(std::move(data));
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        KleisliMultiT20(F &&f) : f_(std::move(f)) {}
        ~KleisliMultiT20() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool Threaded, bool FireOnceOnly>
    using KleisliMulti20 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, B, Threaded, FireOnceOnly,KleisliMultiT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class F>
    static auto kleisliMulti20(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type::ValueType::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
public:
    template <class A, class F>
    static auto kleisliMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((InnerData<A> *) nullptr))))::value_type::ValueType::value_type>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return kleisliMulti1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return kleisliMulti2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return kleisliMulti3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return kleisliMulti4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return kleisliMulti5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return kleisliMulti6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return kleisliMulti7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return kleisliMulti8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return kleisliMulti9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return kleisliMulti10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 11) {
            return kleisliMulti11<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 12) {
            return kleisliMulti12<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 13) {
            return kleisliMulti13<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 14) {
            return kleisliMulti14<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 15) {
            return kleisliMulti15<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 16) {
            return kleisliMulti16<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 17) {
            return kleisliMulti17<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 18) {
            return kleisliMulti18<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 19) {
            return kleisliMulti19<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 20) {
            return kleisliMulti20<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, std::variant_alternative_t<19,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("kleisliMulti: bad template parameter");
        }
    }