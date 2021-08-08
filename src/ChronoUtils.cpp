#include <tm_kit/infra/ChronoUtils.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    namespace withtime_utils {
        std::chrono::system_clock::time_point parseLocalTime(int year, int month, int day, int hour, int minute, int second, int microseconds) {
            std::tm m;
            m.tm_year = year-1900;
            m.tm_mon = month-1;
            m.tm_mday = day;
            m.tm_hour = hour;
            m.tm_min = minute;
            m.tm_sec = second;
            m.tm_isdst = -1;
            return std::chrono::system_clock::from_time_t(std::mktime(&m))+std::chrono::microseconds(microseconds);
        }
        std::chrono::system_clock::time_point parseLocalTodayActualTime(int hour, int minute, int second, int microseconds) {
            std::time_t tp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::tm *m = localtime(&tp);            
            m->tm_hour = hour;
            m->tm_min = minute;
            m->tm_sec = second;
            return std::chrono::system_clock::from_time_t(std::mktime(m))+std::chrono::microseconds(microseconds);
        }
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmm" (the microsecond part can be omitted)
        std::chrono::system_clock::time_point parseLocalTime(std::string_view const &s) {
            int year = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
            int mon = (s[5]-'0')*10+(s[6]-'0');
            int day = (s[8]-'0')*10+(s[9]-'0');
            int hour = (s[11]-'0')*10+(s[12]-'0');
            int min = (s[14]-'0')*10+(s[15]-'0');
            int sec = 0;
            if (s.length() >= 19) {
                sec = (s[17]-'0')*10+(s[18]-'0');
            }
            int microsec = 0;
            if (s.length() > 20 && s[19] == '.') {
                int unit = 100000;
                for (std::size_t ii=0; ii<6; ++ii,unit/=10) {
                    if (s.length() > (20+ii)) {
                        microsec += (s[20+ii]-'0')*unit;
                    } else {
                        break;
                    }
                }

            }
            return parseLocalTime(
                year, mon, day, hour, min, sec, microsec
            );
        }    
        std::string localTimeString(std::chrono::system_clock::time_point const &tp) {
            auto t = std::chrono::system_clock::to_time_t(tp);
            std::tm *m = std::localtime(&t);
            std::ostringstream oss;
            oss << std::setw(4) << (m->tm_year+1900)
                << '-'
                << std::setw(2) << std::setfill('0') << (m->tm_mon+1)
                << '-'
                << std::setw(2) << std::setfill('0') << m->tm_mday
                << 'T'
                << std::setw(2) << std::setfill('0') << m->tm_hour
                << ':'
                << std::setw(2) << std::setfill('0') << m->tm_min
                << ':'
                << std::setw(2) << std::setfill('0') << m->tm_sec;
            auto d = tp - std::chrono::system_clock::from_time_t(t);
            int micros = std::chrono::duration_cast<std::chrono::microseconds>(d).count();
            oss << '.' << std::setw(6) << std::setfill('0') << micros;
            return oss.str();
        }    
    }
} } } }