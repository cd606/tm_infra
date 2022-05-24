#ifndef TM_KIT_INFRA_BASIC_ENVIRONMENTS_HPP_
#define TM_KIT_INFRA_BASIC_ENVIRONMENTS_HPP_

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <atomic>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    //an environment is simply a mixture of components
    template <class ... Components>
    class Environment : public virtual Components... {
    private:
        template <class X>
        struct TrueType : std::true_type {};
        template <class X>
        static auto hasFinalizeEnvironment(int) -> TrueType<decltype(std::declval<X>().finalizeEnvironment())>;
        template <class X>
        static auto hasFinalizeEnvironment(long) -> std::false_type;

        template <class FirstComponent, class... RemainingComponents>
        void internal_finalizeEnvironment() {
            if constexpr (decltype(hasFinalizeEnvironment<FirstComponent>(0))::value) {
                this->FirstComponent::finalizeEnvironment();
            }
            if constexpr (sizeof...(RemainingComponents) > 0) {
                internal_finalizeEnvironment<RemainingComponents...>();
            }
        }
    public:
        Environment() : Components()... {}
        Environment(Components const &... components) : Components(components)... {}
        Environment(Components &&... components) : Components(std::move(components))... {}

        void finalizeEnvironment() {
            internal_finalizeEnvironment<Components...>();
        }
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
        static void exit(int status=0) {
            std::exit(status);
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
        void exit(int /*status*/=0) {
            running_ = false;
        }
    };
    //The "hold a value" component
    template <class T>
    class ConstValueHolderComponent {
    private:
        T t_;
    public:
        ConstValueHolderComponent() : t_() {}
        ConstValueHolderComponent(T &&t) : t_(std::move(t)) {}
        template <class... Ts>
        ConstValueHolderComponent(Ts &&... ts) : t_(ts...) {}
        ConstValueHolderComponent(ConstValueHolderComponent const &) = default;
        ConstValueHolderComponent(ConstValueHolderComponent &&) = default;
        ConstValueHolderComponent &operator=(ConstValueHolderComponent const &) = default;
        ConstValueHolderComponent &operator=(ConstValueHolderComponent &&) = default;
        ~ConstValueHolderComponent() {}

        T const &value() const {
            return t_;
        }
    };
    //This marks hidden time dependency inside the environment
    //Currently this affects TopDown execution scheme, but it may
    //affect others in the future
    class HiddenTimeDependencyComponent {};

    //this class is provided for template specialization purposes
    template <class TimePoint=std::chrono::system_clock::time_point>
    class EmptyEnvironment final {
    public:
        using TimePointType = TimePoint;
        static TimePoint resolve() {
            if constexpr (std::is_same_v<TimePoint, std::chrono::system_clock::time_point>) {
                return std::chrono::system_clock::now();
            } else {
                return TimePoint {};
            }
        }
        static TimePoint resolve(TimePoint const &t) {
            return t;
        }
        static TimePoint now() {
            return resolve();
        }
    }; 
} } } }

#endif
