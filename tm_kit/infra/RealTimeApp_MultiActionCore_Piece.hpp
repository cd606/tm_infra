template <class A0, class A1, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1> fromA0(A0 &&x) {
        return std::variant<A0,A1>(std::move(x));
    }
    static std::variant<A0,A1> fromA1(A1 &&x) {
        return std::variant<A0,A1>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2>(std::move(x));
    }
    static std::variant<A0,A1,A2> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2>(std::move(x));
    }
    static std::variant<A0,A1,A2> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()), withtime_utils::makeCopy(tc.get4()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()), withtime_utils::makeCopy(timeChecker_.get4()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual void handle(InnerData<A4> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA4, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()), withtime_utils::makeCopy(tc.get4()), withtime_utils::makeCopy(tc.get5()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()), withtime_utils::makeCopy(timeChecker_.get4()), withtime_utils::makeCopy(timeChecker_.get5()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual void handle(InnerData<A4> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA4, std::move(data), true));
    }
    virtual void handle(InnerData<A5> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA5, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()), withtime_utils::makeCopy(tc.get4()), withtime_utils::makeCopy(tc.get5()), withtime_utils::makeCopy(tc.get6()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()), withtime_utils::makeCopy(timeChecker_.get4()), withtime_utils::makeCopy(timeChecker_.get5()), withtime_utils::makeCopy(timeChecker_.get6()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual void handle(InnerData<A4> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA4, std::move(data), true));
    }
    virtual void handle(InnerData<A5> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA5, std::move(data), true));
    }
    virtual void handle(InnerData<A6> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA6, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()), withtime_utils::makeCopy(tc.get4()), withtime_utils::makeCopy(tc.get5()), withtime_utils::makeCopy(tc.get6()), withtime_utils::makeCopy(tc.get7()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()), withtime_utils::makeCopy(timeChecker_.get4()), withtime_utils::makeCopy(timeChecker_.get5()), withtime_utils::makeCopy(timeChecker_.get6()), withtime_utils::makeCopy(timeChecker_.get7()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual void handle(InnerData<A4> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA4, std::move(data), true));
    }
    virtual void handle(InnerData<A5> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA5, std::move(data), true));
    }
    virtual void handle(InnerData<A6> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA6, std::move(data), true));
    }
    virtual void handle(InnerData<A7> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA7, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()), withtime_utils::makeCopy(tc.get4()), withtime_utils::makeCopy(tc.get5()), withtime_utils::makeCopy(tc.get6()), withtime_utils::makeCopy(tc.get7()), withtime_utils::makeCopy(tc.get8()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()), withtime_utils::makeCopy(timeChecker_.get4()), withtime_utils::makeCopy(timeChecker_.get5()), withtime_utils::makeCopy(timeChecker_.get6()), withtime_utils::makeCopy(timeChecker_.get7()), withtime_utils::makeCopy(timeChecker_.get8()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual void handle(InnerData<A4> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA4, std::move(data), true));
    }
    virtual void handle(InnerData<A5> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA5, std::move(data), true));
    }
    virtual void handle(InnerData<A6> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA6, std::move(data), true));
    }
    virtual void handle(InnerData<A7> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA7, std::move(data), true));
    }
    virtual void handle(InnerData<A8> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA8, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, true, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
private:
    bool done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) = 0;
    virtual void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(std::move(data))) {
            return;
        }
        auto const &tc = this->timeChecker();
        if (tc.good()) {
            auto res = action(data.environment, tc.lastIdx(), withtime_utils::makeCopy(tc.get0()), withtime_utils::makeCopy(tc.get1()), withtime_utils::makeCopy(tc.get2()), withtime_utils::makeCopy(tc.get3()), withtime_utils::makeCopy(tc.get4()), withtime_utils::makeCopy(tc.get5()), withtime_utils::makeCopy(tc.get6()), withtime_utils::makeCopy(tc.get7()), withtime_utils::makeCopy(tc.get8()), withtime_utils::makeCopy(tc.get9()));
            if (res && !res->timedData.value.empty()) {
                if constexpr (FireOnceOnly) {
                    Producer<B>::publish(InnerData<B> {
                        res->environment
                        , {
                            res->timedData.timePoint
                            , std::move(res->timedData.value[0])
                            , true
                        }
                    });
                    done_ = true;
                    this->stop();
                } else {
                    size_t l = res->timedData.value.size();
                    size_t ii = l-1;
                    for (auto &&item : res->timedData.value) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(item)
                                , ((ii==0)?res->timedData.finalFlag:false)
                            }
                        });
                        --ii;
                    }
                }
            }
        }
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return this->timeChecker().fanInParamMask();
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, bool FireOnceOnly>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, false, FireOnceOnly> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
protected:
    virtual MultiData<B> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) = 0;
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(std::move(data))) {
            if (timeChecker_.good()) {
                auto res = action(data.environment, timeChecker_.lastIdx(), withtime_utils::makeCopy(timeChecker_.get0()), withtime_utils::makeCopy(timeChecker_.get1()), withtime_utils::makeCopy(timeChecker_.get2()), withtime_utils::makeCopy(timeChecker_.get3()), withtime_utils::makeCopy(timeChecker_.get4()), withtime_utils::makeCopy(timeChecker_.get5()), withtime_utils::makeCopy(timeChecker_.get6()), withtime_utils::makeCopy(timeChecker_.get7()), withtime_utils::makeCopy(timeChecker_.get8()), withtime_utils::makeCopy(timeChecker_.get9()));
                if (res && !res->timedData.value.empty()) {
                    if constexpr (FireOnceOnly) {
                        Producer<B>::publish(InnerData<B> {
                            res->environment
                            , {
                                res->timedData.timePoint
                                , std::move(res->timedData.value[0])
                                , true
                            }
                        });
                        done_ = true;
                    } else {
                        size_t l = res->timedData.value.size();
                        size_t ii = l-1;
                        for (auto &&item : res->timedData.value) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(item)
                                    , ((ii==0)?res->timedData.finalFlag:false)
                                }
                            });
                            --ii;
                        }
                    }
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::move(x));
    }
public:
    MultiActionCore(FanInParamMask const &requireMask=FanInParamMask()) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(), timeChecker_(requireMask), done_(false) {
    }
    virtual ~MultiActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual void handle(InnerData<A2> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA2, std::move(data), true));
    }
    virtual void handle(InnerData<A3> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA3, std::move(data), true));
    }
    virtual void handle(InnerData<A4> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA4, std::move(data), true));
    }
    virtual void handle(InnerData<A5> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA5, std::move(data), true));
    }
    virtual void handle(InnerData<A6> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA6, std::move(data), true));
    }
    virtual void handle(InnerData<A7> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA7, std::move(data), true));
    }
    virtual void handle(InnerData<A8> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA8, std::move(data), true));
    }
    virtual void handle(InnerData<A9> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA9, std::move(data), true));
    }
    virtual bool isThreaded() const override final {
        return false;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual FanInParamMask fanInParamMask() const override final {
        return timeChecker_.fanInParamMask();
    }
};