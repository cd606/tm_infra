private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT2 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT2(F &&f) : f_(std::move(f)) {}
        ~PureT2() {}
    };
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure2 = ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly,PureT2<A0,A1,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto liftPure2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT3 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT3(F &&f) : f_(std::move(f)) {}
        ~PureT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure3 = ActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly,PureT3<A0,A1,A2,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto liftPure3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT4 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT4(F &&f) : f_(std::move(f)) {}
        ~PureT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure4 = ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly,PureT4<A0,A1,A2,A3,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftPure4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT5 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT5(F &&f) : f_(std::move(f)) {}
        ~PureT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure5 = ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly,PureT5<A0,A1,A2,A3,A4,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftPure5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT6 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT6(F &&f) : f_(std::move(f)) {}
        ~PureT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure6 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly,PureT6<A0,A1,A2,A3,A4,A5,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftPure6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT7 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT7(F &&f) : f_(std::move(f)) {}
        ~PureT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure7 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly,PureT7<A0,A1,A2,A3,A4,A5,A6,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftPure7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT8 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT8(F &&f) : f_(std::move(f)) {}
        ~PureT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure8 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly,PureT8<A0,A1,A2,A3,A4,A5,A6,A7,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftPure8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT9 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT9(F &&f) : f_(std::move(f)) {}
        ~PureT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure9 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly,PureT9<A0,A1,A2,A3,A4,A5,A6,A7,A8,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftPure9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class PureT10 {
    private:
        F f_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        void *getIdleHandlerParam() {
            return (void *) &f_;
        }
    public:
        PureT10(F &&f) : f_(std::move(f)) {}
        ~PureT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    using Pure10 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly,PureT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B,F,Threaded,FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftPure10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr)))),F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr)))),F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr)))),F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr)))),F,false,false>(std::move(f)) );
            }
        }
    }
public:
    template <class A, class F>
    static auto liftPure(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,decltype(f(std::move(*((A *) nullptr))))>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return liftPure1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return liftPure2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return liftPure3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return liftPure4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return liftPure5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return liftPure6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return liftPure7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return liftPure8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return liftPure9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return liftPure10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("liftPure: bad template parameter");
        }
    }