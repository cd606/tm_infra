private:
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    class Multi2 final : public MultiActionCore<std::variant<A0,A1>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi2(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto liftMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type>> ( new Multi2<A0,A1,typename decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    class Multi3 final : public MultiActionCore<std::variant<A0,A1,A2>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi3(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto liftMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type>> ( new Multi3<A0,A1,A2,typename decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    class Multi4 final : public MultiActionCore<std::variant<A0,A1,A2,A3>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi4(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type>> ( new Multi4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    class Multi5 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi5(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type>> ( new Multi5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    class Multi6 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi6(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type>> ( new Multi6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    class Multi7 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi7(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type>> ( new Multi7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    class Multi8 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi8(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type>> ( new Multi8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    class Multi9 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi9(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type>> ( new Multi9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    class Multi10 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
            auto index = data.timedData.value.index();
            auto ret = f_(std::move(data.timedData.value));
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
    public:
        Multi10(F &&f, DelaySimulator const &delaySimulator) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Multi10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type>> ( new Multi10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
public:
    template <class A, class F>
    static auto liftMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((A *) nullptr))))::value_type>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return liftMulti1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return liftMulti2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return liftMulti3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return liftMulti4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return liftMulti5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return liftMulti6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return liftMulti7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return liftMulti8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return liftMulti9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return liftMulti10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("liftMulti: bad template parameter");
        }
    }