private:
    template <class A0, class A1, class B, class F, bool FireOnceOnly>
    class Kleisli2 final : public ActionCore<std::variant<A0,A1>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
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
    public:
        Kleisli2(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto kleisli2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType>> ( new Kleisli2<A0,A1,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool FireOnceOnly>
    class Kleisli3 final : public ActionCore<std::variant<A0,A1,A2>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2>> &&data) override final {
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
    public:
        Kleisli3(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto kleisli3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType>> ( new Kleisli3<A0,A1,A2,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool FireOnceOnly>
    class Kleisli4 final : public ActionCore<std::variant<A0,A1,A2,A3>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
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
    public:
        Kleisli4(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto kleisli4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType>> ( new Kleisli4<A0,A1,A2,A3,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool FireOnceOnly>
    class Kleisli5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
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
    public:
        Kleisli5(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto kleisli5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType>> ( new Kleisli5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool FireOnceOnly>
    class Kleisli6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
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
    public:
        Kleisli6(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto kleisli6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType>> ( new Kleisli6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool FireOnceOnly>
    class Kleisli7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
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
    public:
        Kleisli7(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto kleisli7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType>> ( new Kleisli7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool FireOnceOnly>
    class Kleisli8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
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
    public:
        Kleisli8(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto kleisli8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType>> ( new Kleisli8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool FireOnceOnly>
    class Kleisli9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
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
    public:
        Kleisli9(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto kleisli9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType>> ( new Kleisli9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool FireOnceOnly>
    class Kleisli10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, FireOnceOnly> {
    private:
        F f_;
        DelaySimulator delaySimulator_;
    protected:
        virtual Data<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
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
    public:
        Kleisli10(F &&f, DelaySimulator const &delaySimulator) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,FireOnceOnly>(), f_(std::move(f)), delaySimulator_(delaySimulator) {}
        virtual ~Kleisli10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto kleisli10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> {
        if (liftParam.fireOnceOnly) {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType,F,true>(std::move(f), liftParam.delaySimulator) );
        } else {
            return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType>> ( new Kleisli10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type::ValueType,F,false>(std::move(f), liftParam.delaySimulator) );
        }
    }
public:
    template <class A, class F>
    static auto kleisli(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((InnerData<A> *) nullptr))))::value_type::ValueType>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return kleisli1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return kleisli2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return kleisli3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return kleisli4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return kleisli5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return kleisli6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return kleisli7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return kleisli8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return kleisli9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return kleisli10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("kleisli: bad template parameter");
        }
    }