private:
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT2 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT2(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT2(EnhancedMultiT2 &&) = default;
        ~EnhancedMultiT2() {}
    };
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    using EnhancedMulti2 = MultiActionCore<std::variant<A0,A1>, B, FireOnceOnly, EnhancedMultiT2<A0,A1, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto enhancedMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> ( new EnhancedMulti2<A0,A1,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> ( new EnhancedMulti2<A0,A1,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT3 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT3(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT3(EnhancedMultiT3 &&) = default;
        ~EnhancedMultiT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    using EnhancedMulti3 = MultiActionCore<std::variant<A0,A1,A2>, B, FireOnceOnly, EnhancedMultiT3<A0,A1,A2, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto enhancedMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> ( new EnhancedMulti3<A0,A1,A2,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> ( new EnhancedMulti3<A0,A1,A2,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT4 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT4(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT4(EnhancedMultiT4 &&) = default;
        ~EnhancedMultiT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    using EnhancedMulti4 = MultiActionCore<std::variant<A0,A1,A2,A3>, B, FireOnceOnly, EnhancedMultiT4<A0,A1,A2,A3, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto enhancedMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> ( new EnhancedMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> ( new EnhancedMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT5 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT5(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT5(EnhancedMultiT5 &&) = default;
        ~EnhancedMultiT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    using EnhancedMulti5 = MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, FireOnceOnly, EnhancedMultiT5<A0,A1,A2,A3,A4, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto enhancedMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> ( new EnhancedMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> ( new EnhancedMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT6 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT6(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT6(EnhancedMultiT6 &&) = default;
        ~EnhancedMultiT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    using EnhancedMulti6 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, FireOnceOnly, EnhancedMultiT6<A0,A1,A2,A3,A4,A5, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto enhancedMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> ( new EnhancedMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> ( new EnhancedMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT7 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT7(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT7(EnhancedMultiT7 &&) = default;
        ~EnhancedMultiT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    using EnhancedMulti7 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, FireOnceOnly, EnhancedMultiT7<A0,A1,A2,A3,A4,A5,A6, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto enhancedMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> ( new EnhancedMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> ( new EnhancedMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT8 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT8(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT8(EnhancedMultiT8 &&) = default;
        ~EnhancedMultiT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    using EnhancedMulti8 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, FireOnceOnly, EnhancedMultiT8<A0,A1,A2,A3,A4,A5,A6,A7, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto enhancedMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> ( new EnhancedMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> ( new EnhancedMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT9 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT9(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT9(EnhancedMultiT9 &&) = default;
        ~EnhancedMultiT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    using EnhancedMulti9 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, FireOnceOnly, EnhancedMultiT9<A0,A1,A2,A3,A4,A5,A6,A7,A8, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto enhancedMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> ( new EnhancedMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> ( new EnhancedMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT10 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT10(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT10(EnhancedMultiT10 &&) = default;
        ~EnhancedMultiT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    using EnhancedMulti10 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, FireOnceOnly, EnhancedMultiT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto enhancedMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> ( new EnhancedMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> ( new EnhancedMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT11 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT11(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT11(EnhancedMultiT11 &&) = default;
        ~EnhancedMultiT11() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, class F, bool FireOnceOnly>
    using EnhancedMulti11 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, B, FireOnceOnly, EnhancedMultiT11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class F>
    static auto enhancedMulti11(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type>> ( new EnhancedMulti11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type>> ( new EnhancedMulti11<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT12 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT12(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT12(EnhancedMultiT12 &&) = default;
        ~EnhancedMultiT12() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, class F, bool FireOnceOnly>
    using EnhancedMulti12 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, B, FireOnceOnly, EnhancedMultiT12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class F>
    static auto enhancedMulti12(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type>> ( new EnhancedMulti12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type>> ( new EnhancedMulti12<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT13 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT13(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT13(EnhancedMultiT13 &&) = default;
        ~EnhancedMultiT13() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, class F, bool FireOnceOnly>
    using EnhancedMulti13 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, B, FireOnceOnly, EnhancedMultiT13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class F>
    static auto enhancedMulti13(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type>> ( new EnhancedMulti13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type>> ( new EnhancedMulti13<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT14 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT14(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT14(EnhancedMultiT14 &&) = default;
        ~EnhancedMultiT14() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, class F, bool FireOnceOnly>
    using EnhancedMulti14 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, B, FireOnceOnly, EnhancedMultiT14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class F>
    static auto enhancedMulti14(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type>> ( new EnhancedMulti14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type>> ( new EnhancedMulti14<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT15 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT15(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT15(EnhancedMultiT15 &&) = default;
        ~EnhancedMultiT15() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, class F, bool FireOnceOnly>
    using EnhancedMulti15 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, B, FireOnceOnly, EnhancedMultiT15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class F>
    static auto enhancedMulti15(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type>> ( new EnhancedMulti15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type>> ( new EnhancedMulti15<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT16 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT16(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT16(EnhancedMultiT16 &&) = default;
        ~EnhancedMultiT16() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, class F, bool FireOnceOnly>
    using EnhancedMulti16 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, B, FireOnceOnly, EnhancedMultiT16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class F>
    static auto enhancedMulti16(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type>> ( new EnhancedMulti16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type>> ( new EnhancedMulti16<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT17 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT17(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT17(EnhancedMultiT17 &&) = default;
        ~EnhancedMultiT17() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, class F, bool FireOnceOnly>
    using EnhancedMulti17 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, B, FireOnceOnly, EnhancedMultiT17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class F>
    static auto enhancedMulti17(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type>> ( new EnhancedMulti17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type>> ( new EnhancedMulti17<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT18 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT18(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT18(EnhancedMultiT18 &&) = default;
        ~EnhancedMultiT18() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, class F, bool FireOnceOnly>
    using EnhancedMulti18 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, B, FireOnceOnly, EnhancedMultiT18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class F>
    static auto enhancedMulti18(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type>> ( new EnhancedMulti18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type>> ( new EnhancedMulti18<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT19 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT19(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT19(EnhancedMultiT19 &&) = default;
        ~EnhancedMultiT19() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, class F, bool FireOnceOnly>
    using EnhancedMulti19 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, B, FireOnceOnly, EnhancedMultiT19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class F>
    static auto enhancedMulti19(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type>> ( new EnhancedMulti19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type>> ( new EnhancedMulti19<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool FireOnceOnly>
    class EnhancedMultiT20 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
            auto index = data.timedData.value.index();
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                auto tp = (delaySimulator_?(data.timedData.timePoint+(*delaySimulator_)(index, data.timedData.timePoint)):std::move(data.timedData.timePoint));
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {tp, std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        EnhancedMultiT20(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        EnhancedMultiT20(EnhancedMultiT20 &&) = default;
        ~EnhancedMultiT20() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, class F, bool FireOnceOnly>
    using EnhancedMulti20 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, B, FireOnceOnly, EnhancedMultiT20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class F>
    static auto enhancedMulti20(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type>> ( new EnhancedMulti20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type>> ( new EnhancedMulti20<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> *) nullptr))))::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
public:
    template <class A, class F>
    static auto enhancedMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((std::tuple<TimePoint, A> *) nullptr))))::value_type>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return enhancedMulti1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return enhancedMulti2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return enhancedMulti3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return enhancedMulti4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return enhancedMulti5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return enhancedMulti6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return enhancedMulti7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return enhancedMulti8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return enhancedMulti9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return enhancedMulti10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 11) {
            return enhancedMulti11<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 12) {
            return enhancedMulti12<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 13) {
            return enhancedMulti13<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 14) {
            return enhancedMulti14<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 15) {
            return enhancedMulti15<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 16) {
            return enhancedMulti16<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 17) {
            return enhancedMulti17<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 18) {
            return enhancedMulti18<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 19) {
            return enhancedMulti19<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 20) {
            return enhancedMulti20<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, std::variant_alternative_t<10,A>, std::variant_alternative_t<11,A>, std::variant_alternative_t<12,A>, std::variant_alternative_t<13,A>, std::variant_alternative_t<14,A>, std::variant_alternative_t<15,A>, std::variant_alternative_t<16,A>, std::variant_alternative_t<17,A>, std::variant_alternative_t<18,A>, std::variant_alternative_t<19,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("enhancedMulti: bad template parameter");
        }
    }