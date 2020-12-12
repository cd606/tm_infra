private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi2 final : public MultiActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi2(F &&f) : MultiActionCore<std::variant<A0,A1>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto liftMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi3 final : public MultiActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi3(F &&f) : MultiActionCore<std::variant<A0,A1,A2>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto liftMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi4 final : public MultiActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi4(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi5 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi5(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi6 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi6(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi7 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi7(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi8 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi8(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi9 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi9(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class Multi10 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi10(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~Multi10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }