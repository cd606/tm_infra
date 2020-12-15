#ifndef TM_KIT_INFRA_BASIC_WITHTIME_APP_HPP_
#define TM_KIT_INFRA_BASIC_WITHTIME_APP_HPP_

#include <future>
#include <tm_kit/infra/WithTimeData.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class StateT>
    class BasicWithTimeApp {
    private:
        friend class AppRunner<BasicWithTimeApp>;
    public:
        static constexpr bool PossiblyMultiThreaded = false;
        static constexpr bool CannotHaveLoopEvenWithFacilities = false;

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

        template <class A, class B, std::enable_if_t<!is_keyed_data_v<B> || is_keyed_data_v<A>,int> = 0 >
        struct Action {
            using InputType = A;
            using OutputType = B;

            bool threaded;
            bool oneTimeOnly;

            Action() : threaded(false), oneTimeOnly(false) {}
            Action(bool t, bool o) : threaded(t), oneTimeOnly(o) {}
            Action(LiftParameters<TimePoint> const &liftParam)
                : threaded(liftParam.suggestThreaded)
                , oneTimeOnly(liftParam.fireOnceOnly)
            {}
            ~Action() = default;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };

        template <class A, class B>
        static bool actionIsThreaded(std::shared_ptr<Action<A,B>> const &p) {
            return p->threaded;
        }
        template <class A, class B>
        static bool actionIsOneTimeOnly(std::shared_ptr<Action<A,B>> const &p) {
            return p->oneTimeOnly;
        }

        template <class A, class B>
        static auto emptyAction(LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, B>> {
            return std::make_shared<Action<A, B>>(liftParam);
        }
        template <class A, class F>
        static auto liftPure(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, decltype(f(A()))>> {
            return std::make_shared<Action<A, decltype(f(A()))>>(liftParam);
        }
        template <class A, class F>
        static auto liftMaybe(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(A()))::value_type>>(liftParam);
        }
        template <class A, class F>
        static auto enhancedMaybe(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(liftParam);
        }
        template <class A, class F>
        static auto kleisli(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>(liftParam);
        }
        template <class A, class F>
        static auto liftMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(A()))::value_type>>(liftParam);
        }
        template <class A, class F>
        static auto enhancedMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>(liftParam);
        }
        template <class A, class F>
        static auto kleisliMulti(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType::value_type>> {
            return std::make_shared<Action<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType::value_type>>(liftParam);
        }
        template <class A, class B>
        static auto continuationAction(TimedAppModelContinuation<A, B, EnvironmentType> const &cont, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) -> std::shared_ptr<Action<A, B>> {
            return std::make_shared<Action<A,B>>(liftParam);
        }
        template <class A, class B, class C>
        static std::shared_ptr<Action<A,C>> compose(Action<A,B> &&x, Action<B,C> &&y) {
            return std::make_shared<Action<A,C>>(
                x.threaded || y.threaded
                , x.oneTimeOnly && y.oneTimeOnly
            );
        }

        class IExternalComponent {
        public:
            virtual ~IExternalComponent() {}
            virtual void start(StateT *environment) = 0;
        };

        template <class A, class B>
        class AbstractOnOrderFacility {
        public: 
            void publish(InnerData<Key<B>> &&response) {
            }   
            void publish(StateT *env, Key<B> &&data, bool isFinal) {
            }  
            virtual void handle(InnerData<Key<A>> &&input) = 0;
        };

        template <class A, class B>
        struct OnOrderFacility {
            using InputType = A;
            using OutputType = B;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };

        template <class A, class B>
        static auto emptyOnOrderFacility() 
            -> std::shared_ptr<OnOrderFacility<A, B>> {
            return std::make_shared<OnOrderFacility<A, B>>();
        }
        template <class A, class F>
        static auto liftPureOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A, decltype(f(A()))>>();
        }
        template <class A, class F>
        static auto liftMaybeOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>();
        }
        template <class A, class F>
        static auto enhancedMaybeOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>();
        }
        template <class A, class F>
        static auto kleisliOnOrderFacility(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>();
        }
        template <class A, class F, class StartF>
        static auto liftPureOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, decltype(f(A()))>> {
            return std::make_shared<OnOrderFacility<A, decltype(f(A()))>>();
        }
        template <class A, class F, class StartF>
        static auto liftMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(A()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(A()))::value_type>>();
        }
        template <class A, class F, class StartF>
        static auto enhancedMaybeOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(std::tuple<TimePoint,A>()))::value_type>>();
        }
        template <class A, class F, class StartF>
        static auto kleisliOnOrderFacilityWithStart(F &&f, StartF &&startF, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) 
            -> std::shared_ptr<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>> {
            return std::make_shared<OnOrderFacility<A, typename decltype(f(pureInnerData<A>(nullptr,A())))::value_type::ValueType>>();
        }
        template <class A, class B>
        static auto fromAbstractOnOrderFacility(AbstractOnOrderFacility<A,B> *)
            -> std::shared_ptr<OnOrderFacility<A,B>> {
            return std::make_shared<OnOrderFacility<A,B>>();
        }

        #include <tm_kit/infra/BasicWithTimeApp_VariantAndMerge_Piece.hpp>
        #include <tm_kit/infra/BasicWithTimeApp_Pure_Maybe_Kleisli_Piece.hpp>

        template <class T, std::enable_if_t<!is_keyed_data_v<T>,int> = 0>
        class AbstractImporter : public virtual IExternalComponent {
        public:
            void publish(InnerData<T> &&data) {
            }
            void publish(StateT *env, T &&data, bool finalFlag=false) {
            }
        };

        template <class T>
        struct Importer {
            using DataType = T;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };

        template <class T>
        static std::shared_ptr<Importer<T>> importer(AbstractImporter<T> *) {
            return std::make_shared<Importer<T>>();
        }

        template <class T>
        static std::shared_ptr<Importer<T>> vacuousImporter() {
            return std::make_shared<Importer<T>>();
        }
        template <class T, class F>
        static std::shared_ptr<Importer<T>> simpleImporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Importer<T>>();
        }
        template <class T>
        static std::shared_ptr<Importer<T>> constFirstPushImporter(T &&t = T()) {
            return std::make_shared<Importer<T>>();
        }
        template <class T>
        static std::shared_ptr<Importer<Key<T>>> constFirstPushKeyImporter(T &&t = T()) {
            return constFirstPushImporter<Key<T>>(
                infra::withtime_utils::keyify<T,StateT>(std::move(t))
            );
        }
        template <class T>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void()>> constTriggerImporter(T &&t = T()) {
            return {
                std::make_shared<Importer<T>>()
                , []() {}
            };
        }
        template <class T>
        static std::tuple<std::shared_ptr<Importer<T>>,std::function<void(T&&)>> triggerImporter() {
            return {
                std::make_shared<Importer<T>>()
                , [](T &&) {}
            };
        }
    
        template <class T>
        class AbstractExporter : public virtual IExternalComponent {
        public:
            virtual void handle(InnerData<T> &&) = 0;
        };

        template <class T>
        struct Exporter {
            using DataType = T;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };

        template <class T>
        static std::shared_ptr<Exporter<T>> exporter(AbstractExporter<T> *) {
            return std::make_shared<Exporter<T>>();
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> simpleExporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Exporter<T>>();
        }
        template <class T, class F>
        static std::shared_ptr<Exporter<T>> pureExporter(F &&f, LiftParameters<TimePoint> const &liftParam = LiftParameters<TimePoint>()) {
            return std::make_shared<Exporter<T>>();
        }
        template <class T>
        static std::shared_ptr<Exporter<T>> trivialExporter() {
            return std::make_shared<Exporter<T>>();
        }        

        template <class T1, class T2>
        static std::shared_ptr<Importer<T2>> composeImporter(Importer<T1> &&orig, Action<T1,T2> &&post) {
            return std::make_shared<Importer<T2>>();
        }
        template <class T1, class T2>
        static std::shared_ptr<Exporter<T1>> composeExporter(Action<T1,T2> &&pre, Exporter<T2> &&orig) {
            return std::make_shared<Exporter<T1>>();
        }

        template <class I0, class O0, class I1, class O1>
        static std::shared_ptr<OnOrderFacility<I0,O0>> wrappedOnOrderFacility(OnOrderFacility<I1,O1> &&toWrap, Action<Key<I0>,Key<I1>> &&inputT, Action<Key<O1>,Key<O0>> &&outputT) {
            return std::make_shared<OnOrderFacility<I0,O0>>();
        };

        template <class QueryKeyType, class QueryResultType, class DataInputType>
        struct LocalOnOrderFacility {
            using InputType = QueryKeyType;
            using OutputType = QueryResultType;
            using DataType = DataInputType;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static auto emptyLocalOnOrderFacility() 
            -> std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>();
        }
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>> localOnOrderFacility(
            AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractExporter<DataInputType> *e) {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>();
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
            AbstractIntegratedLocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType> *) {
            return std::make_shared<LocalOnOrderFacility<QueryKeyType, QueryResultType, DataInputType>>();
        }
        
        template <class Fac, class Exp>
        static std::shared_ptr<LocalOnOrderFacility<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Exp::DataType>> localOnOrderFacility(
            Fac &&t, Exp &&e) {
            return std::make_shared<LocalOnOrderFacility<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Exp::DataType>>(
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
            return std::make_shared<LocalOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::DataType>>(
            );
        }

        template <class QueryKeyType, class QueryResultType, class DataInputType>
        struct OnOrderFacilityWithExternalEffects {
            using InputType = QueryKeyType;
            using OutputType = QueryResultType;
            using DataType = DataInputType;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static auto emptyOnOrderFacilityWithExternalEffects() 
            -> std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>();
        }
        template <class QueryKeyType, class QueryResultType, class DataInputType>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>> onOrderFacilityWithExternalEffects(
            AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractImporter<DataInputType> *e) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>();
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
            return std::make_shared<OnOrderFacilityWithExternalEffects<QueryKeyType, QueryResultType, DataInputType>>();
        }
        
        template <class Fac, class Imp>
        static std::shared_ptr<OnOrderFacilityWithExternalEffects<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Imp::DataType>> onOrderFacilityWithExternalEffects(
            Fac &&t, Imp &&i) {
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Imp::DataType>>(
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
            return std::make_shared<OnOrderFacilityWithExternalEffects<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::DataType>>(
            );
        }

        template <class QueryKeyType, class QueryResultType, class ExtraInputT, class ExtraOutputT>
        struct VIEOnOrderFacility {
            using InputType = QueryKeyType;
            using OutputType = QueryResultType;
            using ExtraInputType = ExtraInputT;
            using ExtraOutputType = ExtraOutputT;
            std::unordered_set<void *> getUnderlyingPointers() const {
                return {};
            }
        };
        template <class QueryKeyType, class QueryResultType, class ExtraInputT, class ExtraOutputT>
        static auto emptyVIEOnOrderFacility() 
            -> std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputT, ExtraOutputT>> {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputT, ExtraOutputT>>();
        }
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            AbstractOnOrderFacility<QueryKeyType, QueryResultType> *t
            , AbstractExporter<ExtraInputType> *i
            , AbstractImporter<ExtraOutputType> *o) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>();
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
        template <class QueryKeyType, class QueryResultType, class ExtraInputType, class ExtraOutputType>
        static std::shared_ptr<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>> vieOnOrderFacility(
            AbstractIntegratedVIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType> *p) {
            return std::make_shared<VIEOnOrderFacility<QueryKeyType, QueryResultType, ExtraInputType, ExtraOutputType>>();
        }
        
        template <class Fac, class Exp, class Imp>
        static std::shared_ptr<VIEOnOrderFacility<
            typename Fac::InputType
            , typename Fac::OutputType
            , typename Exp::DataType
            , typename Imp::DataType>> vieOnOrderFacility(
            Fac &&t, Exp &&i, Imp &&o) {
            return std::make_shared<VIEOnOrderFacility<
                typename Fac::InputType
                , typename Fac::OutputType
                , typename Exp::DataType
                , typename Imp::DataType>>(
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
            return std::make_shared<VIEOnOrderFacility<
                typename Action1::InputType::KeyType
                , typename Action2::OutputType::KeyType
                , typename Fac::ExtraInputType
                , typename Fac::ExtraOutputType>>(
            );
        }

        template <class T>
        class Source {
        private:
            friend class BasicWithTimeApp;
            Source() {}
        public:
            Source clone() const {
                return Source {};
            }
        };
        template <class T>
        class Sink {
        private:
            friend class BasicWithTimeApp;
            Sink() {}
        };

    private:
        BasicWithTimeApp() {}
        ~BasicWithTimeApp() {}

        void registerExternalComponent(IExternalComponent *c) {
        }

    private:
        template <class T>
        Source<T> importerAsSource(StateT *env, Importer<T> &importer) {
            return {};
        }
        template <class A, class B>
        Source<B> actionAsSource(StateT *env, Action<A,B> &action) {
            return {};
        }
        template <class A, class B>
        Source<B> execute(Action<A,B> &action, Source<A> &&variable) {
            return {};
        }

        #include <tm_kit/infra/BasicWithTimeApp_ExecuteAction_Piece.hpp>
   
        template <class T>
        Sink<T> exporterAsSink(Exporter<T> &exporter) {
            return {};
        }
        template <class A, class B>
        Sink<A> actionAsSink(Action<A,B> &action) {
            return {};
        }

        #include <tm_kit/infra/BasicWithTimeApp_VariantSink_Piece.hpp>

        template <class A, class B>
        void placeOrderWithFacility(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility, Sink<KeyedData<A,B>> const &sink) {
        }  
        template <class A, class B>
        void placeOrderWithFacilityAndForget(Source<Key<A>> &&input, OnOrderFacility<A,B> &facility) {
        }

        template <class A, class B, class C>
        void placeOrderWithLocalFacility(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
         } 
        template <class A, class B, class C>
        void placeOrderWithLocalFacilityAndForget(Source<Key<A>> &&input, LocalOnOrderFacility<A,B,C> &facility) {
        } 
        template <class A, class B, class C>
        Sink<C> localFacilityAsSink(LocalOnOrderFacility<A,B,C> &facility) {
            return {};
        }

        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffects(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility, Sink<KeyedData<A,B>> const &sink) {
         } 
        template <class A, class B, class C>
        void placeOrderWithFacilityWithExternalEffectsAndForget(Source<Key<A>> &&input, OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
        } 
        template <class A, class B, class C>
        Source<C> facilityWithExternalEffectsAsSource(OnOrderFacilityWithExternalEffects<A,B,C> &facility) {
            return {};
        }

        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacility(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility, Sink<KeyedData<A,B>> const &sink) {
        } 
        template <class A, class B, class C, class D>
        void placeOrderWithVIEFacilityAndForget(Source<Key<A>> &&input, VIEOnOrderFacility<A,B,C,D> &facility) {
        } 
        template <class A, class B, class C, class D>
        Source<D> vieFacilityAsSource(VIEOnOrderFacility<A,B,C,D> &facility) {
            return {};
        }
        template <class A, class B, class C, class D>
        Sink<C> vieFacilityAsSink(VIEOnOrderFacility<A,B,C,D> &facility) {
            return {};
        }

        template <class T>
        void connect(Source<T> &&src, Sink<T> const &sink) {
        }

        #include <tm_kit/infra/BasicWithTimeApp_ConnectN_Piece.hpp>
    
        std::function<void(StateT *)> finalize() { 
            return [](StateT *) {};
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
    };

}}}}

#endif