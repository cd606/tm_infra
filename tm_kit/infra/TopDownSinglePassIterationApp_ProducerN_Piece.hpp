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