#ifndef TM_KIT_INFRA_PID_UTIL_HPP_
#define TM_KIT_INFRA_PID_UTIL_HPP_

#include <cstdint>

namespace dev { namespace cd606 { namespace tm { namespace infra { namespace pid_util {
    extern int64_t getpid();
    extern bool pidIsRunning(int64_t pid);
} } } } }

#endif