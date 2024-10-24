#include <tm_kit/infra/GraphStructureBasedResourceHolderComponent.hpp>
#include <sstream>
#include <unordered_set>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    thread_local std::unordered_map<GraphStructureBasedResourceHolderComponent *, void *> GraphStructureBasedResourceHolderComponent::currentNodes_;
    std::unordered_map<void *, void *> GraphStructureBasedResourceHolderComponent::parentMap_;
    std::mutex GraphStructureBasedResourceHolderComponent::parentMapMutex_;

    std::vector<std::string> GraphStructureBasedResourceHolderComponent::splitNodeName(std::string const &s) {
        auto l = s.length();
        std::size_t x = 0;
        auto y = s.find_first_of('/');
        std::vector<std::string> ret;
        while (x < l) {
            if (y == std::string::npos) {
                ret.push_back(s.substr(x));
                break;
            }
            if (x < y) {
                ret.push_back(s.substr(x,y-x));
            }
            x = y+1;
            y = s.find_first_of('/', x);
        }
        return ret;
    }
    std::string GraphStructureBasedResourceHolderComponent::joinNodeName(std::vector<std::string> const &v) {
        if (v.size() == 0) {
            return "/";
        }
        std::ostringstream oss;
        for (std::size_t ii=0; ii<v.size(); ++ii) {
            if (v[ii] != "") {
                oss << '/' << v[ii];
            }
        }
        return oss.str();
    }
    std::vector<std::string> GraphStructureBasedResourceHolderComponent::nodePrefixes(std::vector<std::string> const &v) {
        std::vector<std::string> ret;
        ret.push_back("/");
        std::ostringstream oss;
        for (std::size_t ii=0; ii<v.size(); ++ii) {
            if (v[ii] != "") {
                oss << '/' << v[ii];
                ret.push_back(oss.str());
            }
        }
        return ret;
    }
    void GraphStructureBasedResourceHolderComponent::registerParentNode(void *childNode, void *parentNode) {
        std::lock_guard<std::mutex> _(parentMapMutex_);
        parentMap_[childNode] = parentNode;
    }
    void GraphStructureBasedResourceHolderComponent::resolveResourceForOneNode(void *n, std::string const &nm) {
        auto parts = splitNodeName(nm);
        resolvedResourceMap_[n] = {};
        auto prefixes = nodePrefixes(parts);
        for (auto const &p : prefixes) {
            auto iter = resourceMap_.find(p);
            if (iter != resourceMap_.end()) {
                for (auto const &resource : iter->second) {
                    resolvedResourceMap_[n][resource.first] = resource.second;
                }
            }
        }
    }
    void GraphStructureBasedResourceHolderComponent::addNodeNameRegistration(void *n, std::string const &name) {
        std::lock_guard<std::mutex> _(mutex_);
        auto parts = splitNodeName(name);
        auto regularizedName = joinNodeName(parts);
        nodeNameMap_[n] = regularizedName;
    }
    void GraphStructureBasedResourceHolderComponent::resolveAllResources() {
        std::lock_guard<std::mutex> _(mutex_);
        if (finalized_) {
            throw GraphStructureBasedResourceHolderComponentException("Resources can only be resolved once");
        }
        finalized_ = true;
        for (auto const &item : nodeNameMap_) {
            resolveResourceForOneNode(item.first, item.second);
        }
        {
            std::lock_guard<std::mutex> _(parentMapMutex_);
            std::unordered_set<void *> toRemove;
            for (auto const &parentItem : parentMap_) {
                void *n = parentItem.first;
                void *p = parentItem.second;
                while (true) {
                    auto iter = parentMap_.find(p);
                    if (iter == parentMap_.end()) {
                        break;
                    }
                    p = iter->second;
                }
                if (p != nullptr) {
                    if (nodeNameMap_.find(p) != nodeNameMap_.end()) {
                        nodeNameMap_[n] = nodeNameMap_[p];
                        toRemove.insert(n);
                    }
                    if (resolvedResourceMap_.find(p) != resolvedResourceMap_.end()) {
                        resolvedResourceMap_[n] = resolvedResourceMap_[p];
                    }
                }
            }
            for (void *n : toRemove) {
                parentMap_.erase(n);
            }
        }
    }
} } } }
