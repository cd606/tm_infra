template <class A0, class A1, class B>
class AbstractActionCore<std::variant<A0,A1>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual AbstractConsumer<A14>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual AbstractConsumer<A14>, public virtual AbstractConsumer<A15>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual AbstractConsumer<A14>, public virtual AbstractConsumer<A15>, public virtual AbstractConsumer<A16>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual AbstractConsumer<A14>, public virtual AbstractConsumer<A15>, public virtual AbstractConsumer<A16>, public virtual AbstractConsumer<A17>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual AbstractConsumer<A14>, public virtual AbstractConsumer<A15>, public virtual AbstractConsumer<A16>, public virtual AbstractConsumer<A17>, public virtual AbstractConsumer<A18>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, class B>
class AbstractActionCore<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,B> : public virtual AbstractConsumer<A0>, public virtual AbstractConsumer<A1>, public virtual AbstractConsumer<A2>, public virtual AbstractConsumer<A3>, public virtual AbstractConsumer<A4>, public virtual AbstractConsumer<A5>, public virtual AbstractConsumer<A6>, public virtual AbstractConsumer<A7>, public virtual AbstractConsumer<A8>, public virtual AbstractConsumer<A9>, public virtual AbstractConsumer<A10>, public virtual AbstractConsumer<A11>, public virtual AbstractConsumer<A12>, public virtual AbstractConsumer<A13>, public virtual AbstractConsumer<A14>, public virtual AbstractConsumer<A15>, public virtual AbstractConsumer<A16>, public virtual AbstractConsumer<A17>, public virtual AbstractConsumer<A18>, public virtual AbstractConsumer<A19>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
public:
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