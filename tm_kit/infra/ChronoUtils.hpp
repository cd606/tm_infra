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
#ifdef _MSC_VER
            return std::chrono::system_clock::time_point { 
                std::chrono::duration_cast<std::chrono::system_clock::duration>(
                    Duration { static_cast<typename Duration::rep>(d) }
                )
            };
#else
            return std::chrono::system_clock::time_point { Duration { static_cast<typename Duration::rep>(d) } };
#endif
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
            MemorizedMidnight(int year, int month, int day) {
                midnight_ = parseLocalTime(year, month, day, 0, 0, 0);
            }
            template <class Duration>
            int64_t sinceMidnight(std::chrono::system_clock::time_point tp) const {
                return static_cast<int64_t>(std::chrono::duration_cast<Duration>(tp-midnight_).count());
            }
            template <class Duration>
            std::chrono::system_clock::time_point midnightDurationToTime(Duration const &d) const {
                return midnight_ + d;
            }
        };

//zoned_time support is not yet complete in gcc, so currently this is only enabled for Visual C++
#if __cplusplus >= 202002L && (defined(_MSC_VER) || (defined(__GNUC__) && !defined(__llvm__) && (__GNUC__ >= 13)))
        //Because we want to use c++20 implementation when the library is included
        //in a c++20 project, we cannot put the implementation into a different
        //.cpp file (which will not be compiled with c++20), so everything is inline

        //The implementation may break down on dst-changing Sundays
        inline std::chrono::system_clock::time_point parseZonedTime(int year, int month, int day, int hour, int minute, int second, int microseconds, std::string_view const &timeZoneName) {
            std::chrono::zoned_time<
                std::chrono::system_clock::duration
            > zt (timeZoneName, std::chrono::local_days {std::chrono::year_month_day {std::chrono::year(year), std::chrono::month(month), std::chrono::day(day)}});
            return zt.get_sys_time()+std::chrono::hours(hour)+std::chrono::minutes(minute)+std::chrono::seconds(second)+std::chrono::microseconds(microseconds);
        }
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmm" (the microsecond part can be omitted)
        inline std::chrono::system_clock::time_point parseZonedTime(std::string_view const &timeString, std::string_view const &timeZoneName) {
            if (timeString.length() == 8) {
                int year = (timeString[0]-'0')*1000+(timeString[1]-'0')*100+(timeString[2]-'0')*10+(timeString[3]-'0');
                int mon = (timeString[4]-'0')*10+(timeString[5]-'0');
                int day = (timeString[6]-'0')*10+(timeString[7]-'0');
                return parseZonedTime(year, mon, day, 0, 0, 0, 0, timeZoneName);
            } else {
                int year = (timeString[0]-'0')*1000+(timeString[1]-'0')*100+(timeString[2]-'0')*10+(timeString[3]-'0');
                int mon = (timeString[5]-'0')*10+(timeString[6]-'0');
                int day = (timeString[8]-'0')*10+(timeString[9]-'0');
                int hour = 0;
                int min = 0;
                int sec = 0;
                int microsec = 0;
                if (timeString.length() >= 16) {
                    hour = (timeString[11]-'0')*10+(timeString[12]-'0');
                    min = (timeString[14]-'0')*10+(timeString[15]-'0');
                    if (timeString.length() >= 19) {
                        sec = (timeString[17]-'0')*10+(timeString[18]-'0');
                    }
                    if (timeString.length() > 20 && timeString[19] == '.') {
                        int unit = 100000;
                        for (std::size_t ii=0; ii<6; ++ii,unit/=10) {
                            if (timeString.length() > (20+ii)) {
                                microsec += (timeString[20+ii]-'0')*unit;
                            } else {
                                break;
                            }
                        }
                    }
                }
                return parseZonedTime(
                    year, mon, day, hour, min, sec, microsec, timeZoneName
                );
            }
        }
        inline std::chrono::system_clock::time_point parseZonedTodayActualTime(int hour, int minute, int second, int microseconds, std::string_view const &timeZoneName) {
            std::chrono::zoned_time<
                std::chrono::system_clock::duration
            > zt {timeZoneName, std::chrono::system_clock::now()};
            auto days = std::chrono::floor<std::chrono::days>(zt.get_local_time());
            std::chrono::year_month_day ymd {days};
            return parseZonedTime((int) ymd.year(), (unsigned) ymd.month(), (unsigned) ymd.day(), hour, minute, second, microseconds, timeZoneName);
        }
        inline std::string zonedTimeString(std::chrono::system_clock::time_point const &tp, std::string_view const &timeZoneName, bool includeZoneName=false) {
            std::chrono::zoned_time<
                std::chrono::system_clock::duration
            > zt {timeZoneName, tp};
            auto days = std::chrono::floor<std::chrono::days>(zt.get_local_time());
            std::chrono::year_month_day ymd {days};
            std::chrono::zoned_time<
                std::chrono::system_clock::duration
            > zt1 {timeZoneName, std::chrono::local_days {ymd}};
            auto micros = std::chrono::duration_cast<std::chrono::microseconds>(
                zt.get_local_time()-zt1.get_local_time()
            ).count();
            std::ostringstream oss;
            oss << std::setw(4) << std::setfill('0') << (int) ymd.year()
                << '-'
                << std::setw(2) << std::setfill('0') << (unsigned) ymd.month()
                << '-'
                << std::setw(2) << std::setfill('0') << (unsigned) ymd.day()
                << 'T'
                << std::setw(2) << std::setfill('0') << (micros/(3600ULL*1000000ULL))
                << ':'
                << std::setw(2) << std::setfill('0') << ((micros%(3600ULL*1000000ULL))/(60ULL*1000000ULL))
                << ':'
                << std::setw(2) << std::setfill('0') << ((micros%(60ULL*1000000ULL))/1000000ULL)
                ;
            if (micros%1000000ULL != 0) {
                oss
                    << '.'
                    << std::setw(6) << std::setfill('0') << (micros%1000000ULL);
            }
            if (includeZoneName) {
                oss << " ("
                    << timeZoneName
                    << ')'
                    ;
            }
            return oss.str();
        }
        
        template <class Duration>
        inline int64_t sinceZonedMidnight(std::chrono::system_clock::time_point const &tp, std::string_view const &timeZoneName) {
            std::chrono::zoned_time<
                std::chrono::system_clock::duration
            > zt {timeZoneName, tp};
            auto days = std::chrono::floor<std::chrono::days>(zt.get_local_time());
            std::chrono::year_month_day ymd {days};
            std::chrono::zoned_time<
                std::chrono::system_clock::duration
            > zt1 {timeZoneName, std::chrono::local_days {ymd}};
            return static_cast<int64_t>(std::chrono::duration_cast<Duration>(zt.get_local_time()-zt1.get_local_time()).count());
        }
        template <class Env
            , std::enable_if_t<std::is_same_v<typename Env::TimePointType, std::chrono::system_clock
