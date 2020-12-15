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
        void writeTrace(Env *env, void *p, std::string const &suffix, char phase) const {
            auto const *n = nodeName(p);
            if (!n) {
                return;
            }
            std::ostringstream oss;
            oss << "{\"name\": \"" << *n << suffix << "\""
                << ",\"pid\": " << pid_
                << ",\"tid\": " << std::hash<std::thread::id>()(std::this_thread::get_id())
                << ",\"ph\": \"" << phase << "\""
                << ",\"ts\": " << static_cast<int64_t>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())
                << "}";
            env->log(LogLevel::Trace, oss.str());
        }
    };

    template <class Env, bool HasTraceComponent = std::is_convertible_v<Env *, TraceNodesComponent *>>
    class TraceNodesComponentWrapper {};

    template <class Env>
    class TraceNodesComponentWrapper<Env, true> {
    private:
        Env *env_;
        void *p_;
        std::string suffix_;
    public:
        TraceNodesComponentWrapper(Env *env, void *p, std::string const &suffix="") : env_(env), p_(p), suffix_(suffix==""?"":(":"+suffix)) {
            env_->template writeTrace<Env>(env_, p_, suffix_, 'B');
        }
        ~TraceNodesComponentWrapper() {
            env_->template writeTrace<Env>(env_, p_, suffix_, 'E');
        }
    };
    template <class Env>
    class TraceNodesComponentWrapper<Env, false> {
    public:
        TraceNodesComponentWrapper(Env *env, void *p, std::string const &suffix="") {}
        ~TraceNodesComponentWrapper() {}
    };

    #define TM_INFRA_IMPORTER_TRACER(data) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper<std::remove_pointer_t<decltype(data.environment)>> _tracer( \
            data.environment \
            , (void *) (static_cast<decltype(this->nullptrToInheritedImporter())>(this)) \
        );
    #define TM_INFRA_EXPORTER_TRACER(data) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper<std::remove_pointer_t<decltype(data.environment)>> _tracer( \
            data.environment \
            , (void *) (static_cast<decltype(this->nullptrToInheritedExporter())>(this)) \
        );
    #define TM_INFRA_FACILITY_TRACER(data) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper<std::remove_pointer_t<decltype(data.environment)>> _tracer( \
            data.environment \
            , (void *) (static_cast<decltype(this->nullptrToInheritedFacility())>(this)) \
        );
    #define TM_INFRA_IMPORTER_TRACER_WITH_SUFFIX(data,suffix) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper<std::remove_pointer_t<decltype(data.environment)>> _tracer( \
            data.environment \
            , (void *) (static_cast<decltype(this->nullptrToInheritedImporter())>(this)) \
            , suffix \
        );
    #define TM_INFRA_EXPORTER_TRACER_WITH_SUFFIX(data,suffix) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper<std::remove_pointer_t<decltype(data.environment)>> _tracer( \
            data.environment \
            , (void *) (static_cast<decltype(this->nullptrToInheritedExporter())>(this)) \
            , suffix \
        );
    #define TM_INFRA_FACILITY_TRACER_WITH_SUFFIX(data,suffix) \
        dev::cd606::tm::infra::TraceNodesComponentWrapper<std::remove_pointer_t<decltype(data.environment)>> _tracer( \
            data.environment \
            , (void *) (static_cast<decltype(this->nullptrToInheritedFacility())>(this)) \
            , suffix \
        );
} } } }

#endif