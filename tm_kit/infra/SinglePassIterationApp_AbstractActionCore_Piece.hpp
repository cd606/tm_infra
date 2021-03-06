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