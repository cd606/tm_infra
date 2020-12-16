#ifndef TM_KIT_INFRA_TRACE_NODES_COMPONENT_HPP_
#define TM_KIT_INFRA_TRACE_NODES_COMPONENT_HPP_

#include <iostream>
#include <sstream>
#include <chrono>
#include <type_traits>
#include <unordered_map>
#include <thread>

#include <tm_kit/infra/PidUtil.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    class TraceNodesComponent {
    private:
        int64_t pid_;
        std::unordered_map<void *, std::string> nodeNameMap_;
    public:
        TraceNodesComponent() : pid_(pid_util::getpid()), nodeNameMap_() {}
        TraceNodesComponent(TraceNodesComponent const &) = default;
        TraceNodesComponent(TraceNodesComponent &&) = default;
        TraceNodesComponent &operator=(TraceNodesComponent const &) = default;
        TraceNodesComponent &operator=(TraceNodesComponent &&) = default;
        ~TraceNodesComponent() = default;
        
        //Please note that the methods are not mutex protected
        void setNodeNameMap(std::unordered_map<void *, std::string> const &m) {
            nodeNameMap_ = m;
        }
        std::string const *nodeName(void *p) const {
            auto iter = nodeNameMap_.find(p);
            if (iter == nodeNameMap_.end()) {
                return nullptr;
            } else {
                return &(iter->second);
            }
        }
        template <class Env>
        void writeTrace(Env *env, std::string const *name, char phase) const {
            if (!name) {
                return;
            }
            std::ostringstream oss;
            oss << "{\"name\": \"" << *name << "\""
                << ",\"pid\": " << pid_
                << ",\"tid\": " << std::hash<std::thread::id>()(std::this_thread::get_id())
                << ",\"ph\": \"" << phase << "\""
                << ",\"ts\": " << static_cast<int64_t>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())
                << "}";
            env->log(LogLevel::Trace, oss.str());
        }
    };

    template <class Env, class BaseClass, bool HasTraceComponent = std::is_convertible_v<Env *, TraceNodesComponent *>>
    class TraceNodesComponentWrapper {};

    template <class Env, class BaseClass>
    class TraceNodesComponentWrapper<Env, BaseClass, true> {
    private:
        Env *env_;
        bool good_;
        std::string name_;
    public:
        template <class T>
        TraceNodesComponentWrapper(Env *env, T *p, std::string const &suffix="") : env_(env), good_(false), name_() {
            auto const *n = env_->nodeName(static_cast<BaseClass *>(p));
            if (n == nullptr) {
                good_ = false;
            } else {
                good_ = true;
                if (suffix == "") {
                    name_ = *n;
                } else {
                    name_ = (*n)+suffix;
                }
                env_->template writeTrace<Env>(env_, &name_, 'B');
            }
        }
        ~TraceNodesComponentWrapper() {
            if (good_) {
                env_->template writeTrace<Env>(env_, &name_, 'E');
            }
        }
    };
    template <class Env, class BaseClass>
    class TraceNodesComponentWrapper<Env, BaseClass, false> {
    public:
        template <class T>
        TraceNodesComponentWrapper(Env *env, T *p, std::string const &suffix="") {}
        ~TraceNodesComponentWrapper() {}
    };

    #define TM_INFRA_IMPORTER_TRACER(env) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper< \
            std::decay_t<std::remove_pointer_t<decltype(env)>> \
            , std::decay_t<std::remove_pointer_t<decltype(this->nullptrToInheritedImporter())>> \
        > _tracer( \
            env \
            , this \
        );
    #define TM_INFRA_EXPORTER_TRACER(env) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper< \
            std::decay_t<std::remove_pointer_t<decltype(env)>> \
            , std::decay_t<std::remove_pointer_t<decltype(this->nullptrToInheritedExporter())>> \
        > _tracer( \
            env \
            , this \
        );
    #define TM_INFRA_FACILITY_TRACER(env) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper< \
            std::decay_t<std::remove_pointer_t<decltype(env)>> \
            , std::decay_t<std::remove_pointer_t<decltype(this->nullptrToInheritedFacility())>> \
        > _tracer( \
            env \
            , this \
        );
    #define TM_INFRA_IMPORTER_TRACER_WITH_SUFFIX(env, suffix) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper< \
            std::decay_t<std::remove_pointer_t<decltype(env)>> \
            , std::decay_t<std::remove_pointer_t<decltype(this->nullptrToInheritedImporter())>> \
        > _tracer( \
            env \
            , this \
            , suffix \
        );
    #define TM_INFRA_EXPORTER_TRACER_WITH_SUFFIX(env, suffix) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper< \
            std::decay_t<std::remove_pointer_t<decltype(env)>> \
            , std::decay_t<std::remove_pointer_t<decltype(this->nullptrToInheritedExporter())>> \
        > _tracer( \
            env \
            , this \
            , suffix \
        );
    #define TM_INFRA_FACILITY_TRACER_WITH_SUFFIX(env, suffix) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper< \
            std::decay_t<std::remove_pointer_t<decltype(env)>> \
            , std::decay_t<std::remove_pointer_t<decltype(this->nullptrToInheritedFacility())>> \
        > _tracer( \
            env \
            , this \
            , suffix \
        );
} } } }

#endif