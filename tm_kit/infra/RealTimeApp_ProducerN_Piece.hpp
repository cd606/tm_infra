template <class A0, class A1>
class Producer<std::variant<A0,A1>> : public virtual IStoppableRealTimeProducer<2> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2>
class Producer<std::variant<A0,A1,A2>> : public virtual IStoppableRealTimeProducer<3> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3>
class Producer<std::variant<A0,A1,A2,A3>> : public virtual IStoppableRealTimeProducer<4> {
private:
    std::vector<IHandler<A0> *> handlers0_;
    std::unordered_set<IHandler<A0> *> handlerSet0_;
    std::vector<IHandler<A1> *> handlers1_;
    std::unordered_set<IHandler<A1> *> handlerSet1_;
    std::vector<IHandler<A2> *> handlers2_;
    std::unordered_set<IHandler<A2> *> handlerSet2_;
    std::vector<IHandler<A3> *> handlers3_;
    std::unordered_set<IHandler<A3> *> handlerSet3_;
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4>
class Producer<std::variant<A0,A1,A2,A3,A4>> : public virtual IStoppableRealTimeProducer<5> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5>
class Producer<std::variant<A0,A1,A2,A3,A4,A5>> : public virtual IStoppableRealTimeProducer<6> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6>> : public virtual IStoppableRealTimeProducer<7> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>> : public virtual IStoppableRealTimeProducer<8> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>> : public virtual IStoppableRealTimeProducer<9> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>> : public virtual IStoppableRealTimeProducer<10> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>> : public virtual IStoppableRealTimeProducer<11> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>> : public virtual IStoppableRealTimeProducer<12> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>> : public virtual IStoppableRealTimeProducer<13> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>> : public virtual IStoppableRealTimeProducer<14> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>> : public virtual IStoppableRealTimeProducer<15> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers14_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<14>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers14_[ii]->handle(ownedCopy.clone());
                        }
                        handlers14_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
        for (auto const &h : handlerSet14_) {
            h->notifyForSourceTermination(info, (A14 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>> : public virtual IStoppableRealTimeProducer<16> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers14_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<14>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers14_[ii]->handle(ownedCopy.clone());
                        }
                        handlers14_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers15_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<15>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers15_[ii]->handle(ownedCopy.clone());
                        }
                        handlers15_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
        for (auto const &h : handlerSet14_) {
            h->notifyForSourceTermination(info, (A14 const *) nullptr);
        }
        for (auto const &h : handlerSet15_) {
            h->notifyForSourceTermination(info, (A15 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>> : public virtual IStoppableRealTimeProducer<17> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers14_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<14>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers14_[ii]->handle(ownedCopy.clone());
                        }
                        handlers14_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers15_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<15>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers15_[ii]->handle(ownedCopy.clone());
                        }
                        handlers15_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers16_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<16>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers16_[ii]->handle(ownedCopy.clone());
                        }
                        handlers16_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
        for (auto const &h : handlerSet14_) {
            h->notifyForSourceTermination(info, (A14 const *) nullptr);
        }
        for (auto const &h : handlerSet15_) {
            h->notifyForSourceTermination(info, (A15 const *) nullptr);
        }
        for (auto const &h : handlerSet16_) {
            h->notifyForSourceTermination(info, (A16 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>> : public virtual IStoppableRealTimeProducer<18> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void addHandler_17(IHandler<A17> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet17_.find(h) == handlerSet17_.end()){
            handlers17_.push_back(h);
            handlerSet17_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers14_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<14>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers14_[ii]->handle(ownedCopy.clone());
                        }
                        handlers14_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers15_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<15>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers15_[ii]->handle(ownedCopy.clone());
                        }
                        handlers15_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers16_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<16>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers16_[ii]->handle(ownedCopy.clone());
                        }
                        handlers16_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 17:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers17_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers17_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<17>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17> &&x) {return std::get<17>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers17_[ii]->handle(ownedCopy.clone());
                        }
                        handlers17_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
        for (auto const &h : handlerSet14_) {
            h->notifyForSourceTermination(info, (A14 const *) nullptr);
        }
        for (auto const &h : handlerSet15_) {
            h->notifyForSourceTermination(info, (A15 const *) nullptr);
        }
        for (auto const &h : handlerSet16_) {
            h->notifyForSourceTermination(info, (A16 const *) nullptr);
        }
        for (auto const &h : handlerSet17_) {
            h->notifyForSourceTermination(info, (A17 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>> : public virtual IStoppableRealTimeProducer<19> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void addHandler_17(IHandler<A17> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet17_.find(h) == handlerSet17_.end()){
            handlers17_.push_back(h);
            handlerSet17_.insert(h);
        }
    }
    void addHandler_18(IHandler<A18> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet18_.find(h) == handlerSet18_.end()){
            handlers18_.push_back(h);
            handlerSet18_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers14_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<14>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers14_[ii]->handle(ownedCopy.clone());
                        }
                        handlers14_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers15_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<15>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers15_[ii]->handle(ownedCopy.clone());
                        }
                        handlers15_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers16_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<16>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers16_[ii]->handle(ownedCopy.clone());
                        }
                        handlers16_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 17:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers17_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers17_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<17>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<17>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers17_[ii]->handle(ownedCopy.clone());
                        }
                        handlers17_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 18:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers18_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers18_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<18>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18> &&x) {return std::get<18>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers18_[ii]->handle(ownedCopy.clone());
                        }
                        handlers18_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
        for (auto const &h : handlerSet14_) {
            h->notifyForSourceTermination(info, (A14 const *) nullptr);
        }
        for (auto const &h : handlerSet15_) {
            h->notifyForSourceTermination(info, (A15 const *) nullptr);
        }
        for (auto const &h : handlerSet16_) {
            h->notifyForSourceTermination(info, (A16 const *) nullptr);
        }
        for (auto const &h : handlerSet17_) {
            h->notifyForSourceTermination(info, (A17 const *) nullptr);
        }
        for (auto const &h : handlerSet18_) {
            h->notifyForSourceTermination(info, (A18 const *) nullptr);
        }
    }
};
template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, class A15, class A16, class A17, class A18, class A19>
class Producer<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>> : public virtual IStoppableRealTimeProducer<20> {
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
    std::mutex mutex_;
public:
    Producer() = default;
    Producer(Producer const &) = delete;
    Producer &operator=(Producer const &) = delete;
    Producer(Producer &&) = delete;
    Producer &operator=(Producer &&) = delete;
    virtual ~Producer() = default;
    void addHandler_0(IHandler<A0> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet0_.find(h) == handlerSet0_.end()){
            handlers0_.push_back(h);
            handlerSet0_.insert(h);
        }
    }
    void addHandler_1(IHandler<A1> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet1_.find(h) == handlerSet1_.end()){
            handlers1_.push_back(h);
            handlerSet1_.insert(h);
        }
    }
    void addHandler_2(IHandler<A2> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet2_.find(h) == handlerSet2_.end()){
            handlers2_.push_back(h);
            handlerSet2_.insert(h);
        }
    }
    void addHandler_3(IHandler<A3> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet3_.find(h) == handlerSet3_.end()){
            handlers3_.push_back(h);
            handlerSet3_.insert(h);
        }
    }
    void addHandler_4(IHandler<A4> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet4_.find(h) == handlerSet4_.end()){
            handlers4_.push_back(h);
            handlerSet4_.insert(h);
        }
    }
    void addHandler_5(IHandler<A5> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet5_.find(h) == handlerSet5_.end()){
            handlers5_.push_back(h);
            handlerSet5_.insert(h);
        }
    }
    void addHandler_6(IHandler<A6> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet6_.find(h) == handlerSet6_.end()){
            handlers6_.push_back(h);
            handlerSet6_.insert(h);
        }
    }
    void addHandler_7(IHandler<A7> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet7_.find(h) == handlerSet7_.end()){
            handlers7_.push_back(h);
            handlerSet7_.insert(h);
        }
    }
    void addHandler_8(IHandler<A8> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet8_.find(h) == handlerSet8_.end()){
            handlers8_.push_back(h);
            handlerSet8_.insert(h);
        }
    }
    void addHandler_9(IHandler<A9> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet9_.find(h) == handlerSet9_.end()){
            handlers9_.push_back(h);
            handlerSet9_.insert(h);
        }
    }
    void addHandler_10(IHandler<A10> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet10_.find(h) == handlerSet10_.end()){
            handlers10_.push_back(h);
            handlerSet10_.insert(h);
        }
    }
    void addHandler_11(IHandler<A11> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet11_.find(h) == handlerSet11_.end()){
            handlers11_.push_back(h);
            handlerSet11_.insert(h);
        }
    }
    void addHandler_12(IHandler<A12> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet12_.find(h) == handlerSet12_.end()){
            handlers12_.push_back(h);
            handlerSet12_.insert(h);
        }
    }
    void addHandler_13(IHandler<A13> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet13_.find(h) == handlerSet13_.end()){
            handlers13_.push_back(h);
            handlerSet13_.insert(h);
        }
    }
    void addHandler_14(IHandler<A14> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet14_.find(h) == handlerSet14_.end()){
            handlers14_.push_back(h);
            handlerSet14_.insert(h);
        }
    }
    void addHandler_15(IHandler<A15> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet15_.find(h) == handlerSet15_.end()){
            handlers15_.push_back(h);
            handlerSet15_.insert(h);
        }
    }
    void addHandler_16(IHandler<A16> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet16_.find(h) == handlerSet16_.end()){
            handlers16_.push_back(h);
            handlerSet16_.insert(h);
        }
    }
    void addHandler_17(IHandler<A17> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet17_.find(h) == handlerSet17_.end()){
            handlers17_.push_back(h);
            handlerSet17_.insert(h);
        }
    }
    void addHandler_18(IHandler<A18> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet18_.find(h) == handlerSet18_.end()){
            handlers18_.push_back(h);
            handlerSet18_.insert(h);
        }
    }
    void addHandler_19(IHandler<A19> *h) {
        if (h == nullptr) {
            return;
        }
        std::lock_guard<std::mutex> _(mutex_);
        if (handlerSet19_.find(h) == handlerSet19_.end()){
            handlers19_.push_back(h);
            handlerSet19_.insert(h);
        }
    }
    void publish(StateT *env, std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&data) {
        publish(withtime_utils::pureTimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType>(env, std::move(data)));
    }
    void publish(TimedDataWithEnvironment<std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19>, StateT, typename StateT::TimePointType> &&data) {
        if (this->producerIsStopped(data.timedData.value.index())) {
            return;
        }
        switch (data.timedData.value.index()) {
        case 0:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers0_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers0_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<0>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<0>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers0_[ii]->handle(ownedCopy.clone());
                        }
                        handlers0_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 1:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers1_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers1_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<1>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<1>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers1_[ii]->handle(ownedCopy.clone());
                        }
                        handlers1_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 2:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers2_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers2_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<2>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<2>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers2_[ii]->handle(ownedCopy.clone());
                        }
                        handlers2_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 3:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers3_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers3_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<3>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<3>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers3_[ii]->handle(ownedCopy.clone());
                        }
                        handlers3_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 4:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers4_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers4_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<4>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<4>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers4_[ii]->handle(ownedCopy.clone());
                        }
                        handlers4_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 5:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers5_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers5_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<5>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<5>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers5_[ii]->handle(ownedCopy.clone());
                        }
                        handlers5_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 6:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers6_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers6_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<6>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<6>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers6_[ii]->handle(ownedCopy.clone());
                        }
                        handlers6_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 7:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers7_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers7_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<7>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<7>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers7_[ii]->handle(ownedCopy.clone());
                        }
                        handlers7_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 8:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers8_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers8_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<8>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<8>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers8_[ii]->handle(ownedCopy.clone());
                        }
                        handlers8_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 9:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers9_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers9_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<9>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<9>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers9_[ii]->handle(ownedCopy.clone());
                        }
                        handlers9_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 10:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers10_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers10_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<10>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<10>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers10_[ii]->handle(ownedCopy.clone());
                        }
                        handlers10_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 11:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers11_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers11_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<11>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<11>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers11_[ii]->handle(ownedCopy.clone());
                        }
                        handlers11_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 12:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers12_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers12_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<12>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<12>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers12_[ii]->handle(ownedCopy.clone());
                        }
                        handlers12_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 13:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers13_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers13_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<13>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<13>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers13_[ii]->handle(ownedCopy.clone());
                        }
                        handlers13_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 14:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers14_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers14_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<14>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<14>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers14_[ii]->handle(ownedCopy.clone());
                        }
                        handlers14_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 15:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers15_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers15_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<15>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<15>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers15_[ii]->handle(ownedCopy.clone());
                        }
                        handlers15_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 16:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers16_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers16_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<16>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<16>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers16_[ii]->handle(ownedCopy.clone());
                        }
                        handlers16_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 17:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers17_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers17_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<17>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<17>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers17_[ii]->handle(ownedCopy.clone());
                        }
                        handlers17_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 18:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers18_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers18_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<18>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<18>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers18_[ii]->handle(ownedCopy.clone());
                        }
                        handlers18_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        case 19:
            {
                //In "publish", the system has reached stable state, so mutex is no longer needed
                //std::lock_guard<std::mutex> _(mutex_);
                auto s = handlers19_.size();
                switch (s) {
                case 0:
                    return;
                case 1:
                    handlers19_.front()->handle(std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<19>(std::move(x));}, true));
                    break;
                default:
                    {
                        auto ownedCopy {std::move(data).mapMove([](std::variant<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19> &&x) {return std::get<19>(std::move(x));}, true)};
                        for (auto ii=0; ii<s-1; ++ii) {
                            handlers19_[ii]->handle(ownedCopy.clone());
                        }
                        handlers19_[s-1]->handle(std::move(ownedCopy));
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
    }
    void notifyHandlersForTermination(std::any const &info) {
        for (auto const &h : handlerSet0_) {
            h->notifyForSourceTermination(info, (A0 const *) nullptr);
        }
        for (auto const &h : handlerSet1_) {
            h->notifyForSourceTermination(info, (A1 const *) nullptr);
        }
        for (auto const &h : handlerSet2_) {
            h->notifyForSourceTermination(info, (A2 const *) nullptr);
        }
        for (auto const &h : handlerSet3_) {
            h->notifyForSourceTermination(info, (A3 const *) nullptr);
        }
        for (auto const &h : handlerSet4_) {
            h->notifyForSourceTermination(info, (A4 const *) nullptr);
        }
        for (auto const &h : handlerSet5_) {
            h->notifyForSourceTermination(info, (A5 const *) nullptr);
        }
        for (auto const &h : handlerSet6_) {
            h->notifyForSourceTermination(info, (A6 const *) nullptr);
        }
        for (auto const &h : handlerSet7_) {
            h->notifyForSourceTermination(info, (A7 const *) nullptr);
        }
        for (auto const &h : handlerSet8_) {
            h->notifyForSourceTermination(info, (A8 const *) nullptr);
        }
        for (auto const &h : handlerSet9_) {
            h->notifyForSourceTermination(info, (A9 const *) nullptr);
        }
        for (auto const &h : handlerSet10_) {
            h->notifyForSourceTermination(info, (A10 const *) nullptr);
        }
        for (auto const &h : handlerSet11_) {
            h->notifyForSourceTermination(info, (A11 const *) nullptr);
        }
        for (auto const &h : handlerSet12_) {
            h->notifyForSourceTermination(info, (A12 const *) nullptr);
        }
        for (auto const &h : handlerSet13_) {
            h->notifyForSourceTermination(info, (A13 const *) nullptr);
        }
        for (auto const &h : handlerSet14_) {
            h->notifyForSourceTermination(info, (A14 const *) nullptr);
        }
        for (auto const &h : handlerSet15_) {
            h->notifyForSourceTermination(info, (A15 const *) nullptr);
        }
        for (auto const &h : handlerSet16_) {
            h->notifyForSourceTermination(info, (A16 const *) nullptr);
        }
        for (auto const &h : handlerSet17_) {
            h->notifyForSourceTermination(info, (A17 const *) nullptr);
        }
        for (auto const &h : handlerSet18_) {
            h->notifyForSourceTermination(info, (A18 const *) nullptr);
        }
        for (auto const &h : handlerSet19_) {
            h->notifyForSourceTermination(info, (A19 const *) nullptr);
        }
    }
};