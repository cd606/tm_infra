template <class A0, class A1>
class ProducerBase<std::variant<A0,A1>> : public virtual IStoppableProducer<2> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, bool IsImporter>
class Producer<std::variant<A0,A1>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2>
class ProducerBase<std::variant<A0,A1,A2>> : public virtual IStoppableProducer<3> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, bool IsImporter>
class Producer<std::variant<A0,A1,A2>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3>
class ProducerBase<std::variant<A0,A1,A2,A3>> : public virtual IStoppableProducer<4> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class ProducerBase<std::variant<A0,A1,A2,A3,A4>> : public virtual IStoppableProducer<5> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5>> : public virtual IStoppableProducer<6> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6>> : public virtual IStoppableProducer<7> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> : public virtual IStoppableProducer<8> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> : public virtual IStoppableProducer<9> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> : public virtual IStoppableProducer<10> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> : public virtual IStoppableProducer<11> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> : public virtual IStoppableProducer<12> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> : public virtual IStoppableProducer<13> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> : public virtual IStoppableProducer<14> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> : public virtual IStoppableProducer<15> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;
    std::vector<IHandler<A14> *> handlers14_;
    std::unordered_set<IHandler<A14> *> handlerSet14_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers14_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<14>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers14_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers14_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> : public virtual IStoppableProducer<16> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;
    std::vector<IHandler<A14> *> handlers14_;
    std::unordered_set<IHandler<A14> *> handlerSet14_;
    std::vector<IHandler<A15> *> handlers15_;
    std::unordered_set<IHandler<A15> *> handlerSet15_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers14_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<14>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers14_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers14_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers15_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<15>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers15_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers15_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> : public virtual IStoppableProducer<17> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;
    std::vector<IHandler<A14> *> handlers14_;
    std::unordered_set<IHandler<A14> *> handlerSet14_;
    std::vector<IHandler<A15> *> handlers15_;
    std::unordered_set<IHandler<A15> *> handlerSet15_;
    std::vector<IHandler<A16> *> handlers16_;
    std::unordered_set<IHandler<A16> *> handlerSet16_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers14_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<14>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers14_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers14_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers15_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<15>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers15_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers15_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers16_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<16>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers16_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers16_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> : public virtual IStoppableProducer<18> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;
    std::vector<IHandler<A14> *> handlers14_;
    std::unordered_set<IHandler<A14> *> handlerSet14_;
    std::vector<IHandler<A15> *> handlers15_;
    std::unordered_set<IHandler<A15> *> handlerSet15_;
    std::vector<IHandler<A16> *> handlers16_;
    std::unordered_set<IHandler<A16> *> handlerSet16_;
    std::vector<IHandler<A17> *> handlers17_;
    std::unordered_set<IHandler<A17> *> handlerSet17_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void addHandler_17(IHandler<A17> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet17_.find(h) == handlerSet17_.end()){
            handlers17_.push_back(h);
            handlerSet17_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers14_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<14>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers14_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers14_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers15_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<15>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers15_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers15_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers16_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<16>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers16_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers16_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 17:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers17_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers17_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<17>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<17>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers17_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers17_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> : public virtual IStoppableProducer<19> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;
    std::vector<IHandler<A14> *> handlers14_;
    std::unordered_set<IHandler<A14> *> handlerSet14_;
    std::vector<IHandler<A15> *> handlers15_;
    std::unordered_set<IHandler<A15> *> handlerSet15_;
    std::vector<IHandler<A16> *> handlers16_;
    std::unordered_set<IHandler<A16> *> handlerSet16_;
    std::vector<IHandler<A17> *> handlers17_;
    std::unordered_set<IHandler<A17> *> handlerSet17_;
    std::vector<IHandler<A18> *> handlers18_;
    std::unordered_set<IHandler<A18> *> handlerSet18_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void addHandler_17(IHandler<A17> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet17_.find(h) == handlerSet17_.end()){
            handlers17_.push_back(h);
            handlerSet17_.insert(h);
        }
    }
    void addHandler_18(IHandler<A18> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet18_.find(h) == handlerSet18_.end()){
            handlers18_.push_back(h);
            handlerSet18_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers14_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<14>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers14_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers14_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers15_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<15>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers15_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers15_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers16_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<16>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers16_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers16_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 17:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers17_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers17_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<17>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<17>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers17_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers17_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 18:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers18_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers18_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<18>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<18>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers18_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers18_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> : public virtual IStoppableProducer<20> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::vector<IHandler<A4> *> handlers4_;
    std::unordered_set<IHandler<A4> *> handlerSet4_;
    std::vector<IHandler<A5> *> handlers5_;
    std::unordered_set<IHandler<A5> *> handlerSet5_;
    std::vector<IHandler<A6> *> handlers6_;
    std::unordered_set<IHandler<A6> *> handlerSet6_;
    std::vector<IHandler<A7> *> handlers7_;
    std::unordered_set<IHandler<A7> *> handlerSet7_;
    std::vector<IHandler<A8> *> handlers8_;
    std::unordered_set<IHandler<A8> *> handlerSet8_;
    std::vector<IHandler<A9> *> handlers9_;
    std::unordered_set<IHandler<A9> *> handlerSet9_;
    std::vector<IHandler<A10> *> handlers10_;
    std::unordered_set<IHandler<A10> *> handlerSet10_;
    std::vector<IHandler<A11> *> handlers11_;
    std::unordered_set<IHandler<A11> *> handlerSet11_;
    std::vector<IHandler<A12> *> handlers12_;
    std::unordered_set<IHandler<A12> *> handlerSet12_;
    std::vector<IHandler<A13> *> handlers13_;
    std::unordered_set<IHandler<A13> *> handlerSet13_;
    std::vector<IHandler<A14> *> handlers14_;
    std::unordered_set<IHandler<A14> *> handlerSet14_;
    std::vector<IHandler<A15> *> handlers15_;
    std::unordered_set<IHandler<A15> *> handlerSet15_;
    std::vector<IHandler<A16> *> handlers16_;
    std::unordered_set<IHandler<A16> *> handlerSet16_;
    std::vector<IHandler<A17> *> handlers17_;
    std::unordered_set<IHandler<A17> *> handlerSet17_;
    std::vector<IHandler<A18> *> handlers18_;
    std::unordered_set<IHandler<A18> *> handlerSet18_;
    std::vector<IHandler<A19> *> handlers19_;
    std::unordered_set<IHandler<A19> *> handlerSet19_;

    friend class TopDownSinglePassIterationApp;

    TopDownSinglePassIterationApp *parent_ = nullptr;
    virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) {
    }
