#ifndef TM_KIT_INFRA_GRAPH_STRUCTURE_BASED_RESOURCE_HOLDER_COMPONENT_HPP_
#define TM_KIT_INFRA_GRAPH_STRUCTURE_BASED_RESOURCE_HOLDER_COMPONENT_HPP_

#include <unordered_map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <any>
#include <mutex>
#include <vector>
#include <type_traits>
#include <optional>
#include <atomic>
#include <exception>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    class GraphStructureBasedResourceHolderComponentException : public std::runtime_error {
    public:
        GraphStructureBasedResourceHolderComponentException(std::string const &msg) : std::runtime_error(msg) {}
    };
    class GraphStructureBasedResourceHolderComponent {
    private:
        static thread_local std::unordered_map<GraphStructureBasedResourceHolderComponent *, void *> currentNodes_;
        static std::unordered_map<void *, void *> parentMap_;
        static std::mutex parentMapMutex_;
        std::unordered_map<void *, std::string> nodeNameMap_;
        std::unordered_map<std::string, std::unordered_map<std::type_index, std::any>> resourceMap_;
        std::unordered_map<void *, std::unordered_map<std::type_index, std::any>> resolvedResourceMap_;
        std::mutex mutex_;
        static std::vector<std::string> splitNodeName(std::string const &s);
        static std::string joinNodeName(std::vector<std::string> const &v);
        static std::vector<std::string> nodePrefixes(std::vector<std::string> const &v);
        void resolveResourceForOneNode(void *n, std::string const &nm);
        std::atomic<bool> finalized_ = false;
    public:
        void setCurrentNode(void *node) {
            currentNodes_[this] = node;
        }
        static void registerParentNode(void *childNode, void *parentNode);
    private:
        void *currentNode() {
            auto iter = currentNodes_.find(this);
            if (iter == currentNodes_.end()) {
                return nullptr;
            }
            return iter->second;
        }
    public:
        template <class T, typename=std::enable_if_t<std::is_copy_constructible_v<T>>>
        void registerResource(std::string const &scopeName, T const &resource) {
            if (finalized_) {
                throw GraphStructureBasedResourceHolderComponentException("Cannot register more resources after the resource map has been finalized");
            }
            std::lock_guard<std::mutex> _(mutex_);
            auto regularizedName = joinNodeName(splitNodeName(scopeName));
            resourceMap_[regularizedName][std::type_index(typeid(std::decay_t<T>))] = std::any {resource};
        }
    private:
        template <class M>
        friend class AppRunner;

        void addNodeNameRegistration(void *n, std::string const &name);
        void resolveAllResources();
    public:
        //This one has no mutex lock
        //because resolveAllResources() should have been called before this.
        //
        //There is a slight chance of race condition where finalize check is
        //done right before the resources are finalized, however, the chance of
        //this is so slight that it is probably not worth it to apply the mutex
        template <class T, typename=std::enable_if_t<std::is_copy_constructible_v<T>>>
        std::optional<T> getResource() {
            if (!finalized_) {
                throw GraphStructureBasedResourceHolderComponentException("Cannot query for resources before resource map has been finalized");
            }
            auto iter = resolvedResourceMap_.find(currentNode());
            if (iter == resolvedResourceMap_.end()) {
                return std::nullopt;
            }
            auto innerIter = iter->second.find(std::type_index(typeid(std::decay_t<T>)));
            if (innerIter == iter->second.end()) {
                return std::nullopt;
            }
            return {std::any_cast<T>(innerIter->second)};
        }
        //This one also has no mutex lock for the same reason
        std::optional<std::string> currentNodeName() {
            if (!finalized_) {
                throw GraphStructureBasedResourceHolderComponentException("Cannot query for node map before resource map has been finalized");
            }
            auto iter = nodeNameMap_.find(currentNode());
            if (iter == nodeNameMap_.end()) {
                return std::nullopt;
            }
            return {iter->second};
        }
    };

    template <class Env>
    class GraphStructureBasedResourceHolderComponent_CurrentNodeSetter {
    private:
        Env *env_;
    public:
        GraphStructureBasedResourceHolderComponent_CurrentNodeSetter(Env *env, void *p) : env_(env) {
            if constexpr (std::is_convertible_v<Env *, GraphStructureBasedResourceHolderComponent *>) {
                env->GraphStructureBasedResourceHolderComponent::setCurrentNode(p);
            }
        }
        ~GraphStructureBasedResourceHolderComponent_CurrentNodeSetter() {
            if constexpr (std::is_convertible_v<Env *, GraphStructureBasedResourceHolderComponent *>) {
                env_->GraphStructureBasedResourceHolderComponent::setCurrentNode(nullptr);
            }
        }
    };
} } } }

#endif