private:
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    class PureT2 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT2(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT2(PureT2 &&) = default;
        ~PureT2() {}
    };
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    using Pure2 = ActionCore<std::variant<A0,A1>, B, FireOnceOnly, PureT2<A0,A1, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto liftPure2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr))))>> ( new Pure2<A0,A1,decltype(f(std::move(*((std::variant<A0,A1> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    class PureT3 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT3(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT3(PureT3 &&) = default;
        ~PureT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    using Pure3 = ActionCore<std::variant<A0,A1,A2>, B, FireOnceOnly, PureT3<A0,A1,A2, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto liftPure3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr))))>> ( new Pure3<A0,A1,A2,decltype(f(std::move(*((std::variant<A0,A1,A2> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    class PureT4 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT4(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT4(PureT4 &&) = default;
        ~PureT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    using Pure4 = ActionCore<std::variant<A0,A1,A2,A3>, B, FireOnceOnly, PureT4<A0,A1,A2,A3, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto liftPure4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr))))>> ( new Pure4<A0,A1,A2,A3,decltype(f(std::move(*((std::variant<A0,A1,A2,A3> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    class PureT5 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT5(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT5(PureT5 &&) = default;
        ~PureT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    using Pure5 = ActionCore<std::variant<A0,A1,A2,A3,A4>, B, FireOnceOnly, PureT5<A0,A1,A2,A3,A4, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto liftPure5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr))))>> ( new Pure5<A0,A1,A2,A3,A4,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    class PureT6 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT6(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT6(PureT6 &&) = default;
        ~PureT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    using Pure6 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, FireOnceOnly, PureT6<A0,A1,A2,A3,A4,A5, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto liftPure6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr))))>> ( new Pure6<A0,A1,A2,A3,A4,A5,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    class PureT7 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT7(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT7(PureT7 &&) = default;
        ~PureT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    using Pure7 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, FireOnceOnly, PureT7<A0,A1,A2,A3,A4,A5,A6, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto liftPure7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr))))>> ( new Pure7<A0,A1,A2,A3,A4,A5,A6,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    class PureT8 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT8(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT8(PureT8 &&) = default;
        ~PureT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    using Pure8 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, FireOnceOnly, PureT8<A0,A1,A2,A3,A4,A5,A6,A7, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto liftPure8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr))))>> ( new Pure8<A0,A1,A2,A3,A4,A5,A6,A7,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    class PureT9 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT9(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT9(PureT9 &&) = default;
        ~PureT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    using Pure9 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, FireOnceOnly, PureT9<A0,A1,A2,A3,A4,A5,A6,A7,A8, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto liftPure9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr))))>> ( new Pure9<A0,A1,A2,A3,A4,A5,A6,A7,A8,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    class PureT10 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(data.timedData.value.index(), data.timedData.timePoint)):std::move(data.timedData.timePoint));
            return pureInnerData(data.environment, WithTime<B,TimePoint> {tp, f_(std::move(data.timedData.value)), data.timedData.finalFlag});
        }
        PureT10(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        PureT10(PureT10 &&) = default;
        ~PureT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    using Pure10 = ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, FireOnceOnly, PureT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto liftPure10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr)))),F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr))))>> ( new Pure10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,decltype(f(std::move(*((std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> *) nullptr)))),F,false>(std::move(f), liftParam.delaySimulator) );
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