#include <tm_kit/infra/GraphStructureBasedResourceHolderComponent.hpp>
#include <sstream>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    thread_local std::unordered_map<GraphStructureBasedResourceHolderComponent *, void *> GraphStructureBasedResourceHolderComponent::currentNodes_;

    std::vector<std::string> GraphStructureBasedResourceHolderComponent::splitNodeName(std::string const &s) {
        auto l = s.length();
        auto x = 0;
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
            oss << '/' << v[ii];
        }
        return oss.str();
    }
    std::vector<std::string> GraphStructureBasedResourceHolderComponent::nodePrefixes(std::vector<std::string> const &v) {
        std::vector<std::string> ret;
        ret.push_back("/");
        std::ostringstream oss;
        for (std::size_t ii=0; ii<v.size(); ++ii) {
            oss << '/' << v[ii];
            ret.push_back(oss.str());
        }
        return ret;
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
    }
} } } }