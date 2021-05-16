#ifndef TM_KIT_INFRA_CONTROLLABLE_NODE_HPP_
#define TM_KIT_INFRA_CONTROLLABLE_NODE_HPP_

#include <vector>
#include <string>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    template <class Env>
    class IControllableNode {
    public:
        virtual ~IControllableNode() = default;
        virtual void control(Env *env, std::string const &command, std::vector<std::string> const &params) = 0;
    };
} } } }

#endif