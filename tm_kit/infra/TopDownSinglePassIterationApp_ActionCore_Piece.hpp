template <class A0, class A1, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1>,B> {
private:
    TimeChecker<std::variant<A0,A1>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
    }
    virtual void handle(InnerData<A0> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA0, std::move(data), true));
    }
    virtual void handle(InnerData<A1> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA1, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
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
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>(std::in_place_index<10>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>(std::in_place_index<11>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>(std::in_place_index<12>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>(std::in_place_index<13>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<13>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>(std::in_place_index<14>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual void handle(InnerData<A14> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA14, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<13>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<14>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>(std::in_place_index<15>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual void handle(InnerData<A14> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA14, std::move(data), true));
    }
    virtual void handle(InnerData<A15> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA15, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<13>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<14>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<15>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>(std::in_place_index<16>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual void handle(InnerData<A14> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA14, std::move(data), true));
    }
    virtual void handle(InnerData<A15> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA15, std::move(data), true));
    }
    virtual void handle(InnerData<A16> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA16, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<13>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<14>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<15>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<16>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA17(A17 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>(std::in_place_index<17>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual void handle(InnerData<A14> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA14, std::move(data), true));
    }
    virtual void handle(InnerData<A15> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA15, std::move(data), true));
    }
    virtual void handle(InnerData<A16> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA16, std::move(data), true));
    }
    virtual void handle(InnerData<A17> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA17, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<13>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<14>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<15>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<16>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA17(A17 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<17>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA18(A18 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>(std::in_place_index<18>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual void handle(InnerData<A14> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA14, std::move(data), true));
    }
    virtual void handle(InnerData<A15> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA15, std::move(data), true));
    }
    virtual void handle(InnerData<A16> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA16, std::move(data), true));
    }
    virtual void handle(InnerData<A17> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA17, std::move(data), true));
    }
    virtual void handle(InnerData<A18> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA18, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B, bool FireOnceOnly, class T>
class ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, B, FireOnceOnly, T> final : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> {
private:
    TimeChecker<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> timeChecker_;
    bool done_;
    T t_;
protected:
    inline void actuallyHandle(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> &&data) {
        if constexpr (FireOnceOnly) {
            if (done_) {
                return;
            }
        }
        if (timeChecker_(data)) {
            GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                data.environment, static_cast<AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> *>(this)
            );
            TraceNodesComponentWrapper<StateT,AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B>> tracer(
                data.environment
                , this
            );
            data.timedData.finalFlag = timeChecker_.isFinalUpdate();
            auto res = t_.action(std::move(data));
            if (res) {
                if constexpr (FireOnceOnly) {
                    res->timedData.finalFlag = true;
                }
                Producer<B>::publish(std::move(*res));
                if constexpr (FireOnceOnly) {
                    done_ = true;
                }
            }
        }
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<0>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<1>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<2>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<3>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<4>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<5>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<6>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<7>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<8>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<9>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<10>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<11>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<12>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<13>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<14>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<15>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<16>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA17(A17 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<17>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA18(A18 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<18>, std::move(x));
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA19(A19 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>(std::in_place_index<19>, std::move(x));
    }
public:
    ActionCore(T &&t) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
    }
    template <class F>
    ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {
    }
    virtual ~ActionCore() {
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
    virtual void handle(InnerData<A10> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA10, std::move(data), true));
    }
    virtual void handle(InnerData<A11> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA11, std::move(data), true));
    }
    virtual void handle(InnerData<A12> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA12, std::move(data), true));
    }
    virtual void handle(InnerData<A13> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA13, std::move(data), true));
    }
    virtual void handle(InnerData<A14> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA14, std::move(data), true));
    }
    virtual void handle(InnerData<A15> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA15, std::move(data), true));
    }
    virtual void handle(InnerData<A16> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA16, std::move(data), true));
    }
    virtual void handle(InnerData<A17> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA17, std::move(data), true));
    }
    virtual void handle(InnerData<A18> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA18, std::move(data), true));
    }
    virtual void handle(InnerData<A19> &&data) override final {
        actuallyHandle(pureInnerDataLift(fromA19, std::move(data), true));
    }
    virtual bool isOneTimeOnly() const override final {
        return FireOnceOnly;
    }
};