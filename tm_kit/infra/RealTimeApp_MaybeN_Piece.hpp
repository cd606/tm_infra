private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class Maybe2 final : public ActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe2(F &&f) : ActionCore<std::variant<A0,A1>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe2() {}
    };
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
    class Maybe3 final : public ActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe3(F &&f) : ActionCore<std::variant<A0,A1,A2>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe3() {}
    };
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
    class Maybe4 final : public ActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe4(F &&f) : ActionCore<std::variant<A0,A1,A2,A3>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe4() {}
    };
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
    class Maybe5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe5(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe5() {}
    };
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
    class Maybe6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe6(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe6() {}
    };
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
    class Maybe7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe7(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe7() {}
    };
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
    class Maybe8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe8(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe8() {}
    };
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
    class Maybe9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe9(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe9() {}
    };
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
    class Maybe10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (ret) {
                return pureInnerData(data.environment, WithTime<B,TimePoint> {std::move(data.timedData.timePoint), std::move(*ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        Maybe10(F &&f) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Maybe10() {}
    };
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
        } else {
            throw std::runtime_error("liftMaybe: bad template parameter");
        }
    }