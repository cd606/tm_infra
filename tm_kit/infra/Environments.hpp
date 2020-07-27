#ifndef TM_KIT_INFRA_BASIC_ENVIRONMENTS_HPP_
#define TM_KIT_INFRA_BASIC_ENVIRONMENTS_HPP_

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <atomic>

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
    //The "exit control" component
    struct TrivialExitControlComponent {
        static constexpr bool running() {
            return true;
        }
        static void exit() {
            std::exit(0);
        }
    };
    //The "exit control by a flag" component 
    class FlagExitControlComponent {
    private:
        std::atomic<bool> running_ = true;
    public:
        bool running() const {
            return running_;
        }
        void exit() {
            running_ = false;
        }
    };

} } } }

#endif
