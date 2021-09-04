template <class A0, class A1, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1>,MultiActionCore<std::variant<A0,A1>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1>,MultiActionCore<std::variant<A0,A1>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1> fromA0(A0 &&x) {
        return std::variant<A0,A1>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1> fromA1(A1 &&x) {
        return std::variant<A0,A1>(std::in_place_index<1>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2>,MultiActionCore<std::variant<A0,A1,A2>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2>,MultiActionCore<std::variant<A0,A1,A2>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2>(std::in_place_index<2>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3>,MultiActionCore<std::variant<A0,A1,A2,A3>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3>,MultiActionCore<std::variant<A0,A1,A2,A3>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3>(std::in_place_index<3>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4>,MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4>,MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3,A4> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4>(std::in_place_index<4>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3,A4,A5> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5>(std::in_place_index<5>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6>(std::in_place_index<6>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7>(std::in_place_index<7>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>(std::in_place_index<8>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, true, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>, public RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,true,FireOnceOnly,T>> {
private:
    bool done_;
    std::function<void(void *)> idleWorker_;
    std::mutex idleWorkerMutex_;
    T t_;
    std::function<void()> startWaiter_;
    std::mutex startWaiterMutex_;
public:
    virtual void *getIdleHandlerParam() {return nullptr;}
    void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (!this->timeCheckGood(data)) {
            return;
        }
        data.timedData.finalFlag = this->timeChecker().isFinalUpdate();
        auto res = t_.action(std::move(data));
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
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(), RealTimeAppComponents<StateT>::template ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,true,FireOnceOnly,T>>(), done_(false), idleWorker_(), idleWorkerMutex_(), t_(std::move(f)), startWaiter_(), startWaiterMutex_() {
    }
    virtual ~MultiActionCore() {
    }
    virtual bool isThreaded() const override final {
        return true;
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        idleWorker_ = worker;
    }
    void idleWork() {
        std::lock_guard<std::mutex> _(idleWorkerMutex_);
        if (idleWorker_) {
            idleWorker_(t_.getIdleHandlerParam());
        }
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        startWaiter_ = waiter;
    }
    void waitForStart() {
        std::lock_guard<std::mutex> _(startWaiterMutex_);
        if (startWaiter_) {
            startWaiter_();
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, bool FireOnceOnly, class T>
class MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, false, FireOnceOnly, T> : public RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    typename RealTimeAppComponents<StateT>::template TimeChecker<true, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> timeChecker_;
    std::conditional_t<FireOnceOnly,std::atomic<bool>,bool> done_;
    T t_;
protected:
    virtual void *getIdleHandlerParam() {return nullptr;}
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
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
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(std::in_place_index<9>, std::move(x));
    }
public:
    template <class F>
    MultiActionCore(F &&f) : RealTimeAppComponents<StateT>::template AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(), timeChecker_(), done_(false), t_(std::move(f)) {
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
    virtual void setIdleWorker(std::function<void(void *)> worker) override final {
    }
    virtual void setStartWaiter(std::function<void()> waiter) override final {
    }
};