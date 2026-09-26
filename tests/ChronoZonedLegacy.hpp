// Frozen pre-optimization C++20 helpers for differential regression tests.
#pragma once
#include <tm_kit/infra/ChronoUtils.hpp>
namespace zoned_legacy {
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
}
