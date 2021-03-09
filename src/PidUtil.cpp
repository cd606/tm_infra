#include <tm_kit/infra/PidUtil.hpp>

#ifdef _MSC_VER
#include <windows.h>
#include <processthreadsapi.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#endif

namespace dev { namespace cd606 { namespace tm { namespace infra { namespace pid_util {
    int64_t getpid() {
        #ifdef _MSC_VER
            return (int64_t) GetCurrentProcessId();
        #else
            return (int64_t) ::getpid();
        #endif
    }
    bool pidIsRunning(int64_t pid) {
        #ifdef _MSC_VER
            DWORD status;
            GetExitCodeProcess((HANDLE) pid, &status);
            return (status == STILL_ACTIVE);
        #else
            std::ostringstream oss;
            oss << "/proc/" << pid;
            struct stat buffer;
            return (stat(oss.str().c_str(), &buffer) == 0);
        #endif
    }
} } } } }