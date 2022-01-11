private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT2 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT2(F &&f) : f_(std::move(f)) {}
        ~MaybeT2() {}
    };
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe2 = ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly,MaybeT2<A0,A1,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto liftMaybe2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Maybe2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Maybe2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Maybe2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Maybe2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT3 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT3(F &&f) : f_(std::move(f)) {}
        ~MaybeT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe3 = ActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly,MaybeT3<A0,A1,A2,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto liftMaybe3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Maybe3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Maybe3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Maybe3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Maybe3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT4 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT4(F &&f) : f_(std::move(f)) {}
        ~MaybeT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe4 = ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly,MaybeT4<A0,A1,A2,A3,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftMaybe4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Maybe4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Maybe4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Maybe4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Maybe4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT5 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT5(F &&f) : f_(std::move(f)) {}
        ~MaybeT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe5 = ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly,MaybeT5<A0,A1,A2,A3,A4,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftMaybe5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Maybe5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Maybe5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Maybe5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Maybe5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT6 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT6(F &&f) : f_(std::move(f)) {}
        ~MaybeT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe6 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly,MaybeT6<A0,A1,A2,A3,A4,A5,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftMaybe6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Maybe6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Maybe6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Maybe6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Maybe6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT7 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT7(F &&f) : f_(std::move(f)) {}
        ~MaybeT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe7 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly,MaybeT7<A0,A1,A2,A3,A4,A5,A6,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftMaybe7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Maybe7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Maybe7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Maybe7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Maybe7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT8 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT8(F &&f) : f_(std::move(f)) {}
        ~MaybeT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe8 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly,MaybeT8<A0,A1,A2,A3,A4,A5,A6,A7,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftMaybe8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Maybe8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Maybe8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Maybe8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Maybe8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT9 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT9(F &&f) : f_(std::move(f)) {}
        ~MaybeT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe9 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly,MaybeT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftMaybe9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Maybe9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Maybe9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Maybe9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Maybe9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT10 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT10(F &&f) : f_(std::move(f)) {}
        ~MaybeT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe10 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly,MaybeT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftMaybe10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Maybe10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Maybe10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Maybe10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Maybe10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT11 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT11(F &&f) : f_(std::move(f)) {}
        ~MaybeT11() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe11 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, B, Threaded, FireOnceOnly,MaybeT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class F>
    static auto liftMaybe11(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type>> ( new Maybe11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type>> ( new Maybe11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type>> ( new Maybe11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type>> ( new Maybe11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT12 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT12(F &&f) : f_(std::move(f)) {}
        ~MaybeT12() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe12 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, B, Threaded, FireOnceOnly,MaybeT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class F>
    static auto liftMaybe12(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type>> ( new Maybe12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type>> ( new Maybe12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type>> ( new Maybe12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type>> ( new Maybe12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT13 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT13(F &&f) : f_(std::move(f)) {}
        ~MaybeT13() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe13 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, B, Threaded, FireOnceOnly,MaybeT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class F>
    static auto liftMaybe13(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type>> ( new Maybe13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type>> ( new Maybe13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type>> ( new Maybe13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type>> ( new Maybe13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT14 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT14(F &&f) : f_(std::move(f)) {}
        ~MaybeT14() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe14 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, B, Threaded, FireOnceOnly,MaybeT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class F>
    static auto liftMaybe14(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type>> ( new Maybe14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type>> ( new Maybe14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type>> ( new Maybe14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type>> ( new Maybe14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT15 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT15(F &&f) : f_(std::move(f)) {}
        ~MaybeT15() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe15 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, B, Threaded, FireOnceOnly,MaybeT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class F>
    static auto liftMaybe15(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type>> ( new Maybe15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type>> ( new Maybe15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type>> ( new Maybe15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type>> ( new Maybe15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT16 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT16(F &&f) : f_(std::move(f)) {}
        ~MaybeT16() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe16 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, B, Threaded, FireOnceOnly,MaybeT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class F>
    static auto liftMaybe16(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type>> ( new Maybe16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type>> ( new Maybe16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type>> ( new Maybe16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type>> ( new Maybe16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT17 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT17(F &&f) : f_(std::move(f)) {}
        ~MaybeT17() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe17 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, B, Threaded, FireOnceOnly,MaybeT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class F>
    static auto liftMaybe17(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type>> ( new Maybe17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type>> ( new Maybe17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type>> ( new Maybe17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type>> ( new Maybe17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT18 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT18(F &&f) : f_(std::move(f)) {}
        ~MaybeT18() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe18 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, B, Threaded, FireOnceOnly,MaybeT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class F>
    static auto liftMaybe18(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type>> ( new Maybe18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type>> ( new Maybe18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type>> ( new Maybe18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type>> ( new Maybe18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT19 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT19(F &&f) : f_(std::move(f)) {}
        ~MaybeT19() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe19 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, B, Threaded, FireOnceOnly,MaybeT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class F>
    static auto liftMaybe19(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type>> ( new Maybe19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type>> ( new Maybe19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type>> ( new Maybe19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type>> ( new Maybe19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool Threaded, bool FireOnceOnly>
    class MaybeT20 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        MaybeT20(F &&f) : f_(std::move(f)) {}
        ~MaybeT20() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool Threaded, bool FireOnceOnly>
    using Maybe20 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, B, Threaded, FireOnceOnly,MaybeT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class F>
    static auto liftMaybe20(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type>> ( new Maybe20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type>> ( new Maybe20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type>> ( new Maybe20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type>> ( new Maybe20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
public:
    template <class A, class F>
    static auto liftMaybe(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((A *) nullptr))))::value_type>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return liftMaybe1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return liftMaybe2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return liftMaybe3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return liftMaybe4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return liftMaybe5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return liftMaybe6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return liftMaybe7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return liftMaybe8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return liftMaybe9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return liftMaybe10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 11) {
            return liftMaybe11<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 12) {
            return liftMaybe12<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 13) {
            return liftMaybe13<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 14) {
            return liftMaybe14<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 15) {
            return liftMaybe15<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 16) {
            return liftMaybe16<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 17) {
            return liftMaybe17<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 18) {
            return liftMaybe18<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 19) {
            return liftMaybe19<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 20) {
            return liftMaybe20<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, std::variant_alternative_t<19,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("liftMaybe: bad template parameter");
        }
    }