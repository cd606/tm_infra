private:
    template <class F, class OutputType, class A0, class A1>
    class VariantFuncT2 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
    public:
        VariantFuncT2(F &&f) : f_(std::move(f)), a0_(), a1_() {}
        VariantFuncT2(VariantFuncT2 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)) {}
        VariantFuncT2 &operator=(VariantFuncT2 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            return *this;
        }
        VariantFuncT2(VariantFuncT2 &&) = default;
        VariantFuncT2 &operator=(VariantFuncT2 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1>>([](std::variant<A0,A1> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1>>([](std::variant<A0,A1> &&x) {
                return std::get<1>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class F>
    static auto variant2(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1())))::value_type::ValueType>>(VariantFuncT2<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1())))::value_type::ValueType,A0,A1>(std::move(f)));
    }
private:
    template <class A0, class A1>
    static Data<std::tuple<A0,A1>> _merge2(int which, InnerData<A0> &&a0, InnerData<A1> &&a1) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<A0,A1>>> merge2(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant2<A0,A1>(_merge2<A0,A1>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2>
    class VariantFuncT3 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
    public:
        VariantFuncT3(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_() {}
        VariantFuncT3(VariantFuncT3 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)) {}
        VariantFuncT3 &operator=(VariantFuncT3 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            return *this;
        }
        VariantFuncT3(VariantFuncT3 &&) = default;
        VariantFuncT3 &operator=(VariantFuncT3 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2>>([](std::variant<A0,A1,A2> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2>>([](std::variant<A0,A1,A2> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2>>([](std::variant<A0,A1,A2> &&x) {
                return std::get<2>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto variant3(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2())))::value_type::ValueType>>(VariantFuncT3<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2())))::value_type::ValueType,A0,A1,A2>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2>
    static Data<std::tuple<A0,A1,A2>> _merge3(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>> merge3(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant3<A0,A1,A2>(_merge3<A0,A1,A2>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3>
    class VariantFuncT4 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
    public:
        VariantFuncT4(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_() {}
        VariantFuncT4(VariantFuncT4 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)) {}
        VariantFuncT4 &operator=(VariantFuncT4 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            return *this;
        }
        VariantFuncT4(VariantFuncT4 &&) = default;
        VariantFuncT4 &operator=(VariantFuncT4 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3>>([](std::variant<A0,A1,A2,A3> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3>>([](std::variant<A0,A1,A2,A3> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3>>([](std::variant<A0,A1,A2,A3> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3>>([](std::variant<A0,A1,A2,A3> &&x) {
                return std::get<3>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto variant4(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3())))::value_type::ValueType>>(VariantFuncT4<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3())))::value_type::ValueType,A0,A1,A2,A3>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3>
    static Data<std::tuple<A0,A1,A2,A3>> _merge4(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>> merge4(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant4<A0,A1,A2,A3>(_merge4<A0,A1,A2,A3>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3, class A4>
    class VariantFuncT5 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
        WithTime<A4, TimePoint> a4_;
    public:
        VariantFuncT5(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_(), a4_() {}
        VariantFuncT5(VariantFuncT5 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)), a4_(withtime_utils::makeCopy(v.a4_)) {}
        VariantFuncT5 &operator=(VariantFuncT5 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            a4_ = withtime_utils::makeCopy(v.a4_);
            return *this;
        }
        VariantFuncT5(VariantFuncT5 &&) = default;
        VariantFuncT5 &operator=(VariantFuncT5 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3,A4>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3,A4>>([](std::variant<A0,A1,A2,A3,A4> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3,A4>>([](std::variant<A0,A1,A2,A3,A4> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3,A4>>([](std::variant<A0,A1,A2,A3,A4> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3,A4>>([](std::variant<A0,A1,A2,A3,A4> &&x) {
                return std::get<3>(std::move(x));
            });
            static auto f4 = liftPure<std::variant<A0,A1,A2,A3,A4>>([](std::variant<A0,A1,A2,A3,A4> &&x) {
                return std::get<4>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 4:
                {
                    auto n = (*f4)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a4_.timePoint)) {
                            a4_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a4_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(4
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto variant5(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4())))::value_type::ValueType>>(VariantFuncT5<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4())))::value_type::ValueType,A0,A1,A2,A3,A4>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3, class A4>
    static Data<std::tuple<A0,A1,A2,A3,A4>> _merge5(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3, InnerData<A4> &&a4) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value)
                }}}};
        case 4:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4>> {
                a4.environment
                , {a4.environment->resolveTime(std::move(a4.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>> merge5(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant5<A0,A1,A2,A3,A4>(_merge5<A0,A1,A2,A3,A4>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3, class A4, class A5>
    class VariantFuncT6 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
        WithTime<A4, TimePoint> a4_;
        WithTime<A5, TimePoint> a5_;
    public:
        VariantFuncT6(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_(), a4_(), a5_() {}
        VariantFuncT6(VariantFuncT6 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)), a4_(withtime_utils::makeCopy(v.a4_)), a5_(withtime_utils::makeCopy(v.a5_)) {}
        VariantFuncT6 &operator=(VariantFuncT6 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            a4_ = withtime_utils::makeCopy(v.a4_);
            a5_ = withtime_utils::makeCopy(v.a5_);
            return *this;
        }
        VariantFuncT6(VariantFuncT6 &&) = default;
        VariantFuncT6 &operator=(VariantFuncT6 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3,A4,A5>>([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3,A4,A5>>([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3,A4,A5>>([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3,A4,A5>>([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {
                return std::get<3>(std::move(x));
            });
            static auto f4 = liftPure<std::variant<A0,A1,A2,A3,A4,A5>>([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {
                return std::get<4>(std::move(x));
            });
            static auto f5 = liftPure<std::variant<A0,A1,A2,A3,A4,A5>>([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {
                return std::get<5>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 4:
                {
                    auto n = (*f4)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a4_.timePoint)) {
                            a4_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a4_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(4
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 5:
                {
                    auto n = (*f5)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a5_.timePoint)) {
                            a5_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a5_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(5
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto variant6(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5())))::value_type::ValueType>>(VariantFuncT6<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5())))::value_type::ValueType,A0,A1,A2,A3,A4,A5>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static Data<std::tuple<A0,A1,A2,A3,A4,A5>> _merge6(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3, InnerData<A4> &&a4, InnerData<A5> &&a5) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value)
                }}}};
        case 4:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5>> {
                a4.environment
                , {a4.environment->resolveTime(std::move(a4.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value)
                }}}};
        case 5:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5>> {
                a5.environment
                , {a5.environment->resolveTime(std::move(a5.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>> merge6(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant6<A0,A1,A2,A3,A4,A5>(_merge6<A0,A1,A2,A3,A4,A5>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    class VariantFuncT7 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
        WithTime<A4, TimePoint> a4_;
        WithTime<A5, TimePoint> a5_;
        WithTime<A6, TimePoint> a6_;
    public:
        VariantFuncT7(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_(), a4_(), a5_(), a6_() {}
        VariantFuncT7(VariantFuncT7 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)), a4_(withtime_utils::makeCopy(v.a4_)), a5_(withtime_utils::makeCopy(v.a5_)), a6_(withtime_utils::makeCopy(v.a6_)) {}
        VariantFuncT7 &operator=(VariantFuncT7 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            a4_ = withtime_utils::makeCopy(v.a4_);
            a5_ = withtime_utils::makeCopy(v.a5_);
            a6_ = withtime_utils::makeCopy(v.a6_);
            return *this;
        }
        VariantFuncT7(VariantFuncT7 &&) = default;
        VariantFuncT7 &operator=(VariantFuncT7 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<3>(std::move(x));
            });
            static auto f4 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<4>(std::move(x));
            });
            static auto f5 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<5>(std::move(x));
            });
            static auto f6 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6>>([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {
                return std::get<6>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 4:
                {
                    auto n = (*f4)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a4_.timePoint)) {
                            a4_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a4_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(4
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 5:
                {
                    auto n = (*f5)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a5_.timePoint)) {
                            a5_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a5_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(5
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 6:
                {
                    auto n = (*f6)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a6_.timePoint)) {
                            a6_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a6_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(6
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto variant7(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6())))::value_type::ValueType>>(VariantFuncT7<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6())))::value_type::ValueType,A0,A1,A2,A3,A4,A5,A6>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static Data<std::tuple<A0,A1,A2,A3,A4,A5,A6>> _merge7(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3, InnerData<A4> &&a4, InnerData<A5> &&a5, InnerData<A6> &&a6) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        case 4:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a4.environment
                , {a4.environment->resolveTime(std::move(a4.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        case 5:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a5.environment
                , {a5.environment->resolveTime(std::move(a5.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        case 6:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6>> {
                a6.environment
                , {a6.environment->resolveTime(std::move(a6.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> merge7(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant7<A0,A1,A2,A3,A4,A5,A6>(_merge7<A0,A1,A2,A3,A4,A5,A6>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    class VariantFuncT8 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
        WithTime<A4, TimePoint> a4_;
        WithTime<A5, TimePoint> a5_;
        WithTime<A6, TimePoint> a6_;
        WithTime<A7, TimePoint> a7_;
    public:
        VariantFuncT8(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_(), a4_(), a5_(), a6_(), a7_() {}
        VariantFuncT8(VariantFuncT8 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)), a4_(withtime_utils::makeCopy(v.a4_)), a5_(withtime_utils::makeCopy(v.a5_)), a6_(withtime_utils::makeCopy(v.a6_)), a7_(withtime_utils::makeCopy(v.a7_)) {}
        VariantFuncT8 &operator=(VariantFuncT8 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            a4_ = withtime_utils::makeCopy(v.a4_);
            a5_ = withtime_utils::makeCopy(v.a5_);
            a6_ = withtime_utils::makeCopy(v.a6_);
            a7_ = withtime_utils::makeCopy(v.a7_);
            return *this;
        }
        VariantFuncT8(VariantFuncT8 &&) = default;
        VariantFuncT8 &operator=(VariantFuncT8 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<3>(std::move(x));
            });
            static auto f4 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<4>(std::move(x));
            });
            static auto f5 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<5>(std::move(x));
            });
            static auto f6 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<6>(std::move(x));
            });
            static auto f7 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {
                return std::get<7>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 4:
                {
                    auto n = (*f4)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a4_.timePoint)) {
                            a4_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a4_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(4
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 5:
                {
                    auto n = (*f5)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a5_.timePoint)) {
                            a5_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a5_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(5
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 6:
                {
                    auto n = (*f6)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a6_.timePoint)) {
                            a6_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a6_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(6
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 7:
                {
                    auto n = (*f7)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a7_.timePoint)) {
                            a7_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a7_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(7
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto variant8(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7())))::value_type::ValueType>>(VariantFuncT8<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7())))::value_type::ValueType,A0,A1,A2,A3,A4,A5,A6,A7>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static Data<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> _merge8(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3, InnerData<A4> &&a4, InnerData<A5> &&a5, InnerData<A6> &&a6, InnerData<A7> &&a7) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 4:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a4.environment
                , {a4.environment->resolveTime(std::move(a4.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 5:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a5.environment
                , {a5.environment->resolveTime(std::move(a5.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 6:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a6.environment
                , {a6.environment->resolveTime(std::move(a6.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        case 7:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> {
                a7.environment
                , {a7.environment->resolveTime(std::move(a7.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> merge8(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant8<A0,A1,A2,A3,A4,A5,A6,A7>(_merge8<A0,A1,A2,A3,A4,A5,A6,A7>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    class VariantFuncT9 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
        WithTime<A4, TimePoint> a4_;
        WithTime<A5, TimePoint> a5_;
        WithTime<A6, TimePoint> a6_;
        WithTime<A7, TimePoint> a7_;
        WithTime<A8, TimePoint> a8_;
    public:
        VariantFuncT9(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_(), a4_(), a5_(), a6_(), a7_(), a8_() {}
        VariantFuncT9(VariantFuncT9 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)), a4_(withtime_utils::makeCopy(v.a4_)), a5_(withtime_utils::makeCopy(v.a5_)), a6_(withtime_utils::makeCopy(v.a6_)), a7_(withtime_utils::makeCopy(v.a7_)), a8_(withtime_utils::makeCopy(v.a8_)) {}
        VariantFuncT9 &operator=(VariantFuncT9 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            a4_ = withtime_utils::makeCopy(v.a4_);
            a5_ = withtime_utils::makeCopy(v.a5_);
            a6_ = withtime_utils::makeCopy(v.a6_);
            a7_ = withtime_utils::makeCopy(v.a7_);
            a8_ = withtime_utils::makeCopy(v.a8_);
            return *this;
        }
        VariantFuncT9(VariantFuncT9 &&) = default;
        VariantFuncT9 &operator=(VariantFuncT9 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<3>(std::move(x));
            });
            static auto f4 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<4>(std::move(x));
            });
            static auto f5 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<5>(std::move(x));
            });
            static auto f6 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<6>(std::move(x));
            });
            static auto f7 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<7>(std::move(x));
            });
            static auto f8 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {
                return std::get<8>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 4:
                {
                    auto n = (*f4)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a4_.timePoint)) {
                            a4_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a4_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(4
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 5:
                {
                    auto n = (*f5)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a5_.timePoint)) {
                            a5_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a5_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(5
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 6:
                {
                    auto n = (*f6)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a6_.timePoint)) {
                            a6_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a6_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(6
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 7:
                {
                    auto n = (*f7)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a7_.timePoint)) {
                            a7_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a7_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(7
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 8:
                {
                    auto n = (*f8)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a8_.timePoint)) {
                            a8_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a8_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(8
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto variant9(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8())))::value_type::ValueType>>(VariantFuncT9<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8())))::value_type::ValueType,A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static Data<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> _merge9(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3, InnerData<A4> &&a4, InnerData<A5> &&a5, InnerData<A6> &&a6, InnerData<A7> &&a7, InnerData<A8> &&a8) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 4:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a4.environment
                , {a4.environment->resolveTime(std::move(a4.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 5:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a5.environment
                , {a5.environment->resolveTime(std::move(a5.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 6:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a6.environment
                , {a6.environment->resolveTime(std::move(a6.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 7:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a7.environment
                , {a7.environment->resolveTime(std::move(a7.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        case 8:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
                a8.environment
                , {a8.environment->resolveTime(std::move(a8.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> merge9(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant9<A0,A1,A2,A3,A4,A5,A6,A7,A8>(_merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8>);
    }
private:
    template <class F, class OutputType, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    class VariantFuncT10 {
    private:
        F f_;
        WithTime<A0, TimePoint> a0_;
        WithTime<A1, TimePoint> a1_;
        WithTime<A2, TimePoint> a2_;
        WithTime<A3, TimePoint> a3_;
        WithTime<A4, TimePoint> a4_;
        WithTime<A5, TimePoint> a5_;
        WithTime<A6, TimePoint> a6_;
        WithTime<A7, TimePoint> a7_;
        WithTime<A8, TimePoint> a8_;
        WithTime<A9, TimePoint> a9_;
    public:
        VariantFuncT10(F &&f) : f_(std::move(f)), a0_(), a1_(), a2_(), a3_(), a4_(), a5_(), a6_(), a7_(), a8_(), a9_() {}
        VariantFuncT10(VariantFuncT10 const &v) : f_(v.f_), a0_(withtime_utils::makeCopy(v.a0_)), a1_(withtime_utils::makeCopy(v.a1_)), a2_(withtime_utils::makeCopy(v.a2_)), a3_(withtime_utils::makeCopy(v.a3_)), a4_(withtime_utils::makeCopy(v.a4_)), a5_(withtime_utils::makeCopy(v.a5_)), a6_(withtime_utils::makeCopy(v.a6_)), a7_(withtime_utils::makeCopy(v.a7_)), a8_(withtime_utils::makeCopy(v.a8_)), a9_(withtime_utils::makeCopy(v.a9_)) {}
        VariantFuncT10 &operator=(VariantFuncT10 const &v) {
            if (this == &v) {
                return *this;
            }
            f_ = v.f_;
            a0_ = withtime_utils::makeCopy(v.a0_);
            a1_ = withtime_utils::makeCopy(v.a1_);
            a2_ = withtime_utils::makeCopy(v.a2_);
            a3_ = withtime_utils::makeCopy(v.a3_);
            a4_ = withtime_utils::makeCopy(v.a4_);
            a5_ = withtime_utils::makeCopy(v.a5_);
            a6_ = withtime_utils::makeCopy(v.a6_);
            a7_ = withtime_utils::makeCopy(v.a7_);
            a8_ = withtime_utils::makeCopy(v.a8_);
            a9_ = withtime_utils::makeCopy(v.a9_);
            return *this;
        }
        VariantFuncT10(VariantFuncT10 &&) = default;
        VariantFuncT10 &operator=(VariantFuncT10 &&) = default;
        Data<OutputType> operator()(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&input) {
            static auto f0 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<0>(std::move(x));
            });
            static auto f1 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<1>(std::move(x));
            });
            static auto f2 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<2>(std::move(x));
            });
            static auto f3 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<3>(std::move(x));
            });
            static auto f4 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<4>(std::move(x));
            });
            static auto f5 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<5>(std::move(x));
            });
            static auto f6 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<6>(std::move(x));
            });
            static auto f7 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<7>(std::move(x));
            });
            static auto f8 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<8>(std::move(x));
            });
            static auto f9 = liftPure<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {
                return std::get<9>(std::move(x));
            });
            switch (input.timedData.value.index()) {
            case 0:
                {
                    auto n = (*f0)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a0_.timePoint)) {
                            a0_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a0_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a0_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(0
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 1:
                {
                    auto n = (*f1)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a1_.timePoint)) {
                            a1_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a1_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a1_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(1
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 2:
                {
                    auto n = (*f2)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a2_.timePoint)) {
                            a2_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a2_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a2_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(2
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 3:
                {
                    auto n = (*f3)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a3_.timePoint)) {
                            a3_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a3_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a3_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(3
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 4:
                {
                    auto n = (*f4)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a4_.timePoint)) {
                            a4_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a4_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a4_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(4
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 5:
                {
                    auto n = (*f5)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a5_.timePoint)) {
                            a5_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a5_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a5_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(5
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 6:
                {
                    auto n = (*f6)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a6_.timePoint)) {
                            a6_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a6_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a6_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(6
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 7:
                {
                    auto n = (*f7)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a7_.timePoint)) {
                            a7_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a7_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a7_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(7
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 8:
                {
                    auto n = (*f8)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a8_.timePoint)) {
                            a8_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a8_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a8_.timePoint < a9_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(8
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            case 9:
                {
                    auto n = (*f9)(std::move(input));
                    if (n) {
                        if (!StateT::CheckTime || (n->timedData.timePoint >= a9_.timePoint)) {
                            a9_ = std::move(n->timedData);
                            bool timeGood = true;
                            if (StateT::CheckTime) {
                                if (timeGood && (a9_.timePoint < a0_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a1_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a2_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a3_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a4_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a5_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a6_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a7_.timePoint)) {
                                    timeGood = false;
                                }
                                if (timeGood && (a9_.timePoint < a8_.timePoint)) {
                                    timeGood = false;
                                }
                            }
                            if (timeGood) {
                                return f_(9
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a0_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a1_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a2_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a3_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a4_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a5_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a6_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a7_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a8_), true)
                                    , pureInnerData(n->environment, withtime_utils::makeCopy(a9_), true)
                                );
                            } else {
                                return {std::nullopt};
                            }
                        } else {
                            return {std::nullopt};
                        }
                    } else {
                        return {std::nullopt};
                    }
                }
                break;
            default:
                return {std::nullopt};
                break;
            }
        }
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto variant10(F &&f)
        -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8()),pureInnerData<A9>(nullptr,A9())))::value_type::ValueType>>
    {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8()),pureInnerData<A9>(nullptr,A9())))::value_type::ValueType>>(VariantFuncT10<F, typename decltype(f(0,pureInnerData<A0>(nullptr,A0()),pureInnerData<A1>(nullptr,A1()),pureInnerData<A2>(nullptr,A2()),pureInnerData<A3>(nullptr,A3()),pureInnerData<A4>(nullptr,A4()),pureInnerData<A5>(nullptr,A5()),pureInnerData<A6>(nullptr,A6()),pureInnerData<A7>(nullptr,A7()),pureInnerData<A8>(nullptr,A8()),pureInnerData<A9>(nullptr,A9())))::value_type::ValueType,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(f)));
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static Data<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> _merge10(int which, InnerData<A0> &&a0, InnerData<A1> &&a1, InnerData<A2> &&a2, InnerData<A3> &&a3, InnerData<A4> &&a4, InnerData<A5> &&a5, InnerData<A6> &&a6, InnerData<A7> &&a7, InnerData<A8> &&a8, InnerData<A9> &&a9) {
        switch (which) {
        case 0:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a0.environment
                , {a0.environment->resolveTime(std::move(a0.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 1:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a1.environment
                , {a1.environment->resolveTime(std::move(a1.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 2:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a2.environment
                , {a2.environment->resolveTime(std::move(a2.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 3:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a3.environment
                , {a3.environment->resolveTime(std::move(a3.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 4:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a4.environment
                , {a4.environment->resolveTime(std::move(a4.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 5:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a5.environment
                , {a5.environment->resolveTime(std::move(a5.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 6:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a6.environment
                , {a6.environment->resolveTime(std::move(a6.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 7:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a7.environment
                , {a7.environment->resolveTime(std::move(a7.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 8:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a8.environment
                , {a8.environment->resolveTime(std::move(a8.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        case 9:
            return {InnerData<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
                a9.environment
                , {a9.environment->resolveTime(std::move(a9.timedData.timePoint)), {
                    std::move(a0.timedData.value), 
                    std::move(a1.timedData.value), 
                    std::move(a2.timedData.value), 
                    std::move(a3.timedData.value), 
                    std::move(a4.timedData.value), 
                    std::move(a5.timedData.value), 
                    std::move(a6.timedData.value), 
                    std::move(a7.timedData.value), 
                    std::move(a8.timedData.value), 
                    std::move(a9.timedData.value)
                }}}};
        default:
            return {std::nullopt};
        }
    }
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> merge10(FanInParamMask const &notUsed=FanInParamMask()) {
        return variant10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(_merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>);
    }