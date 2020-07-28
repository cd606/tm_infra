#ifndef TM_KIT_INFRA_TERMINATION_CONTROLLER_HPP_
#define TM_KIT_INFRA_TERMINATION_CONTROLLER_HPP_

#include <chrono>
#include <thread>
#include <functional>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    
    class TerminateAtTimePoint {
    private:
        std::chrono::time_point<std::chrono::system_clock> tp_;
    public:
        TerminateAtTimePoint(std::chrono::time_point<std::chrono::system_clock> tp) 
            : tp_(tp)
        {}
        ~TerminateAtTimePoint() {
            auto now = std::chrono::system_clock::now();
            if (tp_ > now) {
                std::this_thread::sleep_until(tp_);
            }
        }
    };

    class TerminateAfterDuration {
    private:
        std::chrono::system_clock::duration duration_;
    public:
        TerminateAfterDuration(std::chrono::system_clock::duration duration) 
            : duration_(duration)
        {}
        ~TerminateAfterDuration() {
            if (duration_ > std::chrono::system_clock::duration::zero()) {
                std::this_thread::sleep_for(duration_);
            }
        }
    };

    class ImmediatelyTerminate {
    };

    class RunForever {
    private:
        std::function<bool()> runningCheck_;
        std::chrono::system_clock::duration duration_;
    public:
        RunForever(std::function<bool()> const &runningCheck = []() {return true;}, std::chrono::system_clock::duration duration=std::chrono::seconds(100)) 
            : runningCheck_(runningCheck), duration_(duration) {}
        template <class Env>
        RunForever(Env *env, std::chrono::system_clock::duration duration=std::chrono::seconds(100)) 
            : runningCheck_([env]() {return env->running();}), duration_(duration) {}
        ~RunForever() {
            while (runningCheck_()) {
                std::this_thread::sleep_for(duration_);
            }
        }
    };

    template <class T>
    inline void terminationController(T const &) {}

} } } }

#endif