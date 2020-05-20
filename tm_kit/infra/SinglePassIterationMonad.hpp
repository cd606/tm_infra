#ifndef TM_KIT_INFRA_SINGLE_PASS_ITERATION_MONAD_HPP_
#define TM_KIT_INFRA_SINGLE_PASS_ITERATION_MONAD_HPP_

#include <tm_kit/infra/WithTimeData.hpp>

#include <deque>
#include <queue>
#include <stack>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    //Nothing in this monad is mutex protected because it is supposed to run
    //single-threaded
    template <class StateT, std::enable_if_t<StateT::PreserveInputRelativeOrder,int> = 0>
    class SinglePassIterationMonad {
    private:
        friend class MonadRunner<SinglePassIterationMonad>;
    public:
        using TimePoint = typename StateT::TimePointType;
        using StateType = StateT;
        using EnvironmentType = StateT;
        template <class T>
        using TimedDataType = WithTime<T, TimePoint>;
        template <class T>
        using Key = Key<T,StateT>;
        template <class A, class B>
        using KeyedData = KeyedData<A,B,StateT>;

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
        static auto pureInnerDataLift(StateT *environment, F const &f, TimedDataType<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(environment, f, std::move(a), preserveTime);
        }
        template <class A, class F>
        static auto pureInnerDataLift(F const &f, InnerData<A> &&a, bool preserveTime=false) -> decltype(withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime)) {
            return withtime_utils::pureTimedDataWithEnvironmentLift<A, F, StateT, TimePoint>(f, std::move(a), preserveTime);
        }

        template <class T>
        using Data = TimedMonadData<T,StateT>;

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
            friend class SinglePassIterationMonad;
            Certificate(std::optional<TimePoint> &&tp, std::stack<Provider<T> *> &&signerStack, Provider<T> *topSigner)
                : timePoint_(std::move(tp)), signerStack_(std::move(signerStack)) 
            {
                if (topSigner != nullptr) {
                    signerStack_.push(topSigner);
                }
            }
        public:
            Certificate() : timePoint_(std::nullopt), signerStack_() {}
            Certificate(std::optional<TimePoint> &&tp, Provider<T> *signer) : timePoint_(std::move(tp)), signerStack_() {
                signerStack_.push(signer);
            }
            Certificate(Certificate const &c) = default;
            Certificate &operator=(Certificate const &c) = default;
            Certificate(Certificate &&c) = default;
            Certificate &operator=(Certificate &&c) = default;
            Certificate push(Provider<T> *signer) {
                auto ret = Certificate {std::move(timePoint_), std::move(signerStack_), signer};
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
            friend class SinglePassIterationMonad;
        public:
            class Output : public virtual Provider<T> {
            private:
                friend class OutputMultiplexer;
                OutputMultiplexer *parent_;
                int idx_;
                std::size_t qPos_;
            public:
                Output(OutputMultiplexer *parent, int idx) : parent_(parent), idx_(idx), qPos_(parent_->queue_.size()) {}
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
            friend class SinglePassForwardingMonad;
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
                outputs_.push_back(std::make_unique<Output>(this, outputs_.size()));
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
            friend class SinglePassIterationMonad;
            std::unique_ptr<T> core_;
            void release() {
                core_.release();
            }
        public:
            using InputType = Input;
            using OutputType = Output;
            TwoWayHolder(std::unique_ptr<T> &&p) : core_(std::move(p)) {}
            template <class A>
            TwoWayHolder(A *p) : core_(std::unique_ptr<T>(static_cast<T *>(p))) {}
        };
        template <class T, class Data>
        class OneWayHolder {
        private:
            friend class SinglePassIterationMonad;
            std::unique_ptr<T> core_;
            void release() {
                core_.release();
            }
        public:
            using DataType = Data;
            OneWayHolder(std::unique_ptr<T> &&p) : core_(std::move(p)) {}
            template <class A>
            OneWayHolder(A *p) : core_(std::unique_ptr<T>(static_cast<T *>(p))) {}
        };
        template <class T1, class Input, class Output, class T2, class Data>
        class ThreeWayHolder {
        private:
            friend class SinglePassIterationMonad;
            //The reason why we use raw pointers here is that
            //the two pointers may well be pointing to the same
            //object (through different base classes). Therefore
            //we give up on managing the memory for this special
            //case
            T1 *core1_;
            T2 *core2_;
            void release() {
                core1_ = nullptr;
                core2_ = nullptr;
            }
        public:
            using InputType = Input;
            using OutputType = Output;
            using DataType = Data;

            template <class A, class B>
            ThreeWayHolder(A *p1, B*p2) : core1_(static_cast<T1 *>(p1)), core2_(static_cast<T2 *>(p2)) {}
            ThreeWayHolder(ThreeWayHolder const &) = delete;
            ThreeWayHolder &operator=(ThreeWayHolder const &) = delete;
            ThreeWayHolder(ThreeWayHolder &&) = default;
            ThreeWayHolder &operator=(ThreeWayHolder &&) = default;
        };

    private:
        template <class A, class B>
        class AbstractActionCore : public virtual AbstractConsumer<A>, public virtual Provider<B> {
        };

        #include <tm_kit/infra/SinglePassIterationMonad_AbstractActionCore_Piece.hpp>

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
                return std::get<1>(ret)();
            }
        };

        template <class A, class B>
        class ActionCore : public virtual AbstractActionCore<A,B>, public virtual Consumer<A>, public virtual BufferedProvider<B> {
        protected:
            virtual typename BufferedProvider<B>::CheckAndProduceResult checkAndProduce() override final {
                Certificate<A> t { this->source()->poll() };
                if (!t.check()) {
                    return std::nullopt;
                }
                auto tp = fetchTimePointUnsafe(t);
                auto produce = [t=std::move(t),this]() -> Data<B> {
                    Certificate<A> t1 {std::move(t)};
                    auto input = this->source()->next(std::move(t1));
                    if (!input) {
                        return std::nullopt;
                    }
                    return handle(std::move(*input));
                };
                return std::tuple<TimePoint, std::function<Data<B>()>> {tp, produce};
            }       
            virtual Data<B> handle(InnerData<A> &&) = 0;
        public:
            ActionCore() : Provider<B>(), Consumer<A>() {}           
        };

    private:
        template <class A, class B, class F>
        class PureActionCore final : public ActionCore<A,B> {
        private:
            F f_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                return {
                    pureInnerDataLift<A>(f_, std::move(a))
                };
            }
        public:
            PureActionCore(F &&f) : ActionCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~PureActionCore() {}
        };
        template <class A, class B, class F>
        class MaybeActionCore final : public ActionCore<A,B> {
        private:
            F f_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                std::optional<B> y = f_(std::move(a.timedData.value));
                if (!y) {
                    return std::nullopt;
                } else {
                    return pureInnerData<B>(
                        a.environment,
                        {a.timedData.timePoint, std::move(*y), a.timedData.finalFlag}
                    );
                }
            }
        public:
            MaybeActionCore(F &&f) : ActionCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~MaybeActionCore() {}
        };
        template <class A, class B, class F>
        class EnhancedMaybeActionCore final : public ActionCore<A,B> {
        private:
            F f_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                std::optional<B> y = f_(std::tuple<TimePoint, A> {a.timedData.timePoint, std::move(a.timedData.value)});
                if (!y) {
                    return std::nullopt;
                } else {
                    return pureInnerData<B>(
                        a.environment,
                        {a.timedData.timePoint, std::move(*y), a.timedData.finalFlag}
                    );
                }
            }
        public:
            EnhancedMaybeActionCore(F &&f) : ActionCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~EnhancedMaybeActionCore() {}
        };
        template <class A, class B, class F>
        class KleisliActionCore final : public ActionCore<A,B> {
        private:
            F f_;
        protected:
            virtual Data<B> handle(InnerData<A> &&a) override final {
                return f_(std::move(a));
            }
        public:
            KleisliActionCore(F &&f) : ActionCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~KleisliActionCore() {}
        };

    public:
        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A>,int> = 0 >
        using AbstractAction = AbstractActionCore<A,B>;

        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A>,int> = 0 >
        using Action = TwoWayHolder<AbstractActionCore<A,B>,A,B>;

    public:
        template <class A, class F>
        static auto liftPure(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> std::shared_ptr<Action<A, decltype(f(A()))>> {
            return std::make_shared<Action<A, decltype(f(A()))>>(new PureActionCore<A,decltype(f(A())),F>(std::move(f)));
        }
        template <class A, class F>
        static auto liftMaybe(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(A()))::value_type>>(new MaybeActionCore<A,typename decltype(f(A()))::value_type,F>(std::move(f)));
        }
        template <class A, class F>
        static auto enhancedMaybe(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeActionCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F>(std::move(f)));
        }
        template <class A, class F>
        static auto kleisli(F &&f, bool suggestThreaded=false, FanInParamMask const &notUsed=FanInParamMask()) 
            -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>(new KleisliActionCore<A,typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType,F>(std::move(f)));
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
        };

    public:
        template <class A, class B, class C>
        static std::shared_ptr<Action<A,C>> compose(Action<A,B> &&x, Action<B,C> &&y) {
            return std::make_shared<Action<A,C>>(new ComposeCore<A,B,C>(std::move(x.core_), std::move(y.core_)));
        }

    private:
        template <class A, class B>
        class OnOrderFacilityCore {
        private:
            struct TimeComparer {
                bool operator()(InnerData<KeyedData<A,B>> const &a, InnerData<KeyedData<A,B>> const &b) {
                    return (a.timedData.timePoint > b.timedData.timePoint);
                }
            };
            using DQueue = std::priority_queue<InnerData<KeyedData<A,B>>, std::vector<InnerData<KeyedData<A,B>>>, TimeComparer>;
            class ResponseProvider final : public virtual Provider<KeyedData<A,B>> {
            private:
                DQueue queue_;
                friend class OnOrderFacilityCore;
                void addResponse(InnerData<KeyedData<A,B>> &&response) {
                    queue_.push(std::move(response));
                }
            public:
                ResponseProvider() = default;
                virtual Certificate<KeyedData<A,B>> poll() override final {
                    if (queue_.empty()) {
                        return Certificate<KeyedData<A,B>> {std::nullopt, this};
                    }
                    return Certificate<KeyedData<A,B>> {queue_.top().timedData.timePoint, this};
                }
                virtual Data<KeyedData<A,B>> next(Certificate<KeyedData<A,B>> &&cert) override final {
                    cert.consume(this);
                    auto ret = std::move(queue_.top());              
                    queue_.pop();
                    return {ret};
                }
            };
            std::unordered_map<typename StateT::IDType, std::tuple<Key<A>, bool, ResponseProvider *>, typename StateT::IDHash> keyMap_;
            std::unordered_map<AbstractConsumer<KeyedData<A,B>> *, std::unique_ptr<ResponseProvider>> providers_;
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
                    if (!std::get<1>(iter->second)) {
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
        public:
            OnOrderFacilityCore() : keyMap_(), providers_() {}
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
            virtual void fetchProvidersForMonadRunner(std::list<Provider<SpecialOutputDataTypeForExporters> *> &output) {
                //by default do nothing
            } 
            friend class SinglePassIterationMonad;       
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
        public:
            PureOnOrderFacilityCore(F &&f) : OnOrderFacilityCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~PureOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                auto resp = pureInnerDataLift([this](Key<A> &&k) {
                    return withtime_utils::apply(f_, std::move(k));
                }, std::move(input));
                resp.timedData.finalFlag = true; 
                this->publishResponse(std::move(resp));
            }
        };
        template <class A, class B, class F>
        class MaybeOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_;
        public:
            MaybeOnOrderFacilityCore(F &&f) : OnOrderFacilityCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~MaybeOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                typename StateT::IDType id = input.timedData.value.id();
                std::optional<B> x = f_(std::move(input.timedData.value.key()));
                if (x) {
                    this->publishResponse(pureInnerData<Key<B>>(input.environment, {input.timedData.timePoint, {id, std::move(*x)}, true}));
                } 
            }
        };
        template <class A, class B, class F>
        class EnhancedMaybeOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_;
        public:
            EnhancedMaybeOnOrderFacilityCore(F &&f) : OnOrderFacilityCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~EnhancedMaybeOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                typename StateT::IDType id = input.timedData.value.id();
                std::optional<B> x = f_(std::tuple<TimePoint,A> {input.timedData.timePoint, std::move(input.timedData.value.key())});
                if (x) {
                    this->publishResponse(pureInnerData<Key<B>>(input.environment, {input.timedData.timePoint, {id, std::move(*x)}, true}));
                } 
            }
        };
        template <class A, class B, class F>
        class KleisliOnOrderFacilityCore final : public OnOrderFacilityCore<A,B> {
        private:
            F f_;
        public:
            KleisliOnOrderFacilityCore(F &&f) : OnOrderFacilityCore<A,B>(), f_(std::move(f)) {
            }
            virtual ~KleisliOnOrderFacilityCore() {}
            virtual void handle(InnerData<Key<A>> &&input) override final {
                typename StateT::IDType id = input.timedData.value.id();
                InnerData<A> x = pureInnerDataLift([](Key<A> &&k) -> A {
                    return k.key();
                }, std::move(input));
                Data<B> y = f_(std::move(x));
                if (y) {
                    y->timedData.finalFlag = true;
                    this->publishResponse(pureInnerDataLift<B>(
                        [id=std::move(id)](B &&b) -> Key<B> {
                            return {id, std::move(b)};
                        }, std::move(*y)));
                }
            }
        };
    public:
        template <class A, class F>
        static auto liftPureOnOrderFacility(F &&f) 
            -> std::shared_ptr<OnOrderFacility<A, decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A, decltype(f(A()))>>(new PureOnOrderFacilityCore<A,decltype(f(A())),F>(std::move(f)));
        }
        template <class A, class F>
        static auto liftMaybeOnOrderFacility(F &&f) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>(new MaybeOnOrderFacilityCore<A,typename decltype(f(A()))::value_type,F>(std::move(f)));
        }
        template <class A, class F>
        static auto enhancedMaybeOnOrderFacility(F &&f) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(new EnhancedMaybeOnOrderFacilityCore<A,typename decltype(f(std::tuple<TimePoint,A>()))::value_type,F>(std::move(f)));
        }
        template <class A, class F>
        static auto kleisliOnOrderFacility(F &&f) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>(new KleisliOnOrderFacilityCore<A,typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType,F>(std::move(f)));
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

        #include <tm_kit/infra/SinglePassIterationMonad_ActionCore_Piece.hpp>

    public:

        #include <tm_kit/infra/SinglePassIterationMonad_Merge_Piece.hpp>
        #include <tm_kit/infra/SinglePassIterationMonad_Pure_Maybe_Kleisli_Piece.hpp>

    public:
        class IExternalComponent {
        public:
            virtual ~IExternalComponent() {}
            virtual void start(StateT *environment) = 0;
        };
        template <class T, std::enable_if_t<!is_keyed_data_v<T>,int> = 0>
        class AbstractImporterCore : public virtual IExternalComponent, public virtual BufferedProvider<T> {
        protected:
            //an importer is NEVER idle in this monad
            virtual typename BufferedProvider<T>::CheckAndProduceResult checkAndProduce() override final {
                auto d = generate();
                return std::tuple<TimePoint, std::function<Data<T>()>> {d.timedData.timePoint, [d=std::move(d)]() -> Data<T> {return {std::move(d)};}};
            }
        public:           
            virtual InnerData<T> generate() = 0;
            AbstractImporterCore() : BufferedProvider<T>() {}
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
            StateT *environment_;
        public:
            SimpleImporter(F &&f) : AbstractImporterCore<T>(), f_(std::move(f)), environment_(nullptr) {}
            virtual void start(StateT *environment) override final {
                environment_ = environment;
            }
            virtual InnerData<T> generate() override final {
                return f_(environment_);
            }
        };

    public:
        template <class T>
        static std::shared_ptr<Importer<T>> vacuousImporter() {
            class LocalI final : public AbstractImporterCore<T> {
            public:
                virtual void start(StateT *environment) override final {
                    throw std::runtime_error("Vacuous importer called");
                }
                virtual InnerData<T> generate() override final {
                    throw std::runtime_error("Vacuous importer called");
                }
            };
            return std::make_shared<Importer<T>>(new LocalI());
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> simpleImporter(F &&f, bool suggestThreaded=false) {
            return std::make_shared<Importer<T>>(new SimpleImporter<T,F>(std::move(f)));
        }
    
    public:
        template <class T>
        class AbstractExporterCore : public virtual IExternalComponent, public virtual Consumer<T>, public virtual Provider<SpecialOutputDataTypeForExporters> {
        private:
            Certificate<T> sourceCert_;
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
                auto env = input->environment;
                auto tp = input->timedData.timePoint;
                auto flag = input->timedData.finalFlag;
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
            AbstractExporterCore() : Consumer<T>(), sourceCert_() {}
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
            virtual void start(StateT *environment) override final {}
            virtual void handle(InnerData<T> &&data) override final {
                f_(std::move(data));
            }
        };

    public:
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> simpleExporter(F &&f, bool suggestThreaded=false) {
            return std::make_shared<Exporter<T>>(new SimpleExporter<T,F>(std::move(f)));
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> pureExporter(F &&f, bool suggestThreaded=false) {
            auto wrapper = [f=std::move(f)](InnerData<T> &&d) {
                f(std::move(d.timedData.value));
            };
            return simpleExporter<T>(std::move(wrapper), suggestThreaded);
        }
        template <class T>
        static std::shared_ptr<Exporter<T>> trivialExporter() {
            return simpleExporter<T>([](InnerData<T> &&) {}, false);
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
                }
                virtual void start(StateT *environment) override final {
                    orig_.core_->start(environment);
                }
                virtual InnerData<T2> generate() override final {
                    while (true) {
                        Certificate<T2> cert = post_.core_->poll(); //this can be assumed to always succeed
                        auto d = post_.core_->next(std::move(cert));
                        if (d) {
                            return *d;
                        }
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
            virtual void fetchProvidersForMonadRunner(std::list<Provider<SpecialOutputDataTypeForExporters> *> &output) override final {
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
        };

    public:
        //For the reason why LocalOnOrderFacility is essentially a tuple
        //and not directly based on AbstractIntegratedLocalOnOrderFacility,
        //please refer to the comments in RealTimeMonad.hpp
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
        {};
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

    public:
        template <class T>
        class Source {
        private:
            friend class SinglePassIterationMonad;
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
            friend class SinglePassIterationMonad;
            AbstractConsumer<T> *consumer;
            Sink(AbstractConsumer<T> *p) : consumer(p) {}
        };
    private:
        std::list<IExternalComponent *> externalComponents_;
        std::unordered_set<IExternalComponent *> externalComponentsSet_;
        InputMultiplexer<SpecialOutputDataTypeForExporters> joinedSource_, joinedSpecialSource_;
        std::unordered_map<ProviderBase *, OutputMultiplexerBase *> outputMultiplexerMap_;
        std::unordered_map<ProviderBase *, std::unordered_set<ConsumerBase *>> connectionMap_;

        SinglePassIterationMonad() : externalComponents_(), externalComponentsSet_(), joinedSource_(), joinedSpecialSource_(), outputMultiplexerMap_(), connectionMap_() {}
        ~SinglePassIterationMonad() {}

        void registerExternalComponent(IExternalComponent *c) {
            if (externalComponentsSet_.find(c) == externalComponentsSet_.end()) {
                externalComponents_.push_back(c);
                externalComponentsSet_.insert(c);
            }
        }
        template <class A>
        Provider<A> *getMultiplexerOutput(Provider<A> *p) {
            auto iter = outputMultiplexerMap_.find(p);
            if (iter == outputMultiplexerMap_.end()) {
                iter = outputMultiplexerMap_.insert(
                    {p, new OutputMultiplexer<A>(p)}
                ).first;
            }
            return dynamic_cast<OutputMultiplexer<A> *>(iter->second)->addOutput();
        }

        template <class A>
        void innerConnect(AbstractConsumer<A> *consumer, Provider<A> *provider) {
            auto iter = connectionMap_.find(dynamic_cast<ProviderBase *>(provider));
            if (iter != connectionMap_.end() && iter->second.find(dynamic_cast<ConsumerBase *>(consumer)) != iter->second.end()) {
                return;
            }
            consumer->connectToSource(getMultiplexerOutput(provider));
            connectionMap_[dynamic_cast<ProviderBase *>(provider)].insert(dynamic_cast<ConsumerBase *>(consumer));
        }
        template <class A, class B>
        void innerConnectFacility(Provider<Key<A>> *provider, OnOrderFacilityCore<A,B> *facility, AbstractConsumer<KeyedData<A,B>> *consumer) {
            class LocalE final : public virtual AbstractExporterCore<Key<A>> {
            private:                 
                OnOrderFacilityCore<A,B> *facility_;
                AbstractConsumer<KeyedData<A,B>> *consumer_;              
            public:
                LocalE(OnOrderFacilityCore<A,B> *p, AbstractConsumer<KeyedData<A,B>> *h) : AbstractExporterCore<Key<A>>(), facility_(p), consumer_(h) {}
                virtual void start(StateT *environment) override final {}
                virtual void handle(InnerData<Key<A>> &&k) override final {
                    facility_->placeOrder(std::move(k), consumer_);
                }
            } *localE = new LocalE(facility, consumer);
            innerConnect(localE, provider);
            std::list<Provider<SpecialOutputDataTypeForExporters> *> l;
            joinedSpecialSource_.addSource(getMultiplexerOutput(localE)); 
            facility->fetchProvidersForMonadRunner(l);
            for (auto *p : l) {
                joinedSpecialSource_.addSource(getMultiplexerOutput(p));
            }      
        }
    private:
        template <class T>
        Source<T> importerAsSource(StateT *env, Importer<T> &importer) {
            registerExternalComponent(dynamic_cast<IExternalComponent *>(importer.core_.get()));
            return {dynamic_cast<Provider<T> *>(importer.core_.get())};
        }
        template <class A, class B>
        Source<B> actionAsSource(StateT *env, Action<A,B> &action) {
            return {dynamic_cast<Provider<B> *>(action.core_.get())};
        }
        template <class A, class B>
        Source<B> execute(Action<A,B> &action, Source<A> &&variable) {
            innerConnect(dynamic_cast<AbstractConsumer<A> *>(action.core_.get()), variable.provider);
            return {dynamic_cast<Provider<B> *>(action.core_.get())};
        }

        #include <tm_kit/infra/SinglePassIterationMonad_ExecuteAction_Piece.hpp>
   
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

        #include <tm_kit/infra/SinglePassIterationMonad_VariantSink_Piece.hpp>

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


        template <class T>
        void connect(Source<T> &&src, Sink<T> const &sink) {
            innerConnect(sink.consumer, src.provider);
        }
    
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
                while (true) {
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
    };
} } } }

#endif
