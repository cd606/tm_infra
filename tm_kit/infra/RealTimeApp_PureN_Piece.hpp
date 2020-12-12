private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class Pure2 final : public ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure2(F &&f) : ActionCore<std::variant<A0,A1>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure2() {}
    };
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
    class Pure3 final : public ActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure3(F &&f) : ActionCore<std::variant<A0,A1,A2>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure3() {}
    };
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
    class Pure4 final : public ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure4(F &&f) : ActionCore<std::variant<A0,A1,A2,A3>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure4() {}
    };
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
    class Pure5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure5(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure5() {}
    };
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
    class Pure6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure6(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure6() {}
    };
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
    class Pure7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure7(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure7() {}
    };
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
    class Pure8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure8(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure8() {}
    };
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
    class Pure9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure9(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure9() {}
    };
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
    class Pure10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
    public:
        Pure10(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Pure10() {}
    };
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