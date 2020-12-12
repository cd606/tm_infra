template <class A0, class A1>
class ThreadedHandler<std::variant<A0,A1>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public ThreadedHandlerBase<std::variant<A0,A1>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1>>() {
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
template <class A0, class A1, class A2>
class ThreadedHandler<std::variant<A0,A1,A2>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public ThreadedHandlerBase<std::variant<A0,A1,A2>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2>>() {
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
template <class A0, class A1, class A2, class A3>
class ThreadedHandler<std::variant<A0,A1,A2,A3>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3>>() {
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
template <class A0, class A1, class A2, class A3, class A4>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4>>() {
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
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5>>() {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6>>() {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>() {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>() {
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ThreadedHandler<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
public:
    ThreadedHandler() : ThreadedHandlerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>() {
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