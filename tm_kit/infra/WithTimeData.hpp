#ifndef TM_KIT_INFRA_WITHTIME_DATA_HPP_
#define TM_KIT_INFRA_WITHTIME_DATA_HPP_

#ifdef _MSC_VER
#pragma warning( disable : 4250 )
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

namespace dev { namespace cd606 { namespace tm { namespace infra {

    constexpr std::size_t MAX_FAN_IN_BRANCH_COUNT = 10;   
    using FanInParamMask = std::bitset<MAX_FAN_IN_BRANCH_COUNT>;

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

    //The final flag indicates that this is the last update that the 
    //sender will ever send (if an action or importer) or will ever send for the 
    //corresponding request (if an on-order facility). The way to deal with 
    //this depends upon the monad. BasicWithTimeMonad will ignore it, RealTimeMonad uses
    //it to "unhook" on-order facilities if the facility returns a final-flagged
    //response for a given request, but otherwise does not use it. However, the
    //SinglePassIterationMonad will depend on this flag heavily, since the downstream
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
        inline A makeValueCopy(A const &a) {
            return a;
        }
        template <class A>
        inline std::unique_ptr<A> makeValueCopy(std::unique_ptr<A> const &a) {
            if (a) {
                return std::make_unique<A>(*a);
            } else {
                return std::unique_ptr<A>();
            }
        }
        template <class TimePoint, class A>
        inline WithTime<A, TimePoint> makeCopy(WithTime<A, TimePoint> const &a) {
            return WithTime<A, TimePoint> {a};
        }
        template <class TimePoint, class A>
        inline WithTime<std::unique_ptr<A>, TimePoint> makeCopy(WithTime<std::unique_ptr<A>, TimePoint> const &a) {
            if (a.value) {
                return WithTime<std::unique_ptr<A>, TimePoint> {
                    a.timePoint,
                    std::make_unique<A>(*(a.value)),
                    a.finalFlag
                };
            } else {
                return WithTime<std::unique_ptr<A>, TimePoint> {
                    a.timePoint,
                    std::unique_ptr<A>(),
                    a.finalFlag
                };
            }
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
        inline auto pureTimedDataWithEnvironmentLift(Environment *environment, F const &f, WithTime<A,TimePoint> &&a, bool preserveTime=false) -> TimedDataWithEnvironment<decltype(f(std::move(a.value))), Environment, TimePoint> {
            return {environment, {preserveTime?a.timePoint:environment->resolveTime(a.timePoint), std::move(f(std::move(a.value))), a.finalFlag}};
        }
        template <class A, class F, class Environment, class TimePoint>
        inline auto pureTimedDataWithEnvironmentLift(F const &f, TimedDataWithEnvironment<A, Environment, TimePoint> &&a, bool preserveTime=false) -> TimedDataWithEnvironment<decltype(f(std::move(a.timedData.value))), Environment, TimePoint> {
            return {a.environment, {preserveTime?a.timedData.timePoint:a.environment->resolveTime(a.timedData.timePoint), std::move(f(std::move(a.timedData.value))), a.timedData.finalFlag}};
        }
    }

    template <class T, class Environment, class TimePoint=typename Environment::TimePointType>
    using TimedMonadData = std::optional<TimedDataWithEnvironment<T, Environment, TimePoint>>;

    template <class A, class B, class Environment, class TimePoint=typename Environment::TimePointType>
    using TimedMonadModelKleisli = std::function<TimedMonadData<B, Environment, TimePoint>(TimedDataWithEnvironment<A, Environment, TimePoint> &&)>;

    namespace withtime_utils {
        template <class T, class Environment, class TimePoint=typename Environment::TimePointType>
        inline TimedMonadData<T,Environment,TimePoint> clone(TimedMonadData<T,Environment,TimePoint> const &data) {
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
        inline TimedMonadData<B,Environment,TimePoint> timedMonadApply(TimedMonadModelKleisli<A,B,Environment,TimePoint> const &f, TimedMonadData<A,Environment,TimePoint> &&input) 
        {
            if (input) {
                return f(std::move(*input));
            } else {
                return std::nullopt;
            }
        }
    }

