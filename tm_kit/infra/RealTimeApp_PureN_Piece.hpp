private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class Pure2 final : public ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
            return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
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