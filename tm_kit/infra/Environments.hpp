#ifndef TM_KIT_INFRA_BASIC_ENVIRONMENTS_HPP_
#define TM_KIT_INFRA_BASIC_ENVIRONMENTS_HPP_

#include <iostream>
#include <chrono>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    //an environment is simply a mixture of components
    template <class ... Components>
    class Environment : public Components... {
    public:
        Environment() : Components()... {}
        Environment(Components const &... components) : Components(components)... {}
        Environment(Components &&... components) : Components(std::move(components))... {}
    };

    //The "checktime" component
    template <bool DoCheck>
    struct CheckTimeComponent {
        static constexpr bool CheckTime = DoCheck;
    };

} } } }

#endif
