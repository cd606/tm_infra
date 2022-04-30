#ifndef TM_KIT_INFRA_CHRONO_UTILS_HPP_
#define TM_KIT_INFRA_CHRONO_UTILS_HPP_

#include <chrono>
#include <ctime>
#include <string>
#include <type_traits>
#include <iostream>
#include <sstream>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    //Some small helper functions to help write apps and tests
    namespace withtime_utils {
        extern std::chrono::system_clock::time_point parseLocalTime(int year, int month, int day, int hour, int minute, int second, int microseconds=0);
        extern std::chrono::system_clock::time_point parseLocalTodayActualTime(int hour, int minute, int second, int microseconds=0);
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmm" (the microsecond part can be omitted)
        extern std::chrono::system_clock::time_point parseLocalTime(std::string_view const &s);    
        extern std::string localTimeString(std::chrono::system_clock::time_point const &tp);
        extern std::chrono::system_clock::time_point parseUtcTime(int year, int month, int day, int hour, int minute, int second, int microseconds=0);
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmmZ" (the microsecond part can be omitted)
        extern std::chrono::system_clock::time_point parseUtcTime(std::string_view const &s);    
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmm+/-HH:mm" (the microsecond part can be omitted)
        extern std::chrono::system_clock::time_point parseZonedTime(std::string_view const &s); 
        extern std::string utcTimeString(std::chrono::system_clock::time_point const &tp);
        template <class TimeType>
        inline std::string genericLocalTimeString(TimeType const &t) {
            std::ostringstream oss;
            oss << t;
            return oss.str();
        }
        template <>
        inline std::string genericLocalTimeString<std::chrono::system_clock::time_point>(std::chrono::system_clock::time_point const &t) {
            return localTimeString(t);
        }

        //The usage is like withtime_utils::sinceMidnight<std::chrono::seconds>(...);
        template <class Duration>
        inline int64_t sinceMidnight(std::chrono::system_clock::time_point const &tp) {
            std::time_t t = std::chrono::system_clock::to_time_t(tp);
            std::tm *m = std::localtime(&t);
            m->tm_hour = 0;
            m->tm_min = 0;
            m->tm_sec = 0;
            auto midnight = std::chrono::system_clock::from_time_t(std::mktime(m));
            return static_cast<int64_t>(std::chrono::duration_cast<Duration>(tp-midnight).count());
        }
        //similar to sinceMidnight
        template <class Duration>
        inline constexpr int64_t sinceEpoch(std::chrono::system_clock::time_point const &tp) {
            return static_cast<int64_t>(std::chrono::duration_cast<Duration>(std::chrono::time_point_cast<Duration>(tp).time_since_epoch()).count());
        }

        template <class Duration>
        inline constexpr std::chrono::system_clock::time_point epochDurationToTime(int64_t d) {
            return std::chrono::system_clock::time_point { Duration { static_cast<typename Duration::rep>(d) } };
        }

        template <class Env
            , std::enable_if_t<std::is_same_v<typename Env::TimePointType, std::chrono::system_clock::time_point>,int> = 0
            >
        class MemorizedMidnight {
        private:
            std::chrono::system_clock::time_point midnight_;
        public:
            MemorizedMidnight(Env *env) {
                std::chrono::system_clock::time_point tp = env->now();
                std::time_t t = std::chrono::system_clock::to_time_t(tp);
                std::tm *m = std::localtime(&t);
                m->tm_hour = 0;
                m->tm_min = 0;
                m->tm_sec = 0;
                midnight_ = std::chrono::system_clock::from_time_t(std::mktime(m));
            }
            template <class Duration>
            int64_t sinceMidnight(std::chrono::system_clock::time_point tp) const {
                return static_cast<uint64_t>(std::chrono::duration_cast<Duration>(tp-midnight_).count());
            }
            template <class Duration>
            std::chrono::system_clock::time_point midnightDurationToTime(Duration const &d) const {
                return midnight_ + d;
            }
        };
    }
} } } }
#endif