public:
    ProducerBase() = default;
    ProducerBase(ProducerBase const &) = delete;
    ProducerBase &operator=(ProducerBase const &) = delete;
    ProducerBase(ProducerBase &&) = delete;
    ProducerBase &operator=(ProducerBase &&) = delete;
    virtual ~ProducerBase() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void addHandler_17(IHandler<A17> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet17_.find(h) == handlerSet17_.end()){
            handlers17_.push_back(h);
            handlerSet17_.insert(h);
        }
    }
    void addHandler_18(IHandler<A18> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet18_.find(h) == handlerSet18_.end()){
            handlers18_.push_back(h);
            handlerSet18_.insert(h);
        }
    }
    void addHandler_19(IHandler<A19> *h) {
        if (h == nullptr) {
            return;
        }
        if (handlerSet19_.find(h) == handlerSet19_.end()){
            handlers19_.push_back(h);
            handlerSet19_.insert(h);
        }
    }
    void setParentForProducer(TopDownSinglePassIterationApp *parent) {
        parent_ = parent;
        this->setParentAdditionalSteps(parent);
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19, bool IsImporter>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>,IsImporter> : public virtual ProducerBase<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> {
private:
    AbstractImporterBase *asImporter() {
        if constexpr (IsImporter) {
            static AbstractImporterBase *ret = nullptr;
            if (ret == nullptr) {
                ret = dynamic_cast<AbstractImporterBase *>(this);
            }
            return ret;
        } else {
            return nullptr;
        }
    }
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&data) {
        if (this->producerIsStopped(data.index())) {
            return;
        }
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        if (this->parent_ == nullptr) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers0_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<0>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers0_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers0_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers1_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<1>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers1_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers1_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers2_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<2>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers2_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers2_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers3_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<3>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers3_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers3_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers4_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<4>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers4_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers4_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers5_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<5>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers5_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers5_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers6_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<6>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers6_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers6_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers7_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<7>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers7_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers7_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers8_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<8>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers8_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers8_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers9_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<9>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers9_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers9_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers10_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<10>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers10_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers10_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers11_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<11>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers11_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers11_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers12_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<12>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers12_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers12_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers13_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<13>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers13_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers13_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers14_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<14>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers14_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers14_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers15_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<15>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers15_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers15_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers16_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<16>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers16_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers16_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 17:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers17_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers17_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<17>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<17>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers17_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers17_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 18:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers18_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers18_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<18>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<18>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers18_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers18_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        case 19:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                auto s = this->handlers19_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    {
                        auto tp = data.timedData.timePoint;
                        auto *p = this->handlers19_.front();
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<19>(std::move(x));}, true)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                default:
                    {
                        auto tp = data.timedData.timePoint;
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<19>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            auto *p = this->handlers19_[ii];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=ownedCopy.clone()]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        auto *p = this->handlers19_[s-1];
                        this->parent_->enqueueTask(
                            asImporter()
                            , tp
                            , [p,data=std::move(ownedCopy)]() mutable {
                                p->handle(std::move(data));
                            }
                        );
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
};