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

#include <tm_kit/infra/ChronoUtils.hpp>
#include <tm_kit/infra/LogLevel.hpp>
#include <tm_kit/infra/VersionedData.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    constexpr std::size_t MAX_FAN_IN_BRANCH_COUNT = 10;   
    using FanInParamMask = std::bitset<MAX_FAN_IN_BRANCH_COUNT>;

    template <class T>
    struct LiftParameters {
        //This is only relevant in multi-input lifts, it specifies which ones are
        //required before the logic can apply
        FanInParamMask requireMask = FanInParamMask();
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

        LiftParameters &RequireMask(FanInParamMask m) {
            requireMask = m;
            return *this;
        }
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
    class Key<std::shared_ptr<T>, Env> {};  //not allowing the holding of an shared pointer as key
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
            typename App::template Source<T> mSource;
            std::string producer;
            bool useAltOutput;
            Source(typename App::template Source<T> &&s, std::string const &p) : mSource(std::move(s)), producer(p), useAltOutput(false) {}
            Source(typename App::template Source<T> &&s, std::string const &p, bool ao) : mSource(std::move(s)), producer(p), useAltOutput(ao) {}
        public:
            Source<T> clone() const {
                return {mSource.clone(), producer, useAltOutput};
            }
        };
        template <class T>
        class Sink {
        private:
            friend class AppRunner;
            typename App::template Sink<T> mSink;
            std::string consumer;
            int pos;
            Sink(typename App::template Sink<T> &&s, std::string const &c, int p) : mSink(std::move(s)), consumer(c), pos(p) {}
        };
    private:
        App m_;
        StateT *env_;
        struct ActionCheckData {
            std::string name;
            int paramCount;
            std::vector<std::unordered_map<std::string,std::set<std::tuple<int,int>>>> paramConnectedFrom;
            std::unordered_map<std::string,std::unordered_set<int>> outputConnectedTo;            
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
                ActionCheckData d {n, 1};
                d.isImporter = false;
                d.isExporter = false;
                return d;
            }

            #include <tm_kit/infra/WithTimeData_ActionCheckDataCreate_Piece.hpp>

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
            FanInParamMask fanInParamMask;
        };
        std::unordered_map<std::string, ActionProperties> actionPropertiesMap_;
        bool restrictFacilityOutputConnectionByDefault_;
        mutable std::mutex mutex_;

        template <class A, class B>
        void registerAction_(ActionPtr<A,B> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
            nameMap_.insert({p, ActionCheckData::create(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
            ActionProperties prop;
            prop.threaded = AppType::actionIsThreaded(f);
            prop.oneTimeOnly = AppType::actionIsOneTimeOnly(f);
            prop.fanInParamMask = AppType::actionFanInParamMask(f);
            actionPropertiesMap_.insert({name, prop});
        }
        template <class A>
        void registerImporter_(ImporterPtr<A> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
        }
        template <class A>
        void registerExporter_(ExporterPtr<A> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
        }
        template <class A, class B>
        void registerOnOrderFacility_(OnOrderFacilityPtr<A,B> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
        }
        template <class A, class B, class C>
        void registerLocalOnOrderFacility_(LocalOnOrderFacilityPtr<A,B,C> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
        }
        template <class A, class B, class C>
        void registerOnOrderFacilityWithExternalEffects_(OnOrderFacilityWithExternalEffectsPtr<A,B,C> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
        }
        template <class A, class B, class C, class D>
        void registerVIEOnOrderFacility_(VIEOnOrderFacilityPtr<A,B,C,D> const &f, std::string const &name) {
            if (reverseLookup_.find(name) != reverseLookup_.end()) {
                throw AppRunnerException(
                    "Attempt to re-use already registered name '"+name+"'"
                );
            }
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
        bool connectAndCheck_(int pos, void *p, std::string const &producer, int colorCode, bool useAltOutput) {
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
                if (connIter->second.find({colorCode, outputLegCode}) != connIter->second.end()) {
                    env_->log(LogLevel::Warning,
                        "Reconnecting an output of '" + producer + "' to '" + iter->second.name + "'"
                    );
                    isReconnect = true;
                } else {
                    connIter->second.insert({colorCode, outputLegCode});
                }
            } else {
                iter->second.paramConnectedFrom[pos].insert({producer, {{colorCode, outputLegCode}}});
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
                auto sourceOutputConnIter = sourceIter->second.outputConnectedTo.find(iter->second.name);
                if (sourceOutputConnIter != sourceIter->second.outputConnectedTo.end()) {
                    if (sourceOutputConnIter->second.find(colorCode) != sourceOutputConnIter->second.end()) {
                        isReconnect = true;
                    } else {
                        sourceOutputConnIter->second.insert(colorCode);
                    }
                } else {
                    sourceIter->second.outputConnectedTo.insert({iter->second.name,{colorCode}});
                }
            }

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
    public:
        class AppRunnerException : public std::runtime_error {
        public:
            AppRunnerException(std::string const &s) : std::runtime_error(s) {}
        };
        AppRunner(StateT *env) : m_(), env_(env), nameMap_(), reverseLookup_(), nextColorCode_(0), components_(), otherPreservedPtrs_(), stateSharingRecords_(), maxConnectivityLimits_(), actionPropertiesMap_(), restrictFacilityOutputConnectionByDefault_(true), mutex_() {}
        template <class T>
        AppRunner(T t, StateT *env) : m_(t), env_(env), nameMap_(), reverseLookup_(), nextColorCode_(0), components_(), otherPreservedPtrs_(), stateSharingRecords_(), maxConnectivityLimits_(), actionPropertiesMap_(), restrictFacilityOutputConnectionByDefault_(true), mutex_() {}
        AppRunner(AppRunner const &) = delete;
        AppRunner &operator=(AppRunner const &) = delete;
        AppRunner(AppRunner &&) = default;
        AppRunner &operator=(AppRunner &&) = default;
        ~AppRunner() noexcept {
        }
        StateT *environment() const {
            return env_;
        }
        /*
         * The reason that methods related to actions are templaterized differently from
         * other methods is as follows.
         * In the actual monads, Actions and let's say Importers are sometimes defined as 
         * aliases of different specialization for a single template. When the compiler tries
         * to match an input type against something that can be either an Action or say an
         * Importer, gcc 9.3.0 will fail (clang 10 and MSVC 14.2 and gcc 9.2.1 work, though).
         * Therefore, we have to engage in template type derivations to distinguish between
         * them. However, when all the rest are written with template type derivations and only
         * Action is left for the compiler to automaticaly deduce the inner types, gcc 9.3.0
         * works. Therefore we keep it as is for now to reduce code generation. If in the future
         * compilers will reject this inner type deduction, then we can always use the same
         * method as for other components to force duduction. 
         */
        template <class A, class B>
        void registerAction(ActionPtr<A,B> const &f, std::string const &name) {
            registerAction_(f, name);
        }
        template <class A, class B>
        void registerAction(std::string const &name, ActionPtr<A,B> const &f) {
            registerAction_(f, name);
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
                std::lock_guard<std::mutex> _(mutex_);
                registerImporter_<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(importer, name);
            }
            return { m_.template importerAsSource<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType>(env_, *importer), name };
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<App,Imp>::DataType> importerAsSource(std::shared_ptr<Imp> const &importer) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
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
        template <class A, class B>
        Source<B> actionAsSource(std::string const &name, ActionPtr<A,B> const &action) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerAction_(action, name);
            }
            return { m_.actionAsSource(env_, *action), name };
        }
        template <class A, class B>
        Source<B> actionAsSource(ActionPtr<A,B> &action) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) action.get());
            }
            return { m_.actionAsSource(env_, *action), name };
        }
        template <class A, class B>
        Source<B> execute(std::string const &name, ActionPtr<A,B> &f, Source<A> &&x) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerAction_(f, name);
                if (!connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
                    return { m_.actionAsSource(env_, *f), name };
                }
            }
            return { m_.execute(*f, std::move(x.mSource)), name };
        }
        template <class A, class B>
        Source<B> execute(ActionPtr<A,B> const &f, Source<A> &&x) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                if (!connectAndCheck_(0, (void *) f.get(), x.producer, 0, x.useAltOutput)) {
                    return { m_.actionAsSource(env_, *f), name };
                }
                name = nameMap_[(void *) f.get()].name;
            }
            return { m_.execute(*f, std::move(x.mSource)), name };
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
                std::lock_guard<std::mutex> _(mutex_);
                registerExporter_<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(exporter, name);
            }
            return { m_.template exporterAsSink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(*exporter), name, 0 };
        }
        template <class Exp>
        Sink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType> exporterAsSink(std::shared_ptr<Exp> const &exporter) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) exporter.get());
            }
            return { m_.template exporterAsSink<typename withtime_utils::ExporterTypeInfo<App,Exp>::DataType>(*exporter), name, 0 };
        }
        template <class A, class B>
        Sink<A> actionAsSink(std::string const &name, ActionPtr<A,B> const &action) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerAction_(action, name);
            }
            return { m_.actionAsSink(*action), name, 0 };
        }
        template <class A, class B>
        Sink<A> actionAsSink(ActionPtr<A,B> const &action) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) action.get());
            }
            return { m_.actionAsSink(*action), name, 0 };
        }
        template <class Fac>
        Sink<typename withtime_utils::ExporterTypeInfo<App,Fac>::DataType> localFacilityAsSink(std::string const &name, std::shared_ptr<Fac> const &facility) {
            {
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
                std::lock_guard<std::mutex> _(mutex_);
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
            std::lock_guard<std::mutex> _(mutex_);
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

        template <class T>
        void setMaxOutputConnectivity(Source<T> &&source, size_t maxOutputConnectivity) {
            std::lock_guard<std::mutex> _(mutex_);
            setMaxOutputConnectivity_(source.producer, maxOutputConnectivity);
        }
        void setMaxOutputConnectivity(std::string const &source, size_t maxOutputConnectivity) {
            std::lock_guard<std::mutex> _(mutex_);
            setMaxOutputConnectivity_(source, maxOutputConnectivity);
        }
        template <class F>
        void setMaxOutputConnectivity(std::shared_ptr<F> const &source, size_t maxOutputConnectivity) {
            std::lock_guard<std::mutex> _(mutex_);
            std::string name = checkName_((void *) source.get());
            setMaxOutputConnectivity_(name, maxOutputConnectivity);
        }
        template <class T>
        void setMaxInputConnectivity(Sink<T> const &sink, size_t maxInputConnectivity) {
            std::lock_guard<std::mutex> _(mutex_);
            setMaxInputConnectivity_(sink.consumer, sink.pos, maxInputConnectivity);
        }
        void setMaxInputConnectivity(std::string const &sink, int pos, size_t maxInputConnectivity) {
            std::lock_guard<std::mutex> _(mutex_);
            setMaxInputConnectivity_(sink, pos, maxInputConnectivity);
        }
        template <class F>
        void setMaxInputConnectivity(std::shared_ptr<F> const &sink, int pos, size_t maxInputConnectivity) {
            std::lock_guard<std::mutex> _(mutex_);
            std::string name = checkName_((void *) sink.get());
            setMaxInputConnectivity_(name, pos, maxInputConnectivity);
        }
        void restrictFacilityOutputConnectionByDefault() {
            std::lock_guard<std::mutex> _(mutex_);
            restrictFacilityOutputConnectionByDefault_ = true;
        }
        void dontRestrictFacilityOutputConnectionByDefault() {
            std::lock_guard<std::mutex> _(mutex_);
            restrictFacilityOutputConnectionByDefault_ = false;
        }

        template <class F>
        std::string getRegisteredName(std::shared_ptr<F> const &p) {
            std::lock_guard<std::mutex> _(mutex_);
            return checkName_((void *) p.get());
        }

        void writeGraphVizDescription(std::ostream &os, std::string const &graphName) const {
            std::lock_guard<std::mutex> _(mutex_);
            os << "digraph " << graphName << "{\n";
            int counter = 1;
            std::unordered_map<std::string, int> m;
            for (auto const &item : nameMap_) {
                m[item.second.name] = counter;
                os << "\t action" << counter << " [";
                if (item.second.hasAltOutput) {
                    if (item.second.paramCount > 1) {
                        os << "label=\"{{";
                        for (int ii=0; ii<item.second.paramCount; ++ii) {
                            if (ii > 0) {
                                os << '|';
                            }
                            os << "<arg" << ii << "> arg" << ii;
                        }
                        os << "}|" << std::regex_replace(item.second.name, std::regex(">"), "\\>");
                        os << "|{<out0> out0|<out1> out1}}\",shape=record";
                    } else {
                        os << "label=\"{";
                        os << std::regex_replace(item.second.name, std::regex(">"), "\\>");
                        os << "|{<out0> out0|<out1> out1}}\",shape=record";
                    }
                } else if (item.second.paramCount > 1) {
                    os << "label=\"{{";
                    for (int ii=0; ii<item.second.paramCount; ++ii) {
                        if (ii > 0) {
                            os << '|';
                        }
                        os << "<arg" << ii << "> arg" << ii;
                    }
                    os << "}|" << std::regex_replace(item.second.name, std::regex(">"), "\\>") << "}\",shape=record";
                } else if (item.second.isImporter || item.second.isExporter) {
                    os << "label=\"" << item.second.name << "\",shape=oval";                   
                } else {
                    os << "label=\"" << item.second.name << "\",shape=box";
                }
                std::vector<std::string> styleStrings;
                if (item.second.isFacility) {
                    os << ",color=blue";
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
                if (item.second.name.find('/') != std::string::npos) {
                    styleStrings.push_back("filled");
                    os << ",fillcolor=gray60";
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
            }
            for (auto const &item : nameMap_) { 
                FanInParamMask paramMask;
                if (item.second.paramCount > 1) {
                    auto propIter = actionPropertiesMap_.find(item.second.name);
                    if (propIter != actionPropertiesMap_.end()) {
                        paramMask = propIter->second.fanInParamMask;
                    }
                }  
                for (int ii=0; ii<item.second.paramCount; ++ii) {
                    for (auto const &src : item.second.paramConnectedFrom[ii]) {
                        auto iter1 = reverseLookup_.find(src.first);
                        auto iter2 = nameMap_.find(iter1->second);
                        bool isExternal = iter2->second.isImporter || item.second.isExporter;
                        for (auto const &connector : src.second) {
                            auto color = std::get<0>(connector);
                            auto srcConnector = std::get<1>(connector);
                            std::string srcConnectorStr;
                            if (srcConnector < 0) {
                                srcConnectorStr = "";
                            } else {
                                srcConnectorStr = std::string(":out")+std::to_string(srcConnector);
                            }
                            if (item.second.paramCount > 1) {
                                os << "\t action" << m[src.first] << srcConnectorStr << " -> action" << m[item.second.name] << ":arg" << ii;
                            } else {
                                os << "\t action" << m[src.first] << srcConnectorStr << " -> action" << m[item.second.name];
                            }   
                            bool hasStyles = false;
                            if (color != 0 && isExternal && ii == 0) {
                                os << " [style=dotted,colorscheme=spectral11,color=" << color;
                                hasStyles = true;
                            } else if (isExternal && ii == 0) {
                                os << " [style=dotted";
                                hasStyles = true;
                            } else if (color != 0) {
                                os << " [style=dashed,colorscheme=spectral11,color=" << color;
                                hasStyles = true;
                            }
                            if (paramMask[ii]) {
                                if (hasStyles) {
                                    os << ",arrowhead=diamond";
                                } else {
                                    os << " [arrowhead=diamond]";
                                }
                            }
                            if (hasStyles) {
                                os << "];\n";
                            } else {
                                os << ";\n";
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
                os << "\t state" << item.second << " [label=\"" << item.first << "\",shape=house];\n";
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
    public:
        void finalize() {
            {
                std::lock_guard<std::mutex> _(mutex_);
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
            m_.finalize()(env_);
        }

        template <class T>
        void preservePointer(std::shared_ptr<T> const &ptr) {
            std::lock_guard<std::mutex> _(mutex_);
            otherPreservedPtrs_.insert(std::static_pointer_cast<void>(ptr));
        }

        template <class A, class B>
        void markStateSharing(std::shared_ptr<A> const &item1, std::shared_ptr<B> const &item2, std::string const &sharedStateName="") {
            std::lock_guard<std::mutex> _(mutex_);
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

        template <class A>
        using Sourceoid = std::function<void(AppRunner &, Sink<A> const &)>;
        template <class A>
        using Sinkoid = std::function<void(AppRunner &, Source<A> &&)>;

        template <class A>
        static Sourceoid<A> sourceAsSourceoid(Source<A> &&src) {
            Source<A> src1 = src.clone();
            return [src1](AppRunner &r, Sink<A> const &sink) {
                r.connect(src1.clone(), sink);
            };
        }
        template <class A>
        static Sourceoid<A> sourceAsSourceoid(std::optional<Source<A>> &&src) {
            if (src) {
                return sourceAsSourceoid(std::move(*src));
            } else {
                return [](AppRunner &, Sink<A> const &) {};
            }
        }
        template <class A>
        using ConvertibleToSourceoid = std::variant<
            Source<A>
            , Sourceoid<A>
            , std::optional<Source<A>>
        >;
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
                    return [](AppRunner &, Sink<A> const &) {};
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

}}}}

#endif
