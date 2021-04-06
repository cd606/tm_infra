private:
    template <class A0, class A1, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti2 final : public MultiActionCore<std::variant<A0,A1>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti2(F &&f) : MultiActionCore<std::variant<A0,A1>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti2() {}
    };
public:
    template <class A0, class A1, class F>
    static auto enhancedMulti2(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> ( new EnhancedMulti2<A0,A1,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> ( new EnhancedMulti2<A0,A1,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> ( new EnhancedMulti2<A0,A1,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type>> ( new EnhancedMulti2<A0,A1,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti3 final : public MultiActionCore<std::variant<A0,A1,A2>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti3(F &&f) : MultiActionCore<std::variant<A0,A1,A2>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti3() {}
    };
public:
    template <class A0, class A1, class A2, class F>
    static auto enhancedMulti3(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> ( new EnhancedMulti3<A0,A1,A2,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> ( new EnhancedMulti3<A0,A1,A2,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> ( new EnhancedMulti3<A0,A1,A2,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type>> ( new EnhancedMulti3<A0,A1,A2,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti4 final : public MultiActionCore<std::variant<A0,A1,A2,A3>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti4(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti4() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class F>
    static auto enhancedMulti4(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> ( new EnhancedMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> ( new EnhancedMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> ( new EnhancedMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type>> ( new EnhancedMulti4<A0,A1,A2,A3,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti5 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti5(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti5() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class F>
    static auto enhancedMulti5(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> ( new EnhancedMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> ( new EnhancedMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> ( new EnhancedMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type>> ( new EnhancedMulti5<A0,A1,A2,A3,A4,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti6 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti6(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti6() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class F>
    static auto enhancedMulti6(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> ( new EnhancedMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> ( new EnhancedMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> ( new EnhancedMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type>> ( new EnhancedMulti6<A0,A1,A2,A3,A4,A5,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti7 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti7(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti7() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class F>
    static auto enhancedMulti7(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> ( new EnhancedMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> ( new EnhancedMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> ( new EnhancedMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type>> ( new EnhancedMulti7<A0,A1,A2,A3,A4,A5,A6,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti8 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti8(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti8() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class F>
    static auto enhancedMulti8(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> ( new EnhancedMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> ( new EnhancedMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> ( new EnhancedMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type>> ( new EnhancedMulti8<A0,A1,A2,A3,A4,A5,A6,A7,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti9 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti9(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti9() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class F>
    static auto enhancedMulti9(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> ( new EnhancedMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> ( new EnhancedMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> ( new EnhancedMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type>> ( new EnhancedMulti9<A0,A1,A2,A3,A4,A5,A6,A7,A8,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
private:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B, class F, bool Threaded, bool FireOnceOnly>
    class EnhancedMulti10 final : public MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, B, Threaded, FireOnceOnly> {
    private:
        F f_;
    protected:
        virtual MultiData<B> action(InnerData<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> &&data) override final {
            auto ret = f_(std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {data.timedData.timePoint, std::move(data.timedData.value)});
            if (!ret.empty()) {
                return pureInnerData(data.environment, WithTime<std::vector<B>,TimePoint> {std::move(data.timedData.timePoint), std::move(ret), data.timedData.finalFlag});
            } else {
                return std::nullopt;
            }
        }
        virtual void *getIdleHandlerParam() override final {
            return (void *) &f_;
        }
    public:
        EnhancedMulti10(F &&f) : MultiActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B,Threaded,FireOnceOnly>(), f_(std::move(f)) {}
        virtual ~EnhancedMulti10() {}
    };
public:
    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class F>
    static auto enhancedMulti10(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> {
        if (liftParam.fireOnceOnly) {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> ( new EnhancedMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type,F,true,true>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> ( new EnhancedMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type,F,false,true>(std::move(f)) );
            }
        } else {
            if (liftParam.suggestThreaded) {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> ( new EnhancedMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type,F,true,false>(std::move(f)) );
            } else {
                return std::make_shared<Action<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type>> ( new EnhancedMulti10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,typename decltype(f(std::move(*((std::tuple<TimePoint, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> *) nullptr))))::value_type,F,false,false>(std::move(f)) );
            }
        }
    }
public:
    template <class A, class F>
    static auto enhancedMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(std::move(*((std::tuple<TimePoint, A> *) nullptr))))::value_type>> {
        if constexpr (!withtime_utils::IsVariant<A>::Value) {
            return enhancedMulti1<A,F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 2) {
            return enhancedMulti2<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 3) {
            return enhancedMulti3<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 4) {
            return enhancedMulti4<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 5) {
            return enhancedMulti5<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 6) {
            return enhancedMulti6<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 7) {
            return enhancedMulti7<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 8) {
            return enhancedMulti8<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 9) {
            return enhancedMulti9<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, F>(std::move(f), liftParam);
        } else if constexpr (std::variant_size_v<A> == 10) {
            return enhancedMulti10<std::variant_alternative_t<0,A>, std::variant_alternative_t<1,A>, std::variant_alternative_t<2,A>, std::variant_alternative_t<3,A>, std::variant_alternative_t<4,A>, std::variant_alternative_t<5,A>, std::variant_alternative_t<6,A>, std::variant_alternative_t<7,A>, std::variant_alternative_t<8,A>, std::variant_alternative_t<9,A>, F>(std::move(f), liftParam);
        } else {
            throw std::runtime_error("enhancedMulti: bad template parameter");
        }
    }