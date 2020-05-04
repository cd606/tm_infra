private:
    template <class A0, class A1>
    class Merge2 final : public ActionCore<std::variant<A0,A1>,std::tuple<A0,A1>,false> {
    protected:
        virtual Data<std::tuple<A0,A1>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1>,TimePoint> {a0.timePoint, std::tuple<A0,A1> {std::move(a0.value), std::move(a1.value)}, (a0.finalFlag && a1.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1>,TimePoint> {a1.timePoint, std::tuple<A0,A1> {std::move(a0.value), std::move(a1.value)}, (a0.finalFlag && a1.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge2(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1>,std::tuple<A0,A1>,false>(requireMask) {}
        virtual ~Merge2() {}
    };
public:
    template <class A0, class A1>
    static std::shared_ptr<Action<std::variant<A0,A1>,std::tuple<A0,A1>>> merge2(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1>,std::tuple<A0,A1>>> ( new Merge2<A0,A1>(requireMask) );
    }
private:
    template <class A0, class A1, class A2>
    class Merge3 final : public ActionCore<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2> {std::move(a0.value), std::move(a1.value), std::move(a2.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2> {std::move(a0.value), std::move(a1.value), std::move(a2.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2> {std::move(a0.value), std::move(a1.value), std::move(a2.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge3(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>,false>(requireMask) {}
        virtual ~Merge3() {}
    };
public:
    template <class A0, class A1, class A2>
    static std::shared_ptr<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>> merge3(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2>,std::tuple<A0,A1,A2>>> ( new Merge3<A0,A1,A2>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3>
    class Merge4 final : public ActionCore<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge4(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>,false>(requireMask) {}
        virtual ~Merge4() {}
    };
public:
    template <class A0, class A1, class A2, class A3>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>> merge4(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3>,std::tuple<A0,A1,A2,A3>>> ( new Merge4<A0,A1,A2,A3>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3, class A4>
    class Merge5 final : public ActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3,A4>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3,A4> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3,A4> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3,A4> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3,A4> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4>,TimePoint> {a4.timePoint, std::tuple<A0,A1,A2,A3,A4> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge5(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>,false>(requireMask) {}
        virtual ~Merge5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>> merge5(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,std::tuple<A0,A1,A2,A3,A4>>> ( new Merge5<A0,A1,A2,A3,A4>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    class Merge6 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3,A4,A5>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3,A4,A5> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3,A4,A5> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3,A4,A5> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3,A4,A5> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5>,TimePoint> {a4.timePoint, std::tuple<A0,A1,A2,A3,A4,A5> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5>,TimePoint> {a5.timePoint, std::tuple<A0,A1,A2,A3,A4,A5> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge6(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>,false>(requireMask) {}
        virtual ~Merge6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>> merge6(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,std::tuple<A0,A1,A2,A3,A4,A5>>> ( new Merge6<A0,A1,A2,A3,A4,A5>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    class Merge7 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3,A4,A5,A6>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a4.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a5.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6>,TimePoint> {a6.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge7(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>,false>(requireMask) {}
        virtual ~Merge7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> merge7(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,std::tuple<A0,A1,A2,A3,A4,A5,A6>>> ( new Merge7<A0,A1,A2,A3,A4,A5,A6>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    class Merge8 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a4.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a5.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a6.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            case 7:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,TimePoint> {a7.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge8(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>,false>(requireMask) {}
        virtual ~Merge8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> merge8(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7>>> ( new Merge8<A0,A1,A2,A3,A4,A5,A6,A7>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    class Merge9 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a4.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a5.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a6.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 7:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a7.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            case 8:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,TimePoint> {a8.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge9(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>,false>(requireMask) {}
        virtual ~Merge9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> merge9(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8>>> ( new Merge9<A0,A1,A2,A3,A4,A5,A6,A7,A8>(requireMask) );
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    class Merge10 final : public ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,false> {
    protected:
        virtual Data<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> action(StateT *env, int which, WithTime<A0,TimePoint> &&a0, WithTime<A1,TimePoint> &&a1, WithTime<A2,TimePoint> &&a2, WithTime<A3,TimePoint> &&a3, WithTime<A4,TimePoint> &&a4, WithTime<A5,TimePoint> &&a5, WithTime<A6,TimePoint> &&a6, WithTime<A7,TimePoint> &&a7, WithTime<A8,TimePoint> &&a8, WithTime<A9,TimePoint> &&a9) override final {
            switch (which) {
            case 0:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a0.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 1:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a1.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 2:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a2.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 3:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a3.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 4:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a4.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 5:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a5.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 6:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a6.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 7:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a7.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 8:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a8.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            case 9:
                return pureInnerData(env, WithTime<std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,TimePoint> {a9.timePoint, std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::move(a0.value), std::move(a1.value), std::move(a2.value), std::move(a3.value), std::move(a4.value), std::move(a5.value), std::move(a6.value), std::move(a7.value), std::move(a8.value), std::move(a9.value)}, (a0.finalFlag && a1.finalFlag && a2.finalFlag && a3.finalFlag && a4.finalFlag && a5.finalFlag && a6.finalFlag && a7.finalFlag && a8.finalFlag && a9.finalFlag)});
            default:
                return std::nullopt;
            }
        }
    public:
        Merge10(FanInParamMask const &requireMask=FanInParamMask()) : ActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,false>(requireMask) {}
        virtual ~Merge10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    static std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> merge10(FanInParamMask const &requireMask=FanInParamMask()) {
        return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,std::tuple<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>> ( new Merge10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(requireMask) );
    }