::time_point>,int> = 0
            >
        class MemorizedZonedMidnight {
        private:
            std::chrono::system_clock::time_point midnight_;
        public:
            MemorizedZonedMidnight(Env *env, std::string_view const &timeZoneName) {
                std::chrono::system_clock::time_point tp = env->now();
                std::chrono::zoned_time<
                    std::chrono::system_clock::duration
                > zt {timeZoneName, tp};
                auto days = std::chrono::floor<std::chrono::days>(zt.get_local_time());
                std::chrono::year_month_day ymd {days};
                std::chrono::zoned_time<
                    std::chrono::system_clock::duration
                > zt1 {timeZoneName, std::chrono::local_days {ymd}};
                midnight_ = zt1.get_sys_time();
            }
            MemorizedZonedMidnight(int year, int month, int day, std::string_view const &timeZoneName) {
                midnight_ = parseZonedTime(year, month, day, 0, 0, 0, 0, timeZoneName);
            }
            template <class Duration>
            int64_t sinceMidnight(std::chrono::system_clock::time_point tp) const {
                return static_cast<int64_t>(std::chrono::duration_cast<Duration>(tp-midnight_).count());
            }
            template <class Duration>
            std::chrono::system_clock::time_point midnightDurationToTime(Duration const &d) const {
                return midnight_ + d;
            }
        };
#endif
    }
} } } }
#endif
