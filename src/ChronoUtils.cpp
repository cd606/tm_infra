#include <tm_kit/infra/ChronoUtils.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <charconv>
#include <algorithm>
#include <locale>

namespace dev { namespace cd606 { namespace tm { namespace infra {
    namespace withtime_utils {
        namespace {
            // Match ostream's right-aligned padding, including zero padding before
            // a minus sign for the legacy pre-epoch fractional-second output.
            char *appendNumber(char *out, int value, int width, char fill) {
                char digits[32];
                auto end = std::to_chars(digits, digits+sizeof(digits), value).ptr;
                auto size = static_cast<int>(end-digits);
                out = std::fill_n(out, std::max(0, width-size), fill);
                return std::copy(digits, end, out);
            }

            std::string formatTime(std::tm const &m, int micros, bool utc) {
                // The previous stream formatter honored the global C++ locale.
                // Retain that behavior for custom locales, including digit grouping.
                if (std::locale() != std::locale::classic()) {
                    std::ostringstream oss;
                    oss << std::setw(4) << (m.tm_year+1900)
                        << '-' << std::setw(2) << std::setfill('0') << (m.tm_mon+1)
                        << '-' << std::setw(2) << m.tm_mday
                        << 'T' << std::setw(2) << m.tm_hour
                        << ':' << std::setw(2) << m.tm_min
                        << ':' << std::setw(2) << m.tm_sec;
                    if (micros != 0) {
                        oss << '.' << std::setw(6) << micros;
                    }
                    if (utc) {
                        oss << 'Z';
                    }
                    return oss.str();
                }
                // Seven int fields, six separators and an optional Z fit even
                // when an int field takes its full decimal width.
                char buffer[128];
                auto out = appendNumber(buffer, m.tm_year+1900, 4, ' ');
                *out++ = '-';
                out = appendNumber(out, m.tm_mon+1, 2, '0');
                *out++ = '-';
                out = appendNumber(out, m.tm_mday, 2, '0');
                *out++ = 'T';
                out = appendNumber(out, m.tm_hour, 2, '0');
                *out++ = ':';
                out = appendNumber(out, m.tm_min, 2, '0');
                *out++ = ':';
                out = appendNumber(out, m.tm_sec, 2, '0');
                if (micros != 0) {
                    *out++ = '.';
                    out = appendNumber(out, micros, 6, '0');
                }
                if (utc) {
                    *out++ = 'Z';
                }
                return std::string(buffer, out);
            }
        }
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
            if (s.length() == 8) {
                int year = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
                int mon = (s[4]-'0')*10+(s[5]-'0');
                int day = (s[6]-'0')*10+(s[7]-'0');
                return parseLocalTime(year, mon, day, 0, 0, 0, 0);
            } else {
                int year = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
                int mon = (s[5]-'0')*10+(s[6]-'0');
                int day = (s[8]-'0')*10+(s[9]-'0');
                int hour = 0;
                int min = 0;
                int sec = 0;
                int microsec = 0;
                if (s.length() >= 16) {
                    hour = (s[11]-'0')*10+(s[12]-'0');
                    min = (s[14]-'0')*10+(s[15]-'0');
                    if (s.length() >= 19) {
                        sec = (s[17]-'0')*10+(s[18]-'0');
                    }
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
                }
                return parseLocalTime(
                    year, mon, day, hour, min, sec, microsec
                );
            }
        }    
        std::string localTimeString(std::chrono::system_clock::time_point const &tp) {
            auto t = std::chrono::system_clock::to_time_t(tp);
            std::tm *m = std::localtime(&t);
            auto d = tp - std::chrono::system_clock::from_time_t(t);
            int micros = std::chrono::duration_cast<std::chrono::microseconds>(d).count();
            return formatTime(*m, micros, false);
        }
        std::chrono::system_clock::time_point parseUtcTime(int year, int month, int day, int hour, int minute, int second, int microseconds) {
            std::tm m;
            m.tm_year = year-1900;
            m.tm_mon = month-1;
            m.tm_mday = day;
            m.tm_hour = hour;
            m.tm_min = minute;
            m.tm_sec = second;
            m.tm_isdst = -1;
#ifdef _MSC_VER
            return std::chrono::system_clock::from_time_t(_mkgmtime(&m))+std::chrono::microseconds(microseconds);
#else
            return std::chrono::system_clock::from_time_t(timegm(&m))+std::chrono::microseconds(microseconds);
#endif
        }
        namespace {
        // Parse a body with a virtual trailing Z. This preserves the original
        // parser's length checks and permissive handling without allocating the
        // body+"Z" string used by numeric-offset parsing.
        std::chrono::system_clock::time_point parseUtcTimeBody(std::string_view const &body) {
            if (body.length() < 8) {
                return std::chrono::system_clock::time_point {};
            }
            struct UtcView {
                std::string_view body;
                std::size_t length() const { return body.length()+1; }
                char operator[](std::size_t i) const {
                    return i == body.length() ? 'Z' : body[i];
                }
            } s {body};
            if (s.length() == 9) {
                int year = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
                int mon = (s[4]-'0')*10+(s[5]-'0');
                int day = (s[6]-'0')*10+(s[7]-'0');
                return parseUtcTime(year, mon, day, 0, 0, 0, 0);
            } else {
                int year = (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
                int mon = (s[5]-'0')*10+(s[6]-'0');
                int day = (s[8]-'0')*10+(s[9]-'0');
                int hour = 0;
                int min = 0;
                int sec = 0;
                int microsec = 0;
                if (s.length() >= 17) {
                    hour = (s[11]-'0')*10+(s[12]-'0');
                    min = (s[14]-'0')*10+(s[15]-'0');
                    if (s.length() >= 19) {
                        sec = (s[17]-'0')*10+(s[18]-'0');
                    }
                    if (s.length() > 21 && s[19] == '.') {
                        int unit = 100000;
                        for (std::size_t ii=0; ii<6; ++ii,unit/=10) {
                            if (s.length() > (20+ii) && s[20+ii] != 'Z') {
                                microsec += (s[20+ii]-'0')*unit;
                            } else {
                                break;
                            }
                        }
                    }
                }
                return parseUtcTime(
                    year, mon, day, hour, min, sec, microsec
                );
            }
        }
        }
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmmZ" (the microsecond part can be omitted)
        std::chrono::system_clock::time_point parseUtcTime(std::string_view const &s) {
            if (s.empty() || s.back() != 'Z') {
                return std::chrono::system_clock::time_point {};
            }
            return parseUtcTimeBody(s.substr(0, s.length()-1));
        }
        //The format is fixed as "yyyy-MM-ddTHH:mm:ss.mmmmmm+/-HH:mm" (the microsecond part can be omitted)
        std::chrono::system_clock::time_point parseZonedTime(std::string_view const &s) {
            if (s.empty()) {
                return std::chrono::system_clock::time_point {};
            }
            if (s.length() < 6) {
                return std::chrono::system_clock::time_point {};
            }
            bool add = false;
            char c = s[s.length()-6];
            if (c == '+') {
                add = true;
            } else if (c == '-') {
                add = false;
            } else {
                return std::chrono::system_clock::time_point {};
            }
            if (s[s.length()-3] != ':') {
                return std::chrono::system_clock::time_point {};
            }
            int offsetMinutes = 
                (s[s.length()-5]-'0')*600
                +(s[s.length()-4]-'0')*60
                +(s[s.length()-2]-'0')*10
                +(s[s.length()-1]-'0');
            auto baseTime = parseUtcTimeBody(s.substr(0,s.length()-6));
            if (add) {
                return baseTime-std::chrono::minutes(offsetMinutes);
            } else {
                return baseTime+std::chrono::minutes(offsetMinutes);
            }
        }    
        std::string utcTimeString(std::chrono::system_clock::time_point const &tp) {
            auto t = std::chrono::system_clock::to_time_t(tp);
            std::tm *m = std::gmtime(&t);
            auto d = tp - std::chrono::system_clock::from_time_t(t);
            int micros = std::chrono::duration_cast<std::chrono::microseconds>(d).count();
            return formatTime(*m, micros, true);
        }    
    }
} } } }