    namespace withtime_utils {
        template <class Monad, class Action>
        struct ActionTypeInfo {
            using InputType = typename Monad::template GetInputOutputType<Action>::InputType; 
            using OutputType = typename Monad::template GetInputOutputType<Action>::OutputType; 
        };
        template <class Monad, class Importer>
        struct ImporterTypeInfo {
            using DataType = typename Monad::template GetDataType<Importer>::DataType; 
        };
        template <class Monad, class Exporter>
        struct ExporterTypeInfo {
            using DataType = typename Monad::template GetDataType<Exporter>::DataType;
        };
        template <class Monad, class OnOrderFacility>
        struct OnOrderFacilityTypeInfo {
            using InputType = typename Monad::template GetInputOutputType<OnOrderFacility>::InputType;
            using OutputType = typename Monad::template GetInputOutputType<OnOrderFacility>::OutputType;
        };
    }

    template <class Monad>
    class MonadRunner {
    public:
        using MonadType = Monad;
        using EnvironmentType = typename Monad::StateType;
        using StateT = typename Monad::StateType;
        template <class A, class B>
        using Action = typename Monad::template Action<A,B>;
        template <class A, class B>
        using ActionPtr = std::shared_ptr<Action<A,B>>;
        template <class T>
        using Importer = typename Monad::template Importer<T>;
        template <class T>
        using ImporterPtr = std::shared_ptr<Importer<T>>;
        template <class T>
        using Exporter = typename Monad::template Exporter<T>;
        template <class T>
        using ExporterPtr = std::shared_ptr<Exporter<T>>;
        template <class A, class B>
        using OnOrderFacility = typename Monad::template OnOrderFacility<A,B>;
        template <class A, class B>
        using OnOrderFacilityPtr = std::shared_ptr<OnOrderFacility<A,B>>;
        template <class A, class B, class C>
        using LocalOnOrderFacility = typename Monad::template LocalOnOrderFacility<A,B,C>;
        template <class A, class B, class C>
        using LocalOnOrderFacilityPtr = std::shared_ptr<LocalOnOrderFacility<A,B,C>>;

        template <class T>
        class Source {
        private:
            friend class MonadRunner;
            typename Monad::template Source<T> mSource;
            std::string producer;
            Source(typename Monad::template Source<T> &&s, std::string const &p) : mSource(std::move(s)), producer(p) {}
        public:
            Source<T> clone() const {
                return {mSource.clone(), producer};
            }
        };
        template <class T>
        class Sink {
        private:
            friend class MonadRunner;
            typename Monad::template Sink<T> mSink;
            std::string consumer;
            int pos;
            Sink(typename Monad::template Sink<T> &&s, std::string const &c, int p) : mSink(std::move(s)), consumer(c), pos(p) {}
        };
    private:
        Monad m_;
        StateT *env_;
        struct ActionCheckData {
            std::string name;
            int paramCount;
            std::vector<std::unordered_map<std::string,std::unordered_set<int>>> paramConnectedFrom;
            std::unordered_map<std::string,std::unordered_set<int>> outputConnectedTo;            
            bool isImporter = false;
            bool isExporter = false;

            ActionCheckData() : name(), paramCount(0), paramConnectedFrom(), outputConnectedTo(), isImporter(false), isExporter(false)
            {}

