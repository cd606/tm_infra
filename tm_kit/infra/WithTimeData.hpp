#ifndef TM_KIT_INFRA_WITHTIME_DATA_HPP_
#define TM_KIT_INFRA_WITHTIME_DATA_HPP_

#ifdef _MSC_VER
#pragma warning( disable : 4250 )
#pragma warning( disable : 4251 )
#endif

#include <variant>
#include <memory>
#include <iostream>
#include <cassert>
#include <optional>
#include <functional>
#include <cstdarg>
#include <chrono>
#include <thread>
#include <map>
#include <set>
#include <deque>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stdint.h>
#include <future>
#include <bitset>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <regex>
#include <any>
#include <typeindex>

#include <tm_kit/infra/ChronoUtils.hpp>
#include <tm_kit/infra/LogLevel.hpp>
#include <tm_kit/infra/VersionedData.hpp>
#include <tm_kit/infra/TraceNodesComponent.hpp>
#include <tm_kit/infra/ControllableNode.hpp>
#include <tm_kit/infra/ObservableNode.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    constexpr std::size_t MAX_FAN_IN_BRANCH_COUNT = 10;   

    template <class T>
    struct LiftParameters {
        //This is only relevant in real-time monad, it specifies whether the logic
        //shall be executed in its own thread
        bool suggestThreaded = false;
        //This is only relevant in single-pass iteration monad, it adds an artificial
        //delay to denote the time needed for the logic 
        //The "int" parameter denotes which input (0-indexed) is coming in, since the
        //delay might be different for different parameters
        using DelaySimulatorType = std::optional<std::function<decltype(T()-T())(int, T const &)>>;
        DelaySimulatorType delaySimulator = std::nullopt;
        //This, if true, means that the lifted action shall only run until 
        //it has produced its first output. 
        //This only applies to actions, not to on-order facilities
        bool fireOnceOnly = false;

        LiftParameters &SuggestThreaded(bool s) {
            suggestThreaded = s;
            return *this;
        }
        LiftParameters &DelaySimulator(DelaySimulatorType const &d) {
            delaySimulator = d;
            return *this;
        }
        LiftParameters &FireOnceOnly(bool f) {
            fireOnceOnly = f;
            return *this;
        }
    };

    template <class T, class Env>
    class Key {
    private:
        typename Env::IDType id_;
        T key_;
    public:
        using KeyType = T;
        Key() : id_(), key_() {}
        Key(typename Env::IDType u, T const &k) : id_(u), key_(k) {}
        Key(typename Env::IDType u, T &&k) : id_(u), key_(std::move(k)) {}
        Key(T const &k) : id_(Env::new_id()), key_(k) {}
        Key(T &&k) : id_(Env::new_id()), key_(std::move(k)) {}
        Key(Key const &) = default;
        Key &operator=(Key const &) = default;
        Key(Key &&) = default;
        Key &operator=(Key &&) = default;
        ~Key() = default;
        typename Env::IDType id() const {
            return id_;
        }
        T const &key() const {
            return key_;
        }
        T key() {
            return key_;
        }
        bool operator==(Key<T,Env> const &k) const {
            if (this == &k) {
                return true;
            }
            if (id_ != k.id_) {
                return false;
            }
            return key_ == k.key_;
        }
        bool operator<(Key<T,Env> const &k) const {
            if (this == &k) {
                return false;
            }
            return Env::less_comparison_id(id_, k.id_);
        }
        template <class F>
        auto map(F const &f) const -> Key<decltype(f(this->key_)), Env> {
            return {id_, f(key_)};
        }
    };

    template <class T, class Env>
    class Key<T *, Env> {};  //not allowing the holding of a bare pointer as key
    template <class T, class Env>
    class Key<std::unique_ptr<T>, Env> {};  //not allowing the holding of an unique pointer as key
    template <class T, class Env>
    class Key<Key<T,Env>, Env> {};  //not allowing duplicate keys

    template <class T>
    struct IsKey {
        enum {value=false};
    };
    template <class T, class Env>
    struct IsKey<Key<T, Env>> {
        enum {value=true};
    };
    template <class T>
    inline constexpr bool is_key_v = IsKey<T>::value;

    template <class T, class Env>
    inline std::ostream &operator<<(std::ostream &os, Key<T,Env> const &x) {
        os << "{id=" << Env::id_to_string(x.id()) << ",key=" << x.key() << "}";
        return os;
    }

    template <class K, class D, class Env>
    struct KeyedData {
        using KeyType = K;
        using DataType = D;
        Key<K,Env> key;
        D data;
        template <class F>
        static KeyedData map(F const &f, Key<K,Env> const &k) {
            return {k, f(k.key())};
        }
    };

    template <class T>
    struct IsKeyedData {
        enum {value=false};
    };
    template <class A, class B, class Env>
    struct IsKeyedData<KeyedData<A,B,Env>> {
        enum {value=true};
    };
    /*
    template <class A, class B>
    struct IsKeyedData<std::variant<A,B>> {
	enum {value=(IsKeyedData<A>::value || IsKeyedData<B>::value)};
    };
    */
    template <class A, class... OtherAs>
    struct IsKeyedData<std::variant<A,OtherAs...>> {
	enum {value=(IsKeyedData<A>::value || IsKeyedData<std::variant<OtherAs...>>::value)};
    };
    template <class T>
    inline constexpr bool is_keyed_data_v = IsKeyedData<T>::value;

    template <class A, class B, class Env>
    inline std::ostream &operator<<(std::ostream &os, KeyedData<A,B,Env> const &x) {
        os << "{key=" << x.key << ",data=" << x.data << "}";
        return os;
    }

    namespace withtime_utils {
        template <class A, class Env>
        inline Key<A,Env> keyify(A &&a) {
            return Key<A,Env> {std::move(a)};
        }
        template <class A, class Env, class F>
        inline auto apply(F const &f, Key<A,Env> const &k) -> Key<decltype(f(k.key())),Env> {
            return k.map(f);
        }
        template <class A, class Env, class F>
        inline auto apply(F const &f, Key<A,Env> &&k) -> Key<decltype(f(k.key())),Env> {
            return {k.id(), f(std::move(k.key()))};
        }
        template <class A, class Env, class F>
        inline auto keyedDataFromKey(F const &f, Key<A,Env> const &k) -> KeyedData<A, decltype(f(k.key())), Env> {
            return {k, f(k.key())};
        }
        template <class A, class Env, class F>
        inline auto keyedDataFromKey(F const &f, Key<A,Env> &&k) -> KeyedData<A, decltype(f(k.key())), Env> {
            return {k, f(std::move(k.key()))};
        }
        template <class A, class B, class Env>
        inline Key<B,Env> discardInputPartFromKeyedData(KeyedData<A,B,Env> &&x) {
            return {x.key.id(), std::move(x.data)};
        }
    }

    //Since Key is designed to be one-per-id, there is no reason to check for
    //the version in Key. But we do want to check version for KeyedData per ID.
    template <class A, class VersionType, class DataType, class Env, class CmpType>
    class VersionChecker<KeyedData<A,VersionedData<VersionType,DataType,CmpType>,Env>> {
    private:
        std::unordered_map<
            typename Env::IDType
            , VersionChecker<VersionedData<VersionType,DataType,CmpType>>
            , typename Env::IDHash
        > checkers_;
    public:
        VersionChecker() : checkers_() {}
        bool checkVersion(KeyedData<A,VersionedData<VersionType,DataType,CmpType>,Env> const &t) {
            auto iter = checkers_.find(t.key.id());
            if (iter == checkers_.end()) {
                iter = checkers_.insert({t.key.id(), VersionChecker<VersionedData<VersionType,DataType,CmpType>> {}}).first;
            }
            return iter->second.checkVersion(t.data);
        }
    };
    template <class A, class GroupIDType, class VersionType, class DataType, class Env, class CmpType>
    class VersionChecker<KeyedData<A,GroupedVersionedData<GroupIDType,VersionType,DataType,CmpType>,Env>> {
    private:
        std::unordered_map<
            typename Env::IDType
            , VersionChecker<GroupedVersionedData<GroupIDType,VersionType,DataType,CmpType>>
            , typename Env::IDHash
        > checkers_;
    public:
        VersionChecker() : checkers_() {}
        bool checkVersion(KeyedData<A,GroupedVersionedData<GroupIDType,VersionType,DataType,CmpType>,Env> const &t) {
            auto iter = checkers_.find(t.key.id());
            if (iter == checkers_.end()) {
                iter = checkers_.insert({t.key.id(), VersionChecker<GroupedVersionedData<GroupIDType,VersionType,DataType,CmpType>> {}}).first;
            }
            return iter->second.checkVersion(t.data);
        }
    };

    //The final flag indicates that this is the last update that the 
    //sender will ever send (if an action or importer) or will ever send for the 
    //corresponding request (if an on-order facility). The way to deal with 
    //this depends upon the monad. BasicWithTimeApp will ignore it, RealTimeApp uses
    //it to "unhook" on-order facilities if the facility returns a final-flagged
    //response for a given request, but otherwise does not use it. However, the
    //SinglePassIterationApp will depend on this flag heavily, since the downstream
    //components will stop pulling once it sees this flag from an action, and in fact if
    //an action never sends this flag, the downstream components will never stop pulling and
    //the monad execution will never finish.
    template <class T, class TimePoint = int64_t>
    struct WithTime {
        using TimePointType = TimePoint;
        using ValueType = T;
        TimePoint timePoint;
        T value;
        bool finalFlag;

        template <class F>
        auto map(F const &f) const -> WithTime<decltype(f(this->value))> {
            return {timePoint, f(value), finalFlag};
        }
        template <class A, class F>
        static WithTime apply(F const &f, WithTime<A, TimePoint> const &x) {
            return {x.timePoint, f(x.value), x.finalFlag};
        }
        template <class A, class F>
        static WithTime apply(F const &f, WithTime<A, TimePoint> &&x) {
            return {x.timePoint, f(std::move(x.value)), x.finalFlag};
        }
    };

    template <class T, class TimePoint>
    struct WithTime<T *, TimePoint> {}; //This simply forbids the use of bare pointer in WithTime

    template <class TimePoint, class T>
    inline std::ostream &operator<<(std::ostream &os, WithTime<T, TimePoint> const &x) {
        os << "{timePoint=" << x.timePoint << ",value=" << x.value;
        if (x.finalFlag) {
            os << " [F]";
        }
        os << '}';
        return os;
    }

    template <class TimePoint, class T>
    inline std::ostream &operator<<(std::ostream &os, WithTime<std::unique_ptr<T>, TimePoint> const &x) {
        os << "{timePoint=" << x.timePoint << ",value=uniq_ptr[";
        if (x.value) {
            os << x.value.get() << "," << *(x.value);
        } else {
            os << "null";
        }
        os << "]";
        if (x.finalFlag) {
            os << " [F]";
        }
        os << '}';
        return os;
    }

    namespace withtime_utils {
        template <class A>
        struct ValueCopier {
            inline static A copy(A const &a) {
                return a;
            }
        };
        //only unique_ptr is specialized, shared_ptr is not, because 
        //shared_ptr is copiable.
        template <class A>
        struct ValueCopier<std::unique_ptr<A>> {
            inline static std::unique_ptr<A> copy(std::unique_ptr<A> const &a) {
                if (a) {
                    return std::make_unique<A>(*a);
                } else {
                    return std::unique_ptr<A>();
                }
            }
        };
        template <class A, class B>
        struct ValueCopier<std::tuple<A,B>> {
            inline static std::tuple<A,B> copy(std::tuple<A,B> const &x) {
                return std::tuple<A,B> {ValueCopier<A>::copy(std::get<0>(x)), ValueCopier<B>::copy(std::get<1>(x))};
            }
        };
        template <class A, class Env>
        struct ValueCopier<Key<A,Env>> {
            inline static Key<A,Env> copy(Key<A,Env> const &x) {
                return Key<A,Env> {x.id(), ValueCopier<A>::copy(x.key())};
            }
        };
        template <class A, class B, class Env>
        struct ValueCopier<KeyedData<A,B,Env>> {
            inline static KeyedData<A,B,Env> copy(KeyedData<A,B,Env> const &x) {
                return KeyedData<A,B,Env> {ValueCopier<Key<A,Env>>::copy(x.key), ValueCopier<B>::copy(x.data)};
            }
        };
        template <class VersionType, class DataType, class Cmp>
        struct ValueCopier<VersionedData<VersionType,DataType,Cmp>> {
            inline static VersionedData<VersionType,DataType,Cmp> copy(VersionedData<VersionType,DataType,Cmp> const &x) {
                return VersionedData<VersionType,DataType,Cmp> {
                    ValueCopier<VersionType>::copy(x.version)
                    , ValueCopier<DataType>::copy(x.data)
                };
            }
        };
        template <class GroupIDType, class VersionType, class DataType, class Cmp>
        struct ValueCopier<GroupedVersionedData<GroupIDType,VersionType,DataType,Cmp>> {
            inline static GroupedVersionedData<GroupIDType,VersionType,DataType,Cmp> copy(GroupedVersionedData<GroupIDType,VersionType,DataType,Cmp> const &x) {
                return GroupedVersionedData<GroupIDType,VersionType,DataType,Cmp> {
                    ValueCopier<GroupIDType>::copy(x.groupID)
                    , ValueCopier<VersionType>::copy(x.version)
                    , ValueCopier<DataType>::copy(x.data)
                };
            }
        };

        template <class A>
        inline A makeValueCopy(A const &a) {
            return ValueCopier<A>::copy(a);
        }

        template <class TimePoint, class A>
        inline WithTime<A, TimePoint> makeCopy(WithTime<A, TimePoint> const &a) {
            return WithTime<A, TimePoint> {a.timePoint, ValueCopier<A>::copy(a.value), a.finalFlag};
        }

        #include <tm_kit/infra/WithTimeData_TupleCopy_Piece.hpp>

        template <class TimePoint, class A>
        inline WithTime<std::any, TimePoint> moveToAny(WithTime<A, TimePoint> &&a) {
            if constexpr (std::is_copy_constructible_v<A>) {
                return WithTime<std::any, TimePoint> {std::move(a.timePoint), std::any(std::move(a.value)), a.finalFlag};
            } else {
                return WithTime<std::any, TimePoint> {std::move(a.timePoint), std::any(std::make_shared<A const>(std::move(a.value))), a.finalFlag};
            }
        }
    }

    template <class T, class TimePoint>
    using OptionalWithTime = std::optional<WithTime<T,TimePoint>>;

    template <class T, class Environment, class TimePoint=typename Environment::TimePointType>
    struct TimedDataWithEnvironment {
        using ValueType = T;
        Environment * const environment;
        WithTime<T, TimePoint> timedData;
        TimedDataWithEnvironment(Environment *env, WithTime<T, TimePoint> &&t) : environment(env), timedData(std::move(t)) {}
        TimedDataWithEnvironment(Environment *env, WithTime<T, TimePoint> const &t) : environment(env), timedData(withtime_utils::makeCopy(t)) {}
        TimedDataWithEnvironment(TimedDataWithEnvironment const &d) : environment(d.environment), timedData(withtime_utils::makeCopy(d.timedData)) {}
        TimedDataWithEnvironment &operator=(TimedDataWithEnvironment const &d) {
            if (this != &d) {
                timedData = withtime_utils::makeCopy(d.timedData);
            }
            return *this;
        }
        TimedDataWithEnvironment(TimedDataWithEnvironment &&d) : environment(d.environment), timedData(std::move(d.timedData)) {}
        TimedDataWithEnvironment &operator=(TimedDataWithEnvironment &&d) {
            if (this != &d) {
                timedData = std::move(d.timedData);
            }
            return *this;
        }
        TimedDataWithEnvironment clone() const {
            return {
                environment,
                withtime_utils::makeCopy(timedData)
            };
        }
        template <class F>
        auto map(F const &f, bool preserveTime=false) const -> TimedDataWithEnvironment<decltype(f(this->timedData.value)), Environment, TimePoint> {
            return {
                environment,
                {
                    (preserveTime?timedData.timePoint:environment->resolveTime(timedData.timePoint))
                    , f(timedData.value)
                    , timedData.finalFlag
                }
            };
        }
        template <class F>
        auto mapMove(F const &f, bool preserveTime=false) && -> TimedDataWithEnvironment<decltype(f(std::move(* ((T *) nullptr)))), Environment, TimePoint> {
            return {
                environment,
                {
                    (preserveTime?timedData.timePoint:environment->resolveTime(timedData.timePoint))
                    , f(std::move(timedData.value))
                    , timedData.finalFlag
                }
            };
        }
        TimedDataWithEnvironment &overrideTime(TimePoint const &tp) {
            timedData.timePoint = tp;
            return *this;
        }
        TimedDataWithEnvironment &overrideTime() {
            timedData.timePoint = environment->resolveTime(timedData.timePoint);
            return *this;
        }
        auto moveToAny() && -> TimedDataWithEnvironment<std::any, Environment, TimePoint> {
            return {
                environment,
                withtime_utils::moveToAny<TimePoint,T>(std::move(timedData))
            };
        }
    };

    namespace withtime_utils {
        template <class T, class Environment, class TimePoint>
        inline TimedDataWithEnvironment<T, Environment, TimePoint> pureTimedDataWithEnvironment(Environment *env, T &&t, bool finalFlag = false) {
            return {env, WithTime<T,TimePoint> {env->resolveTime(), std::move(t), finalFlag}};
        }
        template <class T, class Environment, class TimePoint>
        inline TimedDataWithEnvironment<T, Environment, TimePoint> pureTimedDataWithEnvironment(Environment *environment, WithTime<T,TimePoint> &&t, bool preserveTime=false) {
            return {environment, WithTime<T,TimePoint> {preserveTime?t.timePoint:environment->resolveTime(t.timePoint), std::move(t.value), t.finalFlag}};
        }   
        template <class A, class Environment, class TimePoint>
        inline TimedDataWithEnvironment<A, Environment, TimePoint> pureTimedDataWithEnvironment(TimedDataWithEnvironment<A, Environment, TimePoint> &&a, bool preserveTime=false) {
            if (preserveTime) {
                return std::move(a);
            } else {
                return {a.environment, {a.environment->resolveTime(a.timedData.timePoint), std::move(a.timedData.value), a.timedData.finalFlag}};
            } 
        }  
        template <class A, class F, class Environment, class TimePoint>
        inline auto pureTimedDataWithEnvironmentLift(Environment *environment, F &f, WithTime<A,TimePoint> &&a, bool preserveTime=false) -> TimedDataWithEnvironment<decltype(f(std::move(a.value))), Environment, TimePoint> {
            return {environment, {preserveTime?a.timePoint:environment->resolveTime(a.timePoint), std::move(f(std::move(a.value))), a.finalFlag}};
        }
        template <class A, class F, class Environment, class TimePoint>
        inline auto pureTimedDataWithEnvironmentLift(F &f, TimedDataWithEnvironment<A, Environment, TimePoint> &&a, bool preserveTime=false) -> TimedDataWithEnvironment<decltype(f(std::move(a.timedData.value))), Environment, TimePoint> {
            return {a.environment, {preserveTime?a.timedData.timePoint:a.environment->resolveTime(a.timedData.timePoint), std::move(f(std::move(a.timedData.value))), a.timedData.finalFlag}};
        }
        template <class A, class F, class Environment, class TimePoint>
        inline auto pureTimedDataWithEnvironmentLift(Environment *environment, F const &f, WithTime<A,TimePoint> &&a, bool preserveTime=false) -> TimedDataWithEnvironment<decltype(f(std::move(a.value))), Environment, TimePoint> {
            return {environment, {preserveTime?a.timePoint:environment->resolveTime(a.timePoint), std::move(f(std::move(a.value))), a.finalFlag}};
        }
        template <class A, class F, class Environment, class TimePoint>
        inline auto pureTimedDataWithEnvironmentLift(F const &f, TimedDataWithEnvironment<A, Environment, TimePoint> &&a, bool preserveTime=false) -> TimedDataWithEnvironment<decltype(f(std::move(a.timedData.value))), Environment, TimePoint> {
            return {a.environment, {preserveTime?a.timedData.timePoint:a.environment->resolveTime(a.timedData.timePoint), std::move(f(std::move(a.timedData.value))), a.timedData.finalFlag}};
        }
    }

    template <class T, class Environment, class TimePoint=typename Environment::TimePointType>
    using TimedAppData = std::optional<TimedDataWithEnvironment<T, Environment, TimePoint>>;

    template <class A, class B, class Environment, class TimePoint=typename Environment::TimePointType>
    using TimedAppModelKleisli = std::function<TimedAppData<B, Environment, TimePoint>(TimedDataWithEnvironment<A, Environment, TimePoint> &&)>;

    template <class T, class Environment, class TimePoint=typename Environment::TimePointType>
    using TimedAppMultiData = std::optional<TimedDataWithEnvironment<std::vector<T>, Environment, TimePoint>>;

    template <class A, class B, class ContinuationStructure, class Environment, class TimePoint=typename Environment::TimePointType>
    using TimedAppModelContinuation = std::function<
        void(
            TimedDataWithEnvironment<A, Environment, TimePoint> &&
            , ContinuationStructure &
            , std::function<void(TimedDataWithEnvironment<B, Environment, TimePoint> &&)>
        )
    >;

    namespace withtime_utils {
        template <class T, class Environment, class TimePoint=typename Environment::TimePointType>
        inline TimedAppData<T,Environment,TimePoint> clone(TimedAppData<T,Environment,TimePoint> const &data) {
            if (!data) {
                return std::nullopt;
            } else {
                return TimedDataWithEnvironment<T,Environment,TimePoint> {
                    data->environment,
                    makeCopy(data->timedData)
                };
            }
        }
        template <class A, class B, class Environment, class TimePoint=typename Environment::TimePointType>
        inline TimedAppData<B,Environment,TimePoint> timedAppApply(TimedAppModelKleisli<A,B,Environment,TimePoint> const &f, TimedAppData<A,Environment,TimePoint> &&input) 
        {
            if (input) {
                return f(std::move(*input));
            } else {
                return std::nullopt;
            }
        }
    }

    namespace withtime_utils {
        template <class App, class Action>
        struct ActionTypeInfo {
            using InputType = typename App::template GetInputOutputType<Action>::InputType; 
            using OutputType = typename App::template GetInputOutputType<Action>::OutputType; 
        };
        template <class App, class Importer>
        struct ImporterTypeInfo {
            using DataType = typename App::template GetDataType<Importer>::DataType; 
        };
        template <class App, class Exporter>
        struct ExporterTypeInfo {
            using DataType = typename App::template GetDataType<Exporter>::DataType;
        };
        template <class App, class OnOrderFacility>
        struct OnOrderFacilityTypeInfo {
            using InputType = typename App::template GetInputOutputType<OnOrderFacility>::InputType;
            using OutputType = typename App::template GetInputOutputType<OnOrderFacility>::OutputType;
        };
        template <class App, class VIEOnOrderFacility>
        struct VIEOnOrderFacilityTypeInfo {
            using InputType = typename App::template GetInputOutputType<VIEOnOrderFacility>::InputType;
            using OutputType = typename App::template GetInputOutputType<VIEOnOrderFacility>::OutputType;
            using ExtraInputType = typename App::template GetExtraInputOutputType<VIEOnOrderFacility>::ExtraInputType;
            using ExtraOutputType = typename App::template GetExtraInputOutputType<VIEOnOrderFacility>::ExtraOutputType;
        };

        template <class T>
        class IsVariant {
        public:
            static constexpr bool Value = false;
        };
        template <class ...Ts>
        class IsVariant<std::variant<Ts...>> {
        public:
            static constexpr bool Value = true;
        };
    }

    template <class App>
    class AppRunner {
    public:
        using AppType = App;
        using EnvironmentType = typename App::StateType;
        using StateT = typename App::StateType;
        template <class A, class B>
        using Action = typename App::template Action<A,B>;
        template <class A, class B>
        using ActionPtr = std::shared_ptr<Action<A,B>>;
        template <class T>
        using Importer = typename App::template Importer<T>;
        template <class T>
        using ImporterPtr = std::shared_ptr<Importer<T>>;
        template <class T>
        using Exporter = typename App::template Exporter<T>;
        template <class T>
        using ExporterPtr = std::shared_ptr<Exporter<T>>;
        template <class A, class B>
        using OnOrderFacility = typename App::template OnOrderFacility<A,B>;
        template <class A, class B>
        using OnOrderFacilityPtr = std::shared_ptr<OnOrderFacility<A,B>>;
        template <class A, class B, class C>
        using LocalOnOrderFacility = typename App::template LocalOnOrderFacility<A,B,C>;
        template <class A, class B, class C>
        using LocalOnOrderFacilityPtr = std::shared_ptr<LocalOnOrderFacility<A,B,C>>;
        template <class A, class B, class C>
        using OnOrderFacilityWithExternalEffects = typename App::template OnOrderFacilityWithExternalEffects<A,B,C>;
        template <class A, class B, class C>
        using OnOrderFacilityWithExternalEffectsPtr = std::shared_ptr<OnOrderFacilityWithExternalEffects<A,B,C>>;
        template <class A, class B, class C, class D>
        using VIEOnOrderFacility = typename App::template VIEOnOrderFacility<A,B,C,D>;
        template <class A, class B, class C, class D>
        using VIEOnOrderFacilityPtr = std::shared_ptr<VIEOnOrderFacility<A,B,C,D>>;

        template <class T>
        class Source {
        private:
            friend class AppRunner;
            using TheDataTypeOfThisSource = T;
            typename App::template Source<T> mSource;
            std::string producer;
            bool useAltOutput;
            Source(typename App::template Source<T> &&s, std::string const &p) : mSource(std::move(s)), producer(p), useAltOutput(false) {}
            Source(typename App::template Source<T> &&s, std::string const &p, bool ao) : mSource(std::move(s)), producer(p), useAltOutput(ao) {}
        public:
            Source<T> clone() const {
                return {mSource.clone(), producer, useAltOutput};
            }
            //The name is always copied back for safety
            std::string registeredNodeName() const {
                return producer;
            }
        };
        template <class T>
        class Sink {
        private:
            friend class AppRunner;
            using TheDataTypeOfThisSink = T;
            typename App::template Sink<T> mSink;
            std::string consumer;
            int pos;
            Sink(typename App::template Sink<T> &&s, std::string const &c, int p) : mSink(std::move(s)), consumer(c), pos(p) {}
        public:
            //The name is always copied back for safety
            std::string registeredNodeName() const {
                return consumer;
            }
        };
    
    private:
        template <class A>
        class SinkMatch {
        public:
            using TheType = Sink<A>;
        };
        template <class... As>
        class SinkMatch<std::variant<As...>> {
        public:
            using TheType = std::variant<Sink<As>...>;
        };
        template <class A>
        class AnySinkMatch {
        public:
            using TheType = Sink<std::any>;
        };
        template <class... As>
        class AnySinkMatch<std::variant<As...>> {
        public:
            using TheType = std::variant<typename AnySinkMatch<As>::TheType...>;
        };

    public:
        template <class A>
        using Sourceoid = std::function<void(AppRunner &, typename SinkMatch<A>::TheType const &)>;
        using SingleSourceoidForAny = std::function<void(AppRunner &, Sink<std::any> const &)>;
        template <class A>
        using SourceoidForAny = std::function<void(AppRunner &, typename AnySinkMatch<A>::TheType const &)>;
        template <class A>
        using Sinkoid = std::function<void(AppRunner &, Source<A> &&)>;

        template <class A>
        using ConvertibleToSourceoid = std::variant<
            Source<A>
            , Sourceoid<A>
            , std::optional<Source<A>>
        >;
        
        template <class A, class B>
        using FacilitioidConnector =
            std::function<void(AppRunner &, Source<typename App::template Key<A>> &&, std::optional<Sink<typename App::template KeyedData<A,B>>> const &)>;
        template <class A, class B>
        using FacilityWrapper =
            std::optional<std::function<void(AppRunner &, OnOrderFacilityPtr<A,B> const &)>>;
        template <class A, class B, class C>
        using LocalFacilityWrapper =
            std::optional<std::function<void(AppRunner &, LocalOnOrderFacilityPtr<A,B,C> const &)>>;
        template <class A, class B, class C>
        using FacilityWithExternalEffectsWrapper =
            std::optional<std::function<void(AppRunner &, OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &)>>;
        template <class A, class B, class C, class D>
        using VIEFacilityWrapper =
            std::optional<std::function<void(AppRunner &, VIEOnOrderFacilityPtr<A,B,C,D> const &)>>;
        template <class A, class B>
        using FacilitioidConnectorWrapper =
            std::optional<std::function<void(AppRunner &, FacilitioidConnector<A,B> const &)>>;

    private:
        App m_;
        StateT *env_;
        
        struct NamedSourceRep {
            std::optional<std::any> theSource_;
            std::function<void(std::any const &)> theSourceoid_;
        };

        struct ActionCheckData {
            std::string name;
            int paramCount;
            std::vector<std::unordered_map<std::string,std::set<std::tuple<int,int,std::string>>>> paramConnectedFrom;
            std::map<std::tuple<std::string,std::string>,std::unordered_set<int>> outputConnectedTo;            
            bool isImporter = false;
            bool isExporter = false;
            bool hasAltOutput = false;
            bool isFacility = false;
            std::unordered_map<std::string,std::unordered_set<int>> altOutputConnectedTo;

            ActionCheckData() : name(), paramCount(0), paramConnectedFrom(), outputConnectedTo(), isImporter(false), isExporter(false), hasAltOutput(false), altOutputConnectedTo()
            {}

            ActionCheckData(std::string const &n, int c) : name(n), paramCount(c), paramConnectedFrom(), outputConnectedTo(), isImporter(false), isExporter(false), hasAltOutput(false), altOutputConnectedTo()
            {
                paramConnectedFrom.resize(c);
            }

            template <class A, class B>
            static ActionCheckData create(Action<A,B> *f, std::string const &n)
            {
                if constexpr (!withtime_utils::IsVariant<A>::Value) {
                    ActionCheckData d {n, 1};
                    d.isImporter = false;
                    d.isExporter = false;
                    return d;
                } else {
                    ActionCheckData d {n, std::variant_size_v<A>};
                    d.isImporter = false;
                    d.isExporter = false;
                    return d;
                }
            }

            template <class A>
            static ActionCheckData createForImporter(Importer<A> *f, std::string const &n)
            {
                ActionCheckData d {n, 0};
                d.isImporter = true;
                d.isExporter = false;
                return d;
            }
            template <class A>
            static ActionCheckData createForExporter(Exporter<A> *f, std::string const &n)
            {
                ActionCheckData d {n, 1};
                d.isImporter = false;
                d.isExporter = true;
                return d;
            }
            template <class A, class B>
            static ActionCheckData createForOnOrderFacility(OnOrderFacility<A,B> *f, std::string const &n)
            {
                ActionCheckData d {n, 1};
                d.isImporter = false;
                d.isExporter = false;
                d.isFacility = true;
                return d;
            }
            template <class A, class B, class C>
            static ActionCheckData createForLocalOnOrderFacility(LocalOnOrderFacility<A,B,C> *f, std::string const &n)
            {
                ActionCheckData d {n, 2};
                d.isImporter = false;
                d.isExporter = false;
                d.isFacility = true;
                return d;
            }
            template <class A, class B, class C>
            static ActionCheckData createForOnOrderFacilityWithExternalEffects(OnOrderFacilityWithExternalEffects<A,B,C> *f, std::string const &n)
            {
                ActionCheckData d {n, 1};
                d.isImporter = false;
                d.isExporter = false;
                d.hasAltOutput = true;
                d.isFacility = true;
                return d;
            }
            template <class A, class B, class C, class D>
            static ActionCheckData createForVIEOnOrderFacility(VIEOnOrderFacility<A,B,C,D> *f, std::string const &n)
            {
                ActionCheckData d {n, 2};
                d.isImporter = false;
                d.isExporter = false;
                d.hasAltOutput = true;
                d.isFacility = true;
                return d;
            }
        };
        using NameMap = std::unordered_map<void *, ActionCheckData>;
        NameMap nameMap_;
        std::unordered_map<std::string, void *> reverseLookup_;
        int nextColorCode_;
        std::list<std::shared_ptr<void>> components_;
        std::unordered_set<std::shared_ptr<void>> otherPreservedPtrs_;
        std::map<std::tuple<std::string,std::string>, std::string> stateSharingRecords_;
        struct MaxConnectivityLimits {
            size_t outputLimit = std::numeric_limits<size_t>::max();
            size_t inputLimits[MAX_FAN_IN_BRANCH_COUNT] = {
                std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
                , std::numeric_limits<size_t>::max()
            };
        };
        std::unordered_map<std::string, MaxConnectivityLimits> maxConnectivityLimits_;
        struct ActionProperties {
            bool threaded;
            bool oneTimeOnly;
        };
        std::unordered_map<std::string, ActionProperties> actionPropertiesMap_;
        bool restrictFacilityOutputConnectionByDefault_;
        std::unordered_map<void *, std::string> underlyingPointerNameMap_;
        std::unordered_map<std::string, std::vector<
            IControllableNode<StateT> *
        >> controllableNodeMap_;
        std::unordered_map<std::string, std::vector<
            IObservableNode<StateT> *
        >> observableNodeMap_;
        mutable std::recursive_mutex mutex_;

        void registerUnderlyingNames_(std::string const &name, std::unordered_set<void *> ptrs) {
            for (auto p : ptrs) {
                if (p == nullptr) {
                    continue;
                }
                if (underlyingPointerNameMap_.find(p) != underlyingPointerNameMap_.end()) {
                    throw AppRunnerException(
                        "Attempt to re-use an underlying pointer already associated with name '"+underlyingPointerNameMap_[p]+"' to new name '"+name+"'"
                    );
                }
                underlyingPointerNameMap_.insert({p, name});
            }
        }
        void registerControllableNodes_(std::string const &name, std::vector<IControllableNode<StateT> *> &&nodes) {
            if (!nodes.empty()) {
                controllableNodeMap_.insert({name, std::move(nodes)});
            }
        }
        void registerObservableNodes_(std::string const &name, std::vector<IObservableNode<StateT> *> &&nodes) {
            if (!nodes.empty()) {
                observableNodeMap_.insert({name, std::move(nodes)});
            }
        }

        template <class T>
        static void addSourceoidForAny(Source<T> &&s, std::list<SingleSourceoidForAny> &l) {
            auto s1 = sourceAsSourceoidForAny(std::move(s));
            l.push_back(s1);
        }
        template <std::size_t N, std::size_t K, class... As>
        static void addSourceoidForAny_multi(Source<std::variant<As...>> &&s, std::list<SingleSourceoidForAny> &l) {
            if constexpr (K < N) {
                auto s1 = subSourceoidForAny<K>(s.clone());
                l.push_back(s1);
                addSourceoidForAny_multi<N,K+1,As...>(std::move(s), l);
            }
        }
        template <class... As>
        static void addSourceoidForAny(Source<std::variant<As...>> &&s, std::list<SingleSourceoidForAny> &l) {
            addSourceoidForAny_multi<sizeof...(As), 0, As...>(std::move(s), l);
        }
        template <class T>
        static void addTypedSourceoid(Source<T> &&s, std::unordered_map<std::type_index, std::list<std::any>> &m) {
            auto s1 = sourceAsSourceoid(std::move(s));
            m[std::type_index(typeid(T))].push_back(std::any {s1});
        }
        template <std::size_t N, std::size_t K, class... As>
        static void addTypedSourceoid_multi(Source<std::variant<As...>> &&s, std::unordered_map<std::type_index, std::list<std::any>> &m) {
            if constexpr (K < N) {
                auto s1 = subSourceoid<K>(s.clone());
                using T = std::variant_alternative_t<K, std::variant<As...>>;
                m[std::type_index(typeid(T))].push_back(std::any {s1});
                addTypedSourceoid_multi<N,K+1,As...>(std::move(s), m);
            }
        }
        template <class... As>
        static void addTypedSourceoid(Source<std::variant<As...>> &&s, std::unordered_map<std::type_index, std::list<std::any>> &m) {
            addTypedSourceoid_multi<sizeof...(As), 0, As...>(std::move(s), m);
        }
        template <class A>
        static void addTypedKeySource(Source<Key<A,StateT>> &&s, std::map<std::type_index,std::list<std::any>> &m) {
            m[std::type_index(typeid(A))].push_back(std::any {std::move(s)});
        }
        template <class A, class B>
        static void addTypedKeyedDataSink(Sink<KeyedData<A,B,StateT>> const &s, std::map<std::tuple<std::type_index,std::type_index>,std::list<std::any>> &m) {
            m[{std::type_index(typeid(A)), std::type_index(typeid(B))}].push_back(std::any {s});
        }
        template <std::size_t N, std::size_t K, class A>
        void addNamedSource_multi(std::string const &name, Source<A> &&s);
        template <class A>
        void addNamedSource_single(std::string const &name, std::optional<Source<A>> &&s1, Sourceoid<A> const &s2) {
            namedSources_[name].push_back({(s1?(std::any {std::move(*s1)}):std::nullopt), [this,name,s2](std::any const &sink) {
                try {
                    s2(*this, std::any_cast<Sink<A> const &>(sink));
                } catch (std::bad_any_cast const &) {
                    throw AppRunnerException(
                        name+" is being connected to a wrong-typed destination through dynamic connection"
                    );
                }
            }});
        }
        template <class A>
        void addNamedSource(std::string const &name, Source<A> &&s) {
            if constexpr (withtime_utils::IsVariant<A>::Value) {
                addNamedSource_multi<std::variant_size_v<A>, 0, A>(name, s.clone());
                namedSources_[name][0].theSource_ = {std::any {s.clone()}};
            } else {
                addNamedSource_single<A>(name, std::optional<Source<A>> {s.clone()}, sourceAsSourceoid<A>(s.clone()));
            }
        }
        template <class A>
        void addNamedSink(std::string const &name, Sink<A> const &s) {
            namedSinks_[name].push_back(std::any {s});
        }
        template <class A, class B>
        void addNamedFacility(std::string const &name, FacilitioidConnector<A,B> const &s) {
            namedFacilities_[name] = [this,name,s](std::any const &source, std::optional<std::any> const &sink) {
                try {
                    if (sink) {
                        s(*this, std::any_cast<Source<Key<A,StateT>> const &>(source).clone(), std::any_cast<Sink<KeyedData<A,B,StateT>> const &>(*sink));
                    } else {
                        s(*this, std::any_cast<Source<Key<A,StateT>> const &>(source).clone(), std::nullopt);
                    }
                } catch (std::bad_any_cast const &) {
                    throw AppRunnerException(
                        name+" is being connected to wrong-typed source and/or sink through dynamic connection"
                    );
                }
            };
        }

        template <class T>
        void addTypedSink(Sink<T> const &s, std::unordered_map<std::type_index, std::list<std::any>> &m) {
            m[std::type_index(typeid(T))].push_back(std::any {s});
        }
        template <std::size_t N, std::size_t K, class A, class B>
        void addTypedSink_action_multi(ActionPtr<A, B> const &f, std::unordered_map<std::type_index, std::list<std::any>> &m);
        template <class A, class B>
        void addTypedSink_action(ActionPtr<A,B> const &f, std::unordered_map<std::type_index, std::list<std::any>> &m);
        template <std::size_t N, std::size_t K, class A, class B>
        void addTypedKeyedDataSink_action_multi(ActionPtr<A, B> const &f, std::map<std::tuple<std::type_index,std::type_index>,std::list<std::any>> &m);
        template <class A, class B>
        void addTypedKeyedDataSink_action(ActionPtr<A,B> const &f, std::map<std::tuple<std::type_index,std::type_index>,std::list<std::any>> &m);
        template <std::size_t N, std::size_t K, class A, class B>
        void addNamedSink_action_multi(std::string const &name, ActionPtr<A,B> const &f);
        template <class A, class B>
        void addNamedSink_action(std::string const &name, ActionPtr<A,B> const &f);
        
        template <class A, class B>
        void registerAction_(ActionPtr<A,B> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register an action with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for an action"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template create<A,B>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            ActionProperties prop;
            prop.threaded = AppType::template actionIsThreaded<A,B>(f);
            prop.oneTimeOnly = AppType::template actionIsOneTimeOnly<A,B>(f);
            actionPropertiesMap_.insert({name, prop});

            addSourceoidForAny(actionAsSource(f), sourceoidsForAny_);
            addTypedSourceoid(actionAsSource(f), typedSourceoids_);
            if constexpr (IsKey<B>::value) {
                addTypedKeySource(actionAsSource(f), typedKeySources_);
            }
            addTypedSink_action<A,B>(f, typedSinks_);
            addTypedKeyedDataSink_action<A,B>(f, typedKeyedDataSinks_);

            addNamedSource<B>(name, actionAsSource(f));
            addNamedSink_action<A,B>(name, f);
        }
        template <class A>
        void registerImporter_(ImporterPtr<A> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register an importer with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for an importer"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template createForImporter<A>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));

            addSourceoidForAny(importItem(f), sourceoidsForAny_);
            addSourceoidForAny(importItem(f), sourceoidsForAnyFromImporter_);
            addTypedSourceoid(importItem(f), typedSourceoids_);
            addTypedSourceoid(importItem(f), typedSourceoidsFromImporter_);
            if constexpr (IsKey<A>::value) {
                addTypedKeySource(importItem(f), typedKeySources_);
            }
            addNamedSource<A>(name, importItem(f));
        }
        template <class A>
        void registerExporter_(ExporterPtr<A> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register an exporter with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for an exporter"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template createForExporter<A>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            addTypedSink(exporterAsSink(f), typedSinks_);
            if constexpr (IsKeyedData<A>::value) {
                addTypedKeyedDataSink(exporterAsSink(f), typedKeyedDataSinks_);
            }
            addNamedSink<A>(name, exporterAsSink(f));
        }
        template <class A, class B>
        void registerOnOrderFacility_(OnOrderFacilityPtr<A,B> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register an on-order facility with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for an on-order facility"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template createForOnOrderFacility<A,B>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            if (restrictFacilityOutputConnectionByDefault_) {
                setMaxOutputConnectivity_(name, 1);
            }
            addNamedFacility<A,B>(name, facilityConnector(f));
        }
        template <class A, class B, class C>
        void registerLocalOnOrderFacility_(LocalOnOrderFacilityPtr<A,B,C> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register a local on-order facility with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for a local on-order facility"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template createForLocalOnOrderFacility<A,B,C>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            if (restrictFacilityOutputConnectionByDefault_) {
                setMaxOutputConnectivity_(name, 1);
            }
            addTypedSink(localFacilityAsSink(f), typedSinks_);
            if constexpr (IsKeyedData<C>::value) {
                addTypedKeyedDataSink(localFacilityAsSink(f), typedKeyedDataSinks_);
            }
            addNamedFacility<A,B>(name, facilityConnector(f));
            addNamedSink<C>(name, localFacilityAsSink(f));
        }
        template <class A, class B, class C>
        void registerOnOrderFacilityWithExternalEffects_(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register an on-order facility with external effects with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for an on-order facility with external effects"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template createForOnOrderFacilityWithExternalEffects<A,B,C>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            if (restrictFacilityOutputConnectionByDefault_) {
                setMaxOutputConnectivity_(name, 1);
            }

            addSourceoidForAny(facilityWithExternalEffectsAsSource(f), sourceoidsForAny_);
            addSourceoidForAny(facilityWithExternalEffectsAsSource(f), sourceoidsForAnyFromImporter_);
            addTypedSourceoid(facilityWithExternalEffectsAsSource(f), typedSourceoids_);
            addTypedSourceoid(facilityWithExternalEffectsAsSource(f), typedSourceoidsFromImporter_);
            if constexpr (IsKey<C>::value) {
                addTypedKeySource(facilityWithExternalEffectsAsSource(f), typedKeySources_);
            }
            addNamedFacility<A,B>(name, facilityConnector(f));
            addNamedSource<C>(name, facilityWithExternalEffectsAsSource(f));
        }
        template <class A, class B, class C, class D>
        void registerVIEOnOrderFacility_(VIEOnOrderFacilityPtr<A,B,C,D> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
            registerUnderlyingNames_(name, f->getUnderlyingPointers());
            registerControllableNodes_(name, f->getControllableNodes());
            registerObservableNodes_(name, f->getObservableNodes());
            void *p = (void *) (f.get());
            auto nameIter = nameMap_.find(p);
            if (nameIter != nameMap_.end()) {
                if (nameIter->second.name != name) {
                    throw AppRunnerException(
                        "Attempt to re-register a VIE on-order facility with name '"+name+"', it has been registered as '"+nameIter->second.name+"'"
                    );
                } else {
                    env_->log(LogLevel::Warning,
                        "Trying to re-register name '" + name + "' for a VIE on-order facility"
                    );
                    return;
                }
            }
            nameMap_.insert({p, ActionCheckData::template createForVIEOnOrderFacility<A,B,C,D>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            if (restrictFacilityOutputConnectionByDefault_) {
                setMaxOutputConnectivity_(name, 1);
            }
            addSourceoidForAny(vieFacilityAsSource(f), sourceoidsForAny_);
            addSourceoidForAny(vieFacilityAsSource(f), sourceoidsForAnyFromImporter_);
            addTypedSourceoid(vieFacilityAsSource(f), typedSourceoids_);
            addTypedSourceoid(vieFacilityAsSource(f), typedSourceoidsFromImporter_);
            if constexpr (IsKey<D>::value) {
                addTypedKeySource(vieFacilityAsSource(f), typedKeySources_);
            }
            addTypedSink(vieFacilityAsSink(f), typedSinks_);
            if constexpr (IsKeyedData<C>::value) {
                addTypedKeyedDataSink(vieFacilityAsSink(f), typedKeyedDataSinks_);
            }
            addNamedFacility<A,B>(name, facilityConnector(f));
            addNamedSource<D>(name, vieFacilityAsSource(f));
            addNamedSink<C>(name, vieFacilityAsSink(f));
        }
        std::string checkName_(void *p) {
            auto iter = nameMap_.find(p);
            if (iter == nameMap_.end()) {
                throw AppRunnerException(
                    "Attempt to work on an unregistered item"
                );
            }
            return iter->second.name;
        }
        bool connectAndCheck_(int pos, void *p, std::string const &producer, int colorCode, bool useAltOutput, std::string const &edgeLabel="") {
            auto iter = nameMap_.find(p);
            if (iter == nameMap_.end()) {
                throw AppRunnerException(
                    "Attempt to execute an unregistered action"
                );
            }
            if (producer == "") {
                throw AppRunnerException(
                    "Attempt to connect pos "+std::to_string(pos+1)+" of '"+iter->second.name+"' from empty producer"
                );
            }
            
            auto reverseIter = reverseLookup_.find(producer);
            if (reverseIter == reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to connect pos "+std::to_string(pos+1)+" of "+iter->second.name+" from non-existent producer '"+producer+"'"
                );
            }
            auto sourceIter = nameMap_.find(reverseIter->second);
            if (sourceIter == nameMap_.end()) {
                throw AppRunnerException(
                    "Attempt to connect pos "+std::to_string(pos+1)+" of "+iter->second.name+" from non-registered producer '"+producer+"'"
                );
            }

            if (useAltOutput && !(sourceIter->second.hasAltOutput)) {
                throw AppRunnerException(
                    "Attempt to connect alternate output of '"+sourceIter->second.name+"' to '"+iter->second.name+"' but there is no such alternate output"
                );
            }
            int outputLegCode = (useAltOutput?1:(sourceIter->second.hasAltOutput?0:-1));

            bool isReconnect = false;
            auto connIter = iter->second.paramConnectedFrom[pos].find(producer);
            if (connIter != iter->second.paramConnectedFrom[pos].end()) {
                if (colorCode != 0) {
                    for (auto const &item : connIter->second) {
                        if (std::get<1>(item) == outputLegCode && std::get<0>(item) != 0) {
                            throw AppRunnerException(
                                "Attempt to re-connect an output of '"+producer+"' to '"+iter->second.name+"' as a facility order, this will cause double-callback issues"
                            );
                        }
                    }
                }
                if (connIter->second.find({colorCode, outputLegCode, edgeLabel}) != connIter->second.end()) {
                    env_->log(LogLevel::Warning,
                        "Reconnecting an output of '" + producer + "' to '" + iter->second.name + "'"
                    );
                    isReconnect = true;
                } else {
                    connIter->second.insert({colorCode, outputLegCode, edgeLabel});
                }
            } else {
                iter->second.paramConnectedFrom[pos].insert({producer, {{colorCode, outputLegCode, edgeLabel}}});
            }
            
            if (useAltOutput) {
                auto sourceOutputConnIter = sourceIter->second.altOutputConnectedTo.find(iter->second.name);
                if (sourceOutputConnIter != sourceIter->second.altOutputConnectedTo.end()) {
                    if (sourceOutputConnIter->second.find(colorCode) != sourceOutputConnIter->second.end()) {
                        isReconnect = true;
                    } else {
                        sourceOutputConnIter->second.insert(colorCode);
                    }
                } else {
                    sourceIter->second.altOutputConnectedTo.insert({iter->second.name,{colorCode}});   
                }
            } else {
                auto sourceOutputConnIter = sourceIter->second.outputConnectedTo.find({iter->second.name, edgeLabel});
                if (sourceOutputConnIter != sourceIter->second.outputConnectedTo.end()) {
                    if (sourceOutputConnIter->second.find(colorCode) != sourceOutputConnIter->second.end()) {
                        isReconnect = true;
                    } else {
                        sourceOutputConnIter->second.insert(colorCode);
                    }
                } else {
                    sourceIter->second.outputConnectedTo.insert({{iter->second.name, edgeLabel},{colorCode}});
                }
            }

            usedSinks_.insert({iter->second.name, pos});

            return !isReconnect;
        }
        void setMaxOutputConnectivity_(std::string const &name, size_t maxOutputConnectivity) {
            auto iter = maxConnectivityLimits_.find(name);
            if (iter == maxConnectivityLimits_.end()) {
                iter = maxConnectivityLimits_.insert({name, MaxConnectivityLimits()}).first;
            }
            iter->second.outputLimit = maxOutputConnectivity;
        }
        void setMaxInputConnectivity_(std::string const &name, int pos, size_t maxInputConnectivity) {
            if (pos < 0 || pos >= MAX_FAN_IN_BRANCH_COUNT) {
                return;
            }
            auto iter = maxConnectivityLimits_.find(name);
            if (iter == maxConnectivityLimits_.end()) {
                iter = maxConnectivityLimits_.insert({name, MaxConnectivityLimits()}).first;
            }
            iter->second.inputLimits[pos] = maxInputConnectivity;
        }
        int nextColorCode() {
            int res = nextColorCode_+1;
            nextColorCode_ = (nextColorCode_+1)%10;
            return res;
        }

        std::mutex touchupMutex_;
        std::list<std::function<void(AppRunner &)>> touchups_;
        bool touchupDone_;

        std::list<SingleSourceoidForAny> sourceoidsForAny_;
        std::list<SingleSourceoidForAny> sourceoidsForAnyFromImporter_;
        std::unordered_map<std::type_index, std::list<std::any>> typedSourceoids_, typedSourceoidsFromImporter_;
        std::unordered_map<std::type_index, std::list<std::any>> typedSinks_;
        std::map<std::type_index, std::list<std::any>> typedKeySources_;
        std::map<std::tuple<std::type_index, std::type_index>, std::list<std::any>> typedKeyedDataSinks_;
        std::set<std::tuple<std::string, int>> usedSinks_;

        std::unordered_map<std::string, std::vector<NamedSourceRep>> namedSources_;
        std::unordered_map<std::string, std::vector<std::any>> namedSinks_;
        std::unordered_map<std::string, std::function<void(std::any const &, std::optional<std::any> const &)>> namedFacilities_;

    public:
        class AppRunnerException : public std::runtime_error {
        public:
            AppRunnerException(std::string const &s) : std::runtime_error(s) {}
        };
        AppRunner(StateT *env) : m_(), env_(env), nameMap_(), reverseLookup_(), nextColorCode_(0), components_(), otherPreservedPtrs_(), stateSharingRecords_(), maxConnectivityLimits_(), actionPropertiesMap_(), restrictFacilityOutputConnectionByDefault_(true), underlyingPointerNameMap_(), mutex_(), touchupMutex_(), touchups_(), touchupDone_(false), sourceoidsForAny_(), sourceoidsForAnyFromImporter_(), typedSourceoids_(), typedSourceoidsFromImporter_(), typedSinks_(), usedSinks_(), typedKeySources_(), typedKeyedDataSinks_(), namedSources_(), namedSinks_(), namedFacilities_() {}
        template <class T>
        AppRunner(T t, StateT *env) : m_(t), env_(env), nameMap_(), reverseLookup_(), nextColorCode_(0), components_(), otherPreservedPtrs_(), stateSharingRecords_(), maxConnectivityLimits_(), actionPropertiesMap_(), restrictFacilityOutputConnectionByDefault_(true), underlyingPointerNameMap_(), mutex_(), touchupMutex_(), touchups_(), touchupDone_(false), sourceoidsForAny_(), sourceoidsForAnyFromImporter_(), typedSourceoids_(), typedSourceoidsFromImporter_(), typedSinks_(), usedSinks_(), typedKeySources_(), typedKeyedDataSinks_(), namedSources_(), namedSinks_(), namedFacilities_() {}
        AppRunner(AppRunner const &) = delete;
        AppRunner &operator=(AppRunner const &) = delete;
        AppRunner(AppRunner &&) = default;
        AppRunner &operator=(AppRunner &&) = default;
        ~AppRunner() noexcept {
        }
        StateT *environment() const {
            return env_;
        }

        template <class Action>
        void registerAction(std::shared_ptr<Action> const &f, std::string const &name) {
            registerAction_<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(f, name);
        }
        template <class Action>
        void registerAction(std::string const &name, std::shared_ptr<Action> const &f) {
            registerAction_<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(f, name);
        }
        template <class Imp>
        void registerImporter(std::shared_ptr<Imp> const &f, std::string const &name) {
            registerImporter_<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(f, name);
        }
        template <class Imp>
        void registerImporter(std::string const &name, std::shared_ptr<Imp> const &f) {
            registerImporter_<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(f, name);
        }
        template <class Exp>
        void registerExporter(std::shared_ptr<Exp> const &f, std::string const &name) {
            registerExporter_<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(f, name);
        }
        template <class Exp>
        void registerExporter(std::string const &name, std::shared_ptr<Exp> const &f) {
            registerExporter_<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(f, name);
        }
        template <class Fac>
        void registerOnOrderFacility(std::shared_ptr<Fac> const &f, std::string const &name) {
            registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(f, name);
        }
        template <class Fac>
        void registerOnOrderFacility(std::string const &name, std::shared_ptr<Fac> const &f) {
            registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(f, name);
        }
        template <class Fac>
        void registerLocalOnOrderFacility(std::shared_ptr<Fac> const &f, std::string const &name) {
            registerLocalOnOrderFacility_<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType>(f, name);
        }
        template <class Fac>
        void registerLocalOnOrderFacility(std::string const &name, std::shared_ptr<Fac> const &f) {
            registerLocalOnOrderFacility_<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType>(f, name);
        }
        template <class Fac>
        void registerOnOrderFacilityWithExternalEffects(std::shared_ptr<Fac> const &f, std::string const &name) {
            registerOnOrderFacilityWithExternalEffects_<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType>(f, name);
        }
        template <class Fac>
        void registerOnOrderFacilityWithExternalEffects(std::string const &name, std::shared_ptr<Fac> const &f) {
            registerOnOrderFacilityWithExternalEffects_<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType>(f, name);
        }
        template <class Fac>
        void registerVIEOnOrderFacility(std::shared_ptr<Fac> const &f, std::string const &name) {
            registerVIEOnOrderFacility_<
                typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(f, name);
        }
        template <class Fac>
        void registerVIEOnOrderFacility(std::string const &name, std::shared_ptr<Fac> const &f) {
            registerVIEOnOrderFacility_<
                typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(f, name);
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType> importerAsSource(std::string const &name, std::shared_ptr<Imp> const &importer) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerImporter_<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(importer, name);
            }
            return { m_.template importerAsSource<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(env_, *importer), name };
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType> importerAsSource(std::shared_ptr<Imp> const &importer) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) importer.get());
            }
            return { m_.template importerAsSource<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(env_, *importer), name };
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType> importItem(std::string const &name, std::shared_ptr<Imp> const &importer) {
            return importerAsSource<Imp>(name, importer);
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType> importItem(std::shared_ptr<Imp> const &importer) {
            return importerAsSource<Imp>(importer);
        }
        template <class Action>
        Source<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType> actionAsSource(std::string const &name, std::shared_ptr<Action> const &action) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerAction_<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(action, name);
            }
            return { m_.template actionAsSource<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(env_, *action), name };
        }
        template <class Action>
        Source<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType> actionAsSource(std::shared_ptr<Action> const &action) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) action.get());
            }
            return { m_.template actionAsSource<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(env_, *action), name };
        }
        template <class Action, typename = std::enable_if_t<!withtime_utils::IsVariant<typename withtime_utils::ActionTypeInfo<App,Action>::InputType>::Value>>
        Source<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType> execute(std::string const &name, std::shared_ptr<Action> const &f, Source<typename withtime_utils::ActionTypeInfo<App,Action>::InputType> &&x) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerAction_<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(f, name);
                if (!connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
                    return { m_.template actionAsSource<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(env_, *f), name };
                }
            }
            return { m_.template execute<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(*f, std::move(x.mSource)), name };
        }
        template <class Action, typename = std::enable_if_t<!withtime_utils::IsVariant<typename withtime_utils::ActionTypeInfo<App,Action>::InputType>::Value>>
        Source<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType> execute(std::shared_ptr<Action> const &f, Source<typename withtime_utils::ActionTypeInfo<App,Action>::InputType> &&x) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                if (!connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
                    return { m_.template actionAsSource<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(env_, *f), name };
                }
                name = nameMap_[(void *) f.get()].name;
            }
            return { m_.template execute<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(*f, std::move(x.mSource)), name };
        }
        template <
            class Action
            , class A
            , std::enable_if_t<
                std::is_same_v<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, std::any>
                && 
                !withtime_utils::IsVariant<A>::Value
            >
        >
        Source<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType> executeAny(std::string const &name, std::shared_ptr<Action> const &f, Source<A> &&x) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerAction_<std::any, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(f, name);
                if (!connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
                    return { m_.template actionAsSource<std::any, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(env_, *f), name };
                }
            }
            return { m_.template executeAny<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(*f, std::move(x.mSource)), name };
        }
        template <
            class Action
            , class A
            , std::enable_if_t<
                std::is_same_v<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, std::any>
                && 
                !withtime_utils::IsVariant<A>::Value
            >
        >        
        Source<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType> executeAny(std::shared_ptr<Action> const &f, Source<A> &&x) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                if (!connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
                    return { m_.template actionAsSource<std::any, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(env_, *f), name };
                }
                name = nameMap_[(void *) f.get()].name;
            }
            return { m_.template executeAny<typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(*f, std::move(x.mSource)), name };
        }

        #include <tm_kit/infra/WithTimeData_VariantExecute_Piece.hpp>

        template <class Exp>
        void exportItem(std::string const &name, std::shared_ptr<Exp> const &f, Source<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType> &&x) {
            connect(std::move(x), exporterAsSink<Exp>(name, f));
        }
        template <class Exp>
        void exportItem(std::shared_ptr<Exp> const &f, Source<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType> &&x) {
            connect(std::move(x), exporterAsSink<Exp>(f));
        }
        template <
            class Exp
            , class T
            , std::enable_if_t<
                std::is_same_v<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType, std::any>
                && 
                !withtime_utils::IsVariant<T>::Value
            >
        >
        void exportAnyItem(std::string const &name, std::shared_ptr<Exp> const &f, Source<T> &&x) {
            connectAny(std::move(x), exporterAsSink<Exp>(name, f));
        }
        template <
            class Exp
            , class T
            , std::enable_if_t<
                std::is_same_v<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType, std::any>
                && 
                !withtime_utils::IsVariant<T>::Value
            >
        >
        void exportItem(std::shared_ptr<Exp> const &f, Source<T> &&x) {
            connectAny(std::move(x), exporterAsSink<Exp>(f));
        }
        template <class Fac>
        void feedItemToLocalFacility(std::string const &name, std::shared_ptr<Fac> const &f, Source<typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType> &&x) {
            connect(std::move(x), localFacilityAsSink<Fac>(name, f));
        }
        template <class Fac>
        void feedItemToLocalFacility(std::shared_ptr<Fac> const &f, Source<typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType> &&x) {
            connect(std::move(x), localFacilityAsSink<Fac>(f));
        }
        
        template <class Exp>
        Sink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType> exporterAsSink(std::string const &name, std::shared_ptr<Exp> const &exporter) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerExporter_<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(exporter, name);
            }
            return { m_.template exporterAsSink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(*exporter), name, 0 };
        }
        template <class Exp>
        Sink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType> exporterAsSink(std::shared_ptr<Exp> const &exporter) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) exporter.get());
            }
            return { m_.template exporterAsSink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(*exporter), name, 0 };
        }
        template <class Action, typename = std::enable_if_t<!withtime_utils::IsVariant<typename withtime_utils::ActionTypeInfo<App,Action>::InputType>::Value>>
        Sink<typename withtime_utils::ActionTypeInfo<App,Action>::InputType> actionAsSink(std::string const &name, std::shared_ptr<Action> const &action) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerAction_<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(action, name);
            }
            return { m_.template actionAsSink<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(*action), name, 0 };
        }
        template <class Action, typename = std::enable_if_t<!withtime_utils::IsVariant<typename withtime_utils::ActionTypeInfo<App,Action>::InputType>::Value>>
        Sink<typename withtime_utils::ActionTypeInfo<App,Action>::InputType> actionAsSink(std::shared_ptr<Action> const &action) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) action.get());
            }
            return { m_.template actionAsSink<typename withtime_utils::ActionTypeInfo<App,Action>::InputType, typename withtime_utils::ActionTypeInfo<App,Action>::OutputType>(*action), name, 0 };
        }
        template <class Fac>
        Sink<typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType> localFacilityAsSink(std::string const &name, std::shared_ptr<Fac> const &facility) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerLocalOnOrderFacility_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType>(facility, name);
            }
            return { m_.template localFacilityAsSink<
                            typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                            , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                            , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType>(*facility)
                     , name, 1 };
        }
        template <class Fac>
        Sink<typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType> localFacilityAsSink(std::shared_ptr<Fac> const &facility) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) facility.get());
            }
            return { m_.template localFacilityAsSink<
                            typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                            , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                            , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType>(*facility)
                     , name, 1 };
        }
        template <class Fac>
        Sink<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType> vieFacilityAsSink(std::string const &name, std::shared_ptr<Fac> const &facility) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerVIEOnOrderFacility_<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(facility, name);
            }
            return { m_.template vieFacilityAsSink<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(*facility)
                     , name, 1 };
        }
        template <class Fac>
        Sink<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType> vieFacilityAsSink(std::shared_ptr<Fac> const &facility) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) facility.get());
            }
            return { m_.template vieFacilityAsSink<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(*facility)
                     , name, 1 };
        }
        template <class Fac>
        Source<typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType> facilityWithExternalEffectsAsSource(std::string const &name, std::shared_ptr<Fac> const &facility) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerOnOrderFacilityWithExternalEffects_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType>(facility, name);
            }
            return { m_.template facilityWithExternalEffectsAsSource<
                            typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                            , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                            , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType>(*facility)
                     , name, true };
        }
        template <class Fac>
        Source<typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType> facilityWithExternalEffectsAsSource(std::shared_ptr<Fac> const &facility) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) facility.get());
            }
            return { m_.template facilityWithExternalEffectsAsSource<
                            typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                            , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                            , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType>(*facility)
                     , name, true };
        }
        template <class Fac>
        Source<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType> vieFacilityAsSource(std::string const &name, std::shared_ptr<Fac> const &facility) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerVIEOnOrderFacility_<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(facility, name);
            }
            return { m_.template vieFacilityAsSource<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(*facility)
                     , name, true };
        }
        template <class Fac>
        Source<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType> vieFacilityAsSource(std::shared_ptr<Fac> const &facility) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) facility.get());
            }
            return { m_.template vieFacilityAsSource<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType>(*facility)
                     , name, true };
        }

        #include <tm_kit/infra/WithTimeData_VariantSink_Piece.hpp>

        template <class Fac>
        void placeOrderWithFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(f, name);
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithFacility<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) f.get());
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithFacility<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(f, name);
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithFacilityAndForget<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(std::move(input.mSource), *f);
        }
        template <class Fac>
        void placeOrderWithFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                checkName_((void *) f.get());
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithFacilityAndForget<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType>(std::move(input.mSource), *f);
        }

        template <class Fac>
        void placeOrderWithLocalFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerLocalOnOrderFacility_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType
                    >(f, name);
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithLocalFacility<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithLocalFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) f.get());
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithLocalFacility<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithLocalFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerLocalOnOrderFacility_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType
                    >(f, name);
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithLocalFacilityAndForget<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f);
        }
        template <class Fac>
        void placeOrderWithLocalFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                checkName_((void *) f.get());
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithLocalFacilityAndForget<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f);
        }

        template <class Fac>
        void placeOrderWithFacilityWithExternalEffects(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerOnOrderFacilityWithExternalEffects_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType
                    >(f, name);
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithFacilityWithExternalEffects<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithFacilityWithExternalEffects(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) f.get());
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithFacilityWithExternalEffects<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithFacilityWithExternalEffectsAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerOnOrderFacilityWithExternalEffects_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType
                    >(f, name);
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithFacilityWithExternalEffectsAndForget<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f);
        }
        template <class Fac>
        void placeOrderWithFacilityWithExternalEffectsAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                checkName_((void *) f.get());
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithFacilityWithExternalEffectsAndForget<
                typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::ImporterTypeInfo<App,Fac>::DataType
                >(std::move(input.mSource), *f);
        }

        template <class Fac>
        void placeOrderWithVIEFacility(
            Source<Key<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerVIEOnOrderFacility_<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType
                    >(f, name);
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithVIEFacility<
                typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithVIEFacility(
            Source<Key<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType, typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType, StateT>> const &sink) {
            std::string name;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                name = checkName_((void *) f.get());
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw AppRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color, false);
            }
            m_.template placeOrderWithVIEFacility<
                typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithVIEFacilityAndForget(
            Source<Key<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                registerVIEOnOrderFacility_<
                    typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                    , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType
                    >(f, name);
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithVIEFacilityAndForget<
                typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType
                >(std::move(input.mSource), *f);
        }
        template <class Fac>
        void placeOrderWithVIEFacilityAndForget(
            Source<Key<typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::recursive_mutex> _(mutex_);
                checkName_((void *) f.get());
                connectAndCheck_(0, (void *) f.get(), input.producer, color, input.useAltOutput);
            }
            m_.template placeOrderWithVIEFacilityAndForget<
                typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::InputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::OutputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraInputType
                , typename withtime_utils::VIEOnOrderFacilityTypeInfo<App,Fac>::ExtraOutputType
                >(std::move(input.mSource), *f);
        }

        template <class T>
        void connect(Source<T> &&source, Sink<T> const &sink) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto iter = reverseLookup_.find(sink.consumer);
            if (iter == reverseLookup_.end()) {
                throw AppRunnerException(
                    "No such sink '"+sink.consumer+"'"
                );
            }
            if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput)) {
                return;
            }
            m_.connect(std::move(source.mSource), sink.mSink);
        }
        template <class T, typename=std::enable_if_t<!withtime_utils::IsVariant<T>::Value>>
        void connectAny(Source<T> &&source, Sink<std::any> const &sink) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto iter = reverseLookup_.find(sink.consumer);
            if (iter == reverseLookup_.end()) {
                throw AppRunnerException(
                    "No such sink '"+sink.consumer+"'"
                );
            }
            if (!connectAndCheck_(sink.pos, iter->second, source.producer, 0, source.useAltOutput)) {
                return;
            }
            m_.connectAny(std::move(source.mSource), sink.mSink);
        }

        #include <tm_kit/infra/WithTimeData_ConnectN_Piece.hpp>

        template <class T>
        void setMaxOutputConnectivity(Source<T> &&source, size_t maxOutputConnectivity) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            setMaxOutputConnectivity_(source.producer, maxOutputConnectivity);
        }
        void setMaxOutputConnectivity(std::string const &source, size_t maxOutputConnectivity) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            setMaxOutputConnectivity_(source, maxOutputConnectivity);
        }
        template <class F>
        void setMaxOutputConnectivity(std::shared_ptr<F> const &source, size_t maxOutputConnectivity) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            std::string name = checkName_((void *) source.get());
            setMaxOutputConnectivity_(name, maxOutputConnectivity);
        }
        template <class T>
        void setMaxInputConnectivity(Sink<T> const &sink, size_t maxInputConnectivity) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            setMaxInputConnectivity_(sink.consumer, sink.pos, maxInputConnectivity);
        }
        void setMaxInputConnectivity(std::string const &sink, int pos, size_t maxInputConnectivity) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            setMaxInputConnectivity_(sink, pos, maxInputConnectivity);
        }
        template <class F>
        void setMaxInputConnectivity(std::shared_ptr<F> const &sink, int pos, size_t maxInputConnectivity) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            std::string name = checkName_((void *) sink.get());
            setMaxInputConnectivity_(name, pos, maxInputConnectivity);
        }
        void restrictFacilityOutputConnectionByDefault() {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            restrictFacilityOutputConnectionByDefault_ = true;
        }
        void dontRestrictFacilityOutputConnectionByDefault() {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            restrictFacilityOutputConnectionByDefault_ = false;
        }

        template <class F>
        std::string getRegisteredName(std::shared_ptr<F> const &p) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            return checkName_((void *) p.get());
        }

        void addTouchup(std::function<void(AppRunner &)> const &touchup) {
            std::lock_guard<std::mutex> _(touchupMutex_);
            if (touchupDone_) {
                throw AppRunnerException("Cannot add touch up after touch up phase is complete");
            }
            touchups_.push_back(touchup);
        }

        void connectAnySinkToAllNodes(Sink<std::any> const &sink) {
            addTouchup([sink](AppRunner &x) {
                std::list<SingleSourceoidForAny> l;
                {
                    std::lock_guard<std::recursive_mutex> _(x.mutex_);
                    l = x.sourceoidsForAny_;
                }
                for (auto const &f : l) {
                    f(x, sink);
                }
            });
        }
        void connectAnySinkToAllImporters(Sink<std::any> const &sink) {
            addTouchup([sink](AppRunner &x) {
                std::list<SingleSourceoidForAny> l;
                {
                    std::lock_guard<std::recursive_mutex> _(x.mutex_);
                    l = x.sourceoidsForAnyFromImporter_;
                }
                for (auto const &f : l) {
                    f(x, sink);
                }
            });
        }
        template <class T>
        void connectTypedSinkToAllNodes(Sink<T> const &sink) {
            addTouchup([sink](AppRunner &x) {
                std::list<std::any> l;
                {
                    std::lock_guard<std::recursive_mutex> _(x.mutex_);
                    auto iter = x.typedSourceoids_.find(std::type_index(typeid(T)));
                    if (iter != x.typedSourceoids_.end()) {
                        l = iter->second;
                    }
                }
                for (auto const &f : l) {
                    auto s = std::any_cast<Sourceoid<T>>(f);
                    s(x, sink);
                }
            });
        }
        template <class T>
        void connectTypedSinkToAllImporters(Sink<T> const &sink) {
            addTouchup([sink](AppRunner &x) {
                std::list<std::any> l;
                {
                    std::lock_guard<std::recursive_mutex> _(x.mutex_);
                    auto iter = x.typedSourceoidsFromImporter_.find(std::type_index(typeid(T)));
                    if (iter != x.typedSourceoidsFromImporter_.end()) {
                        l = iter->second;
                    }
                }
                for (auto const &f : l) {
                    auto s = std::any_cast<Sourceoid<T>>(f);
                    s(x, sink);
                }
            });
        }
    private:
        template <class T>
        void connectSingleSourceoidToAllSinks_internal(Sourceoid<T> const &source, bool unusedOnly) {
            std::list<std::any> l;
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                auto iter = typedSinks_.find(std::type_index(typeid(T)));
                if (iter != typedSinks_.end()) {
                    l = iter->second;
                }
            }
            for (auto const &s : l) {
                auto s1 = std::any_cast<Sink<T>>(s);
                if (!unusedOnly || usedSinks_.find({s1.consumer, s1.pos}) == usedSinks_.end()) {
                    source(*this, s1);
                }
            }
        }
        template <std::size_t N, std::size_t K, class TheVariant>
        void connectMultiSourceoidToAllSinks_internal_helper(Sourceoid<TheVariant> const &source, bool unusedOnly) {
            if constexpr (K < N) {
                std::list<std::any> l;
                {
                    std::lock_guard<std::recursive_mutex> _(mutex_);
                    auto iter = typedSinks_.find(std::type_index(typeid(std::variant_alternative_t<K,TheVariant>)));
                    if (iter != typedSinks_.end()) {
                        l = iter->second;
                    }
                }
                for (auto const &s : l) {
                    auto s1 = std::any_cast<Sink<std::variant_alternative_t<K,TheVariant>>>(s);
                    if (!unusedOnly || usedSinks_.find({s1.consumer, s1.pos}) == usedSinks_.end()) {
                        source(*this, typename SinkMatch<TheVariant>::TheType {std::in_place_index<K>, s1});
                    }
                }
                connectMultiSourceoidToAllSinks_internal_helper<N,K+1,TheVariant>(source, unusedOnly);
            }            
        }
        template <class TheVariant>
        void connectMultiSourceoidToAllSinks_internal(Sourceoid<TheVariant> const &source, bool unusedOnly) {
            connectMultiSourceoidToAllSinks_internal_helper<std::variant_size_v<TheVariant>,0,TheVariant>(source, unusedOnly);
        }

        template <class A>
        void connectSourceoidToAllSinks_internal(Sourceoid<A> const &source, bool unusedOnly) {
            addTouchup([source,unusedOnly](AppRunner &x) {
                if constexpr (withtime_utils::IsVariant<A>::Value) {
                    x.connectMultiSourceoidToAllSinks_internal<A>(source, unusedOnly);
                } else {
                    x.connectSingleSourceoidToAllSinks_internal<A>(source, unusedOnly);
                }
            });
        }
    public:
        template <class A>
        void connectSourceoidToAllSinks(Sourceoid<A> const &source) {
            connectSourceoidToAllSinks_internal<A>(source, false);
        }
        template <class A>
        void connectSourceoidToAllUnusedSinks(Sourceoid<A> const &source) {
            connectSourceoidToAllSinks_internal<A>(source, true);
        }
        template <class A>
        void connectSourceToAllSinks(Source<A> &&source) {
            connectSourceoidToAllSinks_internal<A>(sourceAsSourceoid<A>(std::move(source)), false);
        }
        template <class A>
        void connectSourceToAllUnusedSinks(Source<A> &&source) {
            connectSourceoidToAllSinks_internal<A>(sourceAsSourceoid<A>(std::move(source)), true);
        }

        template <class A, class B>
        void connectFacilitioidToAllPossiblePlaces(FacilitioidConnector<A,B> const &f) {
            addTouchup([f](AppRunner &x) {
                auto sourceIter = x.typedKeySources_.find(std::type_index(typeid(A)));
                if (sourceIter == x.typedKeySources_.end()) {
                    return;
                }
                auto sinkIter = x.typedKeyedDataSinks_.find({std::type_index(typeid(A)), std::type_index(typeid(B))});
                if (sinkIter == x.typedKeyedDataSinks_.end()) {
                    return;
                }
                for (auto &source : sourceIter->second) {
                    for (auto &sink : sinkIter->second) {
                        f(x, std::any_cast<Source<Key<A,StateT>> &>(source).clone(), std::any_cast<Sink<KeyedData<A,B,StateT>> &>(sink));
                    }
                }
            });
        }
    
    private:
        void doTouchups() {
            std::lock_guard<std::mutex> _(touchupMutex_);
            if (!touchupDone_) {
                if (!touchups_.empty()) {
                    for (auto &t : touchups_) {
                        t(*this);
                    }
                    touchups_.clear();
                }
                touchupDone_ = true;
            }
        }

    public:
        void writeGraphVizDescription(std::ostream &os, std::string const &graphName) {
            doTouchups();
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                writeGraphVizDescription_internal(os, graphName);
            }
        }
    private:
        void writeGraphVizDescription_internal(std::ostream &os, std::string const &graphName) const {
            os << "digraph " << graphName << "{\n";
            int counter = 1;
            int subclusterCounter = 1;
            std::unordered_map<std::string, int> m;
            std::unordered_map<std::string, int> subclusterCountMap;
            for (auto const &item : nameMap_) {
                m[item.second.name] = counter;
                int clusterLevel = 0;
                std::string nodeLabel = item.second.name;
                if (item.second.name.find('/') != std::string::npos) {
                    std::vector<std::string> parts;
                    std::istringstream iss(item.second.name);
                    std::string s;
                    while (std::getline(iss, s, '/')) {
                        if (s != "") {
                            parts.push_back(s);
                        }
                    }
                    nodeLabel = parts.back();
                    parts.pop_back();
                    s = "";
                    for (auto ii=0; ii<parts.size(); ++ii) {
                        if (ii != 0) {
                            s += "/";
                        }
                        s += parts[ii];
                        auto iter = subclusterCountMap.find(s);
                        if (iter == subclusterCountMap.end()) {
                            int currentSubcluster = subclusterCounter;
                            ++subclusterCounter;
                            subclusterCountMap[s] = currentSubcluster;
                            os << "\tsubgraph cluster_" << currentSubcluster << "{\n";
                            os << "\tlabel=\"" << parts[ii] << "\";\n";
                            os << "\tcolor=blue;\n";
                        } else {
                            os << "\tsubgraph cluster_" << iter->second << "{\n";
                        }
                    }
                    clusterLevel = parts.size();
                }
                if (controllableNodeMap_.find(item.second.name) != controllableNodeMap_.end()) {
                    nodeLabel = nodeLabel+" :C";
                }
                if (observableNodeMap_.find(item.second.name) != observableNodeMap_.end()) {
                    nodeLabel = nodeLabel+" :O";
                }
                os << "\t action" << counter << " [";
                std::string htmlNodeShape = "plain";
                if (!item.second.isFacility) {
                    //actionPropertiesMap is not applicable for facilities
                    auto propIter = actionPropertiesMap_.find(item.second.name);
                    if (propIter != actionPropertiesMap_.end()) {
                        if (propIter->second.oneTimeOnly) {
                            htmlNodeShape = "box";
                        }
                    }
                }
                if (item.second.hasAltOutput) {
                    if (item.second.paramCount > 1) {
                        os << "label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\"><TR>";
                        int colSpan = 1;
                        if (item.second.paramCount %2 == 1) {
                            colSpan = 2;
                        }
                        for (int ii=0; ii<item.second.paramCount; ++ii) {
                            os << "<TD PORT=\"arg" << ii << "\" COLSPAN=\"" << colSpan << "\">arg" << ii << "</TD>";
                        }
                        if (item.second.paramCount %2 == 1) {
                            colSpan = item.second.paramCount*2;
                        } else {
                            colSpan = item.second.paramCount;
                        }
                        os << "</TR><TR><TD COLSPAN=\"" << colSpan << "\">" << std::regex_replace(nodeLabel, std::regex(">"), "\\>") << "</TD></TR>";
                        colSpan /= 2;
                        os << "<TR><TD PORT=\"out0\" COLSPAN=\"" << colSpan << "\">out0</TD><TD PORT=\"out1\" COLSPAN=\"" << colSpan << "\">out1</TD></TR>";
                        os << "</TABLE>>,shape=" << htmlNodeShape;
                    } else {
                        os << "label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">";
                        os << "<TR><TD COLSPAN=\"2\">" << std::regex_replace(nodeLabel, std::regex(">"), "\\>") << "</TD></TR>";
                        os << "<TR><TD PORT=\"out0\">out0</TD><TD PORT=\"out1\">out1</TD></TR>";
                        os << "</TABLE>>,shape=" << htmlNodeShape;
                    }
                } else if (item.second.paramCount > 1) {
                    os << "label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\"><TR>";
                    for (int ii=0; ii<item.second.paramCount; ++ii) {
                        os << "<TD PORT=\"arg" << ii << "\">arg" << ii << "</TD>";
                    }
                    os << "</TR><TR><TD COLSPAN=\"" << item.second.paramCount << "\">" << std::regex_replace(nodeLabel, std::regex(">"), "\\>") << "</TD></TR>";
                    os << "</TABLE>>,shape=" << htmlNodeShape;
                } else if (item.second.isImporter || item.second.isExporter) {
                    os << "label=\"" << nodeLabel << "\",shape=oval";                   
                } else {
                    os << "label=\"" << nodeLabel << "\",shape=box";
                }
                std::vector<std::string> styleStrings;
                if (item.second.isFacility) {
                    os << ",color=darkgreen";
                } else {
                    //actionPropertiesMap is not applicable for facilities
                    auto propIter = actionPropertiesMap_.find(item.second.name);
                    if (propIter != actionPropertiesMap_.end()) {
                        if (propIter->second.threaded) {
                            os << ",color=red";
                        }
                        if (propIter->second.oneTimeOnly) {
                            styleStrings.push_back("dotted");
                        }
                    }
                }
                if (!styleStrings.empty()) {
                    os << ",style=\"";
                    for (size_t ii=0; ii<styleStrings.size(); ++ii) {
                        if (ii != 0) {
                            os << ',';
                        }
                        os << styleStrings[ii];
                    }
                    os << "\"";
                }
                os << "];\n";
                ++counter;
                if (clusterLevel > 0) {
                    for (auto ii=0; ii<clusterLevel; ++ii) {
                        os << "\t}\n";
                    }
                }
            }
            for (auto const &item : nameMap_) { 
                for (int ii=0; ii<item.second.paramCount; ++ii) {
                    for (auto const &src : item.second.paramConnectedFrom[ii]) {
                        auto iter1 = reverseLookup_.find(src.first);
                        auto iter2 = nameMap_.find(iter1->second);
                        for (auto const &connector : src.second) {
                            auto color = std::get<0>(connector);
                            auto srcConnector = std::get<1>(connector);
                            bool isExternal = 
                                iter2->second.isImporter || item.second.isExporter
                                || (iter2->second.isFacility && srcConnector == 1)
                                || (item.second.isFacility && ii == 1);
                            std::string srcConnectorStr;
                            if (srcConnector < 0) {
                                srcConnectorStr = "";
                            } else {
                                srcConnectorStr = std::string(":out")+std::to_string(srcConnector);
                            }
                            if (item.second.paramCount > 1) {
                                os << "\t action" << m[src.first] << srcConnectorStr << ":s -> action" << m[item.second.name] << ":arg" << ii << ":n";
                            } else {
                                os << "\t action" << m[src.first] << srcConnectorStr << ":s -> action" << m[item.second.name] << ":n";
                            }   
                            bool hasStyles = false;
                            if (color != 0 && isExternal) {
                                os << " [style=dotted,colorscheme=spectral11,color=" << color;
                                hasStyles = true;
                            } else if (isExternal) {
                                os << " [style=dotted";
                                hasStyles = true;
                            } else if (color != 0) {
                                os << " [style=dashed,colorscheme=spectral11,color=" << color;
                                hasStyles = true;
                            }
                            std::string edgeLabel = std::get<2>(connector);
                            bool srcIsStopped = false;
                            auto observableIter = observableNodeMap_.find(iter2->second.name);
                            if (observableIter != observableNodeMap_.end()) {
                                std::vector<std::string> status;
                                for (auto const *oneObservable : observableIter->second) {
                                    auto oneStatus = oneObservable->observe(env_);
                                    std::copy(oneStatus.begin(), oneStatus.end(), std::back_inserter(status));
                                }
                                int edgeNum = 0;
                                if (edgeLabel != "") {
                                    try {
                                        edgeNum = std::stoi(edgeLabel.substr(0, edgeLabel.find('/')));
                                    } catch (...) {
                                        edgeNum = 0;
                                    }
                                }
                                auto edgeStoppedStr = std::to_string(edgeNum)+" stopped";
                                for (auto const &statusItem : status) {
                                    if (statusItem == "stopped") {
                                        srcIsStopped = true;
                                        break;
                                    } else if (statusItem == edgeStoppedStr) {
                                        srcIsStopped = true;
                                        break;
                                    }
                                }
                            }
                            if (edgeLabel != "") {
                                if (hasStyles) {
                                    os << ",arrowtail=" << (srcIsStopped?"odot,dir=both":"none") << ",label=\"" << edgeLabel << "\"];\n";
                                } else {
                                    os << " [arrowtail=" << (srcIsStopped?"odot,dir=both":"none") << ",label=\"" << edgeLabel << "\"];\n";
                                }  
                            } else {
                                if (hasStyles) {
                                    os << ",arrowtail=" << (srcIsStopped?"odot,dir=both":"none") << "];\n";
                                } else {
                                    os << " [arrowtail=" << (srcIsStopped?"odot,dir=both":"none") << "];\n";
                                }         
                            }
                        }  
                    }                                                        
                }
                ++counter;
            }
            std::unordered_map<std::string, int> stateNames;
            int stateNameCounter = 0;
            for (auto const &sharing : stateSharingRecords_) {
                if (sharing.second != "") {
                    auto stateNameIter = stateNames.find(sharing.second);
                    int stateIdx;
                    if (stateNameIter == stateNames.end()) {
                        stateIdx = ++stateNameCounter;
                        stateNames.insert({sharing.second, stateIdx});
                    } else {
                        stateIdx = stateNameIter->second;
                    }
                }
            }
            for (auto const &item : stateNames) {
                int clusterLevel = 0;
                std::string nodeLabel = item.first;
                if (item.first.find('/') != std::string::npos) {
                    std::vector<std::string> parts;
                    std::istringstream iss(item.first);
                    std::string s;
                    while (std::getline(iss, s, '/')) {
                        if (s != "") {
                            parts.push_back(s);
                        }
                    }
                    nodeLabel = parts.back();
                    parts.pop_back();
                    s = "";
                    for (auto ii=0; ii<parts.size(); ++ii) {
                        if (ii != 0) {
                            s += "/";
                        }
                        s += parts[ii];
                        auto iter = subclusterCountMap.find(s);
                        if (iter == subclusterCountMap.end()) {
                            int currentSubcluster = subclusterCounter;
                            ++subclusterCounter;
                            subclusterCountMap[s] = currentSubcluster;
                            os << "\tsubgraph cluster_" << currentSubcluster << "{\n";
                            os << "\tlabel=\"" << parts[ii] << "\";\n";
                            os << "\tcolor=blue;\n";
                        } else {
                            os << "\tsubgraph cluster_" << iter->second << "{\n";
                        }
                    }
                    clusterLevel = parts.size();
                }
                os << "\t state" << item.second << " [label=\"" << nodeLabel << "\",shape=house];\n";
                if (clusterLevel > 0) {
                    for (auto ii=0; ii<clusterLevel; ++ii) {
                        os << "\t}\n";
                    }
                }
            }
            std::set<std::tuple<int,int>> nameStateSet, nameNameSet;
            for (auto const &sharing : stateSharingRecords_) {
                if (sharing.second != "") {
                    auto stateIdx = stateNames[sharing.second];
                    auto name1Idx = m[std::get<0>(sharing.first)];
                    auto name2Idx = m[std::get<1>(sharing.first)];
                    auto nameState = std::make_tuple(name1Idx, stateIdx);
                    if (nameStateSet.find(nameState) == nameStateSet.end()) {
                        os << "\t action" << name1Idx << " -> state" << stateIdx << " [dir=none,style=bold];\n";
                        nameStateSet.insert(nameState);
                    }
                    nameState = std::make_tuple(name2Idx, stateIdx);
                    if (nameStateSet.find(nameState) == nameStateSet.end()) {
                        os << "\t action" << name2Idx << " -> state" << stateIdx << " [dir=none,style=bold];\n";
                        nameStateSet.insert(nameState);
                    }
                } else {
                    auto name1Idx = m[std::get<0>(sharing.first)];
                    auto name2Idx = m[std::get<1>(sharing.first)];
                    auto nameName1 = std::make_tuple(name1Idx, name2Idx);
                    auto nameName2 = std::make_tuple(name2Idx, name1Idx);
                    if (nameNameSet.find(nameName1) == nameNameSet.end() && nameNameSet.find(nameName2) == nameNameSet.end()) {
                        os << "\t action" << name1Idx << " -> action" << name2Idx << " [dir=none,style=bold];\n";
                        nameNameSet.insert(nameName1);
                        nameNameSet.insert(nameName2);
                    }
                }
            }
            os << "}\n";
        }
    private:
        std::optional<std::string> isCyclic(
            typename NameMap::value_type const &item, 
            std::unordered_set<std::string> &visited,
            std::unordered_set<std::string> &recStack,
            bool includeFacility) 
        {
            if (visited.find(item.second.name) == visited.end()) {
                visited.insert(item.second.name);
                recStack.insert(item.second.name);
                for (auto const &outputTo : item.second.outputConnectedTo) {
                    if (!includeFacility && outputTo.second.find(0) == outputTo.second.end()) {
                        continue;
                    }
                    auto iter = reverseLookup_.find(std::get<0>(outputTo.first));
                    auto iter2 = nameMap_.find(iter->second);
                    if (visited.find(std::get<0>(outputTo.first)) == visited.end()
                        && isCyclic(*iter2, visited, recStack, includeFacility)
                    ) {
                        return item.second.name;
                    } else if (recStack.find(std::get<0>(outputTo.first)) != recStack.end()) {
                        return item.second.name;
                    }
                }
                if (item.second.hasAltOutput) {
                    for (auto const &outputTo : item.second.altOutputConnectedTo) {
                        if (!includeFacility && outputTo.second.find(0) == outputTo.second.end()) {
                            continue;
                        }
                        auto iter = reverseLookup_.find(outputTo.first);
                        auto iter2 = nameMap_.find(iter->second);
                        if (visited.find(outputTo.first) == visited.end()
                            && isCyclic(*iter2, visited, recStack, includeFacility)
                        ) {
                            return item.second.name;
                        } else if (recStack.find(outputTo.first) != recStack.end()) {
                            return item.second.name;
                        }
                    }
                }
            }
            recStack.erase(item.second.name);
            return std::nullopt;
        }
        std::optional<std::string> detectCycle(bool includeFacility) {
            std::unordered_set<std::string> visited;
            std::unordered_set<std::string> recStack;
            for (auto const &item : nameMap_) {
                auto r = isCyclic(item, visited, recStack, includeFacility);
                if (r) {
                    return r;
                }
            }
            return std::nullopt;
        }
    private:
        void finalizeBegin() {
            doTouchups();
            {
                std::lock_guard<std::recursive_mutex> _(mutex_);
                for (auto const &item : nameMap_) {
                    auto limitIter = maxConnectivityLimits_.find(item.second.name);
                    for (int ii=0; ii<item.second.paramCount; ++ii) {
                        if (item.second.paramConnectedFrom[ii].empty()) {
                            throw AppRunnerException(
                                "Component '"+item.second.name+"''s parameter in position "+std::to_string(ii)+" has not been connected!"
                            );
                        }
                        if (limitIter != maxConnectivityLimits_.end()) {
                            if (item.second.paramConnectedFrom[ii].size() > limitIter->second.inputLimits[ii]) {
                                throw AppRunnerException(
                                    "Component '"+item.second.name+"''s parameter in position "+std::to_string(ii)
                                    +" has "+std::to_string(item.second.paramConnectedFrom[ii].size())+" incoming connections, more than the allowed limit of "
                                    + std::to_string(limitIter->second.inputLimits[ii])+"!"
                                );
                            }
                        }
                    }
                    if (limitIter != maxConnectivityLimits_.end()) {
                        for (int ii=item.second.paramCount; ii<MAX_FAN_IN_BRANCH_COUNT; ++ii) {
                            if (limitIter->second.inputLimits[ii] < std::numeric_limits<size_t>::max()) {
                                throw AppRunnerException(
                                    "You tried to limit the max input connectivity to Component '"+item.second.name+"''s parameter in position "+std::to_string(ii)
                                    +", but it only supports "+std::to_string(item.second.paramCount)+" inputs!"
                                );
                            }
                        }
                    }
                    if (item.second.outputConnectedTo.empty() && !item.second.isExporter && !item.second.isFacility) {
                        throw AppRunnerException(
                            "Component '"+item.second.name+"''s output has not been connected!"
                        );
                    }
                    if (item.second.hasAltOutput && item.second.altOutputConnectedTo.empty()) {
                        //Please note that for the only case with alt output (OnOrderFacilityWithExternalEffects)
                        //the alt output actually has to be connected, while the main output (from facility)
                        //does not have to be connected
                        throw AppRunnerException(
                            "Component '"+item.second.name+"''s alternate output has not been connected!"
                        );
                    }
                    if (limitIter != maxConnectivityLimits_.end()) {
                        if (item.second.isExporter && limitIter->second.outputLimit < std::numeric_limits<size_t>::max()) {
                            throw AppRunnerException(
                                "You tried to limit the max output connectivity of Component '"+item.second.name+"'"
                                +", but it is an exporter and has no output!"
                            );
                        }
                    }
                    if (limitIter != maxConnectivityLimits_.end()) {
                        if (item.second.outputConnectedTo.size() > limitIter->second.outputLimit) {
                            throw AppRunnerException(
                                "Component '"+item.second.name+"''s output"
                                +" has "+std::to_string(item.second.outputConnectedTo.size())+" outgoing connections, more than the allowed limit of "
                                + std::to_string(limitIter->second.outputLimit)+"!"
                            );
                        }
                    }
                }
                auto cycleRet = detectCycle(false);
                if (cycleRet) {
                    throw AppRunnerException(
                        "There is a circle starting from '"+(*cycleRet)+"'"
                    );
                }
                cycleRet = detectCycle(true);
                if (cycleRet) {
                    if constexpr (App::CannotHaveLoopEvenWithFacilities) {
                        throw AppRunnerException(
                            "There is a circle involving on-order facility starting from '"+(*cycleRet)+"', this monad prohibits this kind of loop too"
                        );
                    } else {
                        env_->log(LogLevel::Warning,
                            "There is a circle involving on-order facility starting from '" + (*cycleRet) + "'"
                        );
                    }
                }
            }
            if constexpr (std::is_convertible_v<StateT *, TraceNodesComponent *>) {
                env_->setNodeNameMap(underlyingPointerNameMap_);
            }
        }
    public:
        void finalize() {
            finalizeBegin();
            m_.finalize()(env_);
        }
        std::function<bool()> finalizeForInterleaving() {
            finalizeBegin();
            auto f = m_.finalizeForInterleaving()(env_);
            return [f,this]() -> bool {
                return f(env_);
            };
        }

        template <class T>
        void preservePointer(std::shared_ptr<T> const &ptr) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            otherPreservedPtrs_.insert(std::static_pointer_cast<void>(ptr));
        }

        template <class A, class B>
        void markStateSharing(std::shared_ptr<A> const &item1, std::shared_ptr<B> const &item2, std::string const &sharedStateName="") {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto name1 = checkName_((void *) item1.get());
            auto name2 = checkName_((void *) item2.get());
            if (name1 == name2) {
                throw AppRunnerException(
                    "Cannot mark a state sharing between two identical components"
                );
            }
            auto smallerName = std::min(name1, name2);
            auto biggerName = std::max(name1, name2);
            stateSharingRecords_[{smallerName, biggerName}] = sharedStateName;
        }

        template <class A, class B>
        static FacilitioidConnector<A,B> facilityConnector(OnOrderFacilityPtr<A,B> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&source, std::optional<Sink<typename App::template KeyedData<A,B>>> const &sink) {
                if (sink) {
                    r.placeOrderWithFacility(std::move(source), facility, *sink);
                } else {
                    r.placeOrderWithFacilityAndForget(std::move(source), facility);
                }
            };
        }
        template <class A, class B, class C>
        static FacilitioidConnector<A,B> localFacilityConnector(LocalOnOrderFacilityPtr<A,B,C> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&source, std::optional<Sink<typename App::template KeyedData<A,B>>> const &sink) {
                if (sink) {
                    r.placeOrderWithLocalFacility(std::move(source), facility, *sink);
                } else {
                    r.placeOrderWithLocalFacilityAndForget(std::move(source), facility);
                }
            };
        }
        template <class A, class B, class C>
        static FacilitioidConnector<A,B> facilityWithExternalEffectsConnector(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&source, std::optional<Sink<typename App::template KeyedData<A,B>>> const &sink) {
                if (sink) {
                    r.placeOrderWithFacilityWithExternalEffects(std::move(source), facility, *sink);
                } else {
                    r.placeOrderWithFacilityWithExternalEffectsAndForget(std::move(source), facility);
                }
            };
        }
        template <class A, class B, class C, class D>
        static FacilitioidConnector<A,B> vieFacilityConnector(VIEOnOrderFacilityPtr<A,B,C,D> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&source, std::optional<Sink<typename App::template KeyedData<A,B>>> const &sink) {
                if (sink) {
                    r.placeOrderWithVIEFacility(std::move(source), facility, *sink);
                } else {
                    r.placeOrderWithVIEFacilityAndForget(std::move(source), facility);
                }
            };
        }
        template <class A, class B, class C>
        static FacilitioidConnector<A,B> facilityConnector(LocalOnOrderFacilityPtr<A,B,C> const &facility) {
            return localFacilityConnector<A,B,C>(facility);
        }
        template <class A, class B, class C>
        static FacilitioidConnector<A,B> facilityConnector(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &facility) {
            return facilityWithExternalEffectsConnector<A,B,C>(facility);
        }
        template <class A, class B, class C, class D>
        static FacilitioidConnector<A,B> facilityConnector(VIEOnOrderFacilityPtr<A,B,C,D> const &facility) {
            return vieFacilityConnector<A,B,C,D>(facility);
        }
    private:
        template <std::size_t Idx, std::size_t Total, class VariantSourceType, class VariantSinkType>
        static void connect_variant_source_to_variant_sink_internal_(
            AppRunner &r 
            , VariantSourceType &&src
            , VariantSinkType const &sink
        );
        template <std::size_t Idx, std::size_t Total, class VariantSourceType, class VariantSinkType>
        static void connect_variant_source_to_variant_any_sink_internal_(
            AppRunner &r 
            , VariantSourceType &&src
            , VariantSinkType const &sink
        );
    public:
        template <class A>
        static Sourceoid<A> sourceAsSourceoid(Source<A> &&src) {
            if constexpr (withtime_utils::IsVariant<A>::Value) {
                return [src1=src.clone()](AppRunner &r, typename SinkMatch<A>::TheType const &sink) {
                    connect_variant_source_to_variant_sink_internal_<0, std::variant_size_v<A>, Source<A>, typename SinkMatch<A>::TheType>(r, src1.clone(), sink);
                };
            } else {
                return [src1=src.clone()](AppRunner &r, Sink<A> const &sink) {
                    r.connect(src1.clone(), sink);
                };
            }
        }
        template <class A>
        static SourceoidForAny<A> sourceAsSourceoidForAny(Source<A> &&src) {
            if constexpr (withtime_utils::IsVariant<A>::Value) {
                return [src1=src.clone()](AppRunner &r, typename AnySinkMatch<A>::TheType const &sink) {
                    connect_variant_source_to_variant_any_sink_internal_<0, std::variant_size_v<A>, Source<A>, typename AnySinkMatch<A>::TheType>(r, src1.clone(), sink);
                };
            } else {
                return [src1=src.clone()](AppRunner &r, Sink<std::any> const &sink) {
                    r.connectAny(src1.clone(), sink);
                };
            }
        }
        template <class A>
        static Sourceoid<A> sourceAsSourceoid(std::optional<Source<A>> &&src) {
            if (src) {
                return sourceAsSourceoid(std::move(*src));
            } else {
                return Sourceoid<A> {};
            }
        }
        template <class A>
        static SourceoidForAny<A> sourceAsSourceoidForAny(std::optional<Source<A>> &&src) {
            if (src) {
                return sourceAsSourceoidForAny(std::move(*src));
            } else {
                return SourceoidForAny<A> {};
            }
        }
        template <std::size_t Idx, class... As>
        static Sourceoid<std::variant_alternative_t<Idx, std::variant<As...>>> subSourceoid(Source<std::variant<As...>> &&src) {
            auto s = sourceAsSourceoid<std::variant<As...>>(std::move(src));
            return [s](AppRunner &r, Sink<std::variant_alternative_t<Idx,std::variant<As...>>> const &sink) {
                s(r, std::variant<Sink<As>...> {std::in_place_index<Idx>, sink});
            };
        }
        template <std::size_t Idx, class... As>
        static SourceoidForAny<std::variant_alternative_t<Idx, std::variant<As...>>> subSourceoidForAny(Source<std::variant<As...>> &&src) {
            auto s = sourceAsSourceoidForAny<std::variant<As...>>(std::move(src));
            return [s](AppRunner &r, Sink<std::any> const &sink) {
                s(r, typename AnySinkMatch<std::variant<As...>>::TheType{std::in_place_index<Idx>, sink});
            };
        }
        template <class A>
        static Sourceoid<A> convertToSourceoid(ConvertibleToSourceoid<A> &&s) {
            return std::visit([](auto &&x) -> Sourceoid<A> {
                using T = std::decay_t<decltype(x)>;
                if constexpr (std::is_same_v<T, Source<A>>) {
                    return sourceAsSourceoid<A>(std::move(x));
                } else if constexpr (std::is_same_v<T, Sourceoid<A>>) {
                    return x;
                } else if constexpr (std::is_same_v<T, std::optional<Source<A>>>) {
                    return sourceAsSourceoid<A>(std::move(x));
                } else {
                    return Sourceoid<A> {};
                }
            }, std::move(s));
        }
        template <class A, class B>
        static Sourceoid<typename App::template KeyedData<A,B>> facilityAndInputAsSourceoid(OnOrderFacilityPtr<A,B> const &facility, Source<typename App::template Key<A>> &&input) {
            return [facility,input=std::move(input)](AppRunner &r, Sink<typename App::template KeyedData<A,B>> const &sink) {
                r.placeOrderWithFacility(std::move(input), facility, sink);
            };
        }
        template <class A, class B, class C>
        static Sourceoid<typename App::template KeyedData<A,B>> localFacilityAndInputAsSourceoid(LocalOnOrderFacilityPtr<A,B,C> const &facility, Source<typename App::template Key<A>> &&input) {
            return [facility,input=std::move(input)](AppRunner &r, Sink<typename App::template KeyedData<A,B>> const &sink) {
                r.placeOrderWithLocalFacility(std::move(input), facility, sink);
            };;
        }
        template <class A, class B, class C>
        static Sourceoid<typename App::template KeyedData<A,B>> facilityWithExternalEffectsAndInputAsSourceoid(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &facility, Source<typename App::template Key<A>> &&input) {
            return [facility,input=std::move(input)](AppRunner &r, Sink<typename App::template KeyedData<A,B>> const &sink) {
                r.placeOrderWithFacilityWithExternalEffects(std::move(input), facility, sink);
            };
        }
        template <class A, class B, class C, class D>
        static Sourceoid<typename App::template KeyedData<A,B>> vieFacilityAndInputAsSourceoid(VIEOnOrderFacilityPtr<A,B,C,D> const &facility, Source<typename App::template Key<A>> &&input) {
            return [facility,input=std::move(input)](AppRunner &r, Sink<typename App::template KeyedData<A,B>> const &sink) {
                r.placeOrderWithVIEFacility(std::move(input), facility, sink);
            };
        }
        template <class A, class B>
        static Sourceoid<typename App::template KeyedData<A,B>> facilitioidConnectorAndInputAsSourceoid(FacilitioidConnector<A,B> const &f, Source<typename App::template Key<A>> &&input) {
            return [f,input=std::move(input)](AppRunner &r, Sink<typename App::template KeyedData<A,B>> const &sink) {
                f(r, std::move(input), sink);
            };
        }
        template <class A>
        static Sinkoid<A> sinkAsSinkoid(Sink<A> const &sink) {
            return [sink](AppRunner &r, Source<A> &&src) {
                r.connect(std::move(src), sink);
            };
        }
        template <class A>
        static Sinkoid<A> sinkAsSinkoid(std::optional<Sink<A>> &&sink) {
            if (sink) {
                return sinkAsSinkoid(std::move(*sink));
            } else {
                return [](AppRunner &, Source<A> &&) {};
            }
        }
        template <class A>
        using ConvertibleToSinkoid = std::variant<
            Sink<A>
            , Sinkoid<A>
            , std::optional<Sink<A>>
        >;
        template <class A>
        static Sinkoid<A> convertToSinkoid(ConvertibleToSinkoid<A> &&s) {
            return std::visit([](auto &&x) -> Sinkoid<A> {
                using T = std::decay_t<decltype(x)>;
                if constexpr (std::is_same_v<T, Sink<A>>) {
                    return sinkAsSinkoid<A>(std::move(x));
                } else if constexpr (std::is_same_v<T, Sinkoid<A>>) {
                    return x;
                } else if constexpr (std::is_same_v<T, std::optional<Sink<A>>>) {
                    return sinkAsSinkoid<A>(std::move(x));
                } else {
                    return [](AppRunner &, Source<A> &&) {};
                }
            }, std::move(s));
        }
        template <class A, class B>
        static Sinkoid<typename App::template Key<A>> facilityAsSinkoid(OnOrderFacilityPtr<A,B> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                r.placeOrderWithFacilityAndForget(std::move(src), facility);
            };
        }
        template <class A, class B, class C>
        static Sinkoid<typename App::template Key<A>> localFacilityAsSinkoid(LocalOnOrderFacilityPtr<A,B,C> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                r.placeOrderWithLocalFacilityAndForget(std::move(src), facility);
            };
        }
        template <class A, class B, class C>
        static Sinkoid<typename App::template Key<A>> facilityWithExternalEffectsAsSinkoid(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                r.placeOrderWithFacilityWithExternalEffectsAndForget(std::move(src), facility);
            };
        }
        template <class A, class B, class C, class D>
        static Sinkoid<typename App::template Key<A>> vieFacilityAsSinkoid(VIEOnOrderFacilityPtr<A,B,C,D> const &facility) {
            return [facility](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                r.placeOrderWithVIEFacilityAndForget(std::move(src), facility);
            };
        }
        template <class A, class B>
        static Sinkoid<typename App::template Key<A>> facilitioidConnectorAsSinkoid(FacilitioidConnector<A,B> const &f) {
            return [f](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                f(r, std::move(src), std::nullopt);
            };
        }
        template <class A, class B>
        static Sinkoid<typename App::template Key<A>> facilityAndOutputAsSinkoid(OnOrderFacilityPtr<A,B> const &facility, Sink<typename App::template KeyedData<A,B>> const &output) {
            return [facility,output](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                Sink<typename App::template KeyedData<A,B>> outputCopy {output};
                r.placeOrderWithFacility(std::move(src), facility, outputCopy);
            };
        }
        template <class A, class B, class C>
        static Sinkoid<typename App::template Key<A>> localFacilityAndOutputAsSinkoid(LocalOnOrderFacilityPtr<A,B,C> const &facility, Sink<typename App::template KeyedData<A,B>> const &output) {
            return [facility,output](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                Sink<typename App::template KeyedData<A,B>> outputCopy {output};
                r.placeOrderWithLocalFacility(std::move(src), facility, outputCopy);
            };
        }
        template <class A, class B, class C>
        static Sinkoid<typename App::template Key<A>> facilityWithExternalEffectsAndOutputAsSinkoid(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &facility, Sink<typename App::template KeyedData<A,B>> const &output) {
            return [facility,output](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                Sink<typename App::template KeyedData<A,B>> outputCopy {output};
                r.placeOrderWithFacilityWithExternalEffects(std::move(src), facility, outputCopy);
            };
        }
        template <class A, class B, class C, class D>
        static Sinkoid<typename App::template Key<A>> vieFacilityAndOutputAsSinkoid(VIEOnOrderFacilityPtr<A,B,C,D> const &facility, Sink<typename App::template KeyedData<A,B>> const &output) {
            return [facility,output](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                Sink<typename App::template KeyedData<A,B>> outputCopy {output};
                r.placeOrderWithVIEFacility(std::move(src), facility, outputCopy);
            };
        }
        template <class A, class B>
        static Sinkoid<typename App::template Key<A>> facilitioidConnectorAndOutputAsSinkoid(FacilitioidConnector<A,B> const &f, Sink<typename App::template KeyedData<A,B>> const &output) {
            return [f,output](AppRunner &r, Source<typename App::template Key<A>> &&src) {
                Sink<typename App::template KeyedData<A,B>> outputCopy {output};
                f(r, std::move(src), outputCopy);
            };
        }

        template <class A>
        Source<A> sourceoidToSource(Sourceoid<A> const &src, std::string const &connectorName) {
            auto connector = App::template liftPure<A>([](A&&a) -> A {return std::move(a);});
            registerAction(connectorName, connector);
            src(*this, actionAsSink(connector));
            return actionAsSource(connector);
        }
        template <class A>
        Sink<A> sinkoidToSink(Sinkoid<A> const &sink, std::string const &connectorName) {
            auto connector = App::template liftPure<A>([](A&&a) -> A {return std::move(a);});
            registerAction(connectorName, connector);
            sink(*this, actionAsSource(connector));
            return actionAsSink(connector);
        }

        template <class A, class B>
        using Pathway =
            std::function<void(AppRunner &, Source<A> &&, Sink<B> const &)>;

        void controlFirst(std::string const &name, std::string const &command, std::vector<std::string> const &params) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto iter = controllableNodeMap_.find(name);
            if (iter != controllableNodeMap_.end()) {
                if (!iter->second.empty()) {
                    iter->second[0]->control(env_, command, params);
                }
            }
        }
        void controlAll(std::string const &name, std::string const &command, std::vector<std::string> const &params) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto iter = controllableNodeMap_.find(name);
            if (iter != controllableNodeMap_.end()) {
                for (auto *p : iter->second) {
                    p->control(env_, command, params);
                }
            }
        }
        void controlFirstRE(std::regex const &name, std::string const &command, std::vector<std::string> const &params) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            for (auto const &item : controllableNodeMap_) {
                if (std::regex_match(item.first, name)) {
                    if (!item.second.empty()) {
                        item.second[0]->control(env_, command, params);
                        break;
                    }
                }
            }
        }
        void controlAllRE(std::regex const &name, std::string const &command, std::vector<std::string> const &params) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            for (auto const &item : controllableNodeMap_) {
                if (std::regex_match(item.first, name)) {
                    for (auto *p : item.second) {
                        p->control(env_, command, params);
                    }
                }
            }
        }
        std::optional<std::string> findFirstControllableNodeAtOrAbove(std::string const &nodeName) {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            std::unordered_set<std::string> seen;
            std::deque<std::string> q;
            q.push_back(nodeName);
            seen.insert(nodeName);
            while (!q.empty()) {
                auto s = q.front();
                q.pop_front();
                if (controllableNodeMap_.find(s) != controllableNodeMap_.end()) {
                    return s;
                }
                auto reverseIter = reverseLookup_.find(s);
                if (reverseIter != reverseLookup_.end()) {
                    auto iter = nameMap_.find(reverseIter->second);
                    if (iter != nameMap_.end()) {
                        for (auto const &from : iter->second.paramConnectedFrom) {
                            for (auto const &oneFrom : from) {
                                if (seen.find(oneFrom.first) == seen.end()) {
                                    q.push_back(oneFrom.first);
                                    seen.insert(oneFrom.first);
                                }
                            }
                        }
                    }
                }
            }
            return std::nullopt;
        }

        std::vector<std::string> observeFirst(std::string const &name) const {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto iter = observableNodeMap_.find(name);
            if (iter != observableNodeMap_.end()) {
                if (!iter->second.empty()) {
                    return iter->second[0]->observe(env_);
                }
            }
            return {};
        }
        std::vector<std::string> observeAll(std::string const &name) const {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            auto iter = observableNodeMap_.find(name);
            if (iter != observableNodeMap_.end()) {
                std::vector<std::string> ret;
                for (auto *p : iter->second) {
                    auto r = p->observe(env_);
                    std::copy(r.begin(), r.end(), std::back_inserter(ret));
                }
                return ret;
            }
            return {};
        }
        std::vector<std::string> observeFirstRE(std::regex const &name) const {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            for (auto const &item : observableNodeMap_) {
                if (std::regex_match(item.first, name)) {
                    if (!item.second.empty()) {
                        return item.second[0]->observe(env_);
                    }
                }
            }
            return {};
        }
        std::vector<std::string> observeAllRE(std::regex const &name) const {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            for (auto const &item : observableNodeMap_) {
                if (std::regex_match(item.first, name)) {
                    std::vector<std::string> ret;
                    for (auto *p : item.second) {
                        auto r = p->observe(env_);
                        std::copy(r.begin(), r.end(), std::back_inserter(ret));
                    }
                    return ret;
                }
            }
            return {};
        }
        std::unordered_map<std::string, std::vector<std::string>> observeAllNodes() const {
            std::lock_guard<std::recursive_mutex> _(mutex_);
            std::unordered_map<std::string, std::vector<std::string>> ret;
            for (auto const &item : observableNodeMap_) {
                std::vector<std::string> innerRet;
                for (auto *p : item.second) {
                    auto r = p->observe(env_);
                    std::copy(r.begin(), r.end(), std::back_inserter(innerRet));
                }
                ret.insert({item.first, std::move(innerRet)});
            }
            return ret;
        }

        void dynamicConnect(std::string const &sourceName, std::size_t sourceIdx, std::string const &sinkName, std::size_t sinkIdx) {
            auto sourceIter = namedSources_.find(sourceName);
            if (sourceIter == namedSources_.end()) {
                throw AppRunnerException(
                    std::string("dynamicConnect error: source '")+sourceName+"' not found"
                );
            }
            if (sourceIter->second.size() <= sourceIdx) {
                throw AppRunnerException(
                    std::string("dynamicConnect error: source '")+sourceName+"' does not have branch "+std::to_string(sourceIdx)
                );
            }
            auto sinkIter = namedSinks_.find(sinkName);
            if (sinkIter == namedSinks_.end()) {
                throw AppRunnerException(
                    std::string("dynamicConnect error: sink '")+sinkName+"' not found"
                );
            }
            if (sinkIter->second.size() <= sinkIdx) {
                throw AppRunnerException(
                    std::string("dynamicConnect error: sink '")+sinkName+"' does not have branch "+std::to_string(sinkIdx)
                );
            }
            sourceIter->second[sourceIdx].theSourceoid_(sinkIter->second[sinkIdx]);
        }
        void dynamicPlaceOrder(std::string const &sourceName, std::size_t sourceIdx, std::string const &facilityName, std::string const &sinkName, std::size_t sinkIdx) {
            auto sourceIter = namedSources_.find(sourceName);
            if (sourceIter == namedSources_.end()) {
                throw AppRunnerException(
                    std::string("dynamicPlaceOrder error: source '")+sourceName+"' not found"
                );
            }
            if (sourceIter->second.size() <= sourceIdx) {
                throw AppRunnerException(
                    std::string("dynamicPlaceOrder error: source '")+sourceName+"' does not have branch "+std::to_string(sourceIdx)
                );
            }
            if (!sourceIter->second[sourceIdx].theSource_) {
                throw AppRunnerException(
                    std::string("dynamicPlaceOrder error: source '")+sourceName+"' does not have placeable source at branch "+std::to_string(sourceIdx)
                );
            }
            auto sinkIter = namedSinks_.find(sinkName);
            if (sinkIter == namedSinks_.end()) {
                throw AppRunnerException(
                    std::string("dynamicPlaceOrder error: sink '")+sinkName+"' not found"
                );
            }
            if (sinkIter->second.size() <= sinkIdx) {
                throw AppRunnerException(
                    std::string("dynamicPlaceOrder error: sink '")+sinkName+"' does not have branch "+std::to_string(sinkIdx)
                );
            }
            auto facilityIter = namedFacilities_.find(facilityName);
            if (facilityIter == namedFacilities_.end()) {
                throw AppRunnerException(
                    std::string("dynamicPlaceOrder error: facility '")+facilityName+"' not found"
                );
            }
            (facilityIter->second)(*(sourceIter->second[sourceIdx].theSource_), {sinkIter->second[sinkIdx]});
        }

        template <class A>
        std::optional<Source<A>> sourceByName(std::string const &sourceName, std::size_t sourceIdx=0) {
            auto sourceIter = namedSources_.find(sourceName);
            if (sourceIter == namedSources_.end()) {
                throw AppRunnerException(
                    std::string("sourceByName error: source '")+sourceName+"' not found"
                );
            }
            if (sourceIter->second.size() <= sourceIdx) {
                throw AppRunnerException(
                    std::string("sourceByName error: source '")+sourceName+"' does not have branch "+std::to_string(sourceIdx)
                );
            }
            if (!sourceIter->second[sourceIdx].theSource_) {
                return std::nullopt;
            }
            try {
                return { std::any_cast<Source<A> const &>(*(sourceIter->second[sourceIdx].theSource_)).clone() };
            } catch (std::bad_any_cast const &) {
                throw AppRunnerException(
                    std::string("sourceByName error: source '")+sourceName+"' does not have valid source at branch "+std::to_string(sourceIdx)
                );
            }
        }
        template <class A>
        Sourceoid<A> sourceoidByName(std::string const &sourceName, std::size_t sourceIdx=0) {
            auto sourceIter = namedSources_.find(sourceName);
            if (sourceIter == namedSources_.end()) {
                throw AppRunnerException(
                    std::string("sourceoidByName error: source '")+sourceName+"' not found"
                );
            }
            if (sourceIter->second.size() <= sourceIdx) {
                throw AppRunnerException(
                    std::string("sourceoidByName error: source '")+sourceName+"' does not have branch "+std::to_string(sourceIdx)
                );
            }
            auto f = sourceIter->second[sourceIdx].theSourceoid_;
            return [f](AppRunner &r, Sink<A> const &sink) {
                f(std::any {sink});
            };
        }
        template <class A>
        Sink<A> sinkByName(std::string const &sinkName, std::size_t sinkIdx=0) {
            auto sinkIter = namedSinks_.find(sinkName);
            if (sinkIter == namedSinks_.end()) {
                throw AppRunnerException(
                    std::string("sinkByName error: sink '")+sinkName+"' not found"
                );
            }
            if (sinkIter->second.size() <= sinkIdx) {
                throw AppRunnerException(
                    std::string("sinkByName error: sink '")+sinkName+"' does not have branch "+std::to_string(sinkIdx)
                );
            }
            try {
                return std::any_cast<Sink<A> const &>(sinkIter->second);
            } catch (std::bad_any_cast const &) {
                throw AppRunnerException(
                    std::string("sinkByName error: sink '")+sinkName+"' does not have valid sink at branch "+std::to_string(sinkIdx)
                );
            }
        }
        template <class A, class B>
        FacilitioidConnector<A,B> facilitioidByName(std::string const &facilityName) {
            auto facilityIter = namedFacilities_.find(facilityName);
            if (facilityIter == namedFacilities_.end()) {
                throw AppRunnerException(
                    std::string("facilitioidByName error: facility '")+facilityName+"' not found"
                );
            }
            auto f = facilityIter->second;
            return [f](AppRunner &, Source<Key<A,StateT>> &&source, std::optional<Sink<KeyedData<A,B,StateT>>> const &sink) {
                if (sink) {
                    f(std::any {source.clone()}, {std::any {*sink}});
                } else {
                    f(std::any {source.clone()}, std::nullopt);
                }
            };
        }
    };

    template <class T, class Environment, class TimePoint>
    inline std::ostream &operator<<(std::ostream &os, TimedDataWithEnvironment<T,Environment,TimePoint> const &td) {
        os << "{environment=" << td.environment << ",timedData=" << td.timedData << "}";
        return os;
    }  

    template <class T>
    inline std::ostream &operator<<(std::ostream &os, WithTime<T, std::chrono::system_clock::time_point> const &x) {
        os << "{timePoint=" << withtime_utils::localTimeString(x.timePoint) << ",value=" << x.value;
        if (x.finalFlag) {
            os << " [F]";
        }
        os << '}';
        return os;
    }

    template <class T>
    inline std::ostream &operator<<(std::ostream &os, WithTime<std::unique_ptr<T>, std::chrono::system_clock::time_point> const &x) {
        os << "{timePoint=" << withtime_utils::localTimeString(x.timePoint) << ",value=uniq_ptr[";
        if (x.value) {
            os << x.value.get() << "," << *(x.value);
        } else {
            os << "null";
        }
        os << "]";
        if (x.finalFlag) {
            os << " [F]";
        }
        os << '}';
        return os;
    }  

    template <class T>
    inline std::ostream &operator<<(std::ostream &os, WithTime<std::shared_ptr<T>, std::chrono::system_clock::time_point> const &x) {
        os << "{timePoint=" << withtime_utils::localTimeString(x.timePoint) << ",value=shared_ptr[";
        if (x.value) {
            os << x.value.get() << "," << *(x.value);
        } else {
            os << "null";
        }
        os << "]";
        if (x.finalFlag) {
            os << " [F]";
        }
        os << '}';
        return os;
    } 

    namespace AppRunnerHelper {
        #include <tm_kit/infra/WithTimeData_VariantSink_ClassPiece.hpp>
        #include <tm_kit/infra/WithTimeData_ConnectN_ClassPiece.hpp>

        template <class R>
        class GenericExecute {
        private:
            template <class A, class C>
            static bool simple_sink_simple_source_connect_(
                R &r
                , typename R::template Source<C> &&source
                , typename R::template Sink<A> const &sink
            ) {
                if constexpr (std::is_same_v<A,C>) {
                    Connect<1,0>::template call<R, A>(r, std::move(source), sink);
                    return true;
                } else if constexpr (std::is_same_v<A, std::any>) {
                    ConnectAny<1,0>::template call<R,C>(r, std::move(source), sink);
                    return true;
                } else {
                    return false;
                }
            }
            template <class A, class C>
            static bool simple_sink_simple_source_connect_rt_branch_(
                R &r
                , typename R::template Source<C> &&source
                , typename R::template Sink<A> const &sink
                , std::size_t sourceBranchNumber
            ) {
                if constexpr (std::is_same_v<A,C>) {
                    if (sourceBranchNumber == 0) {
                        Connect<1,0>::template call<R, A>(r, std::move(source), sink);
                        return true;
                    } else {
                        return false;
                    }
                } else if constexpr (std::is_same_v<A, std::any>) {
                    if (sourceBranchNumber == 0) {
                        ConnectAny<1,0>::template call<R, C>(r, std::move(source), sink);
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            template <class A, class VariantSourceType, std::size_t K>
            static bool simple_sink_variant_source_connect_internal_(
                R &r
                , typename R::template Source<VariantSourceType> &&source
                , typename R::template Sink<A> const &sink
                , bool accum
            ) {
                if constexpr (K >= std::variant_size_v<VariantSourceType>) {
                    return accum;
                } else {
                    if constexpr (std::is_same_v<A, std::variant_alternative_t<K,VariantSourceType>>) {
                        Connect<
                            std::variant_size_v<VariantSourceType>
                            , K
                        >::template call<R, VariantSourceType>(r, std::move(source), sink);
                        accum = true;
                    } else if constexpr (std::is_same_v<A, std::any>) {
                        ConnectAny<
                            std::variant_size_v<VariantSourceType>
                            , K
                        >::template call<R, VariantSourceType>(r, std::move(source), sink);
                        accum = true;
                    } 
                    return simple_sink_variant_source_connect_internal_<A, VariantSourceType, K+1>(r, std::move(source), sink, accum);
                }
            }
            template <class A, class VariantSourceType, std::size_t K>
            static bool simple_sink_variant_source_connect_rt_branch_internal_(
                R &r
                , typename R::template Source<VariantSourceType> &&source
                , typename R::template Sink<A> const &sink
                , std::size_t sourceBranchNumber
                , bool accum
            ) {
                if constexpr (K >= std::variant_size_v<VariantSourceType>) {
                    return accum;
                } else {
                    if constexpr (std::is_same_v<A, std::variant_alternative_t<K,VariantSourceType>>) {
                        if (K == sourceBranchNumber) {
                            Connect<
                                std::variant_size_v<VariantSourceType>
                                , K
                            >::template call<R, VariantSourceType>(r, std::move(source), sink);
                            accum = true;
                        }
                    } else if constexpr (std::is_same_v<A, std::any>) {
                        if (K == sourceBranchNumber) {
                            ConnectAny<
                                std::variant_size_v<VariantSourceType>
                                , K
                            >::template call<R, VariantSourceType>(r, std::move(source), sink);
                            accum = true;
                        }
                    } 
                    return simple_sink_variant_source_connect_rt_branch_internal_<A, VariantSourceType, K+1>(r, std::move(source), sink, sourceBranchNumber, accum);
                }
            }
            template <class A, class VariantSourceType>
            static bool simple_sink_variant_source_connect_(
                R &r
                , typename R::template Source<VariantSourceType> &&source
                , typename R::template Sink<A> const &sink
            ) {
                return simple_sink_variant_source_connect_internal_<
                    A, VariantSourceType, 0
                >(r, std::move(source), sink, false);
            }
            template <class A, class VariantSourceType>
            static bool simple_sink_variant_source_connect_rt_branch_(
                R &r
                , typename R::template Source<VariantSourceType> &&source
                , typename R::template Sink<A> const &sink
                , std::size_t sourceBranchNumber
            ) {
                return simple_sink_variant_source_connect_rt_branch_internal_<
                    A, VariantSourceType, 0
                >(r, std::move(source), sink, sourceBranchNumber, false);
            }
            template <class A, class C>
            static bool simple_sink_connect_(
                R &r
                , typename R::template Source<C> &&source
                , typename R::template Sink<A> const &sink
            ) {
                if constexpr (withtime_utils::IsVariant<C>::Value) {
                    return simple_sink_variant_source_connect_<A,C>(r, std::move(source), sink);
                } else {
                    return simple_sink_simple_source_connect_<A,C>(r, std::move(source), sink);
                }
            }
            template <class A, class C, std::size_t SourceBranchNumber>
            static bool simple_sink_connect_specific_branch_(
                R &r
                , typename R::template Source<C> &&source
                , typename R::template Sink<A> const &sink
            ) {
                if constexpr (std::is_same_v<A, std::variant_alternative_t<SourceBranchNumber,C>>) {
                    Connect<
                        std::variant_size_v<C>
                        , SourceBranchNumber
                    >::template call<R, C>(r, std::move(source), sink);
                    return true;
                } else if constexpr (std::is_same_v<A, std::any>) {
                    ConnectAny<
                        std::variant_size_v<C>
                        , SourceBranchNumber
                    >::template call<R, C>(r, std::move(source), sink);
                    return true;
                } else {
                    return false;
                }
            }
            template <class A, class C>
            static bool simple_sink_connect_rt_branch_(
                R &r
                , typename R::template Source<C> &&source
                , typename R::template Sink<A> const &sink
                , std::size_t sourceBranchNumber
            ) {
                if constexpr (withtime_utils::IsVariant<C>::Value) {
                    return simple_sink_variant_source_connect_rt_branch_<A,C>(r, std::move(source), sink, sourceBranchNumber);
                } else {
                    return simple_sink_simple_source_connect_rt_branch_<A,C>(r, std::move(source), sink, sourceBranchNumber);
                }
            }
            template <class A, class B>
            static bool simple_exporter_connect_(
                R &r
                , typename R::template ExporterPtr<A> const &exporter
                , typename R::template Source<B> &&source
            ) {
                return simple_sink_connect_<
                    A, B
                >(
                    r
                    , std::move(source)
                    , r.exporterAsSink(exporter)
                );
            }
            template <class A, class B, std::size_t SourceBranchNumber>
            static bool simple_exporter_connect_specific_branch_(
                R &r
                , typename R::template ExporterPtr<A> const &exporter
                , typename R::template Source<B> &&source
            ) {
                return simple_sink_connect_specific_branch_<
                    A, B, SourceBranchNumber
                >(
                    r
                    , std::move(source)
                    , r.exporterAsSink(exporter)
                );
            }
            template <class A, class B>
            static bool simple_exporter_connect_rt_branch_(
                R &r
                , typename R::template ExporterPtr<A> const &exporter
                , typename R::template Source<B> &&source
                , std::size_t sourceBranchNumber
            ) {
                return simple_sink_connect_rt_branch_<
                    A, B
                >(
                    r
                    , std::move(source)
                    , r.exporterAsSink(exporter)
                    , sourceBranchNumber
                );
            }
            template <class A, class B, class C>
            static bool simple_action_connect_(
                R &r
                , typename R::template ActionPtr<A,B> const &action 
                , typename R::template Source<C> &&source
            ) {
                return simple_sink_connect_<
                    A, C
                >(
                    r
                    , std::move(source)
                    , ActionAsSink<
                        1, 0
                    >::template call<
                        R, A, B
                    >(r, action) 
                );
            }
            template <class A, class B, class C, std::size_t SourceBranchNumber>
            static bool simple_action_connect_specific_branch_(
                R &r
                , typename R::template ActionPtr<A,B> const &action 
                , typename R::template Source<C> &&source
            ) {
                return simple_sink_connect_specific_branch_<
                    A, C, SourceBranchNumber
                >(
                    r
                    , std::move(source)
                    , ActionAsSink<
                        1, 0
                    >::template call<
                        R, A, B
                    >(r, action) 
                );
            }
            template <class A, class B, class C>
            static bool simple_action_connect_rt_branch_(
                R &r
                , typename R::template ActionPtr<A,B> const &action 
                , typename R::template Source<C> &&source
                , std::size_t sourceBranchNumber
            ) {
                return simple_sink_connect_rt_branch_<
                    A, C
                >(
                    r
                    , std::move(source)
                    , ActionAsSink<
                        1, 0
                    >::template call<
                        R, A, B
                    >(r, action) 
                    , sourceBranchNumber
                );
            }
            template <class VariantInputType, class B, class C, std::size_t K>
            static bool variant_action_connect_one_(
                R &r
                , typename R::template ActionPtr<VariantInputType,B> const &action 
                , typename R::template Source<C> &&source
            ) {
                return simple_sink_connect_<
                    std::variant_alternative_t<K, VariantInputType>
                    , C
                >(
                    r
                    , std::move(source)
                    , ActionAsSink<
                        std::variant_size_v<VariantInputType>
                        , K 
                    >::template call<
                        R
                        , VariantInputType
                        , B 
                    >(r, action) 
                );
            }
            template <class VariantInputType, class B, class C, std::size_t K, std::size_t SourceBranchNumber>
            static bool variant_action_connect_one_specific_branch_(
                R &r
                , typename R::template ActionPtr<VariantInputType,B> const &action 
                , typename R::template Source<C> &&source
            ) {
                return simple_sink_connect_specific_branch_<
                    std::variant_alternative_t<K, VariantInputType>
                    , C
                    , SourceBranchNumber
                >(
                    r
                    , std::move(source)
                    , ActionAsSink<
                        std::variant_size_v<VariantInputType>
                        , K 
                    >::template call<
                        R
                        , VariantInputType
                        , B 
                    >(r, action) 
                );
            }
            template <class VariantInputType, class B, class C, std::size_t K>
            static bool variant_action_connect_one_rt_branch_(
                R &r
                , typename R::template ActionPtr<VariantInputType,B> const &action 
                , typename R::template Source<C> &&source
                , std::size_t sourceBranchNumber
            ) {
                return simple_sink_connect_rt_branch_<
                    std::variant_alternative_t<K, VariantInputType>
                    , C
                >(
                    r
                    , std::move(source)
                    , ActionAsSink<
                        std::variant_size_v<VariantInputType>
                        , K 
                    >::template call<
                        R
                        , VariantInputType
                        , B 
                    >(r, action) 
                    , sourceBranchNumber
                );
            }
            template <class VariantInputType, class B, class C, std::size_t K>
            static bool variant_action_connect_internal_(
                R &r
                , typename R::template ActionPtr<VariantInputType,B> const &action 
                , typename R::template Source<C> &&source
                , bool &accum
            ) {
                if constexpr (K >= std::variant_size_v<VariantInputType>) {
                    return accum;
                } else {
                    if (variant_action_connect_one_<
                        VariantInputType, B, C, K
                    >(r, action, source.clone())) {
                        accum = true;
                    }
                    return variant_action_connect_internal_<
                        VariantInputType, B, C, K+1
                    >(r, action, std::move(source), accum);
                }
            }
            template <class VariantInputType, class B, class C, std::size_t K, std::size_t SourceBranchNumber>
            static bool variant_action_connect_specific_branch_internal_(
                R &r
                , typename R::template ActionPtr<VariantInputType,B> const &action 
                , typename R::template Source<C> &&source
                , bool &accum
            ) {
                if constexpr (K >= std::variant_size_v<VariantInputType>) {
                    return accum;
                } else {
                    if (variant_action_connect_one_specific_branch_<
                        VariantInputType, B, C, K, SourceBranchNumber
                    >(r, action, source.clone())) {
                        accum = true;
                    }
                    return variant_action_connect_specific_branch_internal_<
                        VariantInputType, B, C, K+1, SourceBranchNumber
                    >(r, action, std::move(source), accum);
                }
            }
            template <class VariantInputType, class B, class C, std::size_t K>
            static bool variant_action_connect_rt_branch_internal_(
                R &r
                , typename R::template ActionPtr<VariantInputType,B> const &action 
                , typename R::template Source<C> &&source
                , std::size_t sourceBranchNumber
                , bool &accum
            ) {
                if constexpr (K >= std::variant_size_v<VariantInputType>) {
                    return accum;
                } else {
                    if (variant_action_connect_one_rt_branch_<
                        VariantInputType, B, C, K
                    >(r, action, source.clone(), sourceBranchNumber)) {
                        accum = true;
                    }
                    return variant_action_connect_rt_branch_internal_<
                        VariantInputType, B, C, K+1
                    >(r, action, std::move(source), sourceBranchNumber, accum);
                }
            }
            template <class A, class B, class C>
            static bool variant_action_connect_(
                R &r
                , typename R::template ActionPtr<A,B> const &action 
                , typename R::template Source<C> &&source
            ) {
                bool accum = false;
                return variant_action_connect_internal_<
                    A, B, C, 0
                >(r, action, std::move(source), accum);
            }
            template <class A, class B, class C, std::size_t SourceBranchNumber>
            static bool variant_action_connect_specific_branch_(
                R &r
                , typename R::template ActionPtr<A,B> const &action 
                , typename R::template Source<C> &&source
            ) {
                bool accum = false;
                return variant_action_connect_specific_branch_internal_<
                    A, B, C, 0, SourceBranchNumber
                >(r, action, std::move(source), accum);
            }
            template <class A, class B, class C>
            static bool variant_action_connect_rt_branch_(
                R &r
                , typename R::template ActionPtr<A,B> const &action 
                , typename R::template Source<C> &&source
                , std::size_t sourceBranchNumber
            ) {
                bool accum = false;
                return variant_action_connect_rt_branch_internal_<
                    A, B, C, 0
                >(r, action, std::move(source), sourceBranchNumber, accum);
            }
        public:
            template <class Action, class C>
            static typename R::template Source<typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::OutputType> call(
                R &r
                , typename std::shared_ptr<Action> const &action 
                , typename R::template Source<C> &&source
            ) {
                using A = typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::InputType;
                using B = typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::OutputType;
                if constexpr (withtime_utils::IsVariant<A>::Value) {
                    if (!variant_action_connect_<A,B,C>(
                        r, action, std::move(source)
                    )) {
                        throw std::runtime_error("GenericExecute::call: cannot connect");
                    }
                } else {
                    if (!simple_action_connect_<A,B,C>(
                        r, action, std::move(source)
                    )) {
                        throw std::runtime_error("GenericExecute::call: cannot connect");
                    }
                }
                return r.template actionAsSource<typename R::template Action<A,B>>(action);
            }
            template <class Exporter, class B>
            static void callExporter(
                R &r
                , typename std::shared_ptr<Exporter> const &exporter
                , typename R::template Source<B> &&source
            ) {
                using A = typename withtime_utils::ExporterTypeInfo<typename R::AppType,Exporter>::DataType;
                if (!simple_exporter_connect_<A,B>(
                        r, exporter, std::move(source)
                    )) {
                    throw std::runtime_error("GenericExecute::callExporter: cannot connect");
                }
            }
            template <std::size_t SourceBranchNumber, class Action, class C>
            static typename R::template Source<typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::OutputType> callOnSourceBranch(
                R &r
                , typename std::shared_ptr<Action> const &action 
                , typename R::template Source<C> &&source
            ) {
                static_assert(
                    (withtime_utils::IsVariant<C>::Value && (std::variant_size_v<C> > SourceBranchNumber))
                    , "Source branch number must be valid"
                );
                using A = typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::InputType;
                using B = typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::OutputType;
                if constexpr (withtime_utils::IsVariant<A>::Value) {
                    if (!variant_action_connect_specific_branch_<A,B,C,SourceBranchNumber>(
                        r, action, std::move(source)
                    )) {
                        throw std::runtime_error("GenericExecute::callOnSourceBranch: cannot connect");
                    }
                } else {
                    if (!simple_action_connect_specific_branch_<A,B,C,SourceBranchNumber>(
                        r, action, std::move(source)
                    )) {
                        throw std::runtime_error("GenericExecute::callOnSourceBranch: cannot connect");
                    }
                }
                return r.template actionAsSource<typename R::template Action<A,B>>(action);
            }
            template <std::size_t SourceBranchNumber, class Exporter, class B>
            static void callExporterOnSourceBranch(
                R &r
                , typename std::shared_ptr<Exporter> const &exporter
                , typename R::template Source<B> &&source
            ) {
                static_assert(
                    (withtime_utils::IsVariant<B>::Value && (std::variant_size_v<B> > SourceBranchNumber))
                    , "Source branch number must be valid"
                );
                using A = typename withtime_utils::ExporterTypeInfo<typename R::AppType,Exporter>::DataType;
                if (!simple_exporter_connect_specific_branch_<A,B,SourceBranchNumber>(
                        r, exporter, std::move(source)
                    )) {
                    throw std::runtime_error("GenericExecute::callExporterOnSourceBranch: cannot connect");
                }
            }
            template <class Action, class C>
            static typename R::template Source<typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::OutputType> callOnRTSourceBranch(
                R &r
                , typename std::shared_ptr<Action> const &action 
                , typename R::template Source<C> &&source
                , std::size_t sourceBranchNumber
            ) {
                using A = typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::InputType;
                using B = typename withtime_utils::ActionTypeInfo<typename R::AppType,Action>::OutputType;
                if constexpr (withtime_utils::IsVariant<A>::Value) {
                    if (!variant_action_connect_rt_branch_<A,B,C>(
                        r, action, std::move(source), sourceBranchNumber
                    )) {
                        throw std::runtime_error("GenericExecute::callOnRTSourceBranch: cannot connect");
                    }
                } else {
                    if (!simple_action_connect_rt_branch_<A,B,C>(
                        r, action, std::move(source), sourceBranchNumber
                    )) {
                        throw std::runtime_error("GenericExecute::callOnRTSourceBranch: cannot connect");
                    }
                }
                return r.template actionAsSource<typename R::template Action<A,B>>(action);
            }
            template <class Exporter, class B>
            static void callExporterOnRTSourceBranch(
                R &r
                , typename std::shared_ptr<Exporter> const &exporter
                , typename R::template Source<B> &&source
                , std::size_t sourceBranchNumber
            ) {
                using A = typename withtime_utils::ExporterTypeInfo<typename R::AppType,Exporter>::DataType;
                if (!simple_exporter_connect_rt_branch_<A,B>(
                        r, exporter, std::move(source), sourceBranchNumber
                    )) {
                    throw std::runtime_error("GenericExecute::callExporterOnRTSourceBranch: cannot connect");
                }
            }
        };
    }

    template <class App>
    template <std::size_t Idx, std::size_t Total, class VariantSourceType, class VariantSinkType>
    void AppRunner<App>::connect_variant_source_to_variant_sink_internal_(
        AppRunner<App> &r 
        , VariantSourceType &&src
        , VariantSinkType const &sink
    ) {
        if constexpr (Idx < Total) {
            if (Idx == sink.index()) {
                AppRunnerHelper::Connect<Total,Idx>::template call<
                    AppRunner<App>, typename VariantSourceType::TheDataTypeOfThisSource
                >(r, std::move(src), std::get<Idx>(sink));
            } else {
                connect_variant_source_to_variant_sink_internal_<Idx+1,Total,VariantSourceType,VariantSinkType>(
                    r, std::move(src), sink
                );
            }
        }
    }
    template <class App>
    template <std::size_t Idx, std::size_t Total, class VariantSourceType, class VariantSinkType>
    void AppRunner<App>::connect_variant_source_to_variant_any_sink_internal_(
        AppRunner<App> &r 
        , VariantSourceType &&src
        , VariantSinkType const &sink
    ) {
        if constexpr (Idx < Total) {
            if (Idx == sink.index()) {
                AppRunnerHelper::ConnectAny<Total,Idx>::template call<
                    AppRunner<App>, typename VariantSourceType::TheDataTypeOfThisSource
                >(r, std::move(src), std::get<Idx>(sink));
            } else {
                connect_variant_source_to_variant_any_sink_internal_<Idx+1,Total,VariantSourceType,VariantSinkType>(
                    r, std::move(src), sink
                );
            }
        }
    }
    template <class App>
    template <std::size_t N, std::size_t K, class A, class B>
    void AppRunner<App>::addTypedSink_action_multi(ActionPtr<A, B> const &f, std::unordered_map<std::type_index, std::list<std::any>> &m) {
        if constexpr (K < N) {
            using T = std::variant_alternative_t<K,A>;
            addTypedSink<T>(AppRunnerHelper::ActionAsSink<N,K>::template call<AppRunner,A,B>(*this, f), m);
            addTypedSink_action_multi<N,K+1,A,B>(f, m);
        }
    }
    template <class App>
    template <class A, class B>
    void AppRunner<App>::addTypedSink_action(ActionPtr<A,B> const &f, std::unordered_map<std::type_index, std::list<std::any>> &m) {
        if constexpr (withtime_utils::IsVariant<A>::Value) {
            addTypedSink_action_multi<std::variant_size_v<A>,0,A,B>(f, m);
        } else {
            addTypedSink<A>(actionAsSink(f), m);
        }
    }
    template <class App>
    template <std::size_t N, std::size_t K, class A, class B>
    void AppRunner<App>::addTypedKeyedDataSink_action_multi(ActionPtr<A, B> const &f, std::map<std::tuple<std::type_index,std::type_index>,std::list<std::any>> &m) {
        if constexpr (K < N) {
            using T = std::variant_alternative_t<K,A>;
            if constexpr (IsKeyedData<T>::value) {
                addTypedKeyedDataSink<typename T::KeyType, typename T::DataType>(AppRunnerHelper::ActionAsSink<N,K>::template call<AppRunner,A,B>(*this, f), m);
            }
            addTypedKeyedDataSink_action_multi<N,K+1,A,B>(f, m);
        }
    }
    template <class App>
    template <class A, class B>
    void AppRunner<App>::addTypedKeyedDataSink_action(ActionPtr<A,B> const &f, std::map<std::tuple<std::type_index,std::type_index>,std::list<std::any>> &m) {
        if constexpr (withtime_utils::IsVariant<A>::Value) {
            addTypedKeyedDataSink_action_multi<std::variant_size_v<A>,0,A,B>(f, m);
        } else {
            if constexpr (IsKeyedData<A>::value) {
                addTypedKeyedDataSink<typename A::KeyType, typename A::DataType>(actionAsSink(f), m);
            }
        }
    }
    template <class App>
    template <std::size_t N, std::size_t K, class A>
    void AppRunner<App>::addNamedSource_multi(std::string const &name, Source<A> &&s) {
        if constexpr (K < N) {
            addNamedSource_single<
                std::variant_alternative_t<K,A>
            >(
                name 
                , std::nullopt
                , subSourceoid<K>(s.clone())
            );
            addNamedSource_multi<N,K+1,A>(name, s.clone());
        }
    }
    template <class App>
    template <std::size_t N, std::size_t K, class A, class B>
    void AppRunner<App>::addNamedSink_action_multi(std::string const &name, ActionPtr<A,B> const &f) {
        if constexpr (K < N) {
            using T = std::variant_alternative_t<K,A>;
            addNamedSink<T>(name, AppRunnerHelper::ActionAsSink<N,K>::template call<AppRunner<App>,A,B>(*this, f));
            addNamedSink_action_multi<N,K+1,A,B>(name, f);
        }
    }
    template <class App>
    template <class A, class B>
    void AppRunner<App>::addNamedSink_action(std::string const &name, ActionPtr<A,B> const &f) {
        if constexpr (withtime_utils::IsVariant<A>::Value) {
            addNamedSink_action_multi<std::variant_size_v<A>,0,A,B>(name, f);
        } else {
            addNamedSink<A>(name, actionAsSink(f));
        }
    }
    

}}}}

#endif
