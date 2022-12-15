#ifndef TM_KIT_INFRA_SINGLE_PASS_ITERATION_APP_HPP_
#define TM_KIT_INFRA_SINGLE_PASS_ITERATION_APP_HPP_

#include <tm_kit/infra/WithTimeData.hpp>
#include <tm_kit/infra/ControllableNode.hpp>
#include <tm_kit/infra/ObservableNode.hpp>
#include <tm_kit/infra/StoppableProducer.hpp>
#include <tm_kit/infra/GraphStructureBasedResourceHolderComponent.hpp>

#include <deque>
#include <queue>
#include <stack>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class M>
    class SynchronousRunner;

    namespace single_pass_iteration_app_utils {
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

        template <class Env, bool HasSetTime=(decltype(hasSetLocalTime<Env>(0))::value && decltype(hasResetLocalTime<Env>(0))::value)>
        class TimePreserver;
        
        template <class Env>
        class TimePreserver<Env, true> {
        private:
            Env *env_;
        public:
            TimePreserver(Env *env, typename Env::TimePointType const &localTime) : env_(env) {
                env->setLocalTime(localTime);
            }
            ~TimePreserver() {
                env_->resetLocalTime();
            }
        };
        template <class Env>
        class TimePreserver<Env, false> {
        public:
            TimePreserver(Env *, typename Env::TimePointType const &) {}
            ~TimePreserver() {}
        };
    }

    //Nothing in this monad is mutex protected because it is supposed to run
    //single-threaded
    template <class StateT, std::enable_if_t<StateT::PreserveInputRelativeOrder,int> = 0>
    class SinglePassIterationApp {
    private:
        friend class AppRunner<SinglePassIterationApp>;
        friend class SynchronousRunner<SinglePassIterationApp>;
    public:
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

        struct SpecialOutputDataTypeForExporters {};

        class ProviderBase {
        public:
            virtual ~ProviderBase() {}
        };

        template <class T>
        class Provider;

        template <class T>
        class Certificate {
        private:
            std::optional<TimePoint> timePoint_;
            std::stack<Provider<T> *> signerStack_;
            void *additionalInfo_;
            friend class SinglePassIterationApp;
            Certificate(std::optional<TimePoint> &&tp, std::stack<Provider<T> *> &&signerStack, Provider<T> *topSigner)
                : timePoint_(std::move(tp)), signerStack_(std::move(signerStack)), additionalInfo_(nullptr)
            {
                if (topSigner != nullptr) {
                    signerStack_.push(topSigner);
                }
            }
        public:
            Certificate() : timePoint_(std::nullopt), signerStack_(), additionalInfo_(nullptr) {}
            Certificate(std::optional<TimePoint> &&tp, Provider<T> *signer, void *additionalInfo=nullptr) : timePoint_(std::move(tp)), signerStack_(), additionalInfo_(additionalInfo) {
                signerStack_.push(signer);
            }
            Certificate(Certificate const &c) = default;
            Certificate &operator=(Certificate const &c) = default;
            Certificate(Certificate &&c) = default;
            Certificate &operator=(Certificate &&c) = default;
            Certificate push(Provider<T> *signer) {
                auto ret = Certificate {std::move(timePoint_), std::move(signerStack_), signer};
                ret.additionalInfo_ = additionalInfo_;
                timePoint_ = std::nullopt;
                while (!signerStack_.empty()) {
                    signerStack_.pop();
                }
                return ret;
            }
            bool check() const {
                return (bool) timePoint_;
            }
            void consume(Provider<T> *consumer) {
                assert((bool) timePoint_ && !signerStack_.empty() && (consumer == signerStack_.top()));
                signerStack_.pop();
                if (signerStack_.empty()) {
                    timePoint_ = std::nullopt;
                }
            }
            Provider<T> *topSigner() const {
                return signerStack_.empty()?nullptr:signerStack_.top();
            }
            void *additionalInfo() const {
                return additionalInfo_;
            }
            std::optional<TimePoint> timePoint() const {
                return timePoint_;
            }
        private:
            TimePoint timePointUnsafe() const {
                return *timePoint_;
            }
        };
    private:
        template <class T>
        static TimePoint fetchTimePointUnsafe(Certificate<T> const &c) {
            return c.timePointUnsafe();
        }
    public:
        //The assumption is that next() will ONLY be called if poll() 
        //returns a valid time point, and the certificate is used to 
        //help enforce that
        template <class T>
        class Provider : public virtual ProviderBase {
        public:
            virtual Certificate<T> poll() = 0;
            virtual Data<T> next(Certificate<T> &&cert) = 0;
            virtual ~Provider() {}
        };

        #include <tm_kit/infra/SinglePassIterationApp_Provider_Adapter_Piece.hpp>

        template <class T>
        class FillableProvider final : public Provider<T> {
        private:
            Data<T> data_;
        public:
            FillableProvider() : data_(std::nullopt) {}
            virtual ~FillableProvider() {}
            virtual Certificate<T> poll() override final {
                if (!data_) {
                    return {std::nullopt, this};
                } else {
                    return {data_->timedData.timePoint, this};
                }
            }
            virtual Data<T> next(Certificate<T> &&cert) override final {
                cert.consume(this);
                Data<T> ret = std::move(data_);
                data_ = std::nullopt;
                return ret;
            }
            void fill(InnerData<T> &&d) {
                data_ = {std::move(d)};
            }
        };

        //In the components in this monad, the inputs are always checked
        //linearly and from left to the right. The reason why we don't use
        //a heap structure to check inputs (so as to achieve O(log(n)) instead
        //of O(n)) is mainly because inputs may choose to stay idle, and therefore
        //each input must be queried every time to make sure they do or do
        //not have data. Moreover, it is expected that no more than 10 (and usually
        //no more than 5) inputs will be there, so the O(n) behavior is acceptable.
        template <class T>
        class InputMultiplexer final : public virtual Provider<T> {
        private:
            std::list<Provider<T> *> sources_;
            std::unordered_set<Provider<T> *> sourceSet_;
        public:
            InputMultiplexer() : sources_(), sourceSet_() {}
            virtual ~InputMultiplexer() {}

            bool hasSource() const {
                return !sources_.empty();
            }

            void addSource(Provider<T> *p) {
                if (p != nullptr && sourceSet_.find(p) == sourceSet_.end()) {
                    sources_.push_back(p);
                    sourceSet_.insert(p);
                }
            }
            virtual Certificate<T> poll() override final {
                Certificate<T> cert;
                std::optional<TimePoint> retTime = std::nullopt;
                for (auto *p : sources_) {
                    auto certP = p->poll();
                    if (certP.check()) {
                        if (!retTime || (*retTime) > fetchTimePointUnsafe(certP)) {
                            retTime = fetchTimePointUnsafe(certP);
                            cert = std::move(certP);
                        }
                    }
                }
                return cert.push(this);
            }
            virtual Data<T> next(Certificate<T> &&cert) override final {
                cert.consume(this);
                auto *p = cert.topSigner();
                Data<T> x = p->next(std::move(cert));
                if (!x) {
                    return x;
                }
                if (x->timedData.finalFlag) {
                    if (sourceSet_.find(p) != sourceSet_.end()) {
                        sources_.erase(std::find(sources_.begin(), sources_.end(), p));
                        sourceSet_.erase(p);
                    }                                    
                    if (!sources_.empty()) {
                        x->timedData.finalFlag = false;
                    }
                }
                return x;
            }
        };

        class ConsumerBase {
        public:
            virtual ~ConsumerBase() {}
        };

        template <class T>
        class AbstractConsumer : public virtual ConsumerBase {
        public:
            virtual ~AbstractConsumer() {}
            virtual Provider<T> *source() = 0;
            virtual void connectToSource(Provider<T> *s) = 0;
        };

        template <class T>
        class Consumer : public virtual AbstractConsumer<T> {
        private:
            InputMultiplexer<T> source_;
        public:
            Consumer() : source_() {}
            virtual Provider<T> *source() override final {
                return &source_;
            }
            virtual void connectToSource(Provider<T> *s) override final {
                source_.addSource(s);
            }
        };

        class OutputMultiplexerBase {
        public:
            virtual ~OutputMultiplexerBase() {}
        };

        template <class T>
        class OutputMultiplexer : public virtual OutputMultiplexerBase {
        private:
            Provider<T> *source_;
            struct QueueItem {
                std::unique_ptr<std::tuple<TimePoint,Data<T>>> data;
                int remainingCount;
            };
            using Queue = std::deque<QueueItem>;
            Queue queue_;
            friend class SinglePassIterationApp;
        public:
            class Output : public virtual Provider<T> {
            private:
                friend class OutputMultiplexer;
                OutputMultiplexer *parent_;
                std::size_t qPos_;
            public:
                Output(OutputMultiplexer *parent) : parent_(parent), qPos_(parent_->queue_.size()) {}
                Output(Output const &) = delete;
                Output &operator=(Output const &) = delete;
                Output(Output &&) = default;
                Output &operator=(Output &&) = default;
                virtual ~Output() {}
                virtual Certificate<T> poll() override final {
                    if (parent_->outputs_.size() == 1) {
                        return parent_->source_->poll().push(this);
                    }                 
                    if (qPos_ >= parent_->queue_.size()) {
                        auto parentCert = parent_->source_->poll();
                        return parentCert.push(this);
                    } else { 
                        return Certificate<T> {std::get<0>(*((parent_->queue_.begin()+qPos_)->data)), this};
                    }
                }
                virtual Data<T> next(Certificate<T> &&cert) override final {
                    if (parent_->outputs_.size() == 1) {
                        cert.consume(this);
                        return parent_->source_->next(std::move(cert));
                    }
                    cert.consume(this);
                    if (qPos_ >= parent_->queue_.size()) {
                        if (parent_->queue_.empty()) {
                            parent_->enqueue(std::move(cert));
                            auto iter = parent_->queue_.begin();
                            Data<T> x;
                            if (std::get<1>(*(iter->data))) {
                                x = std::get<1>(*(iter->data))->clone();
                            } else {
                                x = std::nullopt;
                            }
                            --(iter->remainingCount);
                            qPos_ = 1;
                            parent_->updateQueue();
                            return x;
                        } else {
                            parent_->enqueue(std::move(cert));
                            auto iter = parent_->queue_.begin()+qPos_;
                            Data<T> x;
                            if (std::get<1>(*(iter->data))) {
                                x = std::get<1>(*(iter->data))->clone();
                            } else {
                                x = std::nullopt;
                            }
                            --(iter->remainingCount);
                            qPos_ = parent_->queue_.size();
                            parent_->updateQueue();
                            return x;
                        }
                    } else {
                        auto iter = parent_->queue_.begin()+qPos_;
                        Data<T> x;
                        if (std::get<1>(*(iter->data))) {
                            x = std::get<1>(*(iter->data))->clone();
                        } else {
                            x = std::nullopt;
                        }
                        --(iter->remainingCount);
                        ++qPos_;
                        parent_->updateQueue();
                        return x;
                    }
                }
            };
            friend class Output;
            friend class SinglePassForwardingApp;
        private:
            std::vector<std::unique_ptr<Output>> outputs_;
            void updateQueue() {
                int popCount = 0;
                while (!queue_.empty()) {
                    if (queue_.front().remainingCount <= 0) {
                        queue_.pop_front();
                        ++popCount;
                    } else {
                        break;
                    }
                }
                for (auto &output : outputs_) {
                    output->qPos_ -= popCount;
                    if (output->qPos_ < 0) {
                        output->qPos_ = 0;
                    }
                }
            }
            Output *addOutput() {
                outputs_.push_back(std::make_unique<Output>(this));
                return outputs_.back().get();
            }
            void enqueue(Certificate<T> &&cert) {
                auto tp = fetchTimePointUnsafe(cert);
                queue_.push_back({
                    std::make_unique<std::tuple<TimePoint,Data<T>>>(tp, source_->next(std::move(cert)))
                    , (int) outputs_.size()
                });
            }
        public:
            OutputMultiplexer(Provider<T> *source) : source_(source), queue_(), outputs_() {}
            virtual ~OutputMultiplexer() {}
        };

    private:
        template <class T, class Input, class Output>
        class TwoWayHolder {
        private:
            friend class SinglePassIterationApp;
            IControllableNode<StateT> *controlInfo_;
            IObservableNode<StateT> *observeInfo_;
            std::unique_ptr<T> core_;
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
            friend class SinglePassIterationApp;
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
            OneWayHolder(A *p) : controlInfo_(dynamic_cast<IControllableNode<StateT> *>(p)), observeInfo_(dynamic_cast<IObservableNode<StateT> *>(p)), core_(std::unique_ptr<T>(static_cast<T *>(p))) {}
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
            friend class SinglePassIterationApp;
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
            ThreeWayHolder(A *p1, B*p2) : core1_(static_cast<T1 *>(p1)), core2_(static_cast<T2 *>(p2)) {
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
            friend class SinglePassIterationApp;
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

    private:
        template <class T>
        static constexpr uint8_t variantOutputNumber() {
            if constexpr (withtime_utils::IsVariant<T>::Value) {
                return std::variant_size_v<T>;
            } else {
                return 1;
            }
        }
        template <class A, class B>
        class AbstractActionCore : public virtual AbstractConsumer<A>, public virtual Provider<B>, public virtual IStoppableProducer<variantOutputNumber<B>()>, public virtual IControllableNode<StateT>, public virtual IObservableNode<StateT> {
        public:
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

        #include <tm_kit/infra/SinglePassIterationApp_AbstractActionCore_Piece.hpp>

        template <class B>
        class BufferedProvider : public virtual Provider<B> {
        protected:
            using CheckAndProduceResult =
                std::optional<
                    std::tuple<TimePoint, std::function<Data<B>()>>
                >;
            virtual CheckAndProduceResult checkAndProduce() = 0;
        private:
            CheckAndProduceResult buffer_; 
            void fillBuffer() {
                if (buffer_) {
                    return;
                }
                buffer_ = checkAndProduce();
            }
        public:
            virtual Certificate<B> poll() override final {
                if (!buffer_) {
                    fillBuffer();
                }
                if (!buffer_) {
                    return Certificate<B> { std::nullopt , this };
                } else {
                    return Certificate<B> { std::get<0>(*buffer_) , this };
                }
            }
            virtual Data<B> next(Certificate<B> &&cert) override final {
                cert.consume(this);
                std::tuple<TimePoint, std::function<Data<B>()>> ret = std::move(*buffer_);
                buffer_ = std::nullopt;
                auto v = std::get<1>(ret)();
                if constexpr (!(decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value)) {
                    if (v) {
                        v->overrideTime(std::get<0>(ret));
                    }
                }
                return v;
            }
        };

        using DelaySimulatorType = typename LiftParameters<TimePoint>::DelaySimulatorType;

        template <class T>
        static uint8_t outputIndex(T const &d) {
            if constexpr (withtime_utils::IsVariant<T>::Value) {
                return (uint8_t) (d.index());
            } else {
                return 0;
            }
        }

        template <class A, class B>
        class ActionCore : public virtual AbstractActionCore<A,B>, public virtual Consumer<A>, public virtual BufferedProvider<B> {
        private:
            bool hasA_;
            TimePoint aTime_;
            VersionChecker<A> versionChecker_;
            DelaySimulatorType delaySimulator_;
        protected:
            virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
                Certificate<A> t { this->source()->poll() };
                if (!t.check()) {
                    return std::nullopt;
                }
                auto tp = fetchTimePointUnsafe(t);
                auto produce = [tp,t=std::move(t),this]() -> Data<B> {
                    Certificate<A> t1 {std::move(t)};
                    auto input = this->source()->next(std::move(t1));
                    if (!input) {
                        return std::nullopt;
                    }
                    if (!versionChecker_.checkVersion(input->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !hasA_ || tp >= aTime_) {
                        hasA_ = true;
                        aTime_ = tp;
                        GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                            input->environment, static_cast<AbstractActionCore<A,B> *>(this)
                        );
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<A,B>> tracer(
                            input->environment 
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(std::move(*input));
                                if (r) {
                                    auto tp1 = tp;
                                    tp1 += (*delaySimulator_)(0, tp);
                                    r->overrideTime(tp1);
                                }
                                return r;
                            } else {
                                return realHandle(std::move(*input));
                            }
                        } else {
                            return realHandle(std::move(*input));
                        }
                    } else {
                        return std::nullopt;
                    }    
                };
                auto tp1 = tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(0, tp);
                }
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp1, produce};
            }       
            virtual Data<B> handle(InnerData<A> &&) = 0;
            Data<B> realHandle(InnerData<A> &&a) {
                auto ret = handle(std::move(a));
                if (ret) {
                    if (this->producerIsStopped(outputIndex<B>(ret->timedData.value))) {
                        return std::nullopt;
                    } else {
                        return ret;
                    }
                } else {
                    return std::nullopt;
                }
            }
        public:
            ActionCore(DelaySimulatorType const &delaySimulator=DelaySimulatorType()) : Provider<B>(), Consumer<A>(), hasA_(false), aTime_(), versionChecker_(), delaySimulator_(delaySimulator) {}           
        };

        template <class B>
        class MultiBufferedProvider : public virtual Provider<B> {
        protected:
            using CheckAndProduceResult =
                std::optional<
                    std::tuple<TimePoint, std::function<MultiData<B>()>>
                >;
            virtual CheckAndProduceResult checkAndProduce() = 0;
        private:
            MultiData<B> latestBFrame_;
            std::deque<B> latestBs_;
            CheckAndProduceResult buffer_; 
            void fillBuffer() {
                if (latestBFrame_) {
                    return;
                }
                if (buffer_) {
                    return;
                }
                buffer_ = checkAndProduce();
            }
        public:
            virtual Certificate<B> poll() override final {
                if (latestBFrame_) {
                    return Certificate<B> { latestBFrame_->timedData.timePoint, this };
                }
                if (!buffer_) {
                    fillBuffer();
                }
                if (!buffer_) {
                    return Certificate<B> { std::nullopt , this };
                } else {
                    return Certificate<B> { std::get<0>(*buffer_) , this };
                }
            }
            virtual Data<B> next(Certificate<B> &&cert) override final {
                cert.consume(this);
                if (!latestBFrame_) {
                    std::tuple<TimePoint, std::function<MultiData<B>()>> ret = std::move(*buffer_);
                    buffer_ = std::nullopt;
                    latestBFrame_ = std::get<1>(ret)();
                    if (!latestBFrame_) {
                        return std::nullopt;
                    }
                    if constexpr (!(decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value)) {
                        latestBFrame_->overrideTime(std::get<0>(ret));
                    }
                    if (latestBFrame_->timedData.value.empty()) {
                        latestBFrame_ = std::nullopt;
                        return std::nullopt;
                    }
                    for (auto &&item : latestBFrame_->timedData.value) {
                        latestBs_.push_back(std::move(item));
                    }
                    latestBFrame_->timedData.value.clear();
                }
                InnerData<B> retData = InnerData<B> {
                    latestBFrame_->environment
                    , {
                        latestBFrame_->timedData.timePoint
                        , std::move(latestBs_.front())
                        , latestBFrame_->timedData.finalFlag
                    }
                };
                latestBs_.pop_front();
                if (!latestBs_.empty()) {
                    retData.timedData.finalFlag = false;
                } else {
                    latestBFrame_ = std::nullopt;
                }
                return retData;
            }
        };

        template <class A, class B>
        class MultiActionCore : public virtual AbstractActionCore<A,B>, public virtual Consumer<A>, public virtual MultiBufferedProvider<B> {
        private:
            bool hasA_;
            TimePoint aTime_;
            VersionChecker<A> versionChecker_;
            DelaySimulatorType delaySimulator_;
        protected:
            virtual typename MultiBufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
                Certificate<A> t { this->source()->poll() };
                if (!t.check()) {
                    return std::nullopt;
                }
                auto tp = fetchTimePointUnsafe(t);
                auto produce = [tp,t=std::move(t),this]() -> MultiData<B> {
                    Certificate<A> t1 {std::move(t)};
                    auto input = this->source()->next(std::move(t1));
                    if (!input) {
                        return std::nullopt;
                    }
                    if (!versionChecker_.checkVersion(input->timedData.value)) {
                        return std::nullopt;
                    }
                    if (!StateT::CheckTime || !hasA_ || tp >= aTime_) {
                        hasA_ = true;
                        aTime_ = tp;
                        GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                            input->environment, static_cast<AbstractActionCore<A,B> *>(this)
                        );
                        TraceNodesComponentWrapper<StateT,AbstractActionCore<A,B>> tracer(
                            input->environment 
                            , this
                        );
                        if constexpr (decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value) {
                            if (delaySimulator_) {
                                auto r = realHandle(std::move(*input));
                                if (r) {
                                    auto tp1 = tp;
                                    tp1 += (*delaySimulator_)(0, tp);
                                    r->overrideTime(tp1);
                                }
                                return r;
                            } else {
                                return realHandle(std::move(*input));
                            }
                        } else {
                            return realHandle(std::move(*input));
                        }
                    } else {
                        return std::nullopt;
                    }    
                };
                auto tp1 = tp;
                if (delaySimulator_) {
                    tp1 += (*delaySimulator_)(0, tp);
                }
                return std::tuple<TimePoint, std::function<MultiData<B>()>> {tp1, produce};
            }       
            virtual MultiData<B> handle(InnerData<A> &&) = 0;
            MultiData<B> realHandle(InnerData<A> &&a) {
                auto ret = handle(std::move(a));
                if (ret) {
                    std::vector<B> filtered;
                    for (auto &&item : ret->timedData.value) {
                        if (!this->producerIsStopped(outputIndex<B>(item))) {
                            filtered.push_back(std::move(item));
                        }
                    }
                    if (filtered.empty()) {
                        return std::nullopt;
                    } else {
                        ret->timedData.value = std::move(filtered);
                        return ret;
                    }
                } else {
                    return std::nullopt;
                }
            }
        public:
            MultiActionCore(DelaySimulatorType const &delaySimulator=DelaySimulatorType()) : Provider<B>(), Consumer<A>(), hasA_(false), aTime_(), versionChecker_(), delaySimulator_(delaySimulator) {}           
        };

    private:
        template <class T>
        static inline Data<T> applyDelaySimulator(int which, InnerData<T> &&input, DelaySimulatorType const &delaySimulator) {
            if (delaySimulator) {
                auto delay = (*delaySimulator)(which, input.timedData.timePoint);
                input.timedData.timePoint += delay;
            } 
            return Data<T> {std::move(input)};
        }
        template <class T>
        static inline Data<T> applyDelaySimulatorForKleisli(int which, Data<T> &&input, DelaySimulatorType const &delaySimulator) {
            if (delaySimulator) {
                if (input) {
                    auto delay = (*delaySimulator)(which, input->timedData.timePoint);
                    input->timedData.timePoint += delay;
                }  
            } 
            return std::move(input);
        }
        template <class A, class B, class F>
        class PureActionCore final : public ActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    } else {
                        Data<B> x = pureInnerDataLift<A>(f_, std::move(a));
                        if (x) {
                            x->timedData.finalFlag = true;
                            done_ = true;
                        }
                        return x;
                    }
                } else {
                    return pureInnerDataLift<A>(f_, std::move(a));
                }
            }
        public:
            PureActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            PureActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~PureActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }  
        };
        template <class A, class B, class F>
        class MaybeActionCore final : public ActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    }
                }
                std::optional<B> y = f_(std::move(a.timedData.value));
                if (!y) {
                    return std::nullopt;
                } else {
                    if (fireOnceOnly_) {
                        Data<B> z = pureInnerData<B>(
                            a.environment,
                            {a.timedData.timePoint, std::move(*y), a.timedData.finalFlag}
                        );
                        if (z) {
                            z->timedData.finalFlag = true;
                            done_ = true;
                        }
                        return z;
                    } else {
                        return pureInnerData<B>(
                            a.environment,
                            {a.timedData.timePoint, std::move(*y), a.timedData.finalFlag}
                        );
                    }
                }
            }
        public:
            MaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            MaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~MaybeActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };
        template <class A, class B, class F>
        class EnhancedMaybeActionCore final : public ActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    }
                }
                std::optional<B> y = f_(std::tuple<TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)});
                if (!y) {
                    return std::nullopt;
                } else {
                    if (fireOnceOnly_) {
                        Data<B> z = pureInnerData<B>(
                            a.environment,
                            {a.timedData.timePoint, std::move(*y), a.timedData.finalFlag}
                        );
                        if (z) {
                            z->timedData.finalFlag = true;
                            done_ = true;
                        }
                        return z;
                    } else {
                        return pureInnerData<B>(
                            a.environment,
                            {a.timedData.timePoint, std::move(*y), a.timedData.finalFlag}
                        );
                    }
                }
            }
        public:
            EnhancedMaybeActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            EnhancedMaybeActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~EnhancedMaybeActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };
        template <class A, class B, class F>
        class KleisliActionCore final : public ActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    }
                    auto x = f_(std::move(a));
                    if (x) {
                        x->timedData.finalFlag = true;
                        done_ = true;
                    }
                    return x;
                } else {
                    return f_(std::move(a));
                }
            }
        public:
            KleisliActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : ActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            KleisliActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : ActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~KleisliActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };

    public:
        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A> || is_monostate_keyed_data_v<B>,int> = 0 >
        using AbstractAction = AbstractActionCore<A,B>;

        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A> || is_monostate_keyed_data_v<B>,int> = 0 >
        using Action = TwoWayHolder<AbstractActionCore<A,B>,A,B>;

        template <class A, class B>
        static bool actionIsThreaded(std::shared_ptr<Action<A,B>> const &) {
            return false; 
        }
        template <class A, class B>
        static bool actionIsOneTimeOnly(std::shared_ptr<Action<A,B>> const &a) {
            return a->core_->isOneTimeOnly(); 
        }

    public:
        template <class A, class F>
        static auto liftPure(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, decltype(f(A()))>> {
            return std::make_shared<Action<A, decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
        template <class A, class F>
        static auto liftMaybe(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
        template <class A, class F>
        static auto enhancedMaybe(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
        template <class A, class F>
        static auto kleisli(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>(new KleisliActionCore<A,typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType,F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
    private:
        template <class A, class B, class F>
        class SimpleMultiActionCore final : public MultiActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual MultiData<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    }
                    MultiData<B> x = {
                        pureInnerDataLift<A>(f_, std::move(a))
                    };
                    if (x && x->timedData.value.size() > 0) {
                        x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                        x->timedData.finalFlag = true;
                        done_ = true;
                    }
                    return x;
                } else {
                    return MultiData<B> {
                        pureInnerDataLift<A>(f_, std::move(a))
                    };
                }
            }
        public:
            SimpleMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            SimpleMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~SimpleMultiActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };
        template <class A, class B, class F>
        class EnhancedMultiActionCore final : public MultiActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual MultiData<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    }
                }
                std::vector<B> y = f_(std::tuple<TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)});
                if (fireOnceOnly_) {
                    MultiData<B> z = pureInnerData<std::vector<B>>(
                        a.environment,
                        {a.timedData.timePoint, std::move(y), a.timedData.finalFlag}
                    );
                    if (z && z->timedData.value.size() > 0) {
                        z->timedData.value = std::vector<B> {std::move(z->timedData.value[0])};
                        z->timedData.finalFlag = true;
                        done_ = true;
                    }
                    return z;
                } else {
                    return pureInnerData<std::vector<B>>(
                        a.environment,
                        {a.timedData.timePoint, std::move(y), a.timedData.finalFlag}
                    );
                }
            }
        public:
            EnhancedMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            EnhancedMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~EnhancedMultiActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };
        template <class A, class B, class F>
        class KleisliMultiActionCore final : public MultiActionCore<A,B> {
        private:
            F f_;
            bool fireOnceOnly_;
            bool done_;
        protected:
            virtual MultiData<B> handle(InnerData<A> &&a) override final {
                if (fireOnceOnly_) {
                    if (done_) {
                        return std::nullopt;
                    }
                    auto x = f_(std::move(a));
                    if (x && x->timedData.value.size() > 0) {
                        x->timedData.value = std::vector<B> {std::move(x->timedData.value[0])};
                        x->timedData.finalFlag = true;
                        done_ = true;
                    }
                    return x;
                } else {
                    return f_(std::move(a));
                }
            }
        public:
            KleisliMultiActionCore(F &&f, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : MultiActionCore<A,B>(delaySimulator), f_(std::move(f)), fireOnceOnly_(fireOnceOnly), done_(false) {
            }
            KleisliMultiActionCore(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) : MultiActionCore<A,B>(liftParam.delaySimulator), f_(std::move(f)), fireOnceOnly_(liftParam.fireOnceOnly), done_(false) {
            }
            virtual ~KleisliMultiActionCore() {}
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };
    public:
        template <class A, class F>
        static auto liftMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(A()))::value_type>>(new SimpleMultiActionCore<A,typename decltype(f(A()))::value_type,F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
        template <class A, class F>
        static auto enhancedMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMultiActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
        template <class A, class F>
        static auto kleisliMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType::value_type>>(new KleisliMultiActionCore<A,typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType::value_type,F>(std::move(f), liftParam.delaySimulator, liftParam.fireOnceOnly));
        }
    private:
        template <class B, class ContinuationStructure>
        class ContinuationProvider : public virtual Provider<B> {
        protected:
            struct CheckAndProduceResult {
                std::optional<
                    std::tuple<TimePoint, std::function<std::tuple<CheckAndProduceResult, Data<B>>()>>
                > content;
            };
            virtual CheckAndProduceResult checkAndProduce() = 0;
        private:
            CheckAndProduceResult res_;
        public:
            virtual Certificate<B> poll() override final {
                if (!(res_.content)) {
                    res_ = checkAndProduce();
                }
                if (res_.content) {
                    return Certificate<B> { std::get<0>(*(res_.content)), this };
                } else {
                    return Certificate<B> { std::nullopt, this };
                }
            }
            virtual Data<B> next(Certificate<B> &&cert) override final {
                cert.consume(this);
                if (res_.content) {
                    auto ret = std::get<1>(*(res_.content))();
                    if constexpr (!(decltype(single_pass_iteration_app_utils::hasSetLocalTime<StateT>(0))::value && decltype(single_pass_iteration_app_utils::hasResetLocalTime<StateT>(0))::value)) {
                        if (std::get<1>(ret)) {
                            std::get<1>(ret)->overrideTime(std::get<0>(*(res_.content)));
                        }
                    }
                    res_ = std::get<0>(ret);
                    return std::get<1>(ret);
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, class B, class ContinuationStructure>
        class ContinuationActionCore final : public virtual AbstractActionCore<A,B>, public virtual Consumer<A>, public virtual ContinuationProvider<B, ContinuationStructure> {
        private:
            bool hasA_;
            TimePoint aTime_;
            VersionChecker<A> versionChecker_;
            TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> cont_;
            ContinuationStructure state_;
            DelaySimulatorType delaySimulator_;
            bool fireOnceOnly_;
            bool done_;
            using CPR = typename ContinuationProvider<B,ContinuationStructure>::CheckAndProduceResult;
            
            Data<A> inputCopy_;
            std::tuple<CPR, Data<B>> nextStep() {
                if (fireOnceOnly_ && done_) {
                    return std::tuple<CPR, Data<B>> {{std::nullopt}, std::nullopt};
                }
                Data<B> ret = std::nullopt;
                cont_(inputCopy_->clone(), state_, [this,&ret](InnerData<B> &&b) {
                    ret = std::move(b);
                    if (fireOnceOnly_) {
                        done_ = true;
                    }
                });
                if (!ret) {
                    return std::tuple<CPR, Data<B>> {{std::nullopt}, std::nullopt};
                }
                std::optional<TimePoint> nextTP = state_.nextTimePoint();
                if (!nextTP) {
                    return std::tuple<CPR, Data<B>> {{std::nullopt}, std::move(ret)};
                }
                return std::tuple<CPR, Data<B>> {
                    CPR { std::tuple<TimePoint, std::function<std::tuple<CPR,Data<B>>()>> {
                        *nextTP 
                        , [this](){
                            return nextStep();
                        }
                    }}
                    , std::move(ret)
                };
            }
        protected:
            virtual CPR checkAndProduce() override final {
                Certificate<A> t { this->source()->poll() };
                if (!t.check()) {
                    return {std::nullopt};
                }
                auto tp = fetchTimePointUnsafe(t);
                if (delaySimulator_) {
                    tp += (*delaySimulator_)(0, tp);
                }
                auto produce = [tp,t=std::move(t),this]() -> std::tuple<CPR,Data<B>> {
                    Certificate<A> t1 {std::move(t)};
                    auto input = this->source()->next(std::move(t1));
                    if (!input) {
                        return {{std::nullopt}, std::nullopt};
                    }
                    if (!versionChecker_.checkVersion(input->timedData.value)) {
                        return {{std::nullopt}, std::nullopt};
                    }
                    if (!StateT::CheckTime || !hasA_ || tp >= aTime_) {
                        hasA_ = true;
                        aTime_ = tp;
                        inputCopy_ = std::move(*input);
                        return nextStep();                        
                    } else {
                        return {{std::nullopt}, std::nullopt};
                    }    
                };
                TimePoint tp1 = tp;
                std::optional<TimePoint> tp2 = state_.nextTimePoint();
                if (tp2 && *tp2 < tp1) {
                    tp1 = *tp2;
                }
                return CPR { { std::tuple<TimePoint, std::function<std::tuple<CPR,Data<B>>()>> {tp1, produce} } };
            }       
        public:
            ContinuationActionCore(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state, DelaySimulatorType const &delaySimulator, bool fireOnceOnly) : Provider<B>(), Consumer<A>(), hasA_(false), aTime_(), versionChecker_(), cont_(cont), state_(std::move(state)), delaySimulator_(delaySimulator), fireOnceOnly_(fireOnceOnly), done_(false), inputCopy_(std::nullopt) {}           
            virtual bool isOneTimeOnly() const override final {
                return fireOnceOnly_;
            }
        };
    public:
        template <class A, class B, class ContinuationStructure>
        static auto continuationAction(TimedAppModelContinuation<A, B, ContinuationStructure, EnvironmentType> const &cont, ContinuationStructure &&state=ContinuationStructure(), LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, B>> {
            return std::make_shared<Action<A,B>>(
                new ContinuationActionCore<A,B,ContinuationStructure>(cont, std::move(state), liftParam.delaySimulator, liftParam.fireOnceOnly)
            );
        }
    
    private:
        template <class A, class B, class C>
        class ComposeCore : public virtual AbstractActionCore<A,C> {
        private:
            std::unique_ptr<AbstractActionCore<A,B>> x_;
            std::unique_ptr<AbstractActionCore<B,C>> y_;
        protected:
            virtual Provider<A> *source() override final {
                return x_->source();
            }
        public:
            ComposeCore(std::unique_ptr<AbstractActionCore<A,B>> &&x, std::unique_ptr<AbstractActionCore<B,C>> &&y) 
                : x_(std::move(x)), y_(std::move(y))
            {
                y_->connectToSource(x_.get());
                if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                    GraphStructureBasedResourceHolderComponent::registerParentNode(x_.get(), static_cast<AbstractActionCore<A,C> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(y_.get(), static_cast<AbstractActionCore<A,C> *>(this));
                }
            }
            virtual void connectToSource(Provider<A> *source) override final {
                x_->connectToSource(source);
            }
            virtual Certificate<C> poll() override final {
                auto c = y_->poll();
                return c.push(this);
            }
            virtual Data<C> next(Certificate<C> &&cert) override final {
                cert.consume(this);
                return y_->next(std::move(cert));
            }
            virtual bool isOneTimeOnly() const override final {
                return x_->isOneTimeOnly() || y_->isOneTimeOnly();
            }
        };

    public:
        template <class A, class B, class C>
        static std::shared_ptr<Action<A,C>> compose(Action<A,B> &&x, Action<B,C> &&y) {
            return std::make_shared<Action<A,C>>(new ComposeCore<A,B,C>(std::move(x.core_), std::move(y.core_)));
        }
    public:
        template <class T, typename=std::enable_if_t<
            !withtime_utils::IsVariant<T>::Value
            && !std::is_same_v<T, std::any>
        >>
        static auto passThroughAction() {
            return liftPure<T>([](T &&t) {return std::move(t);});
        }
    private:
        template <class... Ts>
        class DispatchTupleActionF {
        private:
            template <std::size_t Idx>
            void fillRes(std::vector<std::variant<Ts...>> &res, std::tuple<Ts...> &&data) {
                if constexpr (Idx < sizeof...(Ts)) {
                    res.push_back(std::variant<Ts...> {
                        std::in_place_index<Idx>, std::move(std::get<Idx>(data))
                    });
                    fillRes<Idx+1>(res, std::move(data));
                }
            }
        public:
            std::vector<std::variant<Ts...>> operator()(std::tuple<Ts...> &&data) {
                std::vector<std::variant<Ts...>> res;
                fillRes<0>(res, std::move(data));
                return res;
            }
        };
    public:
        template <class... Ts>
        static auto dispatchTupleAction() {
            return liftMulti<std::tuple<Ts...>>(DispatchTupleActionF<Ts...> {});
        }
    public:
        class IExternalComponent {
        public:
            virtual ~IExternalComponent() {}
            virtual void start(StateT *environment) = 0;
        };

    private:
        template <class A, class B>
        class OnOrderFacilityCore {
        private:
            friend class SinglePassIterationApp;
            struct TimeComparer {
                bool operator()(std::tuple<uint64_t,InnerData<KeyedData<A,B>>> const &a, std::tuple<uint64_t,InnerData<KeyedData<A,B>>> const &b) {
                    if (std::get<1>(a).timedData.timePoint > std::get<1>(b).timedData.timePoint) {
                        return true;
                    } else if (std::get<1>(a).timedData.timePoint < std::get<1>(b).timedData.timePoint) {
                        return false;
                    } else {
                        return (std::get<0>(a) > std::get<0>(b));
                    }
                }
            };
            using DQueue = std::priority_queue<std::tuple<uint64_t,InnerData<KeyedData<A,B>>>, std::vector<std::tuple<uint64_t,InnerData<KeyedData<A,B>>>>, TimeComparer>;
            class ResponseProvider final : public virtual Provider<KeyedData<A,B>> {
            private:
                DQueue queue_;
                friend class OnOrderFacilityCore;
                uint64_t counter_ = 0;
                void addResponse(InnerData<KeyedData<A,B>> &&response) {
                    queue_.push({counter_, std::move(response)});
                    ++counter_;
                }
            public:
                ResponseProvider() = default;
                virtual Certificate<KeyedData<A,B>> poll() override final {
                    if (queue_.empty()) {
                        return Certificate<KeyedData<A,B>> {std::nullopt, this};
                    }
                    return Certificate<KeyedData<A,B>> {std::get<1>(queue_.top()).timedData.timePoint, this};
                }
                virtual Data<KeyedData<A,B>> next(Certificate<KeyedData<A,B>> &&cert) override final {
                    cert.consume(this);
                    auto ret = std::move(std::get<1>(queue_.top()));              
                    queue_.pop();
                    return {ret};
                }
            };
            std::unordered_map<typename StateT::IDType, std::tuple<Key<A>, bool, ResponseProvider *>, typename StateT::IDHash> keyMap_;
            std::unordered_map<AbstractConsumer<KeyedData<A,B>> *, std::unique_ptr<ResponseProvider>> providers_;
            bool synchronousRunnerMode_;
            void enableSynchronousRunnerMode() {
                synchronousRunnerMode_ = true;
            }
            void clearConsumersInSynchronousRunnerMode() {
                if (synchronousRunnerMode_) {
                    keyMap_.clear();
                    providers_.clear();
                }
            }
        protected:
            void publishResponse(InnerData<Key<B>> &&response) {
                auto iter = keyMap_.find(response.timedData.value.id());
                if (iter == keyMap_.end()) {
                    return;
                }
                bool isFinalResponseForThisKey = response.timedData.finalFlag;
                Key<A> key = std::get<0>(iter->second);
                auto keyedData = pureInnerDataLift(
                    [key=std::move(key)](Key<B> &&b) -> KeyedData<A,B> {
                        return {key, b.key()};
                    }
                    , std::move(response)
                    , true
                );
                auto *responder = std::get<2>(iter->second);
                if (isFinalResponseForThisKey) {
                    if (!synchronousRunnerMode_ && !std::get<1>(iter->second)) {
                        //this key is not final
                        keyedData.timedData.finalFlag = false; 
                    }
                    keyMap_.erase(iter);
                }
                responder->addResponse(std::move(keyedData));
            }
            void publish(InnerData<Key<B>> &&response) {
                publishResponse(std::move(response));
            }   
            void publish(StateT *env, Key<B> &&data, bool isFinal) {
                publish(pureInnerData<Key<B>>(env, std::move(data), isFinal));
            }  
            void markEndHandlingRequest(typename StateT::IDType const &id) {                
                keyMap_.erase(id);
            }
            static constexpr OnOrderFacilityCore *nullptrToInheritedFacility() {return nullptr;}
        public:
            OnOrderFacilityCore() : keyMap_(), providers_(), synchronousRunnerMode_(false) {}
            virtual ~OnOrderFacilityCore() {}           
            void placeOrder(InnerData<Key<A>> &&input, AbstractConsumer<KeyedData<A,B>> *consumer) {
                if (consumer != nullptr) {
                    Key<A> keyCopy = input.timedData.value;
                    bool keyIsFinal = input.timedData.finalFlag;
                    ResponseProvider *p = nullptr;
                    auto iter = providers_.find(consumer);
                    if (iter == providers_.end()) {
                        auto pp = std::make_unique<ResponseProvider>();
                        p = pp.get();
                        providers_.insert({consumer, std::move(pp)});
                        consumer->connectToSource(p);
                    } else {
                        p = iter->second.get();
                    }
                    keyMap_.insert({
                        keyCopy.id()
                        , {keyCopy, keyIsFinal, p}
                    });                   
                }
                handle(std::move(input));
            }   
            virtual void handle(InnerData<Key<A>> &&input) = 0;
        private:
            virtual void fetchProvidersForAppRunner(std::list<Provider<SpecialOutputDataTypeForExporters> *> &) {
                //by default do nothing
            } 
            friend class SinglePassIterationApp;       
        };

    public:
        template <class A, class B>
        using AbstractOnOrderFacility = OnOrderFacilityCore<A,B>;
        template <class A, class B>
        using OnOrderFacility = TwoWayHolder<OnOrderFacilityCore<A,B>,A,B>;

    private:
        template <class A, class B, class F>
        class PureOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_; 
            DelaySimulatorType delaySimulator_;
        public:
            PureOnOrderFacilityCore(F &&f, DelaySimulatorType const &delaySimulator) : OnOrderFacilityCore<A,B>(), f_(std::move(f)), delaySimulator_(delaySimulator) {
            }
            virtual ~PureOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                auto resp = *applyDelaySimulator<Key<B>>(0, pureInnerDataLift([this](Key<A> &&k) {
                    return withtime_utils::apply(f_, std::move(k));
                }, std::move(input)), delaySimulator_);
                resp.timedData.finalFlag = true; 
                this->publishResponse(std::move(resp));
            }
        };
        template <class A, class B, class F>
        class MaybeOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_;
            DelaySimulatorType delaySimulator_;
        public:
            MaybeOnOrderFacilityCore(F &&f, DelaySimulatorType const &delaySimulator) : OnOrderFacilityCore<A,B>(), f_(std::move(f)), delaySimulator_(delaySimulator) {
            }
            virtual ~MaybeOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                typename StateT::IDType id = input.timedData.value.id();
                std::optional<B> x = f_(std::move(input.timedData.value.key()));
                if (x) {
                    this->publishResponse(*applyDelaySimulator<Key<B>>(0, pureInnerData<Key<B>>(input.environment, {input.timedData.timePoint, {id, std::move(*x)}, true}), delaySimulator_));
                } 
            }
        };
        template <class A, class B, class F>
        class EnhancedMaybeOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_;
            DelaySimulatorType delaySimulator_;
        public:
            EnhancedMaybeOnOrderFacilityCore(F &&f, DelaySimulatorType const &delaySimulator) : OnOrderFacilityCore<A,B>(), f_(std::move(f)), delaySimulator_(delaySimulator) {
            }
            virtual ~EnhancedMaybeOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                typename StateT::IDType id = input.timedData.value.id();
                std::optional<B> x = f_(std::tuple<TimePoint,A> {input.timedData.timePoint, std::move(input.timedData.value.key())});
                if (x) {
                    this->publishResponse(*applyDelaySimulator<Key<B>>(0, pureInnerData<Key<B>>(input.environment, {input.timedData.timePoint, {id, std::move(*x)}, true}), delaySimulator_));
                } 
            }
        };
        template <class A, class B, class F>
        class KleisliOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_;
            DelaySimulatorType delaySimulator_;
        public:
            KleisliOnOrderFacilityCore(F &&f, DelaySimulatorType const &delaySimulator) : OnOrderFacilityCore<A,B>(), f_(std::move(f)), delaySimulator_(delaySimulator) {
            }
            virtual ~KleisliOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                typename StateT::IDType id = input.timedData.value.id();
                InnerData<A> x = pureInnerDataLift([](Key<A> &&k) -> A {
                    return k.key();
                }, std::move(input));
                Data<B> y = f_(std::move(x));
                if (y) {
                    y->timedData.finalFlag = true;
                    this->publishResponse(*applyDelaySimulator<Key<B>>(0, pureInnerDataLift<B>(
                        [id=std::move(id)](B &&b) -> Key<B> {
                            return {id, std::move(b)};
                        }, std::move(*y)), delaySimulator_));
                }
            }
        };
        template <class A, class B, class F, class StartF>
        class PureOnOrderFacilityCoreWithStart final : public virtual IExternalComponent, public OnOrderFacilityCore<A,B> {
        private:
            F f_; 
            StartF startF_;
            DelaySimulatorType delaySimulator_;
        public:
            PureOnOrderFacilityCoreWithStart(F &&f, StartF &&startF, DelaySimulatorType const &delaySimulator) : IExternalComponent(), OnOrderFacilityCore<A,B>(), f_(std::move(f)), startF_(std::move(startF)), delaySimulator_(delaySimulator) {
            }
            virtual ~PureOnOrderFacilityCoreWithStart() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                auto resp = *applyDelaySimulator<Key<B>>(0, pureInnerDataLift([this](Key<A> &&k) {
                    return withtime_utils::apply(f_, std::move(k));
                }, std::move(input)), delaySimulator_);
                resp.timedData.finalFlag = true; 
                this->publishResponse(std::move(resp));
            }
            virtual void start(StateT *environment) override final {
                startF_(environment);
            }
        };
        template <class A, class B, class F, class StartF>
        class MaybeOnOrderFacilityCoreWithStart final : public virtual IExternalComponent, public OnOrderFacilityCore<A,B> {
        private:
            F f_;
            StartF startF_;
            DelaySimulatorType delaySimulator_;
        public:
            MaybeOnOrderFacilityCoreWithStart(F &&f, StartF &&startF, DelaySimulatorType const &delaySimulator) : IExternalComponent(), OnOrderFacilityCore<A,B>(), f_(std::move(f)), startF_(std::move(startF)), delaySimulator_(delaySimulator) {
            }
            virtual ~MaybeOnOrderFacilityCoreWithStart() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                typename StateT::IDType id = input.timedData.value.id();
                std::optional<B> x = f_(std::move(input.timedData.value.key()));
                if (x) {
                    this->publishResponse(*applyDelaySimulator<Key<B>>(0, pureInnerData<Key<B>>(input.environment, {input.timedData.timePoint, {id, std::move(*x)}, true}), delaySimulator_));
                } 
            }
            virtual void start(StateT *environment) override final {
                startF_(environment);
            }
        };
        template <class A, class B, class F, class StartF>
        class EnhancedMaybeOnOrderFacilityCoreWithStart final : public virtual IExternalComponent, public OnOrderFacilityCore<A,B> {
        private:
            F f_;
            StartF startF_;
            DelaySimulatorType delaySimulator_;
        public:
            EnhancedMaybeOnOrderFacilityCoreWithStart(F &&f, StartF &&startF, DelaySimulatorType const &delaySimulator) : IExternalComponent(), OnOrderFacilityCore<A,B>(), f_(std::move(f)), startF_(std::move(startF)), delaySimulator_(delaySimulator) {
            }
            virtual ~EnhancedMaybeOnOrderFacilityCoreWithStart() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                typename StateT::IDType id = input.timedData.value.id();
                std::optional<B> x = f_(std::tuple<TimePoint,A> {input.timedData.timePoint, std::move(input.timedData.value.key())});
                if (x) {
                    this->publishResponse(*applyDelaySimulator<Key<B>>(0, pureInnerData<Key<B>>(input.environment, {input.timedData.timePoint, {id, std::move(*x)}, true}), delaySimulator_));
                } 
            }
            virtual void start(StateT *environment) override final {
                startF_(environment);
            }
        };
        template <class A, class B, class F, class StartF>
        class KleisliOnOrderFacilityCoreWithStart final : public virtual IExternalComponent, public OnOrderFacilityCore<A,B> {
        private:
            F f_;
            StartF startF_;
            DelaySimulatorType delaySimulator_;
        public:
            KleisliOnOrderFacilityCoreWithStart(F &&f, StartF &&startF, DelaySimulatorType const &delaySimulator) : IExternalComponent(), OnOrderFacilityCore<A,B>(), f_(std::move(f)), startF_(std::move(startF)), delaySimulator_(delaySimulator) {
            }
            virtual ~KleisliOnOrderFacilityCoreWithStart() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    input.environment, static_cast<AbstractOnOrderFacility<A,B> *>(this)
                );
                typename StateT::IDType id = input.timedData.value.id();
                InnerData<A> x = pureInnerDataLift([](Key<A> &&k) -> A {
                    return k.key();
                }, std::move(input));
                Data<B> y = f_(std::move(x));
                if (y) {
                    y->timedData.finalFlag = true;
                    this->publishResponse(*applyDelaySimulator<Key<B>>(0, pureInnerDataLift<B>(
                        [id=std::move(id)](B &&b) -> Key<B> {
                            return {id, std::move(b)};
                        }, std::move(*y)), delaySimulator_));
                }
            }
            virtual void start(StateT *environment) override final {
                startF_(environment);
            }
        };
    public:
        template <class A, class F>
        static auto liftPureOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A, decltype(f(A()))>>(new PureOnOrderFacilityCore<A,decltype(f(A())),F>(std::move(f), liftParam.delaySimulator));
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
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>(new KleisliOnOrderFacilityCore<A,typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType,F>(std::move(f), liftParam.delaySimulator));
        }
        template <class A, class F, class StartF>
        static auto liftPureOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A, decltype(f(A()))>>(new PureOnOrderFacilityCoreWithStart<A,decltype(f(A())),F,StartF>(std::move(f), std::move(startF), liftParam.delaySimulator));
        }
        template <class A, class F, class StartF>
        static auto liftMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(A()))::value_type,F,StartF>(std::move(f), std::move(startF), liftParam.delaySimulator));
        }
        template <class A, class F, class StartF>
        static auto enhancedMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCoreWithStart<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F,StartF>(std::move(f), std::move(startF), liftParam.delaySimulator));
        }
        template <class A, class F, class StartF>
        static auto kleisliOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>(new KleisliOnOrderFacilityCoreWithStart<A,typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType,F,StartF>(std::move(f), std::move(startF), liftParam.delaySimulator));
        }
        template <class A, class B>
        static auto fromAbstractOnOrderFacility(OnOrderFacilityCore<A,B> *p)
            -> std::shared_ptr<OnOrderFacility<A,B>> {
            return std::make_shared<OnOrderFacility<A,B>>(p);
        }

    private:     
        struct TimePointComparisonStruct {
            int idx;
            TimePoint tp;
            bool operator==(TimePointComparisonStruct const &s) const {
                if (this == &s) {
                    return true;
                }
                return (idx == s.idx && tp == s.tp);
            }
            bool operator<(TimePointComparisonStruct const &s) const {
                if (this == &s) {
                    return false;
                }
                if (tp < s.tp) {
                    return true;
                }
                if (tp > s.tp) {
                    return false;
                }
                return (idx < s.idx);
            }
        };  

        #include <tm_kit/infra/SinglePassIterationApp_ActionCore_Piece.hpp>

    public:

        #include <tm_kit/infra/SinglePassIterationApp_Merge_Piece.hpp>
        #include <tm_kit/infra/SinglePassIterationApp_Pure_Maybe_Kleisli_Piece.hpp>

    public:
        //We don't allow importer to manufacture keyed data "out of the blue"
        template <class T, typename=std::enable_if_t<!is_keyed_data_v<T> || is_monostate_keyed_data_v<T>>>
        class AbstractImporterCore : public virtual IExternalComponent, public virtual BufferedProvider<T> {
        protected:
            virtual typename BufferedProvider<T>::CheckAndProduceResult checkAndProduce() override final {
                auto d = generate((T const *) nullptr);
                if (d) {
                    TimePoint tp = d->timedData.timePoint;
                    return std::tuple<TimePoint, std::function<Data<T>()>> {tp, [d=std::move(d)]() -> Data<T> {return {std::move(*d)};}};
                } else {
                    return std::nullopt;
                }
            }
            static constexpr AbstractImporterCore *nullptrToInheritedImporter() {return nullptr;}
        public:           
            virtual Data<T> generate(T const *notUsed=nullptr) = 0;
            AbstractImporterCore() : BufferedProvider<T>() {}
        };

        template <class T>
        class ConcreteImporterCore : public AbstractImporterCore<T> {
        private:
            std::deque<InnerData<T>> q_;
        public:
            ConcreteImporterCore() : q_() {}
            virtual Data<T> generate(T const * =nullptr) override final {
                if (q_.empty()) {
                    return std::nullopt;
                }
                Data<T> ret = std::move(q_.front());
                q_.pop_front();
                return ret;
            }
            void publish(InnerData<T> &&data) {
                q_.push_back(std::move(data));
            }
            void publish(StateT *env, T &&data, bool finalFlag=false) {
                q_.push_back(InnerData<T> {
                    env, {env->resolveTime(), std::move(data), finalFlag}
                });
            }
        };

        template <class T>
        using AbstractImporter = AbstractImporterCore<T>;

        template <class T>
        using Importer = OneWayHolder<AbstractImporterCore<T>,T>;

        template <class T>
        static std::shared_ptr<Importer<T>> importer(AbstractImporterCore<T> *p) {
            return std::make_shared<Importer<T>>(p);
        }

    private:
        template <class T, class F>
        class SimpleImporter final : public AbstractImporterCore<T> {
        private:
            F f_;
            DelaySimulatorType delaySimulator_;
            StateT *environment_;
        public:
            SimpleImporter(F &&f, DelaySimulatorType const &delaySimulator) : AbstractImporterCore<T>(), f_(std::move(f)), delaySimulator_(delaySimulator), environment_(nullptr) {}
            virtual void start(StateT *environment) override final {
                environment_ = environment;
            }
            virtual Data<T> generate(T const * =nullptr) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    environment_, static_cast<AbstractImporter<T> *>(this)
                );
                auto x = f_(environment_);
                if (x) {
                    return *applyDelaySimulator<T>(0, std::move(*x), delaySimulator_);
                } else {
                    return std::nullopt;
                }
            }
        };

    public:
        template <class T>
        static std::shared_ptr<Importer<T>> vacuousImporter() {
            class LocalI final : public AbstractImporterCore<T> {
            public:
                virtual void start(StateT *) override final {
                }
                virtual Data<T> generate(T const * =nullptr) override final {
                    return std::nullopt;
                }
            };
            return std::make_shared<Importer<T>>(new LocalI());
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> simpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Importer<T>>(new SimpleImporter<T,F>(std::move(f), liftParam.delaySimulator));
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> uniformSimpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return simpleImporter<T>([f=std::move(f)](StateT *env) mutable -> Data<T> {
                return std::get<1>(f(env));
            }, liftParam);
        }
        template <class T>
        static std::shared_ptr<Importer<T>> constFirstPushImporter(T &&t = T()) {
            return simpleImporter<T>([t=std::move(t)](StateT *env) -> Data<T> {
                static bool published = false;
                if (!published) {
                    published = true;
                    return InnerData<T> {
                        env
                        , {
                            env->resolveTime()
                            , std::move(t)
                            , true
                        }
                    };
                } else {
                    return std::nullopt;
                }
            });
        }
        template <class T>
        static std::shared_ptr<Importer<T>> constFirstPushImporterWithTime(TimePoint const &tp, T &&t = T()) {
            return simpleImporter<T>([tp,t=std::move(t)](StateT *env) -> Data<T> {
                static bool published = false;
                if (!published) {
                    published = true;
                    return InnerData<T> {
                        env
                        , {
                            tp
                            , std::move(t)
                            , true
                        }
                    };
                } else {
                    return std::nullopt;
                }
            });
        }
        template <class T>
        static std::shared_ptr<Importer<Key<T>>> constFirstPushKeyImporter(T &&t = T()) {
            return constFirstPushImporter<Key<T>>(
                infra::withtime_utils::keyify<T,StateT>(std::move(t))
            );
        }
        template <class T>
        static std::shared_ptr<Importer<Key<T>>> constFirstPushKeyImporterWithTime(TimePoint const &tp, T &&t = T()) {
            return constFirstPushImporterWithTime<Key<T>>(
                tp, infra::withtime_utils::keyify<T,StateT>(std::move(t))
            );
        }
        template <class T>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void()>> constTriggerImporter(T &&t = T()) {
            class LocalI final : public AbstractImporterCore<T> {
            private:
                T t_;
                StateT *env_;
                Data<T> toPublish_;
            public:           
                virtual Data<T> generate(T const * =nullptr) {
                    Data<T> ret {std::move(toPublish_)};
                    toPublish_ = std::nullopt;
                    return ret;
                }
                LocalI(T &&t) : AbstractImporterCore<T>(), t_(std::move(t)), env_(nullptr), toPublish_(std::nullopt) {}
                virtual void start(StateT *env) override final {
                    env_ = env;
                }
                void trigger() {
                    if (!toPublish_) {
                        toPublish_ = InnerData<T> {
                            env_
                            , {
                                env_->resolveTime()
                                , t_
                                , false
                            }
                        };
                    } else {
                        toPublish_->timedData.timePoint = env_->resolveTime();
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
            class LocalI final : public AbstractImporterCore<T> {
            private:
                std::deque<T> q_;
                StateT *env_;
            public:           
                virtual Data<T> generate(T const * =nullptr) {
                    if (q_.empty()) {
                        return std::nullopt;
                    }
                    Data<T> ret = InnerData<T> {
                        env_
                        , {
                            env_->resolveTime()
                            , std::move(q_.front())
                            , false
                        }
                    };
                    q_.pop_front();
                    return ret;
                }
                LocalI() : AbstractImporterCore<T>(), q_(), env_(nullptr) {}
                virtual void start(StateT *env) override final {
                    env_ = env;
                }
                void trigger(T &&t) {
                    q_.push_back(std::move(t));
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
            class LocalI final : public AbstractImporterCore<T> {
            private:
                std::deque<WithTime<T,TimePoint>> q_;
                StateT *env_;
            public:           
                virtual Data<T> generate(T const * =nullptr) {
                    if (q_.empty()) {
                        return std::nullopt;
                    }
                    Data<T> ret = InnerData<T> {
                        env_
                        , std::move(q_.front())
                    };
                    q_.pop_front();
                    return ret;
                }
                LocalI() : AbstractImporterCore<T>(), q_(), env_(nullptr) {}
                virtual void start(StateT *env) override final {
                    env_ = env;
                }
                void trigger(WithTime<T,TimePoint> &&t) {
                    q_.push_back(std::move(t));
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
    private:
        template <class T>
        class DefaultBunchSplitLogic {
        public:
            bool operator()(std::vector<T> const &/*buffer*/, TimePoint const &lastTime, InnerData<T> const &newData) const {
                return newData.timedData.timePoint > lastTime;
            }
        };
        template <class T, class BunchSplitLogic>
        class BunchedImporter : public AbstractImporterCore<std::vector<T>> {
        private:
            std::shared_ptr<Importer<T>> underlyingImporter_;
            BunchSplitLogic bunchSplitLogic_;
            StateT *env_;
            std::vector<T> buffer_;
            bool stopped_;
            std::optional<TimePoint> lastTime_;
            virtual Data<std::vector<T>> generate(std::vector<T> const *notUsed) override final {
                if (stopped_) {
                    if (!lastTime_ || buffer_.empty()) {
                        return std::nullopt;
                    } else {
                        Data<std::vector<T>> ret = InnerData<std::vector<T>> {
                            env_
                            , {
                                *lastTime_
                                , std::move(buffer_)
                                , true
                            }
                        };
                        buffer_.clear();
                        lastTime_ = std::nullopt;
                        return std::move(ret);
                    }
                }
                auto x = underlyingImporter_->core_->generate((T const *) nullptr);
                stopped_ = (x && x->timedData.finalFlag);
                if (stopped_) {
                    if (!x) {
                        if (!lastTime_ || buffer_.empty()) {
                            return std::nullopt;
                        } else {
                            Data<std::vector<T>> ret = InnerData<std::vector<T>> {
                                env_
                                , {
                                    *lastTime_
                                    , std::move(buffer_)
                                    , true
                                }
                            };
                            buffer_.clear();
                            lastTime_ = std::nullopt;
                            return std::move(ret);
                        }
                    } else {
                        if (!lastTime_ || bunchSplitLogic_(buffer_, *lastTime_, *x)) {
                            Data<std::vector<T>> ret = std::nullopt;
                            if (lastTime_ && !buffer_.empty()) {
                                ret = InnerData<std::vector<T>> {
                                    env_
                                    , {
                                        *lastTime_
                                        , std::move(buffer_)
                                        , false
                                    }
                                };
                                buffer_.clear();
                            }
                            buffer_.push_back(std::move(x->timedData.value));
                            lastTime_ = x->timedData.timePoint;
                            return std::move(ret);
                        } else {
                            buffer_.push_back(std::move(x->timedData.value));
                            Data<std::vector<T>> ret = InnerData<std::vector<T>> {
                                env_
                                , {
                                    *lastTime_
                                    , std::move(buffer_)
                                    , true
                                }
                            };
                            buffer_.clear();
                            lastTime_ = std::nullopt;
                            return std::move(ret);
                        }
                    }
                } else {
                    if (!x) {
                        return std::nullopt;
                    }
                    if (!lastTime_ || bunchSplitLogic_(buffer_, *lastTime_, *x)) {
                        Data<std::vector<T>> ret = std::nullopt;
                        if (lastTime_ && !buffer_.empty()) {
                            ret = InnerData<std::vector<T>> {
                                env_
                                , {
                                    *lastTime_
                                    , std::move(buffer_)
                                    , false
                                }
                            };
                            buffer_.clear();
                        }
                        buffer_.push_back(std::move(x->timedData.value));
                        lastTime_ = x->timedData.timePoint;
                        return std::move(ret);
                    } else {
                        buffer_.push_back(std::move(x->timedData.value));
                        return std::nullopt;
                    }
                }
            }
        public:
            BunchedImporter(std::shared_ptr<Importer<T>> const &underlyingImporter, BunchSplitLogic &&bunchSplitLogic)
                : underlyingImporter_(underlyingImporter)
                , bunchSplitLogic_(std::move(bunchSplitLogic))
                , env_(nullptr)
                , buffer_()
                , stopped_(false)
                , lastTime_(std::nullopt)
            {
            }
            BunchedImporter(BunchedImporter const &) = delete;
            BunchedImporter &operator=(BunchedImporter const &) = delete;
            virtual void start(StateT *env) override final {
                env_ = env;
                underlyingImporter_->core_->start(env);
            }
        };
    public:
        template <class T, class BunchSplitLogic=DefaultBunchSplitLogic<T>>
        static std::shared_ptr<Importer<std::vector<T>>> bunchedImporter(std::shared_ptr<Importer<T>> const &underlyingImporter, BunchSplitLogic &&bunchSplitLogic = BunchSplitLogic {}) {
            return std::make_shared<Importer<std::vector<T>>>(std::make_unique<BunchedImporter<T, BunchSplitLogic>>(underlyingImporter, std::move(bunchSplitLogic)));
        }
    public:
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        class AbstractExporterCore : public virtual IExternalComponent, public virtual Consumer<T>, public virtual Provider<SpecialOutputDataTypeForExporters> {
        private:
            Certificate<T> sourceCert_;
            bool hasT_;
            TimePoint tTime_;
            VersionChecker<T> versionChecker_;
        protected:
            static constexpr AbstractExporterCore *nullptrToInheritedExporter() {return nullptr;}
        public:
            virtual void handle(InnerData<T> &&) = 0;
            virtual Certificate<SpecialOutputDataTypeForExporters> poll() override final {
                sourceCert_ = this->source()->poll();
                if (sourceCert_.check()) {
                    return {fetchTimePointUnsafe(sourceCert_), this};
                } else {
                    return {std::nullopt, this};
                }
            } 
            virtual Data<SpecialOutputDataTypeForExporters> next(Certificate<SpecialOutputDataTypeForExporters> &&cert) override final {
                cert.consume(this);
                auto input = this->source()->next(std::move(sourceCert_));
                if (!input) {
                    return std::nullopt;
                }
                if (!versionChecker_.checkVersion(input->timedData.value)) {
                    return std::nullopt;
                }
                auto env = input->environment;
                auto tp = input->timedData.timePoint;
                auto flag = input->timedData.finalFlag;
                if (!StateT::CheckTime || !hasT_ || tp >= tTime_) {
                    hasT_ = true;
                    tTime_ = tp;
                } else {
                    return std::nullopt;
                }
                TM_INFRA_EXPORTER_TRACER(env);
                handle(std::move(*input));
                return { pureInnerData<SpecialOutputDataTypeForExporters>(
                    env,
                    {
                        tp,
                        SpecialOutputDataTypeForExporters(),
                        flag
                    }
                ) };
            }
            AbstractExporterCore() : Consumer<T>(), sourceCert_(), hasT_(false), tTime_() {}
        };

        template <class T>
        using AbstractExporter = AbstractExporterCore<T>;

        template <class T>
        using Exporter = OneWayHolder<AbstractExporterCore<T>,T>;

        template <class T>
        static std::shared_ptr<Exporter<T>> exporter(AbstractExporterCore<T> *p) {
            return std::make_shared<Exporter<T>>(p);
        }

    private:
        template <class T, class F>
        class SimpleExporter final : public AbstractExporterCore<T> {
        private:
            F f_;
        public:
            SimpleExporter(F &&f) : AbstractExporterCore<T>(), f_(std::move(f)) {}
            virtual void start(StateT *) override final {}
            virtual void handle(InnerData<T> &&data) override final {
                GraphStructureBasedResourceHolderComponent_CurrentNodeSetter<StateT> ns(
                    data.environment, static_cast<AbstractExporter<T> *>(this)
                );
                single_pass_iteration_app_utils::TimePreserver<StateT> _timePreserver(data.environment, data.timedData.timePoint);
                f_(std::move(data));
            }
        };

    public:
        //We ignore the liftParam for exporters because the time point is actually being destroyed
        //by the exporting action and we don't need to apply any delay
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> simpleExporter(F &&f, LiftParameters<TimePoint> const & = LiftParameters<TimePoint>()) {
            return std::make_shared<Exporter<T>>(new SimpleExporter<T,F>(std::move(f)));
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> pureExporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            auto wrapper = [f=std::move(f)](InnerData<T> &&d) mutable {
                f(std::move(d.timedData.value));
            };
            return simpleExporter<T>(std::move(wrapper), liftParam);
        }
        template <class T>
        static std::shared_ptr<Exporter<T>> trivialExporter() {
            return simpleExporter<T>([](InnerData<T> &&) {}, LiftParameters<TimePoint> {});
        }        

    public:
        template <class T1, class T2>
        static std::shared_ptr<Importer<T2>> composeImporter(Importer<T1> &&orig, Action<T1,T2> &&post) {
            class LocalI final : public AbstractImporterCore<T2> {
            private:
                Importer<T1> orig_;
                Action<T1,T2> post_;
            public:
                LocalI(Importer<T1> &&orig, Action<T1,T2> &&post) 
                    : orig_(std::move(orig)), post_(std::move(post))
                {
                    post_.core_->connectToSource(orig_.core_.get());
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(orig_.core_.get(), static_cast<AbstractImporterCore<T2> *>(this));
                        GraphStructureBasedResourceHolderComponent::registerParentNode(post_.core_.get(), static_cast<AbstractImporterCore<T2> *>(this));
                    }
                }
                virtual void start(StateT *environment) override final {
                    orig_.core_->start(environment);
                }
                virtual Data<T2> generate(T2 const * =nullptr) override final {
                    Certificate<T2> cert = post_.core_->poll();
                    if (cert.check()) {
                        return post_.core_->next(std::move(cert));
                    } else {
                        return std::nullopt;
                    }
                }
            };
            return std::make_shared<Importer<T2>>(new LocalI(std::move(orig), std::move(post)));
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> composeExporter(Action<T1,T2> &&pre, Exporter<T2> &&orig) {
            class LocalE final : public AbstractExporterCore<T1> {
            private:
                Action<T1,T2> pre_;
                Exporter<T2> orig_;
                FillableProvider<T1> fillable_;
            public:
                LocalE(Action<T1,T2> &&pre, Exporter<T2> &&orig) 
                    : pre_(std::move(pre)), orig_(std::move(orig)), fillable_()
                {
                    pre_.core_->connectToSource(&fillable_);
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(pre_.core_.get(), static_cast<AbstractExporterCore<T1> *>(this));
                        GraphStructureBasedResourceHolderComponent::registerParentNode(orig_.core_.get(), static_cast<AbstractExporterCore<T1> *>(this));
                    }
                }
                virtual void start(StateT *environment) override final {
                    orig_.core_->start(environment);
                }
                virtual void handle(InnerData<T1> &&data) override final {
                    fillable_.fill(std::move(data));
                    auto cert = pre_.core_->poll();
                    if (cert.check()) {
                        auto t2 = pre_.core_->next(std::move(cert));
                        if (t2) {
                            orig_.core_->handle(std::move(*t2));
                        }
                    }
                }
            };
            return std::make_shared<Exporter<T1>>(new LocalE(std::move(pre), std::move(orig)));
        }
        template <class T1, class T2, typename = std::enable_if_t<!withtime_utils::IsVariant<T2>::Value>>
        static std::shared_ptr<Action<T1,T2>> delayedImporter(Importer<T2> &&importer) {
            class LocalA final : public AbstractActionCore<T1,T2>, public Consumer<T1> {
            private:
                Importer<T2> importer_;
                bool started_;
            public:
                LocalA(Importer<T2> &&importer) 
                    : importer_(std::move(importer)), started_(false)
                {
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(importer_.core_.get(), static_cast<AbstractActionCore<T1,T2> *>(this));
                    }
                }
                virtual bool isOneTimeOnly() const override final {
                    return true;
                }
                virtual Certificate<T2> poll() override final {
                    auto cert1 = this->source()->poll();
                    if (cert1.check()) {
                        auto data = this->source()->next(std::move(cert1));
                        if (data) {
                            if (!started_) {
                                started_ = true;
                                importer_.core_->start(data->environment);
                            }
                        }
                    }
                    if (!started_) {
                        return Certificate<T2>(std::nullopt, this);
                    } else {
                        auto cert2 = importer_.core_->poll();
                        return cert2.push(this);
                    }
                }
                virtual Data<T2> next(Certificate<T2> &&cert) override final {
                    cert.consume(this);
                    auto *p = cert.topSigner();
                    if (p) {
                        return p->next(std::move(cert));
                    } else {
                        return std::nullopt;
                    }
                }
            };
            return std::make_shared<Action<T1,T2>>(new LocalA(std::move(importer)));
        }
        template <class T1, class T2, typename = std::enable_if_t<!withtime_utils::IsVariant<T2>::Value>>
        static std::shared_ptr<Action<T1,T2>> lazyImporter(std::function<std::shared_ptr<Importer<T2>>(T1 &&)> const &importerFactory) {
            class LocalA final : public AbstractActionCore<T1,T2>, public Consumer<T1> {
            private:
                std::function<std::shared_ptr<Importer<T2>>(T1 &&)> importerFactory_;
                std::shared_ptr<Importer<T2>> importer_;
                bool started_;
            public:
                LocalA(std::function<std::shared_ptr<Importer<T2>>(T1 &&)> const &importerFactory) 
                    : importerFactory_(importerFactory), importer_(), started_(false)
                {
                }
                virtual bool isOneTimeOnly() const override final {
                    return true;
                }
                virtual Certificate<T2> poll() override final {
                    auto cert1 = this->source()->poll();
                    if (cert1.check()) {
                        auto data = this->source()->next(std::move(cert1));
                        if (data) {
                            if (!started_) {
                                started_ = true;
                                importer_ = importerFactory_(std::move(data->timedData.value));
                                importer_->core_->start(data->environment);
                            }
                        }
                    }
                    if (!started_) {
                        return Certificate<T2>(std::nullopt, this);
                    } else {
                        auto cert2 = importer_->core_->poll();
                        return cert2.push(this);
                    }
                }
                virtual Data<T2> next(Certificate<T2> &&cert) override final {
                    cert.consume(this);
                    auto *p = cert.topSigner();
                    if (p) {
                        return p->next(std::move(cert));
                    } else {
                        return std::nullopt;
                    }
                }
            };
            return std::make_shared<Action<T1,T2>>(new LocalA(importerFactory));
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> curtailedAction(Action<T1,T2> &&action) {
            class LocalE final : public AbstractExporterCore<T1> {
            private:
                Action<T1,T2> action_;
                FillableProvider<T1> fillable_;
            public:
                LocalE(Action<T1,T2> &&action) 
                    : action_(std::move(action)), fillable_()
                {
                    action_.core_->connectToSource(&fillable_);
                    if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                        GraphStructureBasedResourceHolderComponent::registerParentNode(action_.core_.get(), static_cast<AbstractExporterCore<T1> *>(this));
                    }
                }
                virtual void start(StateT *) override final {
                }
                virtual void handle(InnerData<T1> &&data) override final {
                    fillable_.fill(std::move(data));
                    auto cert = action_.core_->poll();
                    if (cert.check()) {
                        action_.core_->next(std::move(cert));
                    }
                }
            };
            return std::make_shared<Exporter<T1>>(new LocalE(std::move(action)));
        }

    private:
        template <class I0, class O0, class I1, class O1>
        class WrappedOnOrderFacility final : public IExternalComponent, public OnOrderFacilityCore<I0,O0> {
        private:
            OnOrderFacility<I1,O1> toWrap_;
            Action<Key<I0>,Key<I1>> inputT_;
            Action<Key<O1>,Key<O0>> outputT_;
            class Conduit2 final : public AbstractExporterCore<Key<I1>> {
            private:
                OnOrderFacilityCore<I1,O1> *toWrap_;
                AbstractConsumer<KeyedData<I1,O1>> *consumer_;
            public:
                Conduit2(OnOrderFacilityCore<I1,O1> *toWrap, AbstractConsumer<KeyedData<I1,O1>> *consumer)
                    : toWrap_(toWrap), consumer_(consumer) {}
                void handle(InnerData<Key<I1>> &&i1) override final {
                    toWrap_->placeOrder(std::move(i1), consumer_);
                }
                void start(StateT *) override final {}
            }; 
            class Conduit3 final : public ActionCore<KeyedData<I1,O1>, Key<O1>> {
            protected:
                virtual Data<Key<O1>> handle(InnerData<KeyedData<I1,O1>> &&o1WithKey) override final {
                    return { pureInnerDataLift([](KeyedData<I1,O1> &&d) -> Key<O1> {
                        return {d.key.id(), std::move(d.data)};
                    }, std::move(o1WithKey)) };
                }
            public:
                virtual bool isOneTimeOnly() const override final {
                    return false;
                }
            };
            class Conduit4 final : public AbstractExporterCore<Key<O0>> {
            private:
                WrappedOnOrderFacility *parent_;
            public:
                Conduit4(WrappedOnOrderFacility *parent)
                    : parent_(parent) {}
                void handle(InnerData<Key<O0>> &&o1) override final {
                    parent_->publishResponse(std::move(o1));
                }
                void start(StateT *) override final {}
            };
            Conduit4 c4_;
            Conduit3 c3_;   
            Conduit2 c2_;
            FillableProvider<Key<I0>> c1_;
        public:
            WrappedOnOrderFacility(
                OnOrderFacility<I1,O1> &&toWrap,
                Action<Key<I0>,Key<I1>> &&inputT,
                Action<Key<O1>,Key<O0>> &&outputT
            ) : toWrap_(std::move(toWrap)), inputT_(std::move(inputT)), outputT_(std::move(outputT)),
                c4_(this), c3_(), c2_(toWrap_.core_.get(), &c3_), c1_() {
                inputT_.core_->connectToSource(&c1_);
                c2_.connectToSource(inputT_.core_.get());
                outputT_.core_->connectToSource(&c3_);
                c4_.connectToSource(outputT_.core_.get());
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
                c1_.fill(std::move(i0));
            }
        private:
            virtual void fetchProvidersForAppRunner(std::list<Provider<SpecialOutputDataTypeForExporters> *> &output) override final {
                output.push_back(&c4_);
                output.push_back(&c2_);
            } 
        };

    public:
        template <class I0, class O0, class I1, class O1>
        static std::shared_ptr<OnOrderFacility<I0,O0>> wrappedOnOrderFacility(OnOrderFacility<I1,O1> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) {
            return std::make_shared<OnOrderFacility<I0,O0>>(
                new WrappedOnOrderFacility<I0,O0,I1,O1>(std::move(toWrap),std::move(inputT),std::move(outputT))
            );
        }

    private:
        template <class I0, class O0, class I1, class O1>
        class SimpleWrappedOnOrderFacility final : public IExternalComponent, public OnOrderFacilityCore<I0,O0> {
        private:
            OnOrderFacility<I1,O1> toWrap_;
            
            class Conduit2 final : public AbstractExporterCore<Key<I0>> {
            private:
                OnOrderFacilityCore<I1,O1> *toWrap_;
                AbstractConsumer<KeyedData<I1,O1>> *consumer_;
                std::function<I1(I0 &&)> inputT_;
            public:
                Conduit2(OnOrderFacilityCore<I1,O1> *toWrap, AbstractConsumer<KeyedData<I1,O1>> *consumer, std::function<I1(I0 &&)> const &inputT)
                    : toWrap_(toWrap), consumer_(consumer), inputT_(inputT) {}
                void handle(InnerData<Key<I0>> &&i0) override final {
                    if constexpr (std::is_same_v<I0,I1>) {
                        if (inputT_) {
                            InnerData<Key<I1>> i1 = pureInnerDataLift([this](Key<I0> &&k) -> Key<I1> {
                                return {k.id(), inputT_(std::move(k.key()))};
                            }, std::move(i0));
                            toWrap_->placeOrder(std::move(i1), consumer_);
                        } else {
                            toWrap_->placeOrder(std::move(i0), consumer_);
                        }
                    } else {
                        if (inputT_) {
                            InnerData<Key<I1>> i1 = pureInnerDataLift([this](Key<I0> &&k) -> Key<I1> {
                                return {k.id(), inputT_(std::move(k.key()))};
                            }, std::move(i0));
                            toWrap_->placeOrder(std::move(i1), consumer_);
                        }
                    }
                }
                void start(StateT *) override final {}
            }; 
            class Conduit3 final : public AbstractExporterCore<KeyedData<I1,O1>> {
            private:
                SimpleWrappedOnOrderFacility *parent_;
                std::function<O0(I1 const &, O1 &&)> outputT_;
            public:
                Conduit3(SimpleWrappedOnOrderFacility *parent, std::function<O0(I1 const &, O1 &&)> const &outputT)
                    : parent_(parent), outputT_(outputT)
                {}
                virtual void handle(InnerData<KeyedData<I1,O1>> &&o1) override final {
                    if constexpr (std::is_same_v<O0,O1>) {
                        if (outputT_) {
                            parent_->publishResponse(pureInnerDataLift([this](KeyedData<I1,O1> &&a) -> Key<O0> {
                                return {a.key.id(), outputT_(a.key.key(), std::move(a.data))};
                            }, std::move(o1)));
                        } else {
                            parent_->publishResponse(pureInnerDataLift([](KeyedData<I1,O1> &&a) -> Key<O0> {
                                return {a.key.id(), std::move(a.data)};
                            }, std::move(o1)));
                        }
                    } else {
                        if (outputT_) {
                            parent_->publishResponse(pureInnerDataLift([this](KeyedData<I1,O1> &&a) -> Key<O0> {
                                return {a.key.id(), outputT_(a.key.key(), std::move(a.data))};
                            }, std::move(o1)));
                        }
                    }
                }
                void start(StateT *) override final {}
            };
            Conduit3 c3_;   
            Conduit2 c2_;
            FillableProvider<Key<I0>> c1_;
        public:
            SimpleWrappedOnOrderFacility(
                OnOrderFacility<I1,O1> &&toWrap,
                std::function<I1(I0 &&)> const &inputT,
                std::function<O0(I1 const &, O1 &&)> const &outputT
            ) : toWrap_(std::move(toWrap)), 
                c3_(this, outputT), c2_(toWrap_.core_.get(), &c3_, inputT), c1_() {
                c2_.connectToSource(&c1_);
                if constexpr (std::is_convertible_v<StateT *, GraphStructureBasedResourceHolderComponent *>) {
                    GraphStructureBasedResourceHolderComponent::registerParentNode(toWrap_.core_.get(), static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(&c1_, static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(&c2_, static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
                    GraphStructureBasedResourceHolderComponent::registerParentNode(&c3_, static_cast<AbstractOnOrderFacility<I0,O0> *>(this));
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
                c1_.fill(std::move(i0));
            }
        private:
            virtual void fetchProvidersForAppRunner(std::list<Provider<SpecialOutputDataTypeForExporters> *> &output) override final {
                output.push_back(&c3_);
                output.push_back(&c2_);
            } 
        };

    public:
        template <class I0, class O0, class Fac>
        static std::shared_ptr<OnOrderFacility<I0,O0>> simpleWrappedOnOrderFacility(Fac &&toWrap, std::function<typename Fac::InputType(I0 &&)> const &inputT, std::function<O0(typename Fac::InputType const &, typename Fac::OutputType &&)> const&outputT) {
            return std::make_shared<OnOrderFacility<I0,O0>>(
                new SimpleWrappedOnOrderFacility<I0,O0,typename Fac::InputType,typename Fac::OutputType>(std::move(toWrap),inputT,outputT)
            );
        }

    public:
        //For the reason why LocalOnOrderFacility is essentially a tuple
        //and not directly based on AbstractIntegratedLocalOnOrderFacility,
        //please refer to the comments in RealTimeApp.hpp
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using LocalOnOrderFacility = ThreeWayHolder<
            OnOrderFacilityCore<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractExporterCore<DataInputType>,DataInputType
        >;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> localOnOrderFacility(
            OnOrderFacilityCore<QueryKeyType, QueryResultType> *t
            , AbstractExporterCore<DataInputType> *e) {
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
                , typename Exp::DataType>>(
                p_t,p_e
            );
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
                , typename Fac::DataType>>(
                p, e
            );
        }

        template <class I0, class O0, class Fac>
        static std::shared_ptr<LocalOnOrderFacility<
            I0, O0
            , typename Fac::DataType>> simpleWrappedLocalOnOrderFacility(Fac &&toWrap, std::function<typename Fac::InputType(I0 &&)> const &inputT, std::function<O0(typename Fac::InputType const &, typename Fac::OutputType &&)> const &outputT) {
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
                , typename Fac::DataType>>(
                p, e
            );
        }

    public:
        //OnOrderFacilityWithExternalEffects is the dual of OnOrderFacilityWithExternalEffects
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        using OnOrderFacilityWithExternalEffects = ThreeWayHolder<
            OnOrderFacilityCore<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractImporterCore<DataInputType>,DataInputType
        >;
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            OnOrderFacilityCore<QueryKeyType, QueryResultType> *t
            , AbstractImporterCore<DataInputType> *e) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>(t,e);
        }
                
        template <class QueryKeyType, class QueryResultType, class DataInputType, bool HasConcretePublishForImporter=false>
        class AbstractIntegratedOnOrderFacilityWithExternalEffects 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public std::conditional_t<HasConcretePublishForImporter, ConcreteImporterCore<DataInputType>, AbstractImporter<DataInputType>> 
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ImporterParent = std::conditional_t<HasConcretePublishForImporter, ConcreteImporterCore<DataInputType>, AbstractImporter<DataInputType>>;
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType, bool HasConcretePublishForImporter=false>
        using AbstractIntegratedOnOrderFacilityWithExternalEffectsWithPublish = AbstractIntegratedOnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType, true>;
        template <class QueryKeyType, class QueryResultType, class DataInputType, bool HasConcretePublishForImporter=false>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            AbstractIntegratedOnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType, HasConcretePublishForImporter> *p) {
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
                , typename Imp::DataType>>(
                p_t,p_i
            );
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
                , typename Fac::DataType>>(
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
                , typename Fac::DataType>>(
                p, i
            );
        }

    public:
        //for definition of VIEOnOrderFacility and its types
        //,see the comments on the corresponding part of RealTimeApp.hpp
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        using VIEOnOrderFacility = FourWayHolder<
            OnOrderFacilityCore<QueryKeyType,QueryResultType>,QueryKeyType,QueryResultType
            , AbstractExporterCore<ExtraInputType>, ExtraInputType
            , AbstractImporterCore<ExtraOutputType>, ExtraOutputType
        >;
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            OnOrderFacilityCore<QueryKeyType, QueryResultType> *t
            , AbstractExporterCore<ExtraInputType> *i
            , AbstractImporterCore<ExtraOutputType> *o) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>(t,i,o);
        }
                
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType, bool HasConcretePublishForImporter=false>
        class AbstractIntegratedVIEOnOrderFacility 
            : public AbstractOnOrderFacility<QueryKeyType,QueryResultType>, public AbstractExporter<ExtraInputType>, public std::conditional_t<HasConcretePublishForImporter, ConcreteImporterCore<ExtraOutputType>, AbstractImporter<ExtraOutputType>>
        {
        public:
            using FacilityParent = AbstractOnOrderFacility<QueryKeyType,QueryResultType>;
            using ExporterParent = AbstractExporter<ExtraInputType>;
            using ImporterParent = std::conditional_t<HasConcretePublishForImporter, ConcreteImporterCore<ExtraOutputType>, AbstractImporter<ExtraOutputType>>;
        };
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType, bool HasConcretePublishForImporter=false>
        using AbstractIntegratedVIEOnOrderFacilityWithPublish = AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType, true>;
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType, bool HasConcretePublishForImporter=false>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType, HasConcretePublishForImporter> *p) {
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
                , typename Imp::DataType>>(
                p_t,p_i,p_o
            );
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
                , typename Fac::ExtraOutputType>>(
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
                , typename Fac::ExtraOutputType>>(
                p, i, o
            );
        }

    public:
        template <class T>
        class Source {
        private:
            friend class SinglePassIterationApp;
            Provider<T> *provider;
            Source(Provider<T> *p) : provider(p) {}
        public:
            Source clone() const {
                return Source {provider};
            }
        };
        template <class T>
        class Sink {
        private:
            friend class SinglePassIterationApp;
            AbstractConsumer<T> *consumer;
            Sink(AbstractConsumer<T> *p) : consumer(p) {}
        };
    private:
        std::list<IExternalComponent *> externalComponents_;
        std::unordered_set<IExternalComponent *> externalComponentsSet_;
        InputMultiplexer<SpecialOutputDataTypeForExporters> joinedSource_, joinedSpecialSource_;
        std::unordered_map<std::size_t, std::unordered_map<ProviderBase *, OutputMultiplexerBase *>> outputMultiplexerMap_;
        std::unordered_map<std::size_t, std::unordered_map<ProviderBase *, std::unordered_set<ConsumerBase *>>> connectionMap_;

        SinglePassIterationApp() : externalComponents_(), externalComponentsSet_(), joinedSource_(), joinedSpecialSource_(), outputMultiplexerMap_(), connectionMap_() {}
        SinglePassIterationApp(SinglePassIterationApp &&other) : 
            externalComponents_(std::move(other.externalComponents_))
            , externalComponentsSet_(std::move(other.externalComponentsSet_))
            , joinedSource_(std::move(other.joinedSource_))
            , joinedSpecialSource_(std::move(other.joinedSpecialSource_))
            , outputMultiplexerMap_(std::move(other.outputMultiplexerMap_))
            , connectionMap_(std::move(other.connectionMap_)) 
        {}
        SinglePassIterationApp &operator=(SinglePassIterationApp &&other) {
            if (this != &other) {
                externalComponents_ = std::move(other.externalComponents_);
                externalComponentsSet_ = std::move(other.externalComponentsSet_);
                joinedSource_ = std::move(other.joinedSource_);
                joinedSpecialSource_ = std::move(other.joinedSpecialSource_);
                outputMultiplexerMap_ = std::move(other.outputMultiplexerMap_);
                connectionMap_ = std::move(other.connectionMap_);
            }
            return *this;
        }
        ~SinglePassIterationApp() {}

        void registerExternalComponent(IExternalComponent *c) {
            if (externalComponentsSet_.find(c) == externalComponentsSet_.end()) {
                externalComponents_.push_back(c);
                externalComponentsSet_.insert(c);
            }
        }
        template <class A>
        Provider<A> *getMultiplexerOutput(Provider<A> *p) {
            auto &m = outputMultiplexerMap_[typeid(A).hash_code()];
            auto iter = m.find(p);
            if (iter == m.end()) {
                iter = m.insert(
                    {p, new OutputMultiplexer<A>(p)}
                ).first;
            }
            return dynamic_cast<OutputMultiplexer<A> *>(iter->second)->addOutput();
        }

        template <class A>
        void innerConnect(AbstractConsumer<A> *consumer, Provider<A> *provider) {
            auto &m = connectionMap_[typeid(A).hash_code()];
            auto iter = m.find(dynamic_cast<ProviderBase *>(provider));
            if (iter != m.end() && iter->second.find(dynamic_cast<ConsumerBase *>(consumer)) != iter->second.end()) {
                return;
            }
            consumer->connectToSource(getMultiplexerOutput(provider));
            m[dynamic_cast<ProviderBase *>(provider)].insert(dynamic_cast<ConsumerBase *>(consumer));
        }
        template <class A>
        class AnyProviderAdapter : public Provider<std::any> {
        private:
            Provider<A> *provider_;
        public:
            AnyProviderAdapter(Provider<A> *provider) : provider_(provider) {}
            virtual ~AnyProviderAdapter() = default;
            virtual Certificate<std::any> poll() override final {
                auto cert = provider_->poll();
                if (cert.check()) {
                    return Certificate<std::any>(cert.timePoint(), this, new Certificate<A>(cert));
                } else {
                    return Certificate<std::any>(std::nullopt, this, (Certificate<A> *) nullptr);
                }
            }
            virtual Data<std::any> next(Certificate<std::any> &&cert) override final {
                if (cert.check()) {
                    auto *c = (Certificate<A> *) cert.additionalInfo();
                    if (c == nullptr) {
                        return std::nullopt;
                    }
                    if (!c->check()) {
                        return std::nullopt;
                    }
                    auto d = provider_->next(std::move(*c));
                    delete c;
                    if (!d) {
                        return std::nullopt;
                    }
                    return {std::move(*d).moveToAny()};
                } else {
                    return std::nullopt;
                }
            }
        };
        template <class A, typename = std::enable_if_t<!withtime_utils::IsVariant<A>::Value>>
        void innerConnectAny(AbstractConsumer<std::any> *consumer, Provider<A> *provider) {
            if constexpr (std::is_same_v<A, std::any>) {
                innerConnect(consumer, provider);
            } else {
                auto &m = connectionMap_[typeid(A).hash_code()];
                auto iter = m.find(dynamic_cast<ProviderBase *>(provider));
                if (iter != m.end() && iter->second.find(dynamic_cast<ConsumerBase *>(consumer)) != iter->second.end()) {
                    return;
                }
                consumer->connectToSource(new AnyProviderAdapter<A>(getMultiplexerOutput(provider)));
                m[dynamic_cast<ProviderBase *>(provider)].insert(dynamic_cast<ConsumerBase *>(consumer));
            }
        }
        template <class A, class B>
        void innerConnectFacility(Provider<Key<A>> *provider, OnOrderFacilityCore<A,B> *facility, AbstractConsumer<KeyedData<A,B>> *consumer) {
            class LocalE final : public virtual AbstractExporterCore<Key<A>> {
            private:                 
                OnOrderFacilityCore<A,B> *facility_;
                AbstractConsumer<KeyedData<A,B>> *consumer_;              
            public:
                LocalE(OnOrderFacilityCore<A,B> *p, AbstractConsumer<KeyedData<A,B>> *h) : AbstractExporterCore<Key<A>>(), facility_(p), consumer_(h) {}
                virtual void start(StateT *) override final {}
                virtual void handle(InnerData<Key<A>> &&k) override final {
                    facility_->placeOrder(std::move(k), consumer_);
                }
            } *localE = new LocalE(facility, consumer);
            innerConnect(localE, provider);
            std::list<Provider<SpecialOutputDataTypeForExporters> *> l;
            joinedSpecialSource_.addSource(getMultiplexerOutput(localE)); 
            facility->fetchProvidersForAppRunner(l);
            for (auto *p : l) {
                joinedSpecialSource_.addSource(getMultiplexerOutput(p));
            }      
        }
    private:
        template <class T>
        Source<T> importerAsSource(StateT *, Importer<T> &importer) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(importer.core_.get()));
            return {dynamic_cast<Provider<T> *>(importer.core_.get())};
        }
        template <class A, class B>
        Source<B> actionAsSource(StateT *, Action<A,B> &action) {
            return {dynamic_cast<Provider<B> *>(action.core_.get())};
        }
        template <class A, class B>
        Source<B> execute(Action<A,B> &action, Source<A> &&variable) {
            innerConnect(dynamic_cast<AbstractConsumer<A> *>(action.core_.get()), variable.provider);
            return {dynamic_cast<Provider<B> *>(action.core_.get())};
        }
        template <class A, class B>
        Source<B> executeAny(Action<std::any,B> &action, Source<A> &&variable) {
            innerConnectAny(dynamic_cast<AbstractConsumer<std::any> *>(action.core_.get()), variable.provider);
            return {dynamic_cast<Provider<B> *>(action.core_.get())};
        }

        #include <tm_kit/infra/SinglePassIterationApp_ExecuteAction_Piece.hpp>
   
        template <class T>
        Sink<T> exporterAsSink(Exporter<T> &exporter) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(exporter.core_.get()));
            joinedSource_.addSource(getMultiplexerOutput(exporter.core_.get()));
            return {dynamic_cast<AbstractConsumer<T> *>(exporter.core_.get())};
        }
        template <class A, class B>
        Sink<A> actionAsSink(Action<A,B> &action) {
            return {dynamic_cast<AbstractConsumer<A> *>(action.core_.get())};
        }

        #include <tm_kit/infra/SinglePassIterationApp_VariantSink_Piece.hpp>

        template <class A, class B>
        void placeOrderWithFacility(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core_.get());
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core_.get(), sink.consumer);
        }  
        template <class A, class B>
        void placeOrderWithFacilityAndForget(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core_.get());
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core_.get(), (AbstractConsumer<KeyedData<A,B>> *) nullptr);
        }

        template <class A, class B, class C>
        void placeOrderWithLocalFacility(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C>
        void placeOrderWithLocalFacilityAndForget(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core1_, (AbstractConsumer<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C>
        Sink<C> localFacilityAsSink(LocalOnOrderFacility<A,B,C> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_));
            joinedSource_.addSource(getMultiplexerOutput(facility.core2_));
            return {dynamic_cast<AbstractConsumer<C> *>(facility.core2_)};
        }

        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffects(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffectsAndForget(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core1_, (AbstractConsumer<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C>
        Source<C> facilityWithExternalEffectsAsSource(OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_));
            return {dynamic_cast<Provider<C> *>(facility.core2_)};
        }

        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacility(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility, Sink<KeyedData<A,B>> const &sink) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core1_, sink.consumer);
         } 
        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacilityAndForget(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility) {
            auto *p = dynamic_cast<IExternalComponent *>(facility.core1_);
            if (p != nullptr) {
                registerExternalComponent(p);
            } 
            innerConnectFacility(input.provider, facility.core1_, (AbstractConsumer<KeyedData<A,B>> *) nullptr);
        } 
        template <class A, class B, class C, class D>
        Source<D> vieFacilityAsSource(VIEOnOrderFacility<A,B,C,D> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core3_));
            return {dynamic_cast<Provider<D> *>(facility.core3_)};
        }
        template <class A, class B, class C, class D>
        Sink<C> vieFacilityAsSink(VIEOnOrderFacility<A,B,C,D> &facility) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(facility.core2_));
            joinedSource_.addSource(getMultiplexerOutput(facility.core2_));
            return {dynamic_cast<AbstractConsumer<C> *>(facility.core2_)};
        }

        template <class T>
        void connect(Source<T> &&src, Sink<T> const &sink) {
            innerConnect(sink.consumer, src.provider);
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void connectAny(Source<T> &&src, Sink<std::any> const &sink) {
            innerConnectAny(sink.consumer, src.provider);
        }

        #include <tm_kit/infra/SinglePassIterationApp_ConnectN_Piece.hpp>
    
        std::function<void(StateT *)> finalize() { 
            std::list<IExternalComponent *> aCopy = std::move(externalComponents_);
            InputMultiplexer<SpecialOutputDataTypeForExporters> joinedSourceCopy = std::move(joinedSource_);
            InputMultiplexer<SpecialOutputDataTypeForExporters> joinedSpecialSourceCopy = std::move(joinedSpecialSource_);
            return [aCopy=std::move(aCopy),joinedSourceCopy=std::move(joinedSourceCopy),joinedSpecialSourceCopy=std::move(joinedSpecialSourceCopy)](StateT *env) {
                for (auto c : aCopy) {
                    c->start(env);
                }
                InputMultiplexer<SpecialOutputDataTypeForExporters> s = std::move(joinedSourceCopy);
                InputMultiplexer<SpecialOutputDataTypeForExporters> s1 = std::move(joinedSpecialSourceCopy);
                if (!s.hasSource() && !s1.hasSource()) {
                    return;
                }
                InputMultiplexer<SpecialOutputDataTypeForExporters> finalMultiplexer;
                if (s1.hasSource()) {
                    finalMultiplexer.addSource(&s1);
                }
                if (s.hasSource()) {
                    finalMultiplexer.addSource(&s);
                }
                while (env->running()) {
                    auto cert = finalMultiplexer.poll();
                    if (cert.check()) {
                        auto d = finalMultiplexer.next(std::move(cert));
                        if (!d) {
                            continue;
                        }
                        if (d->timedData.finalFlag) {
                            break;
                        }
                    }
                }       
            };        
        }
        std::function<std::function<bool(StateT *)>(StateT *)> finalizeForInterleaving() {
            std::list<IExternalComponent *> aCopy = std::move(externalComponents_);
            InputMultiplexer<SpecialOutputDataTypeForExporters> joinedSourceCopy = std::move(joinedSource_);
            InputMultiplexer<SpecialOutputDataTypeForExporters> joinedSpecialSourceCopy = std::move(joinedSpecialSource_);
            return [aCopy=std::move(aCopy),joinedSourceCopy=std::move(joinedSourceCopy),joinedSpecialSourceCopy=std::move(joinedSpecialSourceCopy)](StateT *env) -> std::function<bool(StateT *)> {
                for (auto c : aCopy) {
                    c->start(env);
                }
                InputMultiplexer<SpecialOutputDataTypeForExporters> s = std::move(joinedSourceCopy);
                InputMultiplexer<SpecialOutputDataTypeForExporters> s1 = std::move(joinedSpecialSourceCopy);
                if (!s.hasSource() && !s1.hasSource()) {
                    return [](StateT *) {
                        return false;
                    };
                }
                auto *finalMultiplexer = new InputMultiplexer<SpecialOutputDataTypeForExporters>();
                if (s1.hasSource()) {
                    finalMultiplexer->addSource(new InputMultiplexer<SpecialOutputDataTypeForExporters>(s1));
                }
                if (s.hasSource()) {
                    finalMultiplexer->addSource(new InputMultiplexer<SpecialOutputDataTypeForExporters>(s));
                }
                return [finalMultiplexer](StateT *stepEnv) -> bool {
                    if (stepEnv->running()) {
                        auto cert = finalMultiplexer->poll();
                        if (cert.check()) {
                            auto d = finalMultiplexer->next(std::move(cert));
                            if (!d) {
                                return true;
                            }
                            if (d->timedData.finalFlag) {
                                return false;
                            }
                            return true;
                        } else {
                            return true;
                        }
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
        static std::unique_ptr<SynchronousRunResult<T>> runUnstartedImporterSynchronously(StateT *env, std::shared_ptr<Importer<T>> const &importer) {
            std::unique_ptr<SynchronousRunResult<T>> res = std::make_unique<SynchronousRunResult<T>>();
            importer->core_->start(env);
            while (true) {
                auto cert = importer->core_->poll();
                if (cert.check()) {
                    auto data = importer->core_->next(std::move(cert));
                    if (data) {
                        bool lastOne = data->timedData.finalFlag;
                        res->push_back(std::move(*data));
                        if (lastOne) {
                            break;
                        }
                    }
                }
            }
            return res;
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        static std::unique_ptr<SynchronousRunResult<T>> runUnstartedImporterSynchronouslyUntil(StateT *env, std::shared_ptr<Importer<T>> const &importer, std::function<bool(InnerData<T> const &)> const &condition) {
            std::unique_ptr<SynchronousRunResult<T>> res = std::make_unique<SynchronousRunResult<T>>();
            importer->core_->start(env);
            while (true) {
                auto cert = importer->core_->poll();
                if (cert.check()) {
                    auto data = importer->core_->next(std::move(cert));
                    if (data) {
                        bool conditionSatisfied = condition(*data);
                        bool lastOne = data->timedData.finalFlag;
                        res->push_back(std::move(*data));
                        if (conditionSatisfied || lastOne) {
                            break;
                        }
                    }
                }
            }
            return res;
        }
        template <class T1, class T2>
        static void startFacilitySynchronously(StateT *env, std::shared_ptr<OnOrderFacility<T1,T2>> const &facility) {
            facility->core_->enableSynchronousRunnerMode();
            auto *p = facilityAsExternalComponent(facility);
            if (p) {
                p->start(env);
            }
        }
        template <class T1, class T2>
        static std::unique_ptr<SynchronousRunResult<KeyedData<T1,T2>>> runStartedFacilitySynchronously(StateT *, std::shared_ptr<OnOrderFacility<T1,T2>> const &facility, InnerData<Key<T1>> &&key) {
            std::unique_ptr<SynchronousRunResult<KeyedData<T1,T2>>> res = std::make_unique<SynchronousRunResult<KeyedData<T1,T2>>>();
            auto action = liftPure<KeyedData<T1,T2>>(
                [](KeyedData<T1,T2> &&d) -> KeyedData<T1,T2> {
                    return std::move(d);
                }
            );
            facility->core_->placeOrder(std::move(key), action->core_.get());
            while (true) {
                auto cert = action->core_->poll();
                if (cert.check()) {
                    auto data = action->core_->next(std::move(cert));
                    if (data) {
                        bool lastOne = data->timedData.finalFlag;
                        res->push_back(std::move(*data));
                        if (lastOne) {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
            facility->core_->clearConsumersInSynchronousRunnerMode();
            return res;
        }
        template <class T1, class T2>
        static void streamToStartedFacilitySynchronously(StateT *, std::shared_ptr<OnOrderFacility<T1,T2>> const &facility, InnerData<Key<T1>> &&key, SynchronousRunResult<KeyedData<T1,T2>> *output) {
            if (output) {
                auto action = liftPure<KeyedData<T1,T2>>(
                    [](KeyedData<T1,T2> &&d) -> KeyedData<T1,T2> {
                        return std::move(d);
                    }
                );
                facility->core_->placeOrder(std::move(key), action->core_.get());
                while (true) {
                    auto cert = action->core_->poll();
                    if (cert.check()) {
                        auto data = action->core_->next(std::move(cert));
                        if (data) {
                            bool lastOne = data->timedData.finalFlag;
                            output->push_back(std::move(*data));
                            if (lastOne) {
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                }
                facility->core_->clearConsumersInSynchronousRunnerMode();
            } else {
                facility->core_->placeOrder(std::move(key), nullptr);
            }
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        static void startExporterSynchronously(StateT *env, std::shared_ptr<Exporter<T>> const &exporter) {
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
            friend class SinglePassIterationApp;
            AbstractImporterCore<T> *importerCore_;
            Data<T> data_;
            bool hasMore_;
            UnregisteredImporterIterator() : importerCore_(nullptr), data_(std::nullopt), hasMore_(false) {}
            UnregisteredImporterIterator(EnvironmentType *env, AbstractImporterCore<T> *importerCore) 
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
                        data_ = importerCore_->generate(nullptr);
                        hasMore_ = !(data_ && data_->timedData.finalFlag);
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
            friend class SinglePassIterationApp;
            AbstractExporterCore<T> *exporterCore_;
            EnvironmentType *env_;
            UnregisteredExporterIterator() : exporterCore_(nullptr), env_(nullptr) {}
            UnregisteredExporterIterator(EnvironmentType *env, AbstractExporterCore<T> *exporterCore) 
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
    using SinglePassIterationApp_T = SinglePassIterationApp<T>;
} } } }

#endif