            ActionCheckData(std::string const &n, int c) : name(n), paramCount(c), paramConnectedFrom(), outputConnectedTo(), isImporter(false), isExporter(false)
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
                return d;
            }
            template <class A, class B, class C>
            static ActionCheckData createForLocalOnOrderFacility(LocalOnOrderFacility<A,B,C> *f, std::string const &n)
            {
                ActionCheckData d {n, 2};
                d.isImporter = false;
                d.isExporter = true;
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
        mutable std::mutex mutex_;

        template <class A, class B>
        void registerAction_(ActionPtr<A,B> const &f, std::string const &name) {
            void *p = (void *) (f.get());
            if (nameMap_.find(p) != nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to re-register an action with name '"+name+"'"
                );
            }
            nameMap_.insert({p, ActionCheckData::create(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
        }
        template <class A>
        void registerImporter_(ImporterPtr<A> const &f, std::string const &name) {
            void *p = (void *) (f.get());
            if (nameMap_.find(p) != nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to re-register an importer with name '"+name+"'"
                );
            }
            nameMap_.insert({p, ActionCheckData::template createForImporter<A>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
        }
        template <class A>
        void registerExporter_(ExporterPtr<A> const &f, std::string const &name) {
            void *p = (void *) (f.get());
            if (nameMap_.find(p) != nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to re-register an exporter with name '"+name+"'"
                );
            }
            nameMap_.insert({p, ActionCheckData::template createForExporter<A>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
        }
        template <class A, class B>
        void registerOnOrderFacility_(OnOrderFacilityPtr<A,B> const &f, std::string const &name) {
            void *p = (void *) (f.get());
            if (nameMap_.find(p) != nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to re-register an on-order facility with name '"+name+"'"
                );
            }
            nameMap_.insert({p, ActionCheckData::template createForOnOrderFacility<A,B>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
        }
        template <class A, class B, class C>
        void registerLocalOnOrderFacility_(LocalOnOrderFacilityPtr<A,B,C> const &f, std::string const &name) {
            void *p = (void *) (f.get());
            if (nameMap_.find(p) != nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to re-register a local on-order facility with name '"+name+"'"
                );
            }
            nameMap_.insert({p, ActionCheckData::template createForLocalOnOrderFacility<A,B,C>(f.get(), name)});
            reverseLookup_.insert({name, p});
            components_.push_back(std::static_pointer_cast<void>(f));
        }
        std::string checkName_(void *p) {
            auto iter = nameMap_.find(p);
            if (iter == nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to work on an unregistered item"
                );
            }
            return iter->second.name;
        }
        void connectAndCheck_(int pos, void *p, std::string const &producer, int colorCode=0) {
            auto iter = nameMap_.find(p);
            if (iter == nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to execute an unregistered action"
                );
            }
            if (producer == "") {
                throw MonadRunnerException(
                    "Attempt to connect pos "+std::to_string(pos+1)+" of '"+iter->second.name+"' from empty producer"
                );
            }
            iter->second.paramConnectedFrom[pos][producer].insert(colorCode);
            auto reverseIter = reverseLookup_.find(producer);
            if (reverseIter == reverseLookup_.end()) {
                throw MonadRunnerException(
                    "Attempt to connect pos "+std::to_string(pos+1)+" of "+iter->second.name+" from non-existent producer '"+producer+"'"
                );
            }
            auto sourceIter = nameMap_.find(reverseIter->second);
            if (sourceIter == nameMap_.end()) {
                throw MonadRunnerException(
                    "Attempt to connect pos "+std::to_string(pos+1)+" of "+iter->second.name+" from non-registered producer '"+producer+"'"
                );
            }
            sourceIter->second.outputConnectedTo[iter->second.name].insert(colorCode);
        }
        int nextColorCode() {
            int res = nextColorCode_+1;
            nextColorCode_ = (nextColorCode_+1)%10;
            return res;
        }
    public:
        class MonadRunnerException : public std::runtime_error {
        public:
            MonadRunnerException(std::string const &s) : std::runtime_error(s) {}
        };
        MonadRunner(StateT *env) : m_(), env_(env), nameMap_(), reverseLookup_(), nextColorCode_(0), components_(), otherPreservedPtrs_(), stateSharingRecords_(), mutex_() {}
        template <class T>
        MonadRunner(T t, StateT *env) : m_(t), env_(env), nameMap_(), reverseLookup_(), nextColorCode_(0), components_(), otherPreservedPtrs_(), stateSharingRecords_(), mutex_() {}
        MonadRunner(MonadRunner const &) = delete;
        MonadRunner &operator=(MonadRunner const &) = delete;
        MonadRunner(MonadRunner &&) = default;
        MonadRunner &operator=(MonadRunner &&) = default;
        ~MonadRunner() noexcept {
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
            registerImporter_<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType>(f, name);
        }
        template <class Imp>
        void registerImporter(std::string const &name, std::shared_ptr<Imp> const &f) {
            registerImporter_<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType>(f, name);
        }
        template <class Exp>
        void registerExporter(std::shared_ptr<Exp> const &f, std::string const &name) {
            registerExporter_<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType>(f, name);
        }
        template <class Exp>
        void registerExporter(std::string const &name, std::shared_ptr<Exp> const &f) {
            registerExporter_<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType>(f, name);
        }
        template <class Fac>
        void registerOnOrderFacility(std::shared_ptr<Fac> const &f, std::string const &name) {
            registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(f, name);
        }
        template <class Fac>
        void registerOnOrderFacility(std::string const &name, std::shared_ptr<Fac> const &f) {
            registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(f, name);
        }
        template <class Fac>
        void registerLocalOnOrderFacility(std::shared_ptr<Fac> const &f, std::string const &name) {
            registerLocalOnOrderFacility_<
                typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType>(f, name);
        }
        template <class Fac>
        void registerLocalOnOrderFacility(std::string const &name, std::shared_ptr<Fac> const &f) {
            registerLocalOnOrderFacility_<
                typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType>(f, name);
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType> importerAsSource(std::string const &name, std::shared_ptr<Imp> const &importer) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerImporter_<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType>(importer, name);
            }
            return { m_.template importerAsSource<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType>(env_, *importer), name };
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType> importerAsSource(std::shared_ptr<Imp> const &importer) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) importer.get());
            }
            return { m_.template importerAsSource<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType>(env_, *importer), name };
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType> importItem(std::string const &name, std::shared_ptr<Imp> const &importer) {
            return importerAsSource<Imp>(name, importer);
        }
        template <class Imp>
        Source<typename withtime_utils::ImporterTypeInfo<Monad,Imp>::DataType> importItem(std::shared_ptr<Imp> const &importer) {
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
                connectAndCheck_(0, (void *) f.get(), x.producer);
            }
            return { m_.execute(*f, std::move(x.mSource)), name };
        }
        template <class A, class B>
        Source<B> execute(ActionPtr<A,B> const &f, Source<A> &&x) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                connectAndCheck_(0, (void *) f.get(), x.producer);
                name = nameMap_[(void *) f.get()].name;
            }
            return { m_.execute(*f, std::move(x.mSource)), name };
        }

