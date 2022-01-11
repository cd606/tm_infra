template <class A0, class A1, class W>
class ThreadedHandler<std::variant<A0,A1>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public ThreadedHandlerBase<std::variant<A0,A1>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1> fromA0(A0 &&x) {
        return std::variant<A0,A1> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1> fromA1(A1 &&x) {
        return std::variant<A0,A1> {std::in_place_index<1>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class W>
class ThreadedHandler<std::variant<A0,A1,A2>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public ThreadedHandlerBase<std::variant<A0,A1,A2>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<10>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<11>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<12>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<13>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<13>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<14>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA14, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<13>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<14>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<15>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA14, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA15, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<13>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<14>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<15>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<16>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA14, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA15, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA16, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public virtual IHandler<A17>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<13>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<14>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<15>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<16>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> fromA17(A17 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<17>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA14, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA15, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA16, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A17, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA17, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public virtual IHandler<A17>, public virtual IHandler<A18>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<13>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<14>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<15>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<16>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA17(A17 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<17>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> fromA18(A18 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<18>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA14, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA15, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA16, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A17, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA17, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A18, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA18, std::move(data), true));
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class W>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, W> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public virtual IHandler<A17>, public virtual IHandler<A18>, public virtual IHandler<A19>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, W> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, W>() {
    }
    virtual ~ThreadedHandler() {
    }
private:
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA0(A0 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<0>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA1(A1 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<1>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA2(A2 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<2>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA3(A3 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<3>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA4(A4 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<4>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA5(A5 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<5>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA6(A6 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<6>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA7(A7 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<7>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA8(A8 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<8>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA9(A9 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<9>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA10(A10 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<10>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA11(A11 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<11>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA12(A12 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<12>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA13(A13 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<13>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA14(A14 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<14>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA15(A15 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<15>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA16(A16 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<16>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA17(A17 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<17>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA18(A18 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<18>, std::move(x)};
    }
    static std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> fromA19(A19 &&x) {
        return std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<19>, std::move(x)};
    }
public:
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA0, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA1, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA2, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA3, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA4, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA5, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA6, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA7, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA8, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA9, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA10, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA11, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA12, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA13, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA14, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA15, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA16, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A17, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA17, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A18, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA18, std::move(data), true));
    }
    virtual void handle(TimedDataWithEnvironment<A19, StateT, typename StateT::TimePointType> &&data) override final {
        this->putData(withtime_utils::pureTimedDataWithEnvironmentLift(fromA19, std::move(data), true));
    }
};