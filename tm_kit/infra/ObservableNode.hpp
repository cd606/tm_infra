#ifndef TM_KIT_INFRA_OBSERVABLE_NODE_HPP_
#define TM_KIT_INFRA_OBSERVABLE_NODE_HPP_

#include <vector>
#include <string>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class Env>
    class IObservableNode {
    public:
        virtual ~IObservableNode() = default;
        virtual std::vector<std::string> observe(Env *) const = 0;
    };
} } } }

#endif