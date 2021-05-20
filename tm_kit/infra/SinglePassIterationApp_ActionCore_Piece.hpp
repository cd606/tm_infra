template <class A0, class A1, class B>
class ActionCore<std::variant<A0,A1>,B> : public virtual AbstractActionCore<std::variant<A0,A1>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    std::bitset<2> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(2);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class B>
class MultiActionCore<std::variant<A0,A1>,B> : public virtual AbstractActionCore<std::variant<A0,A1>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    std::bitset<2> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(2);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1>> {env, WithTime<std::variant<A0,A1>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class B, class F>
class PureActionCore<std::variant<A0,A1>,B,F> final : public ActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class B, class F>
class MaybeActionCore<std::variant<A0,A1>,B,F> final : public ActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1>,B,F> final : public ActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class B, class F>
class KleisliActionCore<std::variant<A0,A1>,B,F> final : public ActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1>,B,F> final : public MultiActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1>,B,F> final : public MultiActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1>,B,F> final : public MultiActionCore<std::variant<A0,A1>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B>
class ActionCore<std::variant<A0,A1,A2>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    std::bitset<3> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(3);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class B>
class MultiActionCore<std::variant<A0,A1,A2>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    std::bitset<3> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(3);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2>> {env, WithTime<std::variant<A0,A1,A2>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class B, class F>
class PureActionCore<std::variant<A0,A1,A2>,B,F> final : public ActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2>,B,F> final : public ActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2>,B,F> final : public ActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2>,B,F> final : public ActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B>
class ActionCore<std::variant<A0,A1,A2,A3>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    std::bitset<4> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(4);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    std::bitset<4> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(4);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3>> {env, WithTime<std::variant<A0,A1,A2,A3>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B>
class ActionCore<std::variant<A0,A1,A2,A3,A4>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    std::bitset<5> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(5);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> Data<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    std::bitset<5> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(5);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> MultiData<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> {env, WithTime<std::variant<A0,A1,A2,A3,A4>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    std::bitset<6> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(6);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> Data<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> Data<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    std::bitset<6> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(6);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> MultiData<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> MultiData<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    std::bitset<7> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(7);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> Data<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> Data<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> Data<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    std::bitset<7> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(7);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> MultiData<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> MultiData<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> MultiData<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual Consumer<A7>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    VersionChecker<A7> versionChecker7_;
    std::optional<TimePoint> tp7_;
    std::bitset<8> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        auto cert7 = this->Consumer<A7>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(8);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (cert7.check()) {
            vec.push_back({7, fetchTimePointUnsafe(cert7)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> Data<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> Data<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> Data<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 7:
            {
                auto produce = [cert7=std::move(cert7),updateIdx,this]() -> Data<B> {
                    Certificate<A7> cert7_copy = std::move(cert7);
                    auto x7 = this->Consumer<A7>::source()->next(std::move(cert7_copy));
                    if (!x7) {
                        return std::nullopt;
                    }
                    if (!versionChecker7_.checkVersion(x7->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp7_ || x7->timedData.timePoint >= *tp7_) {
                        tp7_ = x7->timedData.timePoint;
                        StateT *env = x7->environment;
                        if (x7->timedData.finalFlag) {
                            finalMask_.set(7);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp7_;
                                    newTP += (*delaySimulator_)(7, *tp7_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), versionChecker7_(), tp7_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual Consumer<A7>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    VersionChecker<A7> versionChecker7_;
    std::optional<TimePoint> tp7_;
    std::bitset<8> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        auto cert7 = this->Consumer<A7>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(8);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (cert7.check()) {
            vec.push_back({7, fetchTimePointUnsafe(cert7)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> MultiData<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> MultiData<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> MultiData<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 7:
            {
                auto produce = [cert7=std::move(cert7),updateIdx,this]() -> MultiData<B> {
                    Certificate<A7> cert7_copy = std::move(cert7);
                    auto x7 = this->Consumer<A7>::source()->next(std::move(cert7_copy));
                    if (!x7) {
                        return std::nullopt;
                    }
                    if (!versionChecker7_.checkVersion(x7->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp7_ || x7->timedData.timePoint >= *tp7_) {
                        tp7_ = x7->timedData.timePoint;
                        StateT *env = x7->environment;
                        if (x7->timedData.finalFlag) {
                            finalMask_.set(7);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp7_;
                                    newTP += (*delaySimulator_)(7, *tp7_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), versionChecker7_(), tp7_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual Consumer<A7>, public virtual Consumer<A8>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    VersionChecker<A7> versionChecker7_;
    std::optional<TimePoint> tp7_;
    VersionChecker<A8> versionChecker8_;
    std::optional<TimePoint> tp8_;
    std::bitset<9> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        auto cert7 = this->Consumer<A7>::source()->poll();
        auto cert8 = this->Consumer<A8>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(9);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (cert7.check()) {
            vec.push_back({7, fetchTimePointUnsafe(cert7)});
        }
        if (cert8.check()) {
            vec.push_back({8, fetchTimePointUnsafe(cert8)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> Data<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> Data<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> Data<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 7:
            {
                auto produce = [cert7=std::move(cert7),updateIdx,this]() -> Data<B> {
                    Certificate<A7> cert7_copy = std::move(cert7);
                    auto x7 = this->Consumer<A7>::source()->next(std::move(cert7_copy));
                    if (!x7) {
                        return std::nullopt;
                    }
                    if (!versionChecker7_.checkVersion(x7->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp7_ || x7->timedData.timePoint >= *tp7_) {
                        tp7_ = x7->timedData.timePoint;
                        StateT *env = x7->environment;
                        if (x7->timedData.finalFlag) {
                            finalMask_.set(7);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp7_;
                                    newTP += (*delaySimulator_)(7, *tp7_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 8:
            {
                auto produce = [cert8=std::move(cert8),updateIdx,this]() -> Data<B> {
                    Certificate<A8> cert8_copy = std::move(cert8);
                    auto x8 = this->Consumer<A8>::source()->next(std::move(cert8_copy));
                    if (!x8) {
                        return std::nullopt;
                    }
                    if (!versionChecker8_.checkVersion(x8->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp8_ || x8->timedData.timePoint >= *tp8_) {
                        tp8_ = x8->timedData.timePoint;
                        StateT *env = x8->environment;
                        if (x8->timedData.finalFlag) {
                            finalMask_.set(8);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp8_;
                                    newTP += (*delaySimulator_)(8, *tp8_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), versionChecker7_(), tp7_(std::nullopt), versionChecker8_(), tp8_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual Consumer<A7>, public virtual Consumer<A8>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    VersionChecker<A7> versionChecker7_;
    std::optional<TimePoint> tp7_;
    VersionChecker<A8> versionChecker8_;
    std::optional<TimePoint> tp8_;
    std::bitset<9> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        auto cert7 = this->Consumer<A7>::source()->poll();
        auto cert8 = this->Consumer<A8>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(9);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (cert7.check()) {
            vec.push_back({7, fetchTimePointUnsafe(cert7)});
        }
        if (cert8.check()) {
            vec.push_back({8, fetchTimePointUnsafe(cert8)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> MultiData<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> MultiData<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> MultiData<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 7:
            {
                auto produce = [cert7=std::move(cert7),updateIdx,this]() -> MultiData<B> {
                    Certificate<A7> cert7_copy = std::move(cert7);
                    auto x7 = this->Consumer<A7>::source()->next(std::move(cert7_copy));
                    if (!x7) {
                        return std::nullopt;
                    }
                    if (!versionChecker7_.checkVersion(x7->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp7_ || x7->timedData.timePoint >= *tp7_) {
                        tp7_ = x7->timedData.timePoint;
                        StateT *env = x7->environment;
                        if (x7->timedData.finalFlag) {
                            finalMask_.set(7);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp7_;
                                    newTP += (*delaySimulator_)(7, *tp7_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 8:
            {
                auto produce = [cert8=std::move(cert8),updateIdx,this]() -> MultiData<B> {
                    Certificate<A8> cert8_copy = std::move(cert8);
                    auto x8 = this->Consumer<A8>::source()->next(std::move(cert8_copy));
                    if (!x8) {
                        return std::nullopt;
                    }
                    if (!versionChecker8_.checkVersion(x8->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp8_ || x8->timedData.timePoint >= *tp8_) {
                        tp8_ = x8->timedData.timePoint;
                        StateT *env = x8->environment;
                        if (x8->timedData.finalFlag) {
                            finalMask_.set(8);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp8_;
                                    newTP += (*delaySimulator_)(8, *tp8_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), versionChecker7_(), tp7_(std::nullopt), versionChecker8_(), tp8_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual Consumer<A7>, public virtual Consumer<A8>, public virtual Consumer<A9>, public virtual BufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    VersionChecker<A7> versionChecker7_;
    std::optional<TimePoint> tp7_;
    VersionChecker<A8> versionChecker8_;
    std::optional<TimePoint> tp8_;
    VersionChecker<A9> versionChecker9_;
    std::optional<TimePoint> tp9_;
    std::bitset<10> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        auto cert7 = this->Consumer<A7>::source()->poll();
        auto cert8 = this->Consumer<A8>::source()->poll();
        auto cert9 = this->Consumer<A9>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(10);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (cert7.check()) {
            vec.push_back({7, fetchTimePointUnsafe(cert7)});
        }
        if (cert8.check()) {
            vec.push_back({8, fetchTimePointUnsafe(cert8)});
        }
        if (cert9.check()) {
            vec.push_back({9, fetchTimePointUnsafe(cert9)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> Data<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> Data<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> Data<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> Data<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> Data<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> Data<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> Data<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 7:
            {
                auto produce = [cert7=std::move(cert7),updateIdx,this]() -> Data<B> {
                    Certificate<A7> cert7_copy = std::move(cert7);
                    auto x7 = this->Consumer<A7>::source()->next(std::move(cert7_copy));
                    if (!x7) {
                        return std::nullopt;
                    }
                    if (!versionChecker7_.checkVersion(x7->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp7_ || x7->timedData.timePoint >= *tp7_) {
                        tp7_ = x7->timedData.timePoint;
                        StateT *env = x7->environment;
                        if (x7->timedData.finalFlag) {
                            finalMask_.set(7);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp7_;
                                    newTP += (*delaySimulator_)(7, *tp7_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 8:
            {
                auto produce = [cert8=std::move(cert8),updateIdx,this]() -> Data<B> {
                    Certificate<A8> cert8_copy = std::move(cert8);
                    auto x8 = this->Consumer<A8>::source()->next(std::move(cert8_copy));
                    if (!x8) {
                        return std::nullopt;
                    }
                    if (!versionChecker8_.checkVersion(x8->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp8_ || x8->timedData.timePoint >= *tp8_) {
                        tp8_ = x8->timedData.timePoint;
                        StateT *env = x8->environment;
                        if (x8->timedData.finalFlag) {
                            finalMask_.set(8);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp8_;
                                    newTP += (*delaySimulator_)(8, *tp8_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        case 9:
            {
                auto produce = [cert9=std::move(cert9),updateIdx,this]() -> Data<B> {
                    Certificate<A9> cert9_copy = std::move(cert9);
                    auto x9 = this->Consumer<A9>::source()->next(std::move(cert9_copy));
                    if (!x9) {
                        return std::nullopt;
                    }
                    if (!versionChecker9_.checkVersion(x9->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp9_ || x9->timedData.timePoint >= *tp9_) {
                        tp9_ = x9->timedData.timePoint;
                        StateT *env = x9->environment;
                        if (x9->timedData.finalFlag) {
                            finalMask_.set(9);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x9->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x9->timedData.value)}, x9->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp9_;
                                    newTP += (*delaySimulator_)(9, *tp9_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x9->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x9->timedData.value)}, x9->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x9->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x9->timedData.value)}, x9->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&) = 0;
    Data<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                return std::nullopt;
            } else {
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    ActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), versionChecker7_(), tp7_(std::nullopt), versionChecker8_(), tp8_(std::nullopt), versionChecker9_(), tp9_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> : public virtual AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>, public virtual Consumer<A0>, public virtual Consumer<A1>, public virtual Consumer<A2>, public virtual Consumer<A3>, public virtual Consumer<A4>, public virtual Consumer<A5>, public virtual Consumer<A6>, public virtual Consumer<A7>, public virtual Consumer<A8>, public virtual Consumer<A9>, public virtual MultiBufferedProvider<B> {
private:
    VersionChecker<A0> versionChecker0_;
    std::optional<TimePoint> tp0_;
    VersionChecker<A1> versionChecker1_;
    std::optional<TimePoint> tp1_;
    VersionChecker<A2> versionChecker2_;
    std::optional<TimePoint> tp2_;
    VersionChecker<A3> versionChecker3_;
    std::optional<TimePoint> tp3_;
    VersionChecker<A4> versionChecker4_;
    std::optional<TimePoint> tp4_;
    VersionChecker<A5> versionChecker5_;
    std::optional<TimePoint> tp5_;
    VersionChecker<A6> versionChecker6_;
    std::optional<TimePoint> tp6_;
    VersionChecker<A7> versionChecker7_;
    std::optional<TimePoint> tp7_;
    VersionChecker<A8> versionChecker8_;
    std::optional<TimePoint> tp8_;
    VersionChecker<A9> versionChecker9_;
    std::optional<TimePoint> tp9_;
    std::bitset<10> finalMask_;
    DelaySimulatorType delaySimulator_;
protected:
    virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
        auto cert0 = this->Consumer<A0>::source()->poll();
        auto cert1 = this->Consumer<A1>::source()->poll();
        auto cert2 = this->Consumer<A2>::source()->poll();
        auto cert3 = this->Consumer<A3>::source()->poll();
        auto cert4 = this->Consumer<A4>::source()->poll();
        auto cert5 = this->Consumer<A5>::source()->poll();
        auto cert6 = this->Consumer<A6>::source()->poll();
        auto cert7 = this->Consumer<A7>::source()->poll();
        auto cert8 = this->Consumer<A8>::source()->poll();
        auto cert9 = this->Consumer<A9>::source()->poll();
        std::vector<TimePointComparisonStruct> vec;
        vec.reserve(10);
        if (cert0.check()) {
            vec.push_back({0, fetchTimePointUnsafe(cert0)});
        }
        if (cert1.check()) {
            vec.push_back({1, fetchTimePointUnsafe(cert1)});
        }
        if (cert2.check()) {
            vec.push_back({2, fetchTimePointUnsafe(cert2)});
        }
        if (cert3.check()) {
            vec.push_back({3, fetchTimePointUnsafe(cert3)});
        }
        if (cert4.check()) {
            vec.push_back({4, fetchTimePointUnsafe(cert4)});
        }
        if (cert5.check()) {
            vec.push_back({5, fetchTimePointUnsafe(cert5)});
        }
        if (cert6.check()) {
            vec.push_back({6, fetchTimePointUnsafe(cert6)});
        }
        if (cert7.check()) {
            vec.push_back({7, fetchTimePointUnsafe(cert7)});
        }
        if (cert8.check()) {
            vec.push_back({8, fetchTimePointUnsafe(cert8)});
        }
        if (cert9.check()) {
            vec.push_back({9, fetchTimePointUnsafe(cert9)});
        }
        if (vec.empty()) {
            return std::nullopt;
        }
        std::sort(vec.begin(), vec.end());
        int updateIdx = vec[0].idx;
        switch (updateIdx) {
        case 0:
            {
                auto produce = [cert0=std::move(cert0),updateIdx,this]() -> MultiData<B> {
                    Certificate<A0> cert0_copy = std::move(cert0);
                    auto x0 = this->Consumer<A0>::source()->next(std::move(cert0_copy));
                    if (!x0) {
                        return std::nullopt;
                    }
                    if (!versionChecker0_.checkVersion(x0->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp0_ || x0->timedData.timePoint >= *tp0_) {
                        tp0_ = x0->timedData.timePoint;
                        StateT *env = x0->environment;
                        if (x0->timedData.finalFlag) {
                            finalMask_.set(0);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp0_;
                                    newTP += (*delaySimulator_)(0, *tp0_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x0->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x0->timedData.value)}, x0->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 1:
            {
                auto produce = [cert1=std::move(cert1),updateIdx,this]() -> MultiData<B> {
                    Certificate<A1> cert1_copy = std::move(cert1);
                    auto x1 = this->Consumer<A1>::source()->next(std::move(cert1_copy));
                    if (!x1) {
                        return std::nullopt;
                    }
                    if (!versionChecker1_.checkVersion(x1->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp1_ || x1->timedData.timePoint >= *tp1_) {
                        tp1_ = x1->timedData.timePoint;
                        StateT *env = x1->environment;
                        if (x1->timedData.finalFlag) {
                            finalMask_.set(1);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp1_;
                                    newTP += (*delaySimulator_)(1, *tp1_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x1->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x1->timedData.value)}, x1->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 2:
            {
                auto produce = [cert2=std::move(cert2),updateIdx,this]() -> MultiData<B> {
                    Certificate<A2> cert2_copy = std::move(cert2);
                    auto x2 = this->Consumer<A2>::source()->next(std::move(cert2_copy));
                    if (!x2) {
                        return std::nullopt;
                    }
                    if (!versionChecker2_.checkVersion(x2->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp2_ || x2->timedData.timePoint >= *tp2_) {
                        tp2_ = x2->timedData.timePoint;
                        StateT *env = x2->environment;
                        if (x2->timedData.finalFlag) {
                            finalMask_.set(2);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp2_;
                                    newTP += (*delaySimulator_)(2, *tp2_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x2->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x2->timedData.value)}, x2->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 3:
            {
                auto produce = [cert3=std::move(cert3),updateIdx,this]() -> MultiData<B> {
                    Certificate<A3> cert3_copy = std::move(cert3);
                    auto x3 = this->Consumer<A3>::source()->next(std::move(cert3_copy));
                    if (!x3) {
                        return std::nullopt;
                    }
                    if (!versionChecker3_.checkVersion(x3->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp3_ || x3->timedData.timePoint >= *tp3_) {
                        tp3_ = x3->timedData.timePoint;
                        StateT *env = x3->environment;
                        if (x3->timedData.finalFlag) {
                            finalMask_.set(3);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp3_;
                                    newTP += (*delaySimulator_)(3, *tp3_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x3->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x3->timedData.value)}, x3->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 4:
            {
                auto produce = [cert4=std::move(cert4),updateIdx,this]() -> MultiData<B> {
                    Certificate<A4> cert4_copy = std::move(cert4);
                    auto x4 = this->Consumer<A4>::source()->next(std::move(cert4_copy));
                    if (!x4) {
                        return std::nullopt;
                    }
                    if (!versionChecker4_.checkVersion(x4->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp4_ || x4->timedData.timePoint >= *tp4_) {
                        tp4_ = x4->timedData.timePoint;
                        StateT *env = x4->environment;
                        if (x4->timedData.finalFlag) {
                            finalMask_.set(4);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp4_;
                                    newTP += (*delaySimulator_)(4, *tp4_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x4->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x4->timedData.value)}, x4->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 5:
            {
                auto produce = [cert5=std::move(cert5),updateIdx,this]() -> MultiData<B> {
                    Certificate<A5> cert5_copy = std::move(cert5);
                    auto x5 = this->Consumer<A5>::source()->next(std::move(cert5_copy));
                    if (!x5) {
                        return std::nullopt;
                    }
                    if (!versionChecker5_.checkVersion(x5->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp5_ || x5->timedData.timePoint >= *tp5_) {
                        tp5_ = x5->timedData.timePoint;
                        StateT *env = x5->environment;
                        if (x5->timedData.finalFlag) {
                            finalMask_.set(5);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp5_;
                                    newTP += (*delaySimulator_)(5, *tp5_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x5->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x5->timedData.value)}, x5->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 6:
            {
                auto produce = [cert6=std::move(cert6),updateIdx,this]() -> MultiData<B> {
                    Certificate<A6> cert6_copy = std::move(cert6);
                    auto x6 = this->Consumer<A6>::source()->next(std::move(cert6_copy));
                    if (!x6) {
                        return std::nullopt;
                    }
                    if (!versionChecker6_.checkVersion(x6->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp6_ || x6->timedData.timePoint >= *tp6_) {
                        tp6_ = x6->timedData.timePoint;
                        StateT *env = x6->environment;
                        if (x6->timedData.finalFlag) {
                            finalMask_.set(6);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp6_;
                                    newTP += (*delaySimulator_)(6, *tp6_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x6->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x6->timedData.value)}, x6->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 7:
            {
                auto produce = [cert7=std::move(cert7),updateIdx,this]() -> MultiData<B> {
                    Certificate<A7> cert7_copy = std::move(cert7);
                    auto x7 = this->Consumer<A7>::source()->next(std::move(cert7_copy));
                    if (!x7) {
                        return std::nullopt;
                    }
                    if (!versionChecker7_.checkVersion(x7->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp7_ || x7->timedData.timePoint >= *tp7_) {
                        tp7_ = x7->timedData.timePoint;
                        StateT *env = x7->environment;
                        if (x7->timedData.finalFlag) {
                            finalMask_.set(7);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp7_;
                                    newTP += (*delaySimulator_)(7, *tp7_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x7->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x7->timedData.value)}, x7->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 8:
            {
                auto produce = [cert8=std::move(cert8),updateIdx,this]() -> MultiData<B> {
                    Certificate<A8> cert8_copy = std::move(cert8);
                    auto x8 = this->Consumer<A8>::source()->next(std::move(cert8_copy));
                    if (!x8) {
                        return std::nullopt;
                    }
                    if (!versionChecker8_.checkVersion(x8->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp8_ || x8->timedData.timePoint >= *tp8_) {
                        tp8_ = x8->timedData.timePoint;
                        StateT *env = x8->environment;
                        if (x8->timedData.finalFlag) {
                            finalMask_.set(8);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp8_;
                                    newTP += (*delaySimulator_)(8, *tp8_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x8->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x8->timedData.value)}, x8->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        case 9:
            {
                auto produce = [cert9=std::move(cert9),updateIdx,this]() -> MultiData<B> {
                    Certificate<A9> cert9_copy = std::move(cert9);
                    auto x9 = this->Consumer<A9>::source()->next(std::move(cert9_copy));
                    if (!x9) {
                        return std::nullopt;
                    }
                    if (!versionChecker9_.checkVersion(x9->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !tp9_ || x9->timedData.timePoint >= *tp9_) {
                        tp9_ = x9->timedData.timePoint;
                        StateT *env = x9->environment;
                        if (x9->timedData.finalFlag) {
                            finalMask_.set(9);
                        }
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                            env
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x9->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x9->timedData.value)}, x9->timedData.finalFlag}});
                                if (r) {
                                    auto newTP = *tp9_;
                                    newTP += (*delaySimulator_)(9, *tp9_);
                                    r->overrideTime(newTP);
                                }
                                return std::move(r);
                            } else {
                                return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x9->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x9->timedData.value)}, x9->timedData.finalFlag}});
                            }
                        } else {
                            return realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {env, WithTime<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {std::move(x9->timedData.timePoint), std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x9->timedData.value)}, x9->timedData.finalFlag}});
                        }
                    } else {
                        return std::nullopt;
                    }
                };
                auto tp1 = vec[0].tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(updateIdx, vec[0].tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }
            break;
        default:
            return std::nullopt;
            break;
        }
    }
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&) = 0;
    MultiData<B> realHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&x) {
        auto ret = handle(std::move(x));
        if (ret) {
            std::vector<B> filtered;
            for (auto &&item : ret->timedData.value) {
                if (!this->producerIsStopped(outputIndex<B>(item))) {
                    filtered.push_back(std::move(item));
                }
            }
            if (filtered.empty()) {
                return std::nullopt;
            } else {
                ret->timedData.value = std::move(filtered);
                return std::move(ret);
            }
        } else {
            return std::nullopt;
        }
    }
public:
    MultiActionCore(DelaySimulatorType const &delaySimulator) : versionChecker0_(), tp0_(std::nullopt), versionChecker1_(), tp1_(std::nullopt), versionChecker2_(), tp2_(std::nullopt), versionChecker3_(), tp3_(std::nullopt), versionChecker4_(), tp4_(std::nullopt), versionChecker5_(), tp5_(std::nullopt), versionChecker6_(), tp6_(std::nullopt), versionChecker7_(), tp7_(std::nullopt), versionChecker8_(), tp8_(std::nullopt), versionChecker9_(), tp9_(std::nullopt), finalMask_(), delaySimulator_(delaySimulator) {
    }
    bool isFinalUpdate() const {
        return finalMask_.all();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class PureActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        B b = f_(std::move(data.timedData.value));
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~PureActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class MaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::move(data.timedData.value));
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~MaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class EnhancedMaybeActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::optional<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {tp, std::move(data.timedData.value)});
        if (!b) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            Data<B> x = pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , true
                }
            );
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<B>(
                env
                , {
                    tp
                    , std::move(*b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMaybeActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class KleisliActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual Data<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x) {
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class SimpleMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::move(data.timedData.value));
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~SimpleMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class EnhancedMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
        }
        StateT *env = data.environment;
        TimePoint tp = data.timedData.timePoint;
        std::vector<B> b = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {tp, std::move(data.timedData.value)});
        if (b.empty()) {
            return std::nullopt;
        }
        if (fireOnceOnly_) {
            MultiData<B> x = pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , true
                }
            );
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            return pureInnerData<std::vector<B>>(
                env
                , {
                    tp
                    , std::move(b)
                    , this->isFinalUpdate()
                }
            );
        }
    }
public:
    EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~EnhancedMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F>
class KleisliMultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,F> final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    F f_;
    bool fireOnceOnly_;
    bool done_;
protected:
    virtual MultiData<B> handle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
        if (fireOnceOnly_) {
            if (done_) {
                return std::nullopt;
            }
            data.timedData.finalFlag = this->isFinalUpdate();
            auto x = f_(std::move(data));
            if (x && x->timedData.value.size() > 0) {
                x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                x->timedData.finalFlag = true;
                done_ = true;
            }
            return x;
        } else {
            data.timedData.finalFlag = this->isFinalUpdate();
            return f_(std::move(data));
        }
    }
public:
    KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
    }
    KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
    }
    virtual ~KleisliMultiActionCore() {}
    virtual bool isOneTimeOnly() const override final {
        return fireOnceOnly_;
    }
};