        #include <tm_kit/infra/WithTimeData_VariantExecute_Piece.hpp>

        template <class Exp>
        void exportItem(std::string const &name, std::shared_ptr<Exp> const &f, Source<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType> &&x) {
            connect(std::move(x), exporterAsSink<Exp>(name, f));
        }
        template <class Exp>
        void exportItem(std::shared_ptr<Exp> const &f, Source<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType> &&x) {
            connect(std::move(x), exporterAsSink<Exp>(f));
        }
        template <class Fac>
        void feedItemToLocalFacility(std::string const &name, std::shared_ptr<Fac> const &f, Source<typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType> &&x) {
            connect(std::move(x), localFacilityAsSink<Fac>(name, f));
        }
        template <class Fac>
        void feedItemToLocalFacility(std::shared_ptr<Fac> const &f, Source<typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType> &&x) {
            connect(std::move(x), localFacilityAsSink<Fac>(f));
        }
        
        template <class Exp>
        Sink<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType> exporterAsSink(std::string const &name, std::shared_ptr<Exp> const &exporter) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerExporter_<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType>(exporter, name);
            }
            return { m_.template exporterAsSink<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType>(*exporter), name, 0 };
        }
        template <class Exp>
        Sink<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType> exporterAsSink(std::shared_ptr<Exp> const &exporter) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) exporter.get());
            }
            return { m_.template exporterAsSink<typename withtime_utils::ExporterTypeInfo<Monad,Exp>::DataType>(*exporter), name, 0 };
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
        Sink<typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType> localFacilityAsSink(std::string const &name, std::shared_ptr<Fac> const &facility) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerLocalOnOrderFacility_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                    , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType>(facility, name);
            }
            return { m_.template localFacilityAsSink<
                            typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                            , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                            , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType>(*facility)
                     , name, 1 };
        }
        template <class Fac>
        Sink<typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType> localFacilityAsSink(std::shared_ptr<Fac> const &facility) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) facility.get());
            }
            return { m_.template localFacilityAsSink<
                            typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                            , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                            , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType>(*facility)
                     , name, 1 };
        }

        #include <tm_kit/infra/WithTimeData_VariantSink_Piece.hpp>

        template <class Fac>
        void placeOrderWithFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType, StateT>> const &sink) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(f, name);
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw MonadRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color);
            }
            m_.template placeOrderWithFacility<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType, StateT>> const &sink) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) f.get());
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw MonadRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color);
            }
            m_.template placeOrderWithFacility<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::mutex> _(mutex_);
                registerOnOrderFacility_<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(f, name);
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
            }
            m_.template placeOrderWithFacilityAndForget<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(std::move(input.mSource), *f);
        }
        template <class Fac>
        void placeOrderWithFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::mutex> _(mutex_);
                checkName_((void *) f.get());
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
            }
            m_.template placeOrderWithFacilityAndForget<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType>(std::move(input.mSource), *f);
        }

        template <class Fac>
        void placeOrderWithLocalFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType, StateT>> const &sink) {
            {
                std::lock_guard<std::mutex> _(mutex_);
                registerLocalOnOrderFacility_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                    , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType
                    >(f, name);
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw MonadRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color);
            }
            m_.template placeOrderWithLocalFacility<
                typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithLocalFacility(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f
            , Sink<KeyedData<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType, StateT>> const &sink) {
            std::string name;
            {
                std::lock_guard<std::mutex> _(mutex_);
                name = checkName_((void *) f.get());
                int color = nextColorCode();
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
                auto iter = reverseLookup_.find(sink.consumer);
                if (iter == reverseLookup_.end()) {
                    throw MonadRunnerException(
                        "No such sink '"+sink.consumer+"'"
                    );
                }
                connectAndCheck_(sink.pos, iter->second, name, color);
            }
            m_.template placeOrderWithLocalFacility<
                typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType
                >(std::move(input.mSource), *f, sink.mSink);
        }
        template <class Fac>
        void placeOrderWithLocalFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::string const &name
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::mutex> _(mutex_);
                registerLocalOnOrderFacility_<
                    typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                    , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                    , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType
                    >(f, name);
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
            }
            m_.template placeOrderWithLocalFacilityAndForget<
                typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType
                >(std::move(input.mSource), *f);
        }
        template <class Fac>
        void placeOrderWithLocalFacilityAndForget(
            Source<Key<typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType, StateT>> &&input
            , std::shared_ptr<Fac> const &f) {
            {
                int color = nextColorCode();
                std::lock_guard<std::mutex> _(mutex_);
                checkName_((void *) f.get());
                connectAndCheck_(0, (void *) f.get(), input.producer, color);
            }
            m_.template placeOrderWithLocalFacilityAndForget<
                typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::InputType
                , typename withtime_utils::OnOrderFacilityTypeInfo<Monad,Fac>::OutputType
                , typename withtime_utils::ExporterTypeInfo<Monad,Fac>::DataType
                >(std::move(input.mSource), *f);
        }

        template <class T>
        void connect(Source<T> &&source, Sink<T> const &sink) {
            std::lock_guard<std::mutex> _(mutex_);
            auto iter = reverseLookup_.find(sink.consumer);
            if (iter == reverseLookup_.end()) {
                throw MonadRunnerException(
                    "No such sink '"+sink.consumer+"'"
                );
            }
            connectAndCheck_(sink.pos, iter->second, source.producer);
            m_.connect(std::move(source.mSource), sink.mSink);
        }

        void writeGraphVizDescription(std::ostream &os, std::string const &graphName) const {
            std::lock_guard<std::mutex> _(mutex_);
            os << "digraph " << graphName << "{\n";
            int counter = 1;
            std::unordered_map<std::string, int> m;
            for (auto const &item : nameMap_) {
                m[item.second.name] = counter;
                os << "\t action" << counter << " [";
                if (item.second.paramCount > 1) {
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
                os << "];\n";
                ++counter;
            }
            for (auto const &item : nameMap_) {   
                for (int ii=0; ii<item.second.paramCount; ++ii) {
                    for (auto const &src : item.second.paramConnectedFrom[ii]) {
                        auto iter1 = reverseLookup_.find(src.first);
                        auto iter2 = nameMap_.find(iter1->second);
                        bool isExternal = iter2->second.isImporter || item.second.isExporter;
                        for (auto color : src.second) {
                            if (item.second.paramCount > 1) {
                                os << "\t action" << m[src.first] << " -> action" << m[item.second.name] << ":arg" << ii;
                            } else {
                                os << "\t action" << m[src.first] << " -> action" << m[item.second.name];
                            }   
                            if (color != 0 && isExternal && ii == 0) {
                                os << " [style=dotted,colorscheme=spectral11,color=" << color << "]";
                            } else if (isExternal && ii == 0) {
                                os << " [style=dotted]";
                            } else if (color != 0) {
                                os << " [style=dashed,colorscheme=spectral11,color=" << color << "]";
                            }
                            os << ";\n";
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
            for (auto const &sharing : stateSharingRecords_) {
                if (sharing.second != "") {
                    auto stateIdx = stateNames[sharing.second];
                    auto name1Idx = m[std::get<0>(sharing.first)];
                    auto name2Idx = m[std::get<1>(sharing.first)];
                    os << "\t action" << name1Idx << " -> state" << stateIdx << " [dir=none,style=bold];\n";
                    os << "\t action" << name2Idx << " -> state" << stateIdx << " [dir=none,style=bold];\n";
                } else {
                    auto name1Idx = m[std::get<0>(sharing.first)];
                    auto name2Idx = m[std::get<1>(sharing.first)];
                    os << "\t action" << name1Idx << " -> action" << name2Idx << " [dir=none,style=bold];\n";
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
                    for (int ii=0; ii<item.second.paramCount; ++ii) {
                        if (item.second.paramConnectedFrom[ii].empty()) {
                            throw MonadRunnerException(
                                "Action '"+item.second.name+"''s parameter in position "+std::to_string(ii+1)+" has not been connected!"
                            );
                        }
                    }
                    if (item.second.outputConnectedTo.empty() && !item.second.isExporter) {
                        throw MonadRunnerException(
                            "Action '"+item.second.name+"''s output has not been connected!"
                        );
                    }
                }
                auto cycleRet = detectCycle(false);
                if (cycleRet) {
                    throw MonadRunnerException(
                        "There is a circle starting from '"+(*cycleRet)+"'"
                    );
                }
                cycleRet = detectCycle(true);
                if (cycleRet) {
                    env_->log(LogLevel::Warning,
                        "There is a circle involving on-order facility starting from '" + (*cycleRet) + "'"
                    );
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
                throw MonadRunnerException(
                    "Cannot mark a state sharing between two identical components"
                );
            }
            auto smallerName = std::min(name1, name2);
            auto biggerName = std::max(name1, name2);
            stateSharingRecords_[{smallerName, biggerName}] = sharedStateName;
        }

        
        template <class A, class B>
        using FacilitioidConnector =
            std::function<void(MonadRunner &, Source<typename Monad::template Key<A>> &&, Sink<typename Monad::template KeyedData<A,B>> const &)>;
        template <class A, class B>
        using FacilityWrapper =
            std::optional<std::function<void(MonadRunner &, OnOrderFacilityPtr<A,B> const &)>>;
        template <class A, class B, class C>
        using LocalFacilityWrapper =
            std::optional<std::function<void(MonadRunner &, LocalOnOrderFacilityPtr<A,B,C> const &)>>;

        template <class A, class B>
        static FacilitioidConnector<A,B> facilityConnector(OnOrderFacilityPtr<A,B> const &facility) {
            return [facility](MonadRunner &r, Source<typename Monad::template Key<A>> &&source, Sink<typename Monad::template KeyedData<A,B>> const &sink) {
                r.placeOrderWithFacility(std::move(source), facility, sink);
            };
        }
        template <class A, class B, class C>
        static FacilitioidConnector<A,B> localFacilityConnector(LocalOnOrderFacilityPtr<A,B,C> const &facility) {
            return [facility](MonadRunner &r, Source<typename Monad::template Key<A>> &&source, Sink<typename Monad::template KeyedData<A,B>> const &sink) {
                r.placeOrderWithLocalFacility(std::move(source), facility, sink);
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

}}}}

#endif
