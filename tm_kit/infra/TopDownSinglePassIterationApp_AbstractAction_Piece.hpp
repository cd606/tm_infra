template <class A0, class A1, class B>
class AbstractAction<std::variant<A0,A1>,B> : public virtual IHandler<A0>, public virtual IHandler<A1>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3,A4>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3,A4,A5>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3,A4,A5,A6>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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
    static_assert((!is_keyed_data_v<B> || is_monostate_keyed_data_v<B> || is_keyed_data_v<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>>), "action cannot manufacture keyed data");
    virtual bool isOneTimeOnly() const = 0;
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