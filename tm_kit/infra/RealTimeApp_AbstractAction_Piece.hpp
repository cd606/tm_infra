template <class A0, class A1, class B>
class AbstractAction<std::variant<A0,A1>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class B>
class SingleEntryAbstractAction<std::variant<A0,A1>,B> : public AbstractAction<std::variant<A0,A1>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class B>
class AbstractAction<std::variant<A0,A1,A2>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2>,B> : public AbstractAction<std::variant<A0,A1,A2>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class B>
class AbstractAction<std::variant<A0,A1,A2,A3>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3>,B> : public AbstractAction<std::variant<A0,A1,A2,A3>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A14 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {14, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> {std::in_place_index<14>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A14 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {14, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A15 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {15, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<14>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> {std::in_place_index<15>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A14 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {14, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A15 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {15, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A16 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {16, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<14>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<15>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> {std::in_place_index<16>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public virtual IHandler<A17>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A14 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {14, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A15 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {15, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A16 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {16, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A17 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {17, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<14>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<15>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<16>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A17, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> {std::in_place_index<17>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public virtual IHandler<A17>, public virtual IHandler<A18>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A14 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {14, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A15 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {15, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A16 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {16, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A17 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {17, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A18 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {18, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<14>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<15>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<16>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A17, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<17>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A18, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> {std::in_place_index<18>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
class AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public virtual IHandler<A2>, public virtual IHandler<A3>, public virtual IHandler<A4>, public virtual IHandler<A5>, public virtual IHandler<A6>, public virtual IHandler<A7>, public virtual IHandler<A8>, public virtual IHandler<A9>, public virtual IHandler<A10>, public virtual IHandler<A11>, public virtual IHandler<A12>, public virtual IHandler<A13>, public virtual IHandler<A14>, public virtual IHandler<A15>, public virtual IHandler<A16>, public virtual IHandler<A17>, public virtual IHandler<A18>, public virtual IHandler<A19>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    virtual bool isThreaded() const = 0;
    virtual bool isOneTimeOnly() const = 0;
    virtual void setIdleWorker(std::function<void(void *)> worker) = 0;
    virtual void setStartWaiter(std::function<void()> waiter) = 0;
    void control(StateT *env, std::string const &command, std::vector<std::string> const &params) override final {
        if (command == "stop") {
            if (params.empty()) {
                this->stopProducer();
            } else {
                this->stopProducer((uint8_t) std::stoi(params[0]));
            }
        } else if (command == "restart") {
            if (params.empty()) {
                this->restartProducer();
            } else {
                this->restartProducer((uint8_t) std::stoi(params[0]));
            }
        }
    }
    std::vector<std::string> observe(StateT *env) const override final {
        return this->producerStoppedStatus();
    }
    virtual void notifyForSourceTermination(std::any const &info, A0 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {0, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A1 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {1, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A2 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {2, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A3 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {3, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A4 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {4, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A5 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {5, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A6 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {6, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A7 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {7, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A8 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {8, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A9 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {9, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A10 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {10, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A11 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {11, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A12 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {12, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A13 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {13, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A14 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {14, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A15 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {15, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A16 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {16, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A17 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {17, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A18 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {18, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
    virtual void notifyForSourceTermination(std::any const &info, A19 const *notUsed) override {
        std::tuple<std::size_t, std::any> wrappedAny {19, info};
        this->Producer<B>::notifyHandlersForTermination(std::any {wrappedAny});
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
class SingleEntryAbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> : public AbstractAction<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> {
public:
    virtual void handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> &&data) = 0;
    virtual void handle(TimedDataWithEnvironment<A0, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<0>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A1, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<1>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A2, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<2>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A3, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<3>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A4, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<4>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A5, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<5>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A6, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<6>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A7, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<7>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A8, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<8>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A9, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<9>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A10, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<10>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A11, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<11>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A12, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<12>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A13, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<13>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A14, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<14>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A15, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<15>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A16, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<16>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A17, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<17>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A18, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<18>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
    virtual void handle(TimedDataWithEnvironment<A19, StateT, typename StateT::TimePointType> &&data) override final {
        handle(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> {
            data.environment
            , {
                data.timedData.timePoint
                , std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> {std::in_place_index<19>, std::move(data.timedData.value)}
                , data.timedData.finalFlag
            }
        });
    }
};