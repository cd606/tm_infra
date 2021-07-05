private:
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    class KleisliMultiT2 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT2(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT2() {}
    };
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    using KleisliMulti2 = MultiActionCore<std::variant<A0,A1>, B, FireOnceOnly, KleisliMultiT2<A0,A1, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class F>
    static auto kleisliMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    class KleisliMultiT3 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT3(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT3() {}
    };
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    using KleisliMulti3 = MultiActionCore<std::variant<A0,A1,A2>, B, FireOnceOnly, KleisliMultiT3<A0,A1,A2, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class F>
    static auto kleisliMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    class KleisliMultiT4 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT4(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT4() {}
    };
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    using KleisliMulti4 = MultiActionCore<std::variant<A0,A1,A2,A3>, B, FireOnceOnly, KleisliMultiT4<A0,A1,A2,A3, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto kleisliMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    class KleisliMultiT5 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT5(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT5() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    using KleisliMulti5 = MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, FireOnceOnly, KleisliMultiT5<A0,A1,A2,A3,A4, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto kleisliMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    class KleisliMultiT6 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT6(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT6() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    using KleisliMulti6 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, FireOnceOnly, KleisliMultiT6<A0,A1,A2,A3,A4,A5, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto kleisliMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    class KleisliMultiT7 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT7(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT7() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    using KleisliMulti7 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, FireOnceOnly, KleisliMultiT7<A0,A1,A2,A3,A4,A5,A6, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto kleisliMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    class KleisliMultiT8 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT8(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT8() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    using KleisliMulti8 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, FireOnceOnly, KleisliMultiT8<A0,A1,A2,A3,A4,A5,A6,A7, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto kleisliMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    class KleisliMultiT9 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT9(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT9() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    using KleisliMulti9 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, FireOnceOnly, KleisliMultiT9<A0,A1,A2,A3,A4,A5,A6,A7,A8, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto kleisliMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    class KleisliMultiT10 {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    public:
        MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
            if (delaySimulator_) {
                auto index = data.timedData.value.index();
                auto ret = f_(std::move(data));
                if (ret) {
                    ret->timedData.timePoint += (*delaySimulator_)(index, ret->timedData.timePoint);
                }
                return std::move(ret);
            } else {
                return f_(std::move(data));
            }
        }
        KleisliMultiT10(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
        ~KleisliMultiT10() {}
    };
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    using KleisliMulti10 = MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, FireOnceOnly, KleisliMultiT10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9, B, F, FireOnceOnly>>;
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto kleisliMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type>> ( new KleisliMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType::value_type,F,false>(std::move(f), liftParam.delaySimulator) );
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
        } else {
            throw std::runtime_error("kleisliMulti: bad template parameter");
        }
    }