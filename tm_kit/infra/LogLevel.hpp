#ifndef TM_KIT_INFRA_LOG_LEVEL_HPP_
#define TM_KIT_INFRA_LOG_LEVEL_HPP_

#include <iostream>
#include <sstream>
#include <string_view>

namespace dev { namespace cd606 { namespace tm { namespace infra {

    enum class LogLevel {
        Trace,
        Debug,
        Info,
        Warning,
        Error,
        Critical
    };
    inline std::string logLevelToString(LogLevel l) {
        switch (l) {
        case LogLevel::Trace:
            return "Trace";
        case LogLevel::Debug:
            return "Debug";
        case LogLevel::Info:
            return "Info";
        case LogLevel::Warning:
            return "Warning";
        case LogLevel::Error:
            return "Error";
        case LogLevel::Critical:
            return "Critical";
        default:
            return "Unknown Log Level";
        }
    }
    inline bool logLevelFromString(std::string_view const &s, LogLevel &l) {
        if (s == "Trace") {
            l = LogLevel::Trace;
            return true;
        }
        if (s == "Debug") {
            l = LogLevel::Debug;
            return true;
        }
        if (s == "Info") {
            l = LogLevel::Info;
            return true;
        }
        if (s == "Warning") {
            l = LogLevel::Warning;
            return true;
        }
        if (s == "Error") {
            l = LogLevel::Error;
            return true;
        }
        if (s == "Critical") {
            l = LogLevel::Critical;
            return true;
        }
        return false;
    }
    inline std::ostream &operator<<(std::ostream &os, LogLevel l) {
        os << logLevelToString(l);
        return os;
    }
    
    namespace withtime_utils {
        template <class T, class Env>
        inline void simpleLog(Env &env, LogLevel level, T const &t) {
            std::ostringstream oss;
            oss << t;
            env.log(level, t);
        }
    }
    
} } } }

#endif
