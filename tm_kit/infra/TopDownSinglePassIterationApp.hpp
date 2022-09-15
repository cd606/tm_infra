#ifndef TM_KIT_INFRA_TOP_DOWN_SINGLE_PASS_ITERATION_APP_HPP_
#define TM_KIT_INFRA_TOP_DOWN_SINGLE_PASS_ITERATION_APP_HPP_

#include <tm_kit/infra/WithTimeData.hpp>
#include <tm_kit/infra/ControllableNode.hpp>
#include <tm_kit/infra/ObservableNode.hpp>
#include <tm_kit/infra/StoppableProducer.hpp>
#include <tm_kit/infra/Environments.hpp>
#include <tm_kit/infra/GraphStructureBasedResourceHolderComponent.hpp>

#include <vector>
#include <list>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <sstream>
#include <any>
#include <iterator>
#include <array>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class M>
    class SynchronousRunner;

    namespace top_down_single_pass_iteration_app_utils {
        template <class T>
        struct TrueType : std::true_type {};

        template <class T>
        static auto hasSetLocalTime(int) -> TrueType<decltype(std::declval<T>().setLocalTime(std::declval<typename T::TimePointType>()))>;
        template <class T>
        static auto hasSetLocalTime(long) -> std::false_type;

        template <class T>
        static auto hasResetLocalTime(int) -> TrueType<decltype(std::declval<T>().resetLocalTime())>;
        template <class T>
        static auto hasResetLocalTime(long) -> std::false_type;

        template <class Env, bool DontUseSetTime, bool HasSetTime=(decltype(hasSetLocalTime<Env>(0))::value && decltype(hasResetLocalTime<Env>(0))::value)>
        class TimeSetter;
        
        template <class Env, bool DontUseSetTime>
        class TimeSetter<Env, DontUseSetTime, true> {
        private:
            Env *env_;
        public:
            TimeSetter(Env *env, typename Env::TimePointType const &localTime, bool fromImporter) : env_(env) {
                if constexpr (!DontUseSetTime) {
                    if (fromImporter) {
                        env->resolveTime(localTime);
                    }
                    env->setLocalTime(localTime);
                } else {
                    env->resolveTime(localTime);
                }
            }
            ~TimeSetter() {
                if constexpr (!DontUseSetTime) {
                    env_->resetLocalTime();
                }
            }
        };
        template <class Env, bool DontUseSetTime>
        class TimeSetter<Env, DontUseSetTime, false> {
        public:
            TimeSetter(Env *env, typename Env::TimePointType const &tp, bool ) {
                env->resolveTime(tp);
            }
            ~TimeSetter() {}
        };
    }
    
    template <class StateT, std::enable_if_t<StateT::PreserveInputRelativeOrder,int> = 0>
    class TopDownSinglePassIterationApp {
    private:
        static constexpr bool UseExecutionStrategyThatAllowsForHiddenTimeDependency
            = std::is_convertible_v<
                StateT *
                , HiddenTimeDependencyComponent *
            >;
    public:
        friend class AppRunner<TopDownSinglePassIterationApp>;
        friend class SynchronousRunner<TopDownSinglePassIterationApp>;

        static constexpr bool PossiblyMultiThreaded = false;
        static constexpr bool CannotHaveLoopEvenWithFacilities = false;

        using TimePoint = typename StateT::TimePointType;
        using Duration = decltype(TimePoint{} - TimePoint{});
        using StateType = StateT;
        using EnvironmentType = StateT;
        template <class T>
        using TimedDataType = WithTime<T, TimePoint>;
        template <class T>
        using Key = Key<T,StateT>;
        template <class A, class B>
        using KeyedData = KeyedData<A,B,StateT>;

        template <class T>
        static Key<T> keyify(T &&t) {
            return withtime_utils::keyify<T,StateT>(std::move(t));
        }

        template <class T>
        using InnerData = TimedDataWithEnvironment<T, StateType, TimePoint>;

        template <class T>
        static InnerData<T> pureInnerData(StateT *env, T &&t, bool finalFlag = false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(env, std::move(t), finalFlag);
        }
        template <class T>
        static InnerData<T> pureInnerData(StateT *env, TimedDataType<T> &&t, bool preserveTime=false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(env, std::move(t), preserveTime);
        }
        template <class T>
        static InnerData<T> pureInnerData(InnerData<T> &&t, bool preserveTime=false) {
            return withtime_utils::pureTimedDataWithEnvironment<T, StateT, TimePoint>(std::move(t), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(StateT *environment, F &f, TimedDataType<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(F &f, InnerData<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(StateT *environment, F const &f, TimedDataType<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(F const &f, InnerData<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime);
        }

        template <class T>
        using Data = TimedAppData<T,StateT>;

        template <class T>
        using MultiData = TimedAppMultiData<T,StateT>;

        template <class T>
        class IHandler {
        public:
            virtual ~IHandler() {}
            virtual void handle(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) = 0;
        };

        template <class T>
        class TimeChecker {
        private:
            bool hasData_;
            typename StateT::TimePointType lastTime_;
            VersionChecker<T> versionChecker_;
        public:
            TimeChecker() : hasData_(false), lastTime_(), versionChecker_() {}
            inline bool operator()(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> const &data) {
                if (!versionChecker_.checkVersion(data.timedData.value)) {
                    return false;
                }
                if (StateT::CheckTime) {
                    if (hasData_ && data.timedData.timePoint < lastTime_) {
                        return false;
                    }
                }
                hasData_ = true;
                lastTime_ = data.timedData.timePoint;
                return true;
            }
            inline bool good() const {
                return hasData_;
            }
        };
        
        #include <tm_kit/infra/TopDownSinglePassIterationApp_TimeChecker_Piece.hpp>

    private:
        uint64_t idCounter_;
    public:
        uint64_t nextID() {
            return (idCounter_++);
        }

        class AbstractImporterBase;

        class TaskQueueItem {
        private:
            typename StateT::TimePointType tp_;
            uint64_t id_;
            AbstractImporterBase *importer_;
            std::function<void()> action_;
        public:
            TaskQueueItem() : tp_(), id_(0), importer_(nullptr), action_() {}
            TaskQueueItem(TopDownSinglePassIterationApp *app, AbstractImporterBase *importer, typename StateT::TimePointType const &tp, std::function<void()> &&action) 
                : tp_(tp), id_(app->nextID()), importer_(importer), action_(std::move(action)) 
            {}
            ~TaskQueueItem() = default;
            TaskQueueItem(TaskQueueItem const &) = default;
            TaskQueueItem &operator=(TaskQueueItem const &) = default;
            TaskQueueItem(TaskQueueItem &&) = default;
            TaskQueueItem &operator=(TaskQueueItem &&) = default;
            bool operator<(TaskQueueItem const &q) const {
                if (this == &q) {
                    return false;
                }
                if (tp_ < q.tp_) {
                    return true;
                }
                if (tp_ > q.tp_) {
                    return false;
                }
                return (id_ < q.id_);
            }
            bool operator>(TaskQueueItem const &q) const {
                if (this == &q) {
                    return false;
                }
                if (tp_ > q.tp_) {
                    return true;
                }
                if (tp_ < q.tp_) {
                    return false;
                }
                return (id_ > q.id_);
            }
            bool operator==(TaskQueueItem const &q) const {
                if (this == &q) {
                    return true;
                }
                return id_ == q.id_;
            }
            bool fromImporter() const {
                return (importer_ != nullptr);
            }
            AbstractImporterBase *importer() const {
                return importer_;
            }
            void act(StateT *env) const {
                top_down_single_pass_iteration_app_utils::TimeSetter<StateT,UseExecutionStrategyThatAllowsForHiddenTimeDependency> _ {env, tp_, (importer_ != nullptr)};
                action_();
            }
        };
        class TaskQueueItemPtrComparor {
        public:
            bool operator()(TaskQueueItem *a, TaskQueueItem *b) {
                return (*b < *a);
            }
        };
        using TaskQueue = std::priority_queue<TaskQueueItem *, std::vector<TaskQueueItem *>, TaskQueueItemPtrComparor>; //std::greater<TaskQueueItem>>;
    private:
        TaskQueue taskQueue_;
    public:
        void enqueueTask(AbstractImporterBase *importer, typename StateT::TimePointType const &tp, std::function<void()> &&action) {
            taskQueue_.push(new TaskQueueItem(this, importer, tp, std::move(action)));
            if constexpr (UseExecutionStrategyThatAllowsForHiddenTimeDependency) {
                if (importer != nullptr) {
                    auto iter = importerInQueueMap_.find(importer);
                    if (iter == importerInQueueMap_.end()) {
                        importerInQueueMap_.insert({importer, 1});
                    } else {
                        ++(iter->second);
                    }
                }
            }
        }

        template <class T>
        class ProducerBase : public virtual IStoppableProducer<1> {
        protected:
            std::vector<IHandler<T> *> handlers_;
            std::unordered_set<IHandler<T> *> handlerSet_;

            friend class TopDownSinglePassIterationApp;

            TopDownSinglePassIterationApp *parent_ = nullptr;
            virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *) {
            }
            TopDownSinglePassIterationApp *parent() const {
                return parent_;
            }
            void copyHandlersTo(ProducerBase<T> *p) const {
                for (auto *x : handlers_) {
                    p->addHandler(x);
                }
            }
        public:
            ProducerBase() : handlers_(), handlerSet_(), parent_(nullptr) {}
            ProducerBase(ProducerBase const &) = delete;
            ProducerBase &operator=(ProducerBase const &) = delete;
            ProducerBase(ProducerBase &&) = default;
            ProducerBase &operator=(ProducerBase &&) = default;
            virtual ~ProducerBase() {}
            void addHandler(IHandler<T> *h) {
                if (h == nullptr) {
                    return;
                }
                if (handlerSet_.find(h) == handlerSet_.end()) {
                    handlers_.push_back(h);
                    handlerSet_.insert(h);
                }               
            }
            void setParentForProducer(TopDownSinglePassIterationApp *parent) {
                parent_ = parent;
                this->setParentAdditionalSteps(parent);
            }
        };

        template <class T, bool IsImporter=false>
        class Producer : public virtual ProducerBase<T> {
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
            Producer(Producer &&) = default;
            Producer &operator=(Producer &&) = default;
            virtual ~Producer() {}
            void publish(StateT *env, T &&data) {
                publish(withtime_utils::pureTimedDataWithEnvironment<T, StateT, typename StateT::TimePointType>(env, std::move(data)));
            }
            void publish(TimedDataWithEnvironment<T, StateT, typename StateT::TimePointType> &&data) {
                if (this->producerIsStopped()) {
                    return;
                }
                if (this->parent_ == nullptr) {
                    return;
                }
                auto s = this->handlers_.size();
                switch (s) {
                    case 0:
                        return;
                    case 1:
                        {
                            auto tp = data.timedData.timePoint;
                            auto *p = this->handlers_.front();
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=std::move(data)]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        break;
                    default:
                        {
                            auto tp = data.timedData.timePoint;
                            for (auto ii=0; ii<s-1; ++ii) {
                                auto *p = this->handlers_[ii];
                                this->parent_->enqueueTask(
                                    asImporter()
                                    , tp
                                    , [p,c=data.clone()]() mutable {
                                        p->handle(std::move(c));
                                    }
                                );
                            }
                            auto *p = this->handlers_[s-1];
                            this->parent_->enqueueTask(
                                asImporter()
                                , tp
                                , [p,data=std::move(data)]() mutable {
                                    p->handle(std::move(data));
                                }
                            );
                        }
                        break;
                }
            }
        };

        #include <tm_kit/infra/TopDownSinglePassIterationApp_ProducerN_Piece.hpp>

        template <class T>
        class OnOrderFacilityProducer {};
        template <class A, class B>
        class OnOrderFacilityProducer<KeyedData<A,B>> {
        protected:
            friend class TopDownSinglePassIterationApp;

            TopDownSinglePassIterationApp *parent_ = nullptr;
            std::unordered_map<typename StateT::IDType, std::tuple<Key<A>, IHandler<KeyedData<A,B>> *>, typename StateT::IDHash> theMap_;
            virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *) {
            }
            bool synchronousRunnerMode_;
            void enableSynchronousRunnerMode() {
                synchronousRunnerMode_ = true;
            }
            void clearConsumersInSynchronousRunnerMode() {
                if (synchronousRunnerMode_) {
                    theMap_.clear();
                }
            }
        public:
            OnOrderFacilityProducer() : parent_(nullptr), theMap_(), synchronousRunnerMode_(false) {}
            OnOrderFacilityProducer(OnOrderFacilityProducer const &) = delete;
            OnOrderFacilityProducer &operator=(OnOrderFacilityProducer const &) = delete;
            OnOrderFacilityProducer(OnOrderFacilityProducer &&) = default;
            OnOrderFacilityProducer &operator=(OnOrderFacilityProducer &&) = default;
            virtual ~OnOrderFacilityProducer() {}
            void registerKeyHandler(Key<A> const &k, IHandler<KeyedData<A,B>> *handler) {
                if (handler != nullptr) {
                    if (theMap_.find(k.id()) == theMap_.end()) {
                        theMap_.insert(std::make_pair(k.id(), std::tuple<Key<A>, IHandler<KeyedData<A,B>> *> {k, handler}));
                    }
                }
            }
            void publish(StateT *env, Key<B> &&data, bool isFinal) {
                auto ret = withtime_utils::pureTimedDataWithEnvironment<Key<B>, StateT, typename StateT::TimePointType>(env, std::move(data), isFinal);
                publish(std::move(ret));
            }
            void publish(TimedDataWithEnvironment<Key<B>, StateT, typename StateT::TimePointType> &&data) {
                auto iter = theMap_.find(data.timedData.value.id());
                if (iter == theMap_.end()) {
                    return;
                }
                auto *h = std::get<1>(iter->second);
                if (h == nullptr) {  
                    return;
                }
                bool isFinal = data.timedData.finalFlag;
                KeyedData<A,B> outputD {std::get<0>(iter->second), std::move(data.timedData.value.key())};
                WithTime<KeyedData<A,B>,typename StateT::TimePointType> outputT {data.timedData.timePoint, std::move(outputD), isFinal};    
                if (isFinal) {
                    theMap_.erase(iter);
                } 
                if (parent_ == nullptr) {
                    return;
                }
                auto tp = data.timedData.timePoint;
                parent_->enqueueTask(
                    nullptr
                    , tp 
                    , [h,output=withtime_utils::pureTimedDataWithEnvironment<KeyedData<A,B>, StateT, typename StateT::TimePointType>(data.environment, std::move(outputT))]() mutable {
                        h->handle(std::move(output));
                    }
                );  
            }
            void publishResponse(TimedDataWithEnvironment<Key<B>, StateT, typename StateT::TimePointType> &&data) {
                this->publish(std::move(data));
            }
            void markEndHandlingRequest(typename StateT::IDType const &id) {
                theMap_.erase(id);
            }
            void setParentForProducer(TopDownSinglePassIterationApp *parent) {
                parent_ = parent;
                this->setParentAdditionalSteps(parent);
            }
        };

        class IExternalComponent {
        public:
            virtual ~IExternalComponent() {}
            virtual void start(StateT *environment) = 0;
        };

        //We don't allow any action to manufacture KeyedData "out of the blue"
        //, but it is ok to manipulate Keys, so the check is one-sided
        //Moreover, we allow manipulation of KeyedData
        template <class A, class B>
        class AbstractAction : public virtual IHandler<A>, public Producer<B>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
        public:
            static_assert((!is_keyed_data_v<B> || is_keyed_data_v<A> || is_monostate_keyed_data_v<B>), "action cannot manufacture keyed data");
            virtual bool isOneTimeOnly() const = 0;
            void control(StateT *, std::string const &command, std::vector<std::string> const &params) override final {
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
            std::vector<std::string> observe(StateT *) const override final {
                return this->producerStoppedStatus();
            }
        };
        
        template <class A, class B>
        class SingleEntryAbstractAction : public AbstractAction<A,B> {};

        #include <tm_kit/infra/TopDownSinglePassIterationApp_AbstractAction_Piece.hpp>

        class AbstractImporterBase : public virtual IExternalComponent {
        public:
            virtual bool next() = 0;
        };
        
        template <class T>
        class UnregisteredImporterIterator;

        //We don't allow importer to manufacture keyed data "out of the blue"
        template <class T, typename=std::enable_if_t<!is_keyed_data_v<T> || is_monostate_keyed_data_v<T>>>
        class AbstractImporter : public virtual AbstractImporterBase, public Producer<T,true> {
        protected:
            friend class UnregisteredImporterIterator<T>;
            static constexpr AbstractImporter *nullptrToInheritedImporter() {return nullptr;}
            virtual std::tuple<bool, Data<T>> generate(T const *notUsed) = 0; //the bool part means whether the importer has more data to come
        public:
            bool next() override final {
                auto d = generate((T const *) nullptr);
                if (std::get<1>(d)) {
                    this->publish(std::move(*(std::get<1>(d))));
                }
                return std::get<0>(d);
            }
        };

        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        class AbstractExporter : public virtual IExternalComponent, public virtual IHandler<T> {
        protected:
            static constexpr AbstractExporter *nullptrToInheritedExporter() {return nullptr;}
            virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *) {
            }
        public:
            virtual bool isTrivialExporter() const {return false;}
            void setParentForExporter(TopDownSinglePassIterationApp *parent) {
                this->setParentAdditionalSteps(parent);
            }
        };

        template <class A, class B>
        class AbstractOnOrderFacility: public virtual IHandler<Key<A>>, public OnOrderFacilityProducer<KeyedData<A,B>> {
        protected:
            static constexpr AbstractOnOrderFacility *nullptrToInheritedFacility() {return nullptr;}
        };
    
    private:
        using DelaySimulator = typename LiftParameters<TimePoint>::DelaySimulatorType;

    public:
        template <class A, class B, class F, bool ForceFinal>
        class PureOneLevelDownKleisli {
        private:
            F f_;
            DelaySimulator delaySimulator_;
        public:
            TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) {
                if constexpr (ForceFinal) {
                    auto ret = withtime_utils::pureTimedDataWithEnvironmentLift(env, f_, std::move(data));
                    ret.timedData.finalFlag = true;
                    if (delaySimulator_) {
                        auto delay = (*delaySimulator_)(0, ret.timedData.timePoint);
                        ret.timedData.timePoint += delay;
                    }
                    return ret;
                } else {
                    return withtime_utils::pureTimedDataWithEnvironmentLift(env, f_, std::move(data));
                }               
            }
            PureOneLevelDownKleisli(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
            PureOneLevelDownKleisli(PureOneLevelDownKleisli const &) = delete;
            PureOneLevelDownKleisli &operator=(PureOneLevelDownKleisli const &) = delete;
            PureOneLevelDownKleisli(PureOneLevelDownKleisli &&) = default;
            PureOneLevelDownKleisli &operator=(PureOneLevelDownKleisli &&) = default;
        };
        //This is only used for multi action. For regular action
        //, if the "enhanced" input data is needed, just use EnhancedMaybe
        template <class A, class B, class F, bool ForceFinal>
        class EnhancedPureOneLevelDownKleisli {
        private:
            F f_;
            DelaySimulator delaySimulator_;
        public:
            TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) {
                auto b = f_(std::tuple<typename StateT::TimePointType, A> {data.timePoint, std::move(data.value)});
                return withtime_utils::pureTimedDataWithEnvironment(env, WithTime<B, typename StateT::TimePointType> {
                    (
                        delaySimulator_?
                        (data.timePoint+(*delaySimulator_)(0, data.timePoint))
                        : data.timePoint 
                    ),
                    std::move(b),
                    (ForceFinal?true:data.finalFlag)
                });
            }
            EnhancedPureOneLevelDownKleisli(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
            EnhancedPureOneLevelDownKleisli(EnhancedPureOneLevelDownKleisli const &) = delete;
            EnhancedPureOneLevelDownKleisli &operator=(EnhancedPureOneLevelDownKleisli const &) = delete;
            EnhancedPureOneLevelDownKleisli(EnhancedPureOneLevelDownKleisli &&) = default;
            EnhancedPureOneLevelDownKleisli &operator=(EnhancedPureOneLevelDownKleisli &&) = default;
        };
        template <class A, class B, class F, bool ForceFinal>
        class MaybeOneLevelDownKleisli {
        private:
            F f_;
            DelaySimulator delaySimulator_;
        public:
            TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) {
                auto b = f_(std::move(data.value));
                if (b) {
                    return withtime_utils::pureTimedDataWithEnvironment(env, WithTime<B, typename StateT::TimePointType> {
                        (
                            delaySimulator_?
                            (data.timePoint+(*delaySimulator_)(0, data.timePoint))
                            : data.timePoint 
                        ),
                        std::move(*b),
                        (ForceFinal?true:data.finalFlag)
                    });
                } else {
                    return std::nullopt;
                }
            }
            MaybeOneLevelDownKleisli(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
            MaybeOneLevelDownKleisli(MaybeOneLevelDownKleisli const &) = delete;
            MaybeOneLevelDownKleisli &operator=(MaybeOneLevelDownKleisli const &) = delete;
            MaybeOneLevelDownKleisli(MaybeOneLevelDownKleisli &&) = default;
            MaybeOneLevelDownKleisli &operator=(MaybeOneLevelDownKleisli &&) = default;
        };
        template <class A, class B, class F, bool ForceFinal>
        class EnhancedMaybeOneLevelDownKleisli {
        private:
            F f_;
            DelaySimulator delaySimulator_;
        public:
            TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) {
                auto b = f_(std::tuple<typename StateT::TimePointType, A> {data.timePoint, std::move(data.value)});
                if (b) {
                    return withtime_utils::pureTimedDataWithEnvironment(env, WithTime<B, typename StateT::TimePointType> {
                        (
                            delaySimulator_?
                            (data.timePoint+(*delaySimulator_)(0, data.timePoint))
                            : data.timePoint 
                        ),
                        std::move(*b),
                        (ForceFinal?true:data.finalFlag)
                    });
                } else {
                    return std::nullopt;
                }
            }
            EnhancedMaybeOneLevelDownKleisli(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
            EnhancedMaybeOneLevelDownKleisli(EnhancedMaybeOneLevelDownKleisli const &) = delete;
            EnhancedMaybeOneLevelDownKleisli &operator=(EnhancedMaybeOneLevelDownKleisli const &) = delete;
            EnhancedMaybeOneLevelDownKleisli(EnhancedMaybeOneLevelDownKleisli &&) = default;
            EnhancedMaybeOneLevelDownKleisli &operator=(EnhancedMaybeOneLevelDownKleisli &&) = default;
        };
        template <class A, class B, class F, bool ForceFinal>
        class DirectOneLevelDownKleisli {
        private:
            F f_;
            DelaySimulator delaySimulator_;
        public:
            TimedAppData<B, StateT> action(StateT *env, WithTime<A,typename StateT::TimePointType> &&data) {
                if (ForceFinal) {
                    auto ret = f_(TimedDataWithEnvironment<A, StateT, typename StateT::TimePointType> {
                        env
                        , std::move(data)
                    });
                    if (!ret) {
                        return ret;
                    } else {
                        if (delaySimulator_) {
                            auto delay = (*delaySimulator_)(0, ret->timedData.timePoint);
                            ret->timedData.timePoint += delay;
                        }
                        ret->timedData.finalFlag = true;
                        return ret;
                    }
                } else {
                    auto ret = f_(TimedDataWithEnvironment<A, StateT, typename StateT::TimePointType> {
                        env
                        , std::move(data)
                    });
                    if (delaySimulator_) {
                        auto delay = (*delaySimulator_)(0, ret->timedData.timePoint);
                        ret->timedData.timePoint += delay;
                    }
                    return ret;
                }               
            }
            DirectOneLevelDownKleisli(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator) {}
            DirectOneLevelDownKleisli(DirectOneLevelDownKleisli const &) = delete;
            DirectOneLevelDownKleisli &operator=(DirectOneLevelDownKleisli const &) = delete;
            DirectOneLevelDownKleisli(DirectOneLevelDownKleisli &&) = default;
            DirectOneLevelDownKleisli &operator=(DirectOneLevelDownKleisli &&) = default;
        };
        
     private:
        template <class T, class Input, class Output>
        class TwoWayHolder {
        private:
            friend class TopDownSinglePassIterationApp;
            std::unique_ptr<T> core_;
            IControllableNode<StateT> *controlInfo_;
            IObservableNode<StateT> *observeInfo_;
            void release() {
                core_.release();
                controlInfo_ = nullptr;
                observeInfo_ = nullptr;
            }
        public:
            using InputType = Input;
            using OutputType = Output;

            TwoWayHolder(std::unique_ptr<T> &&p) : controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p.get())), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p.get())), core_(std::move(p)) {}
            template <class A>
            TwoWayHolder(A *p) : controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p)), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p)), core_(std::unique_ptr<T>(static_cast<T *>(p))) {}
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core_.get()};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                std::vector<IControllableNode<StateT> *> ret;
                if (controlInfo_) {
                    ret.push_back(controlInfo_);
                }
                return ret;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                std::vector<IObservableNode<StateT> *> ret;
                if (observeInfo_) {
                    ret.push_back(observeInfo_);
                }
                return ret;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                if (controlInfo_) {
                    controlInfo_->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                if (observeInfo_) {
                    return observeInfo_->observe(env);
                } else {
                    return {};
                }
            }
        };
        template <class T, class Data>
        class OneWayHolder {
        private:
            friend class TopDownSinglePassIterationApp;
            IControllableNode<StateT> *controlInfo_;
            IObservableNode<StateT> *observeInfo_;
            std::unique_ptr<T> core_;
            void release() {
                core_.release();
                controlInfo_ = nullptr;
                observeInfo_ = nullptr;
            }
        public:
            using DataType = Data;

            OneWayHolder(std::unique_ptr<T> &&p) : controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p.get())), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p.get())), core_(std::move(p)) {}
            template <class A>
            OneWayHolder(A *p) : controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p)), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p)), core_(std::unique_ptr<T>(dynamic_cast<T *>(p))) {}
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core_.get()};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                std::vector<IControllableNode<StateT> *> ret;
                if (controlInfo_) {
                    ret.push_back(controlInfo_);
                }
                return ret;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                std::vector<IObservableNode<StateT> *> ret;
                if (observeInfo_) {
                    ret.push_back(observeInfo_);
                }
                return ret;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                if (controlInfo_) {
                    controlInfo_->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                if (observeInfo_) {
                    return observeInfo_->observe(env);
                } else {
                    return {};
                }
            }
        };
        template <class T1, class Input, class Output, class T2, class Data>
        class ThreeWayHolder {
        private:
            friend class TopDownSinglePassIterationApp;
            //The reason why we use raw pointers here is that
            //the two pointers may well be pointing to the same
            //object (through different base classes). Therefore
            //we give up on managing the memory for this special
            //case
            T1 *core1_;
            T2 *core2_;
            std::vector<IControllableNode<StateT> *> controlInfo_;
            std::vector<IObservableNode<StateT> *> observeInfo_;
            void release() {
                core1_ = nullptr;
                core2_ = nullptr;
                controlInfo_.clear();
                observeInfo_.clear();
            }
        public:
            using InputType = Input;
            using OutputType = Output;
            using DataType = Data;

            template <class A, class B>
            ThreeWayHolder(A *p1, B*p2) : core1_(static_cast<T1 *>(p1)), core2_(static_cast<T2 *>(p2)), controlInfo_() {
                auto *q1 = dynamic_cast<IControllableNode<StateT> *>(p1);
                if (q1) {
                    controlInfo_.push_back(q1);
                }
                auto *q2 = dynamic_cast<IControllableNode<StateT> *>(p2);
                if (q2 && (q2 != q1)) {
                    controlInfo_.push_back(q2);
                }
                auto *o1 = dynamic_cast<IObservableNode<StateT> *>(p1);
                if (o1) {
                    observeInfo_.push_back(o1);
                }
                auto *o2 = dynamic_cast<IObservableNode<StateT> *>(p2);
                if (o2 && (o2 != o1)) {
                    observeInfo_.push_back(o2);
                }
            }
            ThreeWayHolder(ThreeWayHolder const &) = delete;
            ThreeWayHolder &operator=(ThreeWayHolder const &) = delete;
            ThreeWayHolder(ThreeWayHolder &&) = default;
            ThreeWayHolder &operator=(ThreeWayHolder &&) = default;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core1_, core2_};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                return controlInfo_;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                return observeInfo_;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                for (auto *p : controlInfo_) {
                    p->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                std::vector<std::string> ret;
                for (auto *p : observeInfo_) {
                    auto r = p->observe(env);
                    std::copy(r.begin(), r.end(), std::back_inserter(ret));
                }
                return ret;
            }
        };
        template <class T1, class Input, class Output, class T2, class ExtraInput, class T3, class ExtraOutput>
        class FourWayHolder {
        private:
            friend class TopDownSinglePassIterationApp;
            //The reason why we use raw pointers here is that
            //the three pointers may well be pointing to the same
            //object (through different base classes). Therefore
            //we give up on managing the memory for this special
            //case
            T1 *core1_;
            T2 *core2_;
            T3 *core3_;
            std::vector<IControllableNode<StateT> *> controlInfo_;
            std::vector<IObservableNode<StateT> *> observeInfo_;
            void release() {
                core1_ = nullptr;
                core2_ = nullptr;
                core3_ = nullptr;
                controlInfo_.clear();
                observeInfo_.clear();
            }
        public:
            using InputType = Input;
            using OutputType = Output;
            using ExtraInputType = ExtraInput;
            using ExtraOutputType = ExtraOutput;

            template <class A, class B, class C>
            FourWayHolder(A *p1, B *p2, C *p3) : core1_(static_cast<T1 *>(p1)), core2_(static_cast<T2 *>(p2)), core3_(static_cast<T3 *>(p3)) {
                auto *q1 = dynamic_cast<IControllableNode<StateT> *>(p1);
                if (q1) {
                    controlInfo_.push_back(q1);
                }
                auto *q2 = dynamic_cast<IControllableNode<StateT> *>(p2);
                if (q2 && (q2 != q1)) {
                    controlInfo_.push_back(q2);
                }
                auto *q3 = dynamic_cast<IControllableNode<StateT> *>(p3);
                if (q3 && (q3 != q1) && (q3 != q2)) {
                    controlInfo_.push_back(q3);
                }
                auto *o1 = dynamic_cast<IObservableNode<StateT> *>(p1);
                if (o1) {
                    observeInfo_.push_back(o1);
                }
                auto *o2 = dynamic_cast<IObservableNode<StateT> *>(p2);
                if (o2 && (o2 != o1)) {
                    observeInfo_.push_back(o2);
                }
                auto *o3 = dynamic_cast<IObservableNode<StateT> *>(p3);
                if (o3 && (o3 != o1) && (o3 != o2)) {
                    observeInfo_.push_back(o3);
                }
            }
            FourWayHolder(FourWayHolder const &) = delete;
            FourWayHolder &operator=(FourWayHolder const &) = delete;
            FourWayHolder(FourWayHolder &&) = default;
            FourWayHolder &operator=(FourWayHolder &&) = default;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {core1_, core2_, core3_};
            }
            std::vector<IControllableNode<StateT> *> getControllableNodes() const {
                return controlInfo_;
            }
            std::vector<IObservableNode<StateT> *> getObservableNodes() const {
                return observeInfo_;
            }
            void control(StateT *env, std::string const &command, std::vector<std::string> const &params) {
                for (auto *p : controlInfo_) {
                    p->control(env, command, params);
                }
            }
            std::vector<std::string> observe(StateT *env) const {
                std::vector<std::string> ret;
                for (auto *p : observeInfo_) {
                    auto r = p->observe(env);
                    std::copy(r.begin(), r.end(), std::back_inserter(ret));
                }
                return ret;
            }
        };
    
    public:
        template <class A, class B, bool FireOnceOnly, class T>
        class ActionCore final : public AbstractAction<A,B> {
        private:
            TimeChecker<A> timeChecker_;
            bool done_;
            T t_;
        public:
            ActionCore(T &&t) : AbstractAction<A,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
            }
            template <class F>
            ActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<A,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {}
            virtual ~ActionCore() {
            }
            virtual void handle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (timeChecker_(data)) {
                    GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                        data.environment, static_cast<AbstractAction<A,B> *>(this)
                    );
                    TraceNodesComponentWrapper<StateT,AbstractAction<A,B>> tracer(
                        data.environment 
                        , this
                    );
                    auto res = t_.action(data.environment, std::move(data.timedData));
                    if (res) {
                        if constexpr (FireOnceOnly) {
                            res->timedData.finalFlag = true;
                        }
                        Producer<B>::publish(std::move(*res));
                        if constexpr (FireOnceOnly) {
                            done_ = true;
                        }
                    }
                }
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
        };

        template <class A, class B, class F, bool FireOnceOnly>
        using PureActionCore = ActionCore<A,B,FireOnceOnly,PureOneLevelDownKleisli<A,B,F,false>>;
        template <class A, class B, class F, bool FireOnceOnly>
        using MaybeActionCore = ActionCore<A,B,FireOnceOnly,MaybeOneLevelDownKleisli<A,B,F,false>>;
        template <class A, class B, class F, bool FireOnceOnly>
        using EnhancedMaybeActionCore = ActionCore<A,B,FireOnceOnly,EnhancedMaybeOneLevelDownKleisli<A,B,F,false>>;
        template <class A, class B, class F, bool FireOnceOnly>
        using KleisliActionCore = ActionCore<A,B,FireOnceOnly,DirectOneLevelDownKleisli<A,B,F,false>>;

        #include <tm_kit/infra/TopDownSinglePassIterationApp_ActionCore_Piece.hpp>

    public:
        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A> || is_monostate_keyed_data_v<B>, int> = 0>
        using Action = TwoWayHolder<AbstractAction<A,B>,A,B>;

        template <class A, class B>
        static bool actionIsThreaded(std::shared_ptr<Action<A,B>> const &) {
            return false;
        }
        template <class A, class B>
        static bool actionIsOneTimeOnly(std::shared_ptr<Action<A,B>> const &a) {
            return a->core_->isOneTimeOnly(); 
        }

        template <class A, class F>
        static auto liftPure1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,decltype(f(A()))>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A,decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F,true>(std::move(f), liftParam.delaySimulator));
            } else {
                return std::make_shared<Action<A,decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F,false>(std::move(f), liftParam.delaySimulator));
            }
        }     
        template <class A, class F>
        static auto liftMaybe1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F,true>(std::move(f), liftParam.delaySimulator));
            } else {
                return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F,false>(std::move(f), liftParam.delaySimulator));
            }
        }
        template <class A, class F>
        static auto enhancedMaybe1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true>(std::move(f), liftParam.delaySimulator));
            } else {
                return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false>(std::move(f), liftParam.delaySimulator));
            }  
        }
        template <class A, class F>
        static auto kleisli1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                    new KleisliActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, true>(std::move(f), liftParam.delaySimulator)
                );
            } else {
                return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                    new KleisliActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, false>(std::move(f), liftParam.delaySimulator)
                );
            }
        }

    private:
        template <class A, class B, bool FireOnceOnly, class T>
        class MultiActionCore : public AbstractAction<A,B> {
        private:
            TimeChecker<A> timeChecker_;
            bool fireOnceOnly_;
            bool done_;
            T t_;
        public:
            MultiActionCore(T &&t) : AbstractAction<A,B>(), timeChecker_(), done_(false), t_(std::move(t)) {
            }
            template <class F>
            MultiActionCore(F &&f, DelaySimulator const &delaySimulator) : AbstractAction<A,B>(), timeChecker_(), done_(false), t_(std::move(f), delaySimulator) {}
            virtual ~MultiActionCore() {
            }
            virtual void handle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (timeChecker_(data)) {
                    GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                        data.environment, static_cast<AbstractAction<A,B> *>(this)
                    );
                    TraceNodesComponentWrapper<StateT,AbstractAction<A,B>> tracer(
                        data.environment 
                        , this
                    );
                    auto res = t_.action(data.environment, std::move(data.timedData));
                    if (res && !res->timedData.value.empty()) {
                        if constexpr (FireOnceOnly) {
                            Producer<B>::publish(InnerData<B> {
                                res->environment
                                , {
                                    res->timedData.timePoint
                                    , std::move(res->timedData.value[0])
                                    , true
                                }
                            });
                            done_ = true;
                        } else {
                            size_t l = res->timedData.value.size();
                            size_t ii = l-1;
                            for (auto &&item : res->timedData.value) {
                                Producer<B>::publish(InnerData<B> {
                                    res->environment
                                    , {
                                        res->timedData.timePoint
                                        , std::move(item)
                                        , ((ii==0)?res->timedData.finalFlag:false)
                                    }
                                });
                                --ii;
                            }
                        }
                    }
                }
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
        };
        template <class A, class B, class F, bool FireOnceOnly>
        using SimpleMultiActionCore = MultiActionCore<A,B,FireOnceOnly,PureOneLevelDownKleisli<A,std::vector<B>,F,false>>;
        template <class A, class B, class F, bool FireOnceOnly>
        using EnhancedMultiActionCore = MultiActionCore<A,B,FireOnceOnly,EnhancedPureOneLevelDownKleisli<A,std::vector<B>,F,false>>;
        template <class A, class B, class F, bool FireOnceOnly>
        using KleisliMultiActionCore = MultiActionCore<A,B,FireOnceOnly,DirectOneLevelDownKleisli<A,std::vector<B>,F,false>>;
        
        #include <tm_kit/infra/TopDownSinglePassIterationApp_MultiActionCore_Piece.hpp>

    public:
        template <class A, class F>
        static auto liftMulti1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A,typename decltype(f(A()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F,true>(std::move(f), liftParam.delaySimulator));
            } else {
                return std::make_shared<Action<A,typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F,false>(std::move(f), liftParam.delaySimulator));
            }
        }     
        template <class A, class F>
        static auto enhancedMulti1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,true>(std::move(f), liftParam.delaySimulator));
            } else {
                return std::make_shared<Action<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,false>(std::move(f), liftParam.delaySimulator));
            }
        }
        template <class A, class F>
        static auto kleisliMulti1(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>>(
                    new KleisliMultiActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type, F, true>(std::move(f), liftParam.delaySimulator)
                );
            } else {
                return std::make_shared<Action<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type>>(
                    new KleisliMultiActionCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType::value_type, F, false>(std::move(f), liftParam.delaySimulator)
                );
            }
        }

    private:
        template <class A, class B, class ContinuationStructure, bool FireOnceOnly>
        class ContinuationActionCore : public AbstractAction<A,B> {
        private:
            TimeChecker<A> timeChecker_;
            TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> cont_;
            ContinuationStructure state_;
            DelaySimulator delaySimulator_;
            bool done_;
        public:
            ContinuationActionCore(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state, DelaySimulator const &delaySimulator) : AbstractAction<A,B>(), timeChecker_(), cont_(cont), state_(std::move(state)), delaySimulator_(delaySimulator), done_(false) {
            }
            virtual ~ContinuationActionCore() {
            }
            virtual void handle(InnerData<A> &&data) override final {
                if constexpr (FireOnceOnly) {
                    if (done_) {
                        return;
                    }
                }
                if (timeChecker_(data)) {
                    cont_(std::move(data), state_, [this](InnerData<B> &&x) {
                        if constexpr (FireOnceOnly) {
                            done_ = true;
                        }
                        if (delaySimulator_) {
                            x.timedData.timePoint += (*delaySimulator_)(0, x.timedData.timePoint);
                        }
                        Producer<B>::publish(std::move(x));
                    });
                }
            }
            virtual bool isOneTimeOnly() const override final {
                return FireOnceOnly;
            }
        };
    public:
        template <class A, class B, class ContinuationStructure>
        static auto continuationAction(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state=ContinuationStructure(), LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, B>> {
            if (liftParam.fireOnceOnly) {
                return std::make_shared<Action<A,B>>(
                    new ContinuationActionCore<A,B,ContinuationStructure,true>(cont,std::move(state),liftParam.delaySimulator)
                );
            } else {
                return std::make_shared<Action<A,B>>(
                    new ContinuationActionCore<A,B,ContinuationStructure,false>(cont,std::move(state),liftParam.delaySimulator)
                );
            }
        }
    public:
        template <class A, class B, class T>
        class OnOrderFacilityCore final : public AbstractOnOrderFacility<A,B> {
        private:
            TimeChecker<Key<A>> timeChecker_;
            T t_;
        public:
            OnOrderFacilityCore(T &&t) : AbstractOnOrderFacility<A,B>(), timeChecker_(), t_(std::move(t)) {
            }
            template <class F>
            OnOrderFacilityCore(F &&f, DelaySimulator const &delaySimulator) : AbstractOnOrderFacility<A,B>(), timeChecker_(), t_(std::move(f), delaySimulator) {
            }
            virtual ~OnOrderFacilityCore() {
            }
            virtual void handle(InnerData<Key<A>> &&data) override final {
                if (timeChecker_(data)) {
                    GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                        data.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                    );
                    TM_INFRA_FACILITY_TRACER(data.environment);
                    auto id = data.timedData.value.id();
                    WithTime<A,TimePoint> a {data.timedData.timePoint, data.timedData.value.key()};
                    auto res = t_.action(data.environment, std::move(a));
                    if (res) {
                        OnOrderFacilityProducer<KeyedData<A,B>>::publish(
                            pureInnerDataLift([id=std::move(id)](B &&b) -> Key<B> {
                                return {std::move(id), std::move(b)};
                            }, std::move(*res))
                        );
                    }
                }
            }
        };
        template <class A, class B, class T, class StartF>
        class OnOrderFacilityCoreWithStart final : public virtual IExternalComponent, public AbstractOnOrderFacility<A,B> {
        private:
            TimeChecker<Key<A>> timeChecker_;
            T t_;
            StartF startF_;
        public:
            OnOrderFacilityCoreWithStart(T &&t, StartF &&startF) : AbstractOnOrderFacility<A,B>(), timeChecker_(), t_(std::move(t)), startF_(std::move(startF)) {
            }
            template <class F>
            OnOrderFacilityCoreWithStart(F &&f, DelaySimulator const &delaySimulator, StartF &&startF) : AbstractOnOrderFacility<A,B>(), timeChecker_(), t_(std::move(f), delaySimulator), startF_(std::move(startF)) {
            }
            virtual ~OnOrderFacilityCoreWithStart() {
            }
            virtual void start(StateT *environment) override final {
                startF_(environment);
            }
            virtual void handle(InnerData<Key<A>> &&data) override final {
                if (timeChecker_(data)) {
                    GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                        data.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                    );
                    TM_INFRA_FACILITY_TRACER(data.environment);
                    auto id = data.timedData.value.id();
                    WithTime<A,TimePoint> a {data.timedData.timePoint, data.timedData.value.key()};
                    auto res = t_.action(data.environment, std::move(a));
                    if (res) {
                        OnOrderFacilityProducer<KeyedData<A,B>>::publish(
                            pureInnerDataLift([id=std::move(id)](B &&b) -> Key<B> {
                                return {std::move(id), std::move(b)};
                            }, std::move(*res))
                        );
                    }
                }
            }
        };
        template <class A, class B, class F>
        using PureOnOrderFacilityCore = OnOrderFacilityCore<A,B,PureOneLevelDownKleisli<A,B,F,true>>;
        template <class A, class B, class F>
        using MaybeOnOrderFacilityCore = OnOrderFacilityCore<A,B,MaybeOneLevelDownKleisli<A,B,F,true>>;
        template <class A, class B, class F>
        using EnhancedMaybeOnOrderFacilityCore = OnOrderFacilityCore<A,B,EnhancedMaybeOneLevelDownKleisli<A,B,F,true>>;
        template <class A, class B, class F>
        using KleisliOnOrderFacilityCore = OnOrderFacilityCore<A,B,DirectOneLevelDownKleisli<A,B,F,true>>;
        
        template <class A, class B, class F, class StartF>
        using PureOnOrderFacilityCoreWithStart = OnOrderFacilityCoreWithStart<A,B,PureOneLevelDownKleisli<A,B,F,true>,StartF>;
        template <class A, class B, class F, class StartF>
        using MaybeOnOrderFacilityCoreWithStart = OnOrderFacilityCoreWithStart<A,B,MaybeOneLevelDownKleisli<A,B,F,true>,StartF>;
        template <class A, class B, class F, class StartF>
        using EnhancedMaybeOnOrderFacilityCoreWithStart = OnOrderFacilityCoreWithStart<A,B,EnhancedMaybeOneLevelDownKleisli<A,B,F,true>,StartF>;
        template <class A, class B, class F, class StartF>
        using KleisliOnOrderFacilityCoreWithStart = OnOrderFacilityCoreWithStart<A,B,DirectOneLevelDownKleisli<A,B,F,true>,StartF>;

    public:
        template <class A, class B>
        using OnOrderFacility = TwoWayHolder<AbstractOnOrderFacility<A,B>,A,B>;

        template <class A, class F>
        static auto liftPureOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A,decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A,decltype(f(A()))>>(new PureOnOrderFacilityCore<A,decltype(f(A())),F>(std::move(f), liftParam.delaySimulator));
        }     
        template <class A, class F>
        static auto liftMaybeOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCore<A,typename decltype(f(A()))::value_type,F>(std::move(f), liftParam.delaySimulator));
        }
        template <class A, class F>
        static auto enhancedMaybeOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F>(std::move(f), liftParam.delaySimulator));
        }
        template <class A, class F>
        static auto kleisliOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                new KleisliOnOrderFacilityCore<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F>(std::move(f), liftParam.delaySimulator)
            );
        }

        template <class A, class F, class StartF>
        static auto liftPureOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A,decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A,decltype(f(A()))>>(new PureOnOrderFacilityCoreWithStart<A,decltype(f(A())),F,StartF>(std::move(f), liftParam.delaySimulator, std::move(startF)));
        }     
        template <class A, class F, class StartF>
        static auto liftMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(A()))::value_type,F,StartF>(std::move(f), liftParam.delaySimulator,std::move(startF)));
        }
        template <class A, class F, class StartF>
        static auto enhancedMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,StartF>(std::move(f), liftParam.delaySimulator,std::move(startF)));
        }
        template <class A, class F, class StartF>
        static auto kleisliOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType>>(
                new KleisliOnOrderFacilityCoreWithStart<A, typename decltype(f(pureInnerData(nullptr,A())))::value_type::ValueType, F, StartF>(std::move(f), liftParam.delaySimulator, std::move(startF))
            );
        }

        template <class A, class B>
        static std::shared_ptr<Action<A,B>> fromAbstractAction(AbstractAction<A,B> *t) {
            return std::make_shared<Action<A,B>>(t);
        }
        template <class A, class B>
        static std::shared_ptr<OnOrderFacility<A,B>> fromAbstractOnOrderFacility(AbstractOnOrderFacility<A,B> *t) {
            return std::make_shared<OnOrderFacility<A,B>>(t);
        }
    private:
        template <class I0, class O0, class I1, class O1>
        class WrappedOnOrderFacility final : public IExternalComponent, public AbstractOnOrderFacility<I0,O0> {
        private:
            OnOrderFacility<I1,O1> toWrap_;
            Action<Key<I0>,Key<I1>> inputT_;
            Action<Key<O1>,Key<O0>> outputT_;
            class Conduit1 final : public IHandler<Key<I1>> {
            private:
                AbstractOnOrderFacility<I1,O1> *toWrap_;
                IHandler<KeyedData<I1,O1>> *nextConduit_;
            public:
                Conduit1(
                    AbstractOnOrderFacility<I1,O1> *toWrap,
                    IHandler<KeyedData<I1,O1>> *nextConduit
                ) : toWrap_(toWrap), nextConduit_(nextConduit) {}
                void handle(InnerData<Key<I1>> &&i1) override final {
                    toWrap_->registerKeyHandler(i1.timedData.value, nextConduit_);
                    toWrap_->handle(std::move(i1));
                }
            };
            class Conduit2 final : public IHandler<KeyedData<I1,O1>> {
            private:
                AbstractAction<Key<O1>,Key<O0>> *outputT_;
            public:
                Conduit2(AbstractAction<Key<O1>,Key<O0>> *outputT)
                    : outputT_(outputT) {}
                void handle(InnerData<KeyedData<I1,O1>> &&o1) override final {
                    auto x = pureInnerDataLift([](KeyedData<I1,O1> &&a) -> Key<O1> {
                        return {a.key.id(), std::move(a.data)};
                    }, std::move(o1));
                    outputT_->handle(std::move(x));
                }
            }; 
            class Conduit3 final : public IHandler<Key<O0>> {
            private:
                WrappedOnOrderFacility *parent_;
            public:
                Conduit3(WrappedOnOrderFacility *parent)
                    : parent_(parent) {}
                void handle(InnerData<Key<O0>> &&o0) override final {
                    parent_->publish(std::move(o0));
                }
            };        
            Conduit3 c3_;   
            Conduit2 c2_;
            Conduit1 c1_;
        public:
            WrappedOnOrderFacility(
                OnOrderFacility<I1,O1> &&toWrap,
                Action<Key<I0>,Key<I1>> &&inputT,
                Action<Key<O1>,Key<O0>> &&outputT
            ) : toWrap_(std::move(toWrap)), inputT_(std::move(inputT)), outputT_(std::move(outputT)),
                c3_(this), c2_(outputT_.core_.get()), c1_(toWrap_.core_.get(), &c2_) {
                outputT_.core_->addHandler(&c3_);
                inputT_.core_->addHandler(&c1_);
                if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                    GraphStructureBasedResourceHolderComponent::registerParentNode(toWrap_.core_.get(), static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(inputT_.core_.get(), static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(outputT_.core_.get(), static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                }
            }
            virtual void start(StateT *env) override final {
                auto *p = dynamic_cast<IExternalComponent *>(toWrap_.core_.get());
                if (p != nullptr) {
                    p->start(env);
                }
            }
            virtual void handle(InnerData<Key<I0>> &&i0) override final {
                inputT_.core_->handle(std::move(i0));
            }
            virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                toWrap_.core_->setParentForProducer(parent);
                inputT_.core_->setParentForProducer(parent);
                outputT_.core_->setParentForProducer(parent);
            }
        };
    public:
        template <class I0, class O0, class I1, class O1>
        static std::shared_ptr<OnOrderFacility<I0,O0>> wrappedOnOrderFacility(OnOrderFacility<I1,O1> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) {
            return std::make_shared<OnOrderFacility<I0,O0>>(
                new WrappedOnOrderFacility<I0,O0,I1,O1>(std::move(toWrap),std::move(inputT),std::move(outputT))
            );
        };
    private:
        template <class I0, class O0, class I1, class O1>
        class SimpleWrappedOnOrderFacility final : public IExternalComponent, public AbstractOnOrderFacility<I0,O0> {
        private:
            OnOrderFacility<I1,O1> toWrap_;
            std::function<I1(I0 &&)> inputT_;

            class OutputConduit final : public IHandler<KeyedData<I1,O1>> {
            private:
                SimpleWrappedOnOrderFacility *parent_;
                std::function<O1(I1 const &, O0 &&)> outputT_;
            public:
                OutputConduit(SimpleWrappedOnOrderFacility *parent, std::function<O1(I1 const &, O0 &&)> const &outputT)
                    : parent_(parent), outputT_(outputT) {}
                void handle(InnerData<KeyedData<I1,O1>> &&o1) override final {
                    if constexpr (std::is_same_v<O0,O1>) {
                        if (outputT_) {
                            parent_->publish(pureInnerDataLift([this](KeyedData<I1,O1> &&a) -> Key<O0> {
                                return {a.key.id(), outputT_(a.key.key(), std::move(a.data))};
                            }, std::move(o1)));
                        } else {
                            parent_->publish(pureInnerDataLift([](KeyedData<I1,O1> &&a) -> Key<O0> {
                                return {a.key.id(), std::move(a.data)};
                            }, std::move(o1)));
                        }
                    } else {
                        if (outputT_) {
                            parent_->publish(pureInnerDataLift([this](KeyedData<I1,O1> &&a) -> Key<O0> {
                                return {a.key.id(), outputT_(a.key.key(), std::move(a.data))};
                            }, std::move(o1)));
                        }
                    }
                }
            }; 
            OutputConduit c_;
        public:
            SimpleWrappedOnOrderFacility(
                OnOrderFacility<I1,O1> &&toWrap,
                std::function<I1(I0 &&)> const &inputT,
                std::function<O0(I1 const &, O1 &&)> const &outputT
            ) : toWrap_(std::move(toWrap))
                , inputT_(inputT)
                , c_(this, outputT) 
            {
                if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                    GraphStructureBasedResourceHolderComponent::registerParentNode(toWrap_.core_.get(), static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(&c_, static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                }
            }
            virtual void start(StateT *env) override final {
                auto *p = dynamic_cast<IExternalComponent *>(toWrap_.core_.get());
                if (p != nullptr) {
                    p->start(env);
                }
            }
            virtual void handle(InnerData<Key<I0>> &&i0) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    i0.environment, static_cast<AbstractOnOrderFacility<I0,O0> *>(this)
                );
                if constexpr (std::is_same_v<I0,I1>) {
                    if (inputT_) {
                        InnerData<Key<I1>> i1 = pureInnerDataLift([this](Key<I0> &&k) -> Key<I1> {
                            return {k.id(), inputT_(std::move(k.key()))};
                        }, std::move(i0));
                        toWrap_.core_->registerKeyHandler(i1.timedData.value, &c_);
                        toWrap_.core_->handle(std::move(i1));
                    } else {
                        toWrap_.core_->registerKeyHandler(i0.timedData.value, &c_);
                        toWrap_.core_->handle(std::move(i0));
                    }
                } else {
                    if (inputT_) {
                        InnerData<Key<I1>> i1 = pureInnerDataLift([this](Key<I0> &&k) -> Key<I1> {
                            return {k.id(), inputT_(std::move(k.key()))};
                        }, std::move(i0));
                        toWrap_.core_->registerKeyHandler(i1.timedData.value, &c_);
                        toWrap_.core_->handle(std::move(i1));
                    }
                }
            }
            virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                toWrap_.core_->setParentForProducer(parent);
            }
        };
    public:
        template <class I0, class O0, class Fac>
        static std::shared_ptr<OnOrderFacility<I0,O0>> simpleWrappedOnOrderFacility(Fac &&toWrap, std::function<typename Fac::InputType(I0 &&)> const &inputT, std::function<O0(typename Fac::InputType const &, typename Fac::OutputType &&)> const&outputT) {
            return std::make_shared<OnOrderFacility<I0,O0>>(
                new SimpleWrappedOnOrderFacility<I0,O0,typename Fac::InputType,typename Fac::OutputType>(std::move(toWrap),inputT,outputT)
            );
        };
    private:
        template <class A, class B, class C>
        class Compose final : public AbstractAction<A,C> {
        private:
            std::unique_ptr<AbstractAction<A,B>> f_;
            std::unique_ptr<AbstractAction<B,C>> g_;
            class InnerHandler : public IHandler<C> {
            private:
                Producer<C> *p_;
            public:
                InnerHandler(Producer<C> *p) : p_(p) {}
                virtual void handle(InnerData<C> &&data) override final {
                    p_->publish(std::move(data));
                }
            };
            InnerHandler innerHandler_;
        protected:
            virtual void handle(InnerData<A> &&data) override final {
                f_->handle(std::move(data));
            }
        public:
            Compose() : f_(), g_(), innerHandler_(this) {}
            Compose(std::unique_ptr<AbstractAction<A,B>> &&f, std::unique_ptr<AbstractAction<B,C>> &&g) : f_(std::move(f)), g_(std::move(g)), innerHandler_(this) {
                f_->addHandler(g_.get());
                g_->addHandler(&innerHandler_);
                if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                    GraphStructureBasedResourceHolderComponent::registerParentNode(f_.get(), static_cast<AbstractAction<A,C> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(g_.get(), static_cast<AbstractAction<A,C> *>(this));
                }
            }
            virtual bool isOneTimeOnly() const override final {
                return f_->isOneTimeOnly() || g_->isOneTimeOnly();
            }
            virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                f_->setParentForProducer(parent);
                g_->setParentForProducer(parent);
            }
        };
    public:   
        template <class A, class B, class C>
        static std::shared_ptr<Action<A,C>> compose(Action<A,B> &&f, Action<B,C> &&g) {
            return std::make_shared<Action<A,C>>(new Compose<A,B,C>(std::move(f.core_), std::move(g.core_)));
        }

    #include <tm_kit/infra/TopDownSinglePassIterationApp_Merge_Piece.hpp>
    #include <tm_kit/infra/TopDownSinglePassIterationApp_PureN_Piece.hpp>
    #include <tm_kit/infra/TopDownSinglePassIterationApp_MaybeN_Piece.hpp>  
    #include <tm_kit/infra/TopDownSinglePassIterationApp_EnhancedMaybeN_Piece.hpp>  
    #include <tm_kit/infra/TopDownSinglePassIterationApp_KleisliN_Piece.hpp>  
    #include <tm_kit/infra/TopDownSinglePassIterationApp_MultiN_Piece.hpp>  
    #include <tm_kit/infra/TopDownSinglePassIterationApp_EnhancedMultiN_Piece.hpp>  
    #include <tm_kit/infra/TopDownSinglePassIterationApp_KleisliMultiN_Piece.hpp>  

    private:
        template <class T, typename=std::enable_if_t<
            !withtime_utils::IsVariant<T>::Value
            && !std::is_same_v<T, std::any>
        >>
        class PassThroughAction final : public AbstractAction<T,T> {
        private:
            friend class TopDownSinglePassIterationApp;
            std::recursive_mutex mutex_;
            std::list<ProducerBase<T> *> producers_;
            std::list<IHandler<T> *> handlers_;
        public:
            virtual bool isOneTimeOnly() const override final {return false;}
            virtual void handle(InnerData<T> &&) override final {}
        
            PassThroughAction() = default;
            virtual ~PassThroughAction() = default;
        };
    public:
        template <class T, typename=std::enable_if_t<
            !withtime_utils::IsVariant<T>::Value
            && !std::is_same_v<T, std::any>
        >>
        static auto passThroughAction() {
            return std::make_shared<Action<T,T>>(new PassThroughAction<T>());
        }
    private:
        template <class... Ts>
        class DispatchTupleAction final : public AbstractAction<std::tuple<Ts...>,std::variant<Ts...>> {
        private:
            template <std::size_t Idx>
            void handle_internal(InnerData<std::tuple<Ts...>> &&data) {
                if constexpr (Idx < sizeof...(Ts)) {
                    this->publish(InnerData<std::variant<Ts...>> {
                        data.environment
                        , {
                            data.environment->resolveTime(data.timedData.timePoint)
                            , std::variant<Ts...> {std::in_place_index<Idx>, std::move(std::get<Idx>(data.timedData.value))}
                            , data.timedData.finalFlag
                        }
                    });
                    handle_internal<Idx+1>(std::move(data));
                }
            }
        public:
            virtual bool isOneTimeOnly() const override final {return false;}
            virtual void handle(InnerData<std::tuple<Ts...>> &&data) override final {
                handle_internal<0>(std::move(data));
            }
        
            DispatchTupleAction() = default;
            virtual ~DispatchTupleAction() = default;
        };
    public:
        template <class... Ts>
        static auto dispatchTupleAction() {
            return std::make_shared<Action<std::tuple<Ts...>,std::variant<Ts...>>>(new DispatchTupleAction<Ts...>());
        }
    public:
        template <class T>
        using Importer = OneWayHolder<AbstractImporter<T>,T>;
    private:
        template <class T, class F, typename=std::enable_if_t<
            std::is_same_v<
                decltype((* ((F *) nullptr))((StateT *) nullptr))
                , std::tuple<bool, Data<T>>
            >
            ||
            std::is_same_v<
                decltype((* ((F *) nullptr))((StateT *) nullptr))
                , Data<T>
            >
        >>
        class SimpleImporter final : public AbstractImporter<T> {
        private:
            F f_;
            DelaySimulator delaySimulator_;
            StateT *env_;
            std::tuple<bool, Data<T>> generate(T const *) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    env_, static_cast<AbstractImporter<T> *>(this)
                );
                if constexpr(std::is_same_v<
                    decltype((* ((F *) nullptr))((StateT *) nullptr))
                    , std::tuple<bool, Data<T>>
                >) {
                    auto ret = f_(env_);
                    if (std::get<1>(ret)) {
                        if (delaySimulator_) {
                            std::get<1>(ret)->timedData.timePoint += (*delaySimulator_)(0, std::get<1>(ret)->timedData.timePoint);
                        }
                    }
                    return ret;
                } else {
                    auto ret = f_(env_);
                    if (ret) {
                        if (delaySimulator_) {
                            ret->timedData.timePoint += (*delaySimulator_)(0, ret->timedData.timePoint);
                        }
                        return {!(ret->timedData.finalFlag), std::move(ret)};
                    } else {
                        return {true, std::nullopt};
                    }
                }
            }
        public:
            SimpleImporter(F &&f, DelaySimulator const &delaySimulator) : f_(std::move(f)), delaySimulator_(delaySimulator), env_(nullptr) {}
            void start(StateT *env) override final {
                env_ = env;
            }
        };
    public:
        template <class T>
        static std::shared_ptr<Importer<T>> importer(AbstractImporter<T> *p) {
            return std::make_shared<Importer<T>>(p);
        }
        template <class T>
        static std::shared_ptr<Importer<T>> vacuousImporter() {
            class LocalI final : public AbstractImporter<T> {
            private:
                std::tuple<bool, Data<T>> generate(T const *) override final {
                    return {false, std::nullopt};
                }
            public:
                void start(StateT *) override final {
                }
            };
            return std::make_shared<Importer<T>>(new LocalI());
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> simpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Importer<T>>(std::make_unique<SimpleImporter<T,F>>(std::move(f), liftParam.delaySimulator));
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> uniformSimpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return simpleImporter<T,F>(std::move(f), liftParam);
        }
        template <class T>
        static std::shared_ptr<Importer<T>> constFirstPushImporter(T &&t = T()) {
            return simpleImporter<T>(
                [t=std::move(t)](StateT *env) mutable -> std::tuple<bool, Data<T>> {
                    return {false, InnerData<T> {
                        env
                        , {
                            env->resolveTime()
                            , std::move(t)
                            , true
                        }
                    }};
                }
            );
        }
        template <class T>
        static std::shared_ptr<Importer<Key<T>>> constFirstPushKeyImporter(T &&t = T()) {
            return constFirstPushImporter<Key<T>>(
                infra::withtime_utils::keyify<T,StateT>(std::move(t))
            );
        }

        template <class T>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void()>> constTriggerImporter(T &&t = T()) {
            class LocalI final : public AbstractImporter<T> {
            private:
                T t_;
                std::deque<TimePoint> triggerTimes_;
                StateT *env_;
                std::tuple<bool, Data<T>> generate(T const *) override final {
                    if (!env_) {
                        return {true, std::nullopt};
                    }
                    if (triggerTimes_.empty()) {
                        return {true, std::nullopt};
                    }
                    InnerData<T> ret {
                        env_
                        , {
                            triggerTimes_.front()
                            , t_ 
                            , false 
                        }
                    };
                    triggerTimes_.pop_front();
                    return {true, {std::move(ret)}};
                }
            public:
                LocalI(T &&t) : t_(std::move(t)), triggerTimes_(), env_(nullptr) {
                }
                ~LocalI() {
                }
                virtual void start(StateT *env) override final {
                    env_ = env;
                }
                void trigger() {
                    if (env_) {
                        triggerTimes_.push_back(env_->resolveTime());
                    }
                }
            };
            auto *p = new LocalI(std::move(t));
            return {
                std::make_shared<Importer<T>>(p)
                , [p]() {
                    p->trigger();
                }
            };
        }
        template <class T>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void(T&&)>> triggerImporter() {
            class LocalI final : public AbstractImporter<T> {
            private:
                std::deque<InnerData<T>> triggerData_;
                StateT *env_;
                std::tuple<bool, Data<T>> generate(T const *) override final {
                    if (!env_) {
                        return {true, std::nullopt};
                    }
                    if (triggerData_.empty()) {
                        return {true, std::nullopt};
                    }
                    InnerData<T> ret = std::move(triggerData_.front());
                    triggerData_.pop_front();
                    return {true, {std::move(ret)}};
                }
            public:
                LocalI() : triggerData_(), env_(nullptr) {
                }
                ~LocalI() {
                }
                virtual void start(StateT *env) override final {
                    env_ = env;
                }
                void trigger(T &&t) {
                    if (env_) {
                        triggerData_.push_back(InnerData<T> {
                            env_
                            , {
                                env_->resolveTime()
                                , std::move(t)
                                , false
                            }
                        });
                    }
                }
            };
            auto *p = new LocalI();
            return {
                std::make_shared<Importer<T>>(p)
                , [p](T &&t) {
                    p->trigger(std::move(t));
                }
            };
        }
        template <class T>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void(WithTime<T,TimePoint> &&)>> triggerImporterWithTime() {
            class LocalI final : public AbstractImporter<T> {
            private:
                std::deque<InnerData<T>> triggerData_;
                StateT *env_;
                std::tuple<bool, Data<T>> generate(T const *) override final {
                    if (!env_) {
                        return {true, std::nullopt};
                    }
                    if (triggerData_.empty()) {
                        return {true, std::nullopt};
                    }
                    InnerData<T> ret = std::move(triggerData_.front());
                    triggerData_.pop_front();
                    bool final = ret.timedData.finalFlag;
                    return {!final, {std::move(ret)}};
                }
            public:
                LocalI() : triggerData_(), env_(nullptr) {
                }
                ~LocalI() {
                }
                virtual void start(StateT *env) override final {
                    env_ = env;
                }
                void trigger(WithTime<T, TimePoint> &&t) {
                    if (env_) {
                        triggerData_.push_back(InnerData<T> {
                            env_
                            , std::move(t)
                        });
                    }
                }
            };
            auto *p = new LocalI();
            return {
                std::make_shared<Importer<T>>(p)
                , [p](WithTime<T,TimePoint> &&t) {
                    p->trigger(std::move(t));
                }
            };
        }
    public:
        template <class T>
        using Exporter = OneWayHolder<AbstractExporter<T>,T>;
    private:
        template <class T, class F>
        class SimpleExporter final : public virtual AbstractExporter<T> {
        private:
            F f_;    
            TimeChecker<T> timeChecker_; 
            bool isTrivial_;
        public:
        #ifdef _MSC_VER
            SimpleExporter(F &&f, bool isTrivial=false) : f_(std::move(f)), timeChecker_(), isTrivial_(isTrivial) {}
        #else
            SimpleExporter(F &&f, bool isTrivial=false) : AbstractExporter<T>(), f_(std::move(f)), timeChecker_(), isTrivial_(isTrivial) {}
        #endif
            virtual ~SimpleExporter() {}
            virtual void handle(InnerData<T> &&d) override final {
                if (timeChecker_(d)) {
                    GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                        d.environment, static_cast<AbstractExporter<T> *>(this)
                    );
                    TM_INFRA_EXPORTER_TRACER(d.environment);
                    f_(std::move(d));
                }
            } 
            virtual void start(StateT *) override final {}
            virtual bool isTrivialExporter() const override final {
                return isTrivial_;
            }
        };
    public:       
        template <class T>
        static std::shared_ptr<Exporter<T>> exporter(AbstractExporter<T> *p) {
            return std::make_shared<Exporter<T>>(p);
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> simpleExporter(F &&f, LiftParameters<TimePoint> const & = LiftParameters<TimePoint>()) {
            return std::make_shared<Exporter<T>>(std::make_unique<SimpleExporter<T,F>>(std::move(f)));            
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> pureExporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            auto wrapper = [f=std::move(f)](InnerData<T> &&d) mutable {
                f(std::move(d.timedData.value));
            };
            return simpleExporter<T>(std::move(wrapper), liftParam);
        }
    private:
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> trivialExporter_internal(F &&f) {
            return std::make_shared<Exporter<T>>(std::make_unique<SimpleExporter<T,F>>(std::move(f), true));       
        }
    public:
        template <class T>
        static std::shared_ptr<Exporter<T>> trivialExporter() {
            return trivialExporter_internal<T>([](InnerData<T> &&) {});
        }

    public:
        template <class T1, class T2>
        static std::shared_ptr<Importer<T2>> composeImporter(Importer<T1> &&orig, Action<T1,T2> &&post) {
            class LocalI final : public AbstractImporter<T2> {
            private:
                Importer<T1> orig_;
                bool origDone_;
                Action<T1,T2> post_;
                std::deque<InnerData<T2>> data_;
                friend class LocalH;
                class LocalH final : public IHandler<T2> {
                private:
                    LocalI *parent_;
                public:
                    LocalH(LocalI *parent) : parent_(parent) {}
                    virtual void handle(InnerData<T2> &&t2) override final {
                        parent_->data_.push_back(std::move(t2));
                    }
                };
                LocalH localH_;
                std::tuple<bool, Data<T2>> generate(T2 const *) override final {
                    if (!origDone_) {
                        origDone_ = !(orig_.core_->next());
                    }
                    if (data_.empty()) {
                        return {!origDone_, std::nullopt};
                    }
                    InnerData<T2> ret = std::move(data_.front());
                    data_.pop_front();
                    bool final = ret.timedData.finalFlag;
                    return {!final, {std::move(ret)}};
                }
            public:
                LocalI(Importer<T1> &&orig, Action<T1,T2> &&post)
                    : orig_(std::move(orig)), origDone_(false), post_(std::move(post)), localH_(this)
                {
                    orig_.core_->addHandler(post_.core_.get());
                    post_.core_->addHandler(&localH_);
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(orig_.core_.get(), static_cast<AbstractImporter<T2> *>(this));
                        GraphStructureBasedResourceHolderComponent::registerParentNode(post_.core_.get(), static_cast<AbstractImporter<T2> *>(this));
                    }
                }
                virtual ~LocalI() {}
                virtual void start(StateT *env) override final {
                    orig_.core_->start(env);
                }
                virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                    orig_.core_->setParentForProducer(parent);
                    post_.core_->setParentForProducer(parent);
                }
            };
            return std::make_shared<Importer<T2>>(new LocalI(std::move(orig), std::move(post)));
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> composeExporter(Action<T1,T2> &&pre, Exporter<T2> &&orig) {
            class LocalE final : public AbstractExporter<T1> {
            private:
                Action<T1,T2> pre_;
                Exporter<T2> orig_;
            public:
                LocalE(Action<T1,T2> &&pre, Exporter<T2> &&orig)
                    : pre_(std::move(pre)), orig_(std::move(orig))
                {
                    pre_.core_->addHandler(orig_.core_.get());
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(pre_.core_.get(), static_cast<AbstractExporter<T1> *>(this));
                        GraphStructureBasedResourceHolderComponent::registerParentNode(orig_.core_.get(), static_cast<AbstractExporter<T1> *>(this));
                    }
                }
                virtual ~LocalE() {}
                virtual void start(StateT *env) override final {
                    orig_.core_->start(env);
                }
                virtual void handle(InnerData<T1> &&d) override final {
                    pre_.core_->handle(std::move(d));
                } 
                virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                    pre_.core_->setParentForProducer(parent);
                    orig_.core_->setParentForExporter(parent);
                }
            };
            return std::make_shared<Exporter<T1>>(new LocalE(std::move(pre), std::move(orig)));
        }
        template <class T1, class T2, typename = std::enable_if_t<!withtime_utils::IsVariant<T2>::Value>>
        static std::shared_ptr<Action<T1,T2>> delayedImporter(Importer<T2> &&importer) {
            class LocalA final : public AbstractAction<T1,T2> {
            private:
                Importer<T2> importer_;
                bool started_;
            public:
                LocalA(Importer<T2> &&importer)
                    : importer_(std::move(importer)), started_(false)
                {
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(importer_.core_.get(), static_cast<AbstractAction<T1,T2> *>(this));
                    }
                }
                virtual ~LocalA() {}
                virtual void handle(InnerData<T1> &&d) override final {
                    if (!started_) {
                        started_ = true;
                        this->ProducerBase<T2>::copyHandlersTo(importer_.core_.get());
                        this->parent()->registerImporter(importer_.core_.get());
                        importer_.core_->start(d.environment);
                    }
                }
                virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                    importer_.core_->setParentForProducer(parent);
                }
                virtual bool isOneTimeOnly() const override final {
                    return true;
                }
            };
            return std::make_shared<Action<T1,T2>>(new LocalA(std::move(importer)));
        }
        template <class T1, class T2, typename = std::enable_if_t<!withtime_utils::IsVariant<T2>::Value>>
        static std::shared_ptr<Action<T1,T2>> lazyImporter(std::function<std::shared_ptr<Importer<T2>>(T1 &&)> const &importerFactory) {
            class LocalA final : public AbstractAction<T1,T2> {
            private:
                std::function<std::shared_ptr<Importer<T2>>(T1 &&)> importerFactory_;
                std::shared_ptr<Importer<T2>> importer_;
                bool started_;
                TopDownSinglePassIterationApp *parent_;
            public:
                LocalA(std::function<std::shared_ptr<Importer<T2>>(T1 &&)> const &importerFactory)
                    : importerFactory_(importerFactory), importer_(), started_(false), parent_(nullptr)
                {
                }
                virtual ~LocalA() {}
                virtual void handle(InnerData<T1> &&d) override final {
                    if (!started_) {
                        started_ = true;
                        importer_ = importerFactory_(std::move(d.timedData.value));
                        this->ProducerBase<T2>::copyHandlersTo(importer_->core_.get());
                        importer_->core_->setParentForProducer(parent_);
                        this->parent()->registerImporter(importer_->core_.get());
                        importer_->core_->start(d.environment);
                    }
                }
                virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                    parent_ = parent;
                    if (importer_) {
                        importer_->core_->setParentForProducer(parent);
                    }
                }
                virtual bool isOneTimeOnly() const override final {
                    return true;
                }
            };
            return std::make_shared<Action<T1,T2>>(new LocalA(importerFactory));
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> curtailedAction(Action<T1,T2> &&action) {
            class LocalE final : public AbstractExporter<T1> {
            private:
                Action<T1,T2> action_;
            public:
                LocalE(Action<T1,T2> &&action)
                    : action_(std::move(action))
                {
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(action_.core_.get(), static_cast<AbstractExporter<T1> *>(this));
                    }
                }
                virtual ~LocalE() {}
                virtual void start(StateT *) override final {
                }
                virtual void handle(InnerData<T1> &&d) override final {
                    action_.core_->handle(std::move(d));
                } 
                virtual void setParentAdditionalSteps(TopDownSinglePassIterationApp *parent) override final {
                    action_.core_->setParentForProducer(parent);
                }
            };
            return std::make_shared<Exporter<T1>>(new LocalE(std::move(action)));
        }

    public:
        //The reason why LocalOnOrderFacility is defined as essentially 
        //a tuple instead of an integrated object (as in AbstractIntegratedLocalOnOrderFacility)
        //is to facilitate the separate composition of the facility branch
        //and the exporter branch. 
        //The downside of this is that LocalOnOrderFacility cannot manage the 
        //memory pointed to by the two pointers, since it doesn't know whether
        //they point to the same object or to two different objects. However,
        //since all these objects are "functional" objects, and are supposed to
        //last the whole life of the program, this is a small price to pay. In
        //any case, even with the other types that use unique_ptr to manage their
        //inner objects, those pointers usually are either passed in from heap
        //(admittedly, the user can pass in a stack pointer, and then cause 
        //undefined behavior when the stack disappears, but we cannot control
        //everything the user does), or created internally, and still will last
        //the whole life of the program.
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using LocalOnOrderFacility = ThreeWayHolder<
            AbstractOnOrderFacility<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractExporter<DataInputType>,DataInputType
        >;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> localOnOrderFacility(
            AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractExporter<DataInputType> *e) {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>(t,e);
        }
        
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        class AbstractIntegratedLocalOnOrderFacility 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractExporter<DataInputType> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ExporterParent = AbstractExporter<DataInputType>;
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> localOnOrderFacility(
            AbstractIntegratedLocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType> *p) {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>(p,p);
        }
        
        template <class Fac, class Exp>
        static std::shared_ptr<LocalOnOrderFacility<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Exp::DataType>> localOnOrderFacility(
            Fac &&t, Exp &&e) {
            auto *p_t = t.core_.get();
            auto *p_e = e.core_.get();
            t.release();
            e.release();
            return std::make_shared<LocalOnOrderFacility<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Exp::DataType>>(p_t,p_e);
        }

        template <class Fac, class Action1, class Action2
            , std::enable_if_t<std::is_same_v<typename Action1::OutputType::KeyType, typename Fac::InputType>,int> = 0
            , std::enable_if_t<std::is_same_v<typename Action2::InputType::KeyType, typename Fac::OutputType>,int> = 0
            >
        static std::shared_ptr<LocalOnOrderFacility<
            typename Action1::InputType::KeyType
            , typename Action2::OutputType::KeyType
            , typename Fac::DataType>> wrappedLocalOnOrderFacility(Fac &&toWrap, Action1 &&inputT, Action2 &&outputT) {
            auto *t = toWrap.core1_;
            auto *e = toWrap.core2_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = wrappedOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Action1::OutputType::KeyType
                , typename Action2::InputType::KeyType
            >(std::move(*fac), std::move(inputT), std::move(outputT));
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<LocalOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::DataType>
            >(
                p, e
            );
        }

        template <class I0, class O0, class Fac>
        static std::shared_ptr<LocalOnOrderFacility<
            I0, O0, typename Fac::DataType>> simpleWrappedLocalOnOrderFacility(Fac &&toWrap, std::function<typename Fac::InputType(I0 &&)> const &inputT, std::function<O0(typename Fac::InputType const &, typename Fac::OutputType &&)> const &outputT) {
            auto *t = toWrap.core1_;
            auto *e = toWrap.core2_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = simpleWrappedOnOrderFacility<
                I0, O0
                , std::decay_t<decltype(*fac)>
            >(std::move(*fac), inputT, outputT);
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<LocalOnOrderFacility<
                I0, O0
                , typename Fac::DataType>
            >(
                p, e
            );
        }

    public:
        //OnOrderFacilityWithExternalEffects is the dual of LocalOnOrderFacility
        //Basically, it is an importer and an on order facility glued
        //together. 
        //The name "DataInputType" is here viewed from outside, it is 
        //actually the "output" from OnOrderFacilityWithExternalEffects.
        //The reason this was not changed to "DataOutputType" is to avoid
        //too many code changes, and also it does make sense to call it
        //an "input" from outside view anyway.
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using OnOrderFacilityWithExternalEffects = ThreeWayHolder<
            AbstractOnOrderFacility<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractImporter<DataInputType>,DataInputType
        >;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractImporter<DataInputType> *i) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>(t,i);
        }
        
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        class AbstractIntegratedOnOrderFacilityWithExternalEffects 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractImporter<DataInputType> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ImporterParent = AbstractImporter<DataInputType>;
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using AbstractIntegratedOnOrderFacilityWithExternalEffectsWithPublish = AbstractIntegratedOnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            AbstractIntegratedOnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType> *p) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>(p,p);
        }
        
        template <class Fac, class Imp>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Imp::DataType>> onOrderFacilityWithExternalEffects(
            Fac &&t, Imp &&i) {
            auto *p_t = t.core_.get();
            auto *p_i = i.core_.get();
            t.release();
            i.release();
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Imp::DataType>>(p_t,p_i);
        }

        template <class Fac, class Action1, class Action2
            , std::enable_if_t<std::is_same_v<typename Action1::OutputType::KeyType, typename Fac::InputType>,int> = 0
            , std::enable_if_t<std::is_same_v<typename Action2::InputType::KeyType, typename Fac::OutputType>,int> = 0
            >
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<
            typename Action1::InputType::KeyType
            , typename Action2::OutputType::KeyType
            , typename Fac::DataType>> wrappedOnOrderFacilityWithExternalEffects(Fac &&toWrap, Action1 &&inputT, Action2 &&outputT) {
            auto *t = toWrap.core1_;
            auto *i = toWrap.core2_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = wrappedOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Action1::OutputType::KeyType
                , typename Action2::InputType::KeyType
            >(std::move(*fac), std::move(inputT), std::move(outputT));
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::DataType>
            >(
                p, i
            );
        }

        template <class I0, class O0, class Fac>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<
            I0, O0
            , typename Fac::DataType>> simpleWrappedOnOrderFacilityWithExternalEffects(Fac &&toWrap, std::function<typename Fac::InputType(I0 &&)> const &inputT, std::function<O0(typename Fac::InputType const &, typename Fac::OutputType &&)> const &outputT) {
            auto *t = toWrap.core1_;
            auto *i = toWrap.core2_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = simpleWrappedOnOrderFacility<
                I0, O0
                , std::decay_t<decltype(*fac)>
            >(std::move(*fac), inputT, outputT);
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                I0, O0
                , typename Fac::DataType>
            >(
                p, i
            );
        }

    public:
        //VIEOnOrderFacility is the combination of LocalOnOrderFacility
        //and OnOrderFacilityWithExternalEffects. The name "VIE" comes from
        //the fact that it looks like a local facility but it has complex
        //offshore linkage
        //Here the "input" and "output" is viewed from the point of VIEOnOrderFacility
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        using VIEOnOrderFacility = FourWayHolder<
            AbstractOnOrderFacility<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractExporter<ExtraInputType>,ExtraInputType
            , AbstractImporter<ExtraOutputType>,ExtraOutputType
        >;
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractExporter<ExtraInputType> *i
            , AbstractImporter<ExtraOutputType> *o) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>(t,i,o);
        }
        
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        class AbstractIntegratedVIEOnOrderFacility 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractExporter<ExtraInputType>, public AbstractImporter<ExtraOutputType> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ExporterParent = AbstractExporter<ExtraInputType>;
            using ImporterParent = AbstractImporter<ExtraOutputType>;
        };
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        using AbstractIntegratedVIEOnOrderFacilityWithPublish = AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>; 
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType, bool NotUsed=false>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType> *p) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>(p,p,p);
        }
        
        template <class Fac, class Exp, class Imp>
        static std::shared_ptr<VIEOnOrderFacility<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Exp::DataType
            , typename Imp::DataType>> vieOnOrderFacility(
            Fac &&t, Exp &&i, Imp &&o) {
            auto *p_t = t.core_.get();
            auto *p_i = i.core_.get();
            auto *p_o = o.core_.get();
            t.release();
            i.release();
            o.release();
            return std::make_shared<VIEOnOrderFacility<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Exp::DataType
                , typename Imp::DataType>>(p_t,p_i,p_o);
        }

        template <class Fac, class Action1, class Action2
            , std::enable_if_t<std::is_same_v<typename Action1::OutputType::KeyType, typename Fac::InputType>,int> = 0
            , std::enable_if_t<std::is_same_v<typename Action2::InputType::KeyType, typename Fac::OutputType>,int> = 0
            >
        static std::shared_ptr<VIEOnOrderFacility<
            typename Action1::InputType::KeyType
            , typename Action2::OutputType::KeyType
            , typename Fac::ExtraInputType
            , typename Fac::ExtraOutputType>> wrappedVIEOnOrderFacility(Fac &&toWrap, Action1 &&inputT, Action2 &&outputT) {
            auto *t = toWrap.core1_;
            auto *i = toWrap.core2_;
            auto *o = toWrap.core3_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = wrappedOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Action1::OutputType::KeyType
                , typename Action2::InputType::KeyType
            >(std::move(*fac), std::move(inputT), std::move(outputT));
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<VIEOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::ExtraInputType
                , typename Fac::ExtraOutputType>
            >(
                p, i, o
            );
        }

        template <class I0, class O0, class Fac>
        static std::shared_ptr<VIEOnOrderFacility<
            I0, O0
            , typename Fac::ExtraInputType
            , typename Fac::ExtraOutputType>> simpleWrappedVIEOnOrderFacility(Fac &&toWrap, std::function<typename Fac::InputType(I0 &&)> const &inputT, std::function<O0(typename Fac::InputType const &, typename Fac::OutputType &&)> const &outputT) {
            auto *t = toWrap.core1_;
            auto *i = toWrap.core2_;
            auto *o = toWrap.core3_;
            toWrap.release();
            auto fac = fromAbstractOnOrderFacility(t);
            auto fac1 = simpleWrappedOnOrderFacility<
                I0, O0
                , std::decay_t<decltype(*fac)>
            >(std::move(*fac), inputT, outputT);
            auto *p = fac1->core_.get();
            fac1->release();
            return std::make_shared<VIEOnOrderFacility<
                I0, O0
                , typename Fac::ExtraInputType
                , typename Fac::ExtraOutputType>
            >(
                p, i, o
            );
        }

    public:
        template <class T>
        class Source {
        private:
            friend class TopDownSinglePassIterationApp;
            ProducerBase<T> *producer;
            Source(ProducerBase<T> *p) : producer(p) {}
            Source(ProducerBase<T> *p, TopDownSinglePassIterationApp *parent) : producer(p) {
                p->setParentForProducer(parent);
            }
        public:
            Source clone() const {
                return Source {producer};
            }
        };
        template <class T>
        class Sink {
        private:
            friend class TopDownSinglePassIterationApp;
            IHandler<T> *consumer;
            Sink(IHandler<T> *c) : consumer(c) {}
        };           
            
    private:  
        std::array<std::list<IExternalComponent *>,3> externalComponents_;
        std::unordered_set<IExternalComponent *> externalComponentsSet_;
        std::list<AbstractImporterBase *> importers_;
        std::unordered_set<AbstractImporterBase *> importerSet_;
        std::unordered_map<AbstractImporterBase *, std::size_t> importerInQueueMap_;
        std::mutex mutex_;
        TopDownSinglePassIterationApp() : idCounter_(0), taskQueue_(), externalComponents_(), externalComponentsSet_(), importers_(), importerSet_(), importerInQueueMap_(), mutex_() {}
        TopDownSinglePassIterationApp(TopDownSinglePassIterationApp &&other)
            : idCounter_(std::move(other.idCounter_))
            , taskQueue_(std::move(other.taskQueue_))
            , externalComponents_(std::move(other.externalComponents_))
            , externalComponentsSet_(std::move(other.externalComponentsSet_))
            , importers_(std::move(other.importers_))
            , importerSet_(std::move(other.importerSet_))
            , importerInQueueMap_(std::move(other.importerInQueueMap_))
            , mutex_() 
        {}
        TopDownSinglePassIterationApp &operator=(TopDownSinglePassIterationApp &&other) {
            if (this != &other) {
                idCounter_ = std::move(other.idCounter_);
                taskQueue_ = std::move(other.taskQueue_);
                externalComponents_ = std::move(other.externalComponents_);
                externalComponentsSet_ = std::move(other.externalComponentsSet_);
                importers_ = std::move(other.importers_);
                importerSet_ = std::move(other.importerSet_);
                importerInQueueMap_ = std::move(other.importerInQueueMap_);
            }
            return *this;
        }
        ~TopDownSinglePassIterationApp() = default;

        void registerExternalComponent(IExternalComponent *c, int idx) {
            if (c == nullptr) {
                return;
            }
            std::lock_guard<std::mutex> _(mutex_);
            if (externalComponentsSet_.find(c) == externalComponentsSet_.end()) {
                externalComponents_[idx].push_back(c);
                externalComponentsSet_.insert(c);
            }
        }
        void registerImporter(AbstractImporterBase *p) {
            if (p == nullptr) {
                return;
            }
            std::lock_guard<std::mutex> _(mutex_);
            if (importerSet_.find(p) == importerSet_.end()) {
                importers_.push_back(p);
                importerSet_.insert(p);
            }
        }

        template <class A>
        static void innerConnect(IHandler<A> *handler, ProducerBase<A> *producer) {
            if constexpr (
                !withtime_utils::IsVariant<A>::Value
                && !std::is_same_v<A, std::any>
            ) {
                auto *passThroughHandlerCast = dynamic_cast<PassThroughAction<A> *>(handler);
                auto *passThroughProducerCast = dynamic_cast<PassThroughAction<A> *>(producer);
                if (passThroughHandlerCast != nullptr && passThroughProducerCast == passThroughHandlerCast) {
                    return;
                }
                if (passThroughHandlerCast != nullptr) {
                    std::lock_guard<std::recursive_mutex> _(passThroughHandlerCast->mutex_);
                    passThroughHandlerCast->producers_.push_back(producer);
                    for (auto *h : passThroughHandlerCast->handlers_) {
                        innerConnect<A>(h, producer);
                    }
                } else if (passThroughProducerCast != nullptr) {
                    std::lock_guard<std::recursive_mutex> _(passThroughProducerCast->mutex_);
                    passThroughProducerCast->handlers_.push_back(handler);
                    for (auto *p : passThroughProducerCast->producers_) {
                        innerConnect<A>(handler, p);
                    }
                } else {
                    producer->addHandler(handler);
                }
            } else {
                producer->addHandler(handler);
            }
        }
        template <class A>
        class AnyHandlerAdapter : public IHandler<A> {
        private:
            IHandler<std::any> *handler_;
        public:
            AnyHandlerAdapter(IHandler<std::any> *handler) : handler_(handler) {}
            virtual ~AnyHandlerAdapter() = default;
            virtual void handle(InnerData<A> &&x) override final {
                handler_->handle(std::move(x).moveToAny());
            }
        };
        template <class A, typename = std::enable_if_t<!withtime_utils::IsVariant<A>::Value>>
        static void innerConnectAny(IHandler<std::any> *handler, ProducerBase<A> *producer) {
            if constexpr (std::is_same_v<A, std::any>) {
                innerConnect(handler, producer);
            } else {
                innerConnect(new AnyHandlerAdapter<A>(handler), producer);
            }
        }
        template <class A, class B>
        static void innerConnectFacility(ProducerBase<Key<A>> *producer, AbstractOnOrderFacility<A,B> *facility, IHandler<KeyedData<A,B>> *consumer) {
            auto *passThroughHandlerCast = dynamic_cast<PassThroughAction<KeyedData<A,B>> *>(consumer);
            auto *passThroughProducerCast = dynamic_cast<PassThroughAction<Key<A>> *>(producer);
            if (passThroughHandlerCast != nullptr || passThroughProducerCast != nullptr) {
                throw std::runtime_error(
                    "Cannot use pass-through node on either side of a facility"
                );
            }
            class LocalC final : public virtual IHandler<Key<A>> {
            private:                    
                AbstractOnOrderFacility<A,B> *p_;
                IHandler<KeyedData<A,B>> *h_;
            public:
                LocalC(AbstractOnOrderFacility<A,B> *p, IHandler<KeyedData<A,B>> *h) : p_(p), h_(h) {}
                virtual void handle(InnerData<Key<A>> &&k) {
                    p_->registerKeyHandler(k.timedData.value, h_);
                    p_->handle(std::move(k));
                }
            } *localC = new LocalC(facility, consumer);
            producer->addHandler(localC);
        }
    private:
        template <class T>
        Source<T> importerAsSource(StateT *, Importer<T> &importer) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(importer.core_.get()), 2);
            registerImporter(dynamic_cast<AbstractImporterBase *>(importer.core_.get()));
            return {dynamic_cast<ProducerBase<T> *>(importer.core_.get()), this};
        }
        template <class A, class B>
        Source<B> actionAsSource(StateT *, Action<A,B> &action) {
            return {dynamic_cast<ProducerBase<B> *>(action.core_.get()), this};
        }
        template <class A, class B>
        Source<B> execute(Action<A,B> &action, Source<A> &&variable) {
            innerConnect(dynamic_cast<IHandler<A> *>(action.core_.get()), variable.producer);
            return {dynamic_cast<ProducerBase<B> *>(action.core_.get()), this};
        }
        template <class A, class B>
        Source<B> executeAny(Action<std::any,B> &action, Source<A> &&variable) {
            innerConnectAny(dynamic_cast<IHandler<std::any> *>(action.core_.get()), variable.producer);
            return {dynamic_cast<ProducerBase<B> *>(action.core_.get()), this};
        }

        #include <tm_kit/infra/TopDownSinglePassIterationApp_ExecuteAction_Piece.hpp>
 
        template <class T>
        Sink<T> exporterAsSink(Exporter<T> &exporter) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(exporter.core_.get()), 0);
            dynamic_cast<AbstractExporter<T> *>(exporter.core_.get())->setParentForExporter(this);
            if (dynamic_cast<AbstractExporter<T> *>(exporter.core_.get())->isTrivialExporter()) {
                return {(IHandler<T> *) nullptr};
            } else {
                return {dynamic_cast<IHandler<T> *>(exporter.core_.get())};
            }
        }
        template <class A, class B>
        Sink<A> actionAsSink(Action<A,B> &action) {
            return {dynamic_cast<IHandler<A> *>(action.core_.get())};
        }

        #include <tm_kit/infra/TopDownSinglePassIterationApp_VariantSink_Piece.hpp>

        template <class A, class B>
        void placeOrderWithFacility(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core_.get());
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core_.get()->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core_.get(), sink.consumer);
        }  
        template <class A, class B>
        void placeOrderWithFacilityAndForget(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core_.get());
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core_.get()->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core_.get(), (IHandler<KeyedData<A,B>> *) nullptr);
        }

        template <class A, class B, class C>
        void placeOrderWithLocalFacility(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core1_->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C>
        void placeOrderWithLocalFacilityAndForget(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core1_->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core1_, (IHandler<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C>
        Sink<C> localFacilityAsSink(LocalOnOrderFacility<A,B,C> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_), 0);
            dynamic_cast<AbstractExporter<C> *>(facility.core2_)->setParentForExporter(this);
            return {dynamic_cast<IHandler<C> *>(facility.core2_)};
        }

        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffects(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core1_->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffectsAndForget(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core1_->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core1_, (IHandler<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C>
        Source<C> facilityWithExternalEffectsAsSource(OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_), 0);
            registerImporter(dynamic_cast<AbstractImporterBase *>(facility.core2_));
            return {dynamic_cast<ProducerBase<C> *>(facility.core2_), this};
        }

        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacility(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core1_->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacilityAndForget(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p, 1);
            } 
            facility.core1_->setParentForProducer(this);
            innerConnectFacility(input.producer, facility.core1_, (IHandler<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C, class D>
        Source<D> vieFacilityAsSource(VIEOnOrderFacility<A,B,C,D> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core3_), 0);
            registerImporter(dynamic_cast<AbstractImporterBase *>(facility.core3_));
            return {dynamic_cast<ProducerBase<D> *>(facility.core3_), this};
        }
        template <class A, class B, class C, class D>
        Sink<C> vieFacilityAsSink(VIEOnOrderFacility<A,B,C,D> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_), 0);
            dynamic_cast<AbstractExporter<C> *>(facility.core2_)->setParentForExporter(this);
            return {dynamic_cast<IHandler<C> *>(facility.core2_)};
        }

        template <class T>
        void connect(Source<T> &&src, Sink<T> const &sink) {
            innerConnect(sink.consumer, src.producer);
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void connectAny(Source<T> &&src, Sink<std::any> const &sink) {
            innerConnectAny(sink.consumer, src.producer);
        }

        #include <tm_kit/infra/TopDownSinglePassIterationApp_ConnectN_Piece.hpp>

    private:
        bool runOneStep(StateT *env) {
            std::list<typename std::list<AbstractImporterBase *>::iterator> doneIterators;
            if constexpr (UseExecutionStrategyThatAllowsForHiddenTimeDependency) {
                for (auto iter = importers_.begin(); iter != importers_.end(); ++iter) {
                    auto *pImporter = *iter;
                    if (importerInQueueMap_.find(pImporter) == importerInQueueMap_.end()) {
                        if (!pImporter->next()) {
                            importerSet_.erase(pImporter);
                            doneIterators.push_back(iter);
                        }
                    }
                }
                for (auto iter : doneIterators) {
                    importers_.erase(iter);
                }
                if (!taskQueue_.empty()) {
                    auto *topTask = taskQueue_.top();
                    taskQueue_.pop();
                    auto *topTaskImporter = topTask->importer();
                    topTask->act(env);
                    delete topTask;
                    if (topTaskImporter != nullptr) {
                        auto iter = importerInQueueMap_.find(topTaskImporter);
                        if (iter != importerInQueueMap_.end()) {
                            if (iter->second <= 1) {
                                importerInQueueMap_.erase(iter);
                            } else {
                                --(iter->second);
                            }
                        }
                    }
                }
            } else {
                for (auto iter = importers_.begin(); iter != importers_.end(); ++iter) {
                    auto *pImporter = *iter;
                    if (!pImporter->next()) {
                        importerSet_.erase(pImporter);
                        doneIterators.push_back(iter);
                    }
                }
                for (auto iter : doneIterators) {
                    importers_.erase(iter);
                }
                while (!taskQueue_.empty()) {
                    auto *topTask = taskQueue_.top();
                    taskQueue_.pop();
                    bool isImporterTask = topTask->fromImporter();
                    topTask->act(env);
                    delete topTask;
                    if (isImporterTask) {
                        break;
                    }
                }
            }
            return !(importers_.empty() && taskQueue_.empty());
        }

    public:
        std::function<void(StateT *)> finalize() { 
            std::list<IExternalComponent *> aCopy;
            {
                std::lock_guard<std::mutex> _(mutex_);
                std::copy(externalComponents_[0].begin(), externalComponents_[0].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[1].begin(), externalComponents_[1].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[2].begin(), externalComponents_[2].end(), std::back_inserter(aCopy));
            }  
            return [aCopy=std::move(aCopy),this](StateT *env) {
                for (auto c : aCopy) {
                    c->start(env);
                }
                while (env->running()) {
                    if (!runOneStep(env)) {
                        break;
                    }
                }
            };        
        }
        std::function<std::function<bool(StateT *)>(StateT *)> finalizeForInterleaving() { 
            std::list<IExternalComponent *> aCopy;
            {
                std::lock_guard<std::mutex> _(mutex_);
                std::copy(externalComponents_[0].begin(), externalComponents_[0].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[1].begin(), externalComponents_[1].end(), std::back_inserter(aCopy));
                std::copy(externalComponents_[2].begin(), externalComponents_[2].end(), std::back_inserter(aCopy));
            }  
            return [aCopy=std::move(aCopy),this](StateT *env) -> std::function<bool(StateT *)> {
                for (auto c : aCopy) {
                    c->start(env);
                }
                return [this](StateT *stepEnv) -> bool {
                    if (stepEnv->running()) {
                        return runOneStep(stepEnv);
                    } else {
                        return false;
                    }
                };
            };        
        }
    public:
        template <class X>
        struct GetDataType {
            using DataType = typename X::DataType;
        };
        template <class X>
        struct GetInputOutputType {
            using InputType = typename X::InputType;
            using OutputType = typename X::OutputType;
        };
        template <class X>
        struct GetExtraInputOutputType {
            using ExtraInputType = typename X::ExtraInputType;
            using ExtraOutputType = typename X::ExtraOutputType;
        };

        template <class T>
        using SynchronousRunResult = std::deque<InnerData<T>>;

    private:
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        static IExternalComponent *importerAsExternalComponent(std::shared_ptr<Importer<T>> const &importer) {
            return static_cast<IExternalComponent *>(importer->core_.get());
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        static IExternalComponent *exporterAsExternalComponent(std::shared_ptr<Exporter<T>> const &exporter) {
            return static_cast<IExternalComponent *>(exporter->core_.get());
        }
        template <class T1, class T2>
        static IExternalComponent *facilityAsExternalComponent(std::shared_ptr<OnOrderFacility<T1,T2>> const &facility) {
            return dynamic_cast<IExternalComponent *>(facility->core_.get());
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        std::unique_ptr<SynchronousRunResult<T>> runUnstartedImporterSynchronously(StateT *env, std::shared_ptr<Importer<T>> const &importer) {
            class InnerH final : public IHandler<T> {
            private:
                SynchronousRunResult<T> *res_;
            public:
                InnerH(SynchronousRunResult<T> *res) : res_(res) {}
                virtual void handle(InnerData<T> &&x) override final {
                    res_->push_back(std::move(x));
                }
            };
            std::unique_ptr<SynchronousRunResult<T>> res = std::make_unique<SynchronousRunResult<T>>();
            InnerH h(res.get());
            importer->core_->addHandler(&h);
            importer->core_->setParentForProducer(this);
            importer->core_->start(env);
            while (importer->core_->next()) {
                while (!taskQueue_.empty()) {
                    auto *topTask = taskQueue_.top();
                    taskQueue_.pop();
                    topTask->act(env);
                    delete topTask;
                }
            }
            while (!taskQueue_.empty()) {
                auto *topTask = taskQueue_.top();
                taskQueue_.pop();
                topTask->act(env);
                delete topTask;
            }
            return res;
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        std::unique_ptr<SynchronousRunResult<T>> runUnstartedImporterSynchronouslyUntil(StateT *env, std::shared_ptr<Importer<T>> const &importer, std::function<bool(InnerData<T> const &)> const &condition) {
            class InnerH final : public IHandler<T> {
            private:
                SynchronousRunResult<T> *res_;
                std::function<bool(InnerData<T> const &)> condition_;
                bool conditionSatisfied_;
            public:
                InnerH(SynchronousRunResult<T> *res, std::function<bool(InnerData<T> const &)> const &condition) : res_(res), condition_(condition), conditionSatisfied_(false) {}
                virtual void handle(InnerData<T> &&x) override final {
                    if (!conditionSatisfied_) {
                        conditionSatisfied_ = condition_(x);
                        res_->push_back(std::move(x));
                    }
                }
                bool conditionSatisfied() const {
                    return conditionSatisfied_;
                }
            };
            std::unique_ptr<SynchronousRunResult<T>> res = std::make_unique<SynchronousRunResult<T>>();
            InnerH h(res.get(), condition);
            importer->core_->addHandler(&h);
            importer->core_->setParentForProducer(this);
            importer->core_->start(env);
            while (importer->core_->next()) {
                while (!taskQueue_.empty()) {
                    auto *topTask = taskQueue_.top();
                    taskQueue_.pop();
                    topTask->act(env);
                    delete topTask;
                    if (h.conditionSatisfied()) {
                        break;
                    }
                }
                if (h.conditionSatisfied()) {
                    break;
                }
            }
            while (!taskQueue_.empty()) {
                auto *topTask = taskQueue_.top();
                taskQueue_.pop();
                topTask->act(env);
                delete topTask;
                if (h.conditionSatisfied()) {
                    break;
                }
            }
            return res;
        }
        template <class T1, class T2>
        void startFacilitySynchronously(StateT *env, std::shared_ptr<OnOrderFacility<T1,T2>> const &facility) {
            facility->core_->setParentForProducer(this);
            facility->core_->enableSynchronousRunnerMode();
            auto *p = facilityAsExternalComponent(facility);
            if (p) {
                p->start(env);
            }
        }
        template <class T1, class T2>
        std::unique_ptr<SynchronousRunResult<KeyedData<T1,T2>>> runStartedFacilitySynchronously(StateT *env, std::shared_ptr<OnOrderFacility<T1,T2>> const &facility, InnerData<Key<T1>> &&key) {
            class InnerH final : public IHandler<KeyedData<T1,T2>> {
            private:
                SynchronousRunResult<KeyedData<T1,T2>> *res_;
            public:
                InnerH(SynchronousRunResult<KeyedData<T1,T2>> *res) : res_(res) {}
                virtual void handle(InnerData<KeyedData<T1,T2>> &&x) override final {
                    res_->push_back(std::move(x));
                }
            };
            std::unique_ptr<SynchronousRunResult<KeyedData<T1,T2>>> res = std::make_unique<SynchronousRunResult<KeyedData<T1,T2>>>();
            InnerH h(res.get());
            facility->core_->registerKeyHandler(key.timedData.value, &h);
            facility->core_->handle(std::move(key));
            while (!taskQueue_.empty()) {
                auto *topTask = taskQueue_.top();
                taskQueue_.pop();
                topTask->act(env);
                delete topTask;
            }
            facility->core_->clearConsumersInSynchronousRunnerMode();
            return res;
        }
        template <class T1, class T2>
        void streamToStartedFacilitySynchronously(StateT *env, std::shared_ptr<OnOrderFacility<T1,T2>> const &facility, InnerData<Key<T1>> &&key, SynchronousRunResult<KeyedData<T1,T2>> *output) {
            if (output) {
                class InnerH final : public IHandler<KeyedData<T1,T2>> {
                private:
                    SynchronousRunResult<KeyedData<T1,T2>> *res_;
                public:
                    InnerH(SynchronousRunResult<KeyedData<T1,T2>> *res) : res_(res) {}
                    virtual void handle(InnerData<KeyedData<T1,T2>> &&x) override final {
                        res_->push_back(std::move(x));
                    }
                };
                InnerH h(output);
                facility->core_->registerKeyHandler(key.timedData.value, &h);
                facility->core_->handle(std::move(key));
                while (!taskQueue_.empty()) {
                    auto *topTask = taskQueue_.top();
                    taskQueue_.pop();
                    topTask->act(env);
                    delete topTask;
                }
                facility->core_->clearConsumersInSynchronousRunnerMode();
            } else {
                facility->core_->registerKeyHandler(key.timedData.value, nullptr);
                facility->core_->handle(std::move(key));
            }
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void startExporterSynchronously(StateT *env, std::shared_ptr<Exporter<T>> const &exporter) {
            exporter->core_->setParentForExporter(this);
            exporter->core_->start(env);
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        static void runStartedExporterSynchronously(StateT *, std::shared_ptr<Exporter<T>> const &exporter, InnerData<T> &&data) {
            exporter->core_->handle(std::move(data));
        }

    public:
        //This is supposed to be used outside of any Runner instance
        //on an unregistered importer
        template <class T>
        class UnregisteredImporterIterator {
        public:
            using difference_type = void;
            using value_type = Data<T>;
            using pointer = Data<T> *;
            using const_pointer = Data<T> const *;
            using reference = Data<T> &;
            using const_reference = Data<T> const &;
            using iterator_category = std::input_iterator_tag;
        private:
            friend class TopDownSinglePassIterationApp;
            AbstractImporter<T> *importerCore_;
            Data<T> data_;
            bool hasMore_;
            UnregisteredImporterIterator() : importerCore_(nullptr), data_(std::nullopt), hasMore_(false) {}
            UnregisteredImporterIterator(EnvironmentType *env, AbstractImporter<T> *importerCore) 
                : importerCore_(importerCore), data_(), hasMore_(true) {
                if (importerCore_) {
                    importerCore_->start(env);
                }
                next();
            }
            void next() {
                if (importerCore_) {
                    if (!hasMore_) {
                        importerCore_ = nullptr;
                    } else {
                        auto x = importerCore_->generate(nullptr);
                        data_ = std::move(std::get<1>(x));
                        hasMore_ = std::get<0>(x);
                    }
                } else {
                    hasMore_ = false;
                }
            }
        public:
            static UnregisteredImporterIterator endIter() {
                return UnregisteredImporterIterator();
            }
            UnregisteredImporterIterator(UnregisteredImporterIterator const &iter) 
                : importerCore_(iter.importerCore_), data_(withtime_utils::clone(iter.data_)), hasMore_(iter.hasMore_)
            {
            }
            UnregisteredImporterIterator &operator=(UnregisteredImporterIterator const &iter) {
                if (this != &iter) {
                    importerCore_ = iter.importerCore_;
                    data_ = withtime_utils::clone(iter.data_);
                    hasMore_ = iter.hasMore_;
                }
                return *this;
            }
            bool operator==(UnregisteredImporterIterator const &iter) const {
                //very rough check, because the intended use is only to 
                //compare against endIter
                return (importerCore_ == iter.importerCore_ && hasMore_ == iter.hasMore_);
            }
            bool operator!=(UnregisteredImporterIterator const &iter) const {
                return !operator==(iter);
            }
            UnregisteredImporterIterator &operator++() {
                next();
                return *this;
            }
            UnregisteredImporterIterator operator++(int) {
                UnregisteredImporterIterator iter(*this);
                ++(*this);
                return iter;
            }
            reference operator*() {
                return data_;
            }
            pointer operator->() {
                return &data_;
            }
            const_reference operator*() const {
                return data_;
            }
            const_pointer operator->() const {
                return &data_;
            }
        };

        template <class T>
        static UnregisteredImporterIterator<T> beginIterateUnregisteredImporter(EnvironmentType *env, std::shared_ptr<Importer<T>> const &importer) {
            if (!importer) {
                return UnregisteredImporterIterator<T>::endIter();
            } else {
                return UnregisteredImporterIterator<T>(env, importer->core_.get());
            }
        }
        template <class T>
        static UnregisteredImporterIterator<T> endIterateUnregisteredImporter() {
            return UnregisteredImporterIterator<T>::endIter();
        }
        template <class T>
        static UnregisteredImporterIterator<T> endIterateUnregisteredImporter(std::shared_ptr<Importer<T>> const &) {
            return UnregisteredImporterIterator<T>::endIter();
        }
        template <class T>
        static UnregisteredImporterIterator<T> endIterateUnregisteredImporter(EnvironmentType *, std::shared_ptr<Importer<T>> const &) {
            return UnregisteredImporterIterator<T>::endIter();
        }

        template <class T>
        class UnregisteredExporterIterator {
        public:
            using difference_type = void;
            using value_type = Data<T>;
            using iterator_category = std::output_iterator_tag;
        private:
            friend class TopDownSinglePassIterationApp;
            AbstractExporter<T> *exporterCore_;
            EnvironmentType *env_;
            UnregisteredExporterIterator() : exporterCore_(nullptr), env_(nullptr) {}
            UnregisteredExporterIterator(EnvironmentType *env, AbstractExporter<T> *exporterCore) 
                : exporterCore_(exporterCore), env_(env) {
                if (exporterCore_) {
                    exporterCore_->start(env);
                }
            }
        public:
            UnregisteredExporterIterator(UnregisteredExporterIterator const &iter) 
                : exporterCore_(iter.exporterCore_), env_(iter.env_)
            {
            }
            UnregisteredExporterIterator &operator=(UnregisteredExporterIterator const &iter) {
                if (this != &iter) {
                    exporterCore_ = iter.exporterCore_;
                    env_ = iter.env_;
                }
                return *this;
            }
            UnregisteredExporterIterator &operator++() {
                return *this;
            }
            UnregisteredExporterIterator operator++(int) {
                UnregisteredExporterIterator iter(*this);
                ++(*this);
                return iter;
            }
            UnregisteredExporterIterator &operator*() {
                return *this;
            }
            void operator=(Data<T> &&data) {
                if (data) {
                    if (exporterCore_) {
                        exporterCore_->handle(std::move(*data));
                    }
                }
            }
            void operator=(Data<T> const &data) {
                if (data) {
                    if (exporterCore_) {
                        exporterCore_->handle(InnerData<T> {*data});
                    }
                }
            }
            void operator=(InnerData<T> &&data) {
                if (exporterCore_) {
                    exporterCore_->handle(std::move(data));
                }
            }
            void operator=(InnerData<T> const &data) {
                if (exporterCore_) {
                    exporterCore_->handle(InnerData<T> {data});
                }
            }
            void operator=(T &&data) {
                if (exporterCore_) {
                    exporterCore_->handle(InnerData<T> {
                        env_ 
                        , {
                            env_->resolveTime()
                            , std::move(data)
                            , false
                        }
                    });
                }
            }
            void operator=(T const &data) {
                if (exporterCore_) {
                    exporterCore_->handle(InnerData<T> {
                        env_ 
                        , {
                            env_->resolveTime()
                            , std::move(data)
                            , false
                        }
                    });
                }
            }
        };
        template <class T>
        static UnregisteredExporterIterator<T> unregisteredExporterIterator(EnvironmentType *env, std::shared_ptr<Exporter<T>> const &exporter) {
            if (!exporter) {
                return UnregisteredExporterIterator<T>();
            } else {
                return UnregisteredExporterIterator<T>(env, exporter->core_.get());
            }
        }
        template <class T>
        static UnregisteredExporterIterator<T> iterateUnregisteredExporter(EnvironmentType *env, std::shared_ptr<Exporter<T>> const &exporter) {
            return unregisteredExporterIterator(env, exporter);
        }
    };

    template <class T>
    using TopDownSinglePassIterationApp_T = TopDownSinglePassIterationApp<T>;

} } } }

#endif
