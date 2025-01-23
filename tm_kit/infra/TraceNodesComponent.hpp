#ifndef TM_KIT_INFRA_TRACE_NODES_COMPONENT_HPP_
#define TM_KIT_INFRA_TRACE_NODES_COMPONENT_HPP_

#include <iostream>
#include <sstream>
#include <chrono>
#include <type_traits>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <fstream>

#include <tm_kit/infra/PidUtil.hpp>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    class TraceNodesComponent {
    private:
        int64_t pid_;
        std::unordered_map<void *, std::string> nodeNameMap_;
        std::mutex traceStreamMutex_;
        std::mutex mtx_;
        std::atomic<std::ostream*> traceStream_;
        std::unique_ptr<std::ostream> os_;
        bool isFirst_;

    private:
        template <class Env>
        void writeTrace(Env *env, int64_t tid, std::string const *name, char phase) {
            if (!name) {
                return;
            }
            auto p = traceStream_.load(std::memory_order_acquire);
            if (!p) {
                return;
            }
            if (phase != 'B' && phase != 'E') {
                return;
            }
            auto timestamp = static_cast<int64_t>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
            std::lock_guard<std::mutex> _(traceStreamMutex_);
            if (isFirst_) {
                (*p) << "[\n";
                isFirst_ = false;
            } else {
                (*p) << ",\n";
            }
            (*p) << "{\"name\": \"" << *name << "\""
                << ",\"pid\": " << pid_
                << ",\"tid\": " << tid
                << ",\"ph\": \"" << phase << "\""
                << ",\"ts\": " << timestamp
                << "}";
        }
    public:
        TraceNodesComponent() : pid_(pid_util::getpid()), nodeNameMap_(), traceStreamMutex_(), traceStream_(nullptr), isFirst_(true) {}
        TraceNodesComponent(TraceNodesComponent const &) = delete;
        TraceNodesComponent(TraceNodesComponent &&) = delete;
        TraceNodesComponent &operator=(TraceNodesComponent const &) = delete;
        TraceNodesComponent &operator=(TraceNodesComponent &&) = delete;
        ~TraceNodesComponent() {
            auto p = traceStream_.load(std::memory_order_acquire);
            if (p) {
                std::lock_guard<std::mutex> _(traceStreamMutex_);
                (*p) << "\n]\n";
            }
        }
        
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

        void setTraceStream(std::ostream* s) {
            if (traceStream_.load(std::memory_order_relaxed)) {
                return;
            }
            std::lock_guard<std::mutex> _(mtx_);
            if (traceStream_.load(std::memory_order_relaxed)) {
                return;
            }
            traceStream_.store(s, std::memory_order_relaxed);
        }
        
        void setTraceFile(std::string const& filename) {
            if (traceStream_.load(std::memory_order_relaxed)) {
                return;
            }
            std::lock_guard<std::mutex> _(mtx_);
            if (traceStream_.load(std::memory_order_relaxed)) {
                return;
            }
            if (os_) {
                return;
            }
            auto ofs = new std::ofstream(filename, std::ofstream::out);
            if (!ofs->is_open()) {
                throw std::runtime_error("Cannot open trace file: " + filename);
            }
            os_.reset(ofs);
            traceStream_.store(os_.get(), std::memory_order_relaxed);
        }

        template <class Env>
        void writeBeginTrace(Env* env, int64_t tid, std::string const *name) {
            writeTrace(env, tid, name, 'B');
        }

        template <class Env>
        void writeEndTrace(Env* env, int64_t tid, std::string const *name) {
            writeTrace(env, tid, name, 'E');
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
        int64_t tid_;
    public:
        template <class T>
        TraceNodesComponentWrapper(Env *env, T *p, std::string const &suffix="") : env_(env), good_(false), name_(), tid_(0) {
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
                tid_ = std::hash<std::thread::id>()(std::this_thread::get_id());
                env_->template writeBeginTrace<Env>(env_, tid_, &name_);
            }
        }
        ~TraceNodesComponentWrapper() {
            if (good_) {
                env_->template writeEndTrace<Env>(env_, tid_, &name_);
            }
        }
    };
    template <class Env, class BaseClass>
    class TraceNodesComponentWrapper<Env, BaseClass, false> {
    public:
        template <class T>
        TraceNodesComponentWrapper(Env */*env*/, T */*p*/, std::string const &/*suffix*/="") {}
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