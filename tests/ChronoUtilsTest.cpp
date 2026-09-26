#include <tm_kit/infra/ChronoUtils.hpp>
#include "TestSupport.hpp"
#include <cstdlib>
#include <locale>
#include <random>
#include <vector>
#include <array>
#include <algorithm>

namespace dev { namespace cd606 { namespace tm { namespace infra { namespace chrono_legacy {
    std::chrono::system_clock::time_point parseUtcTime(std::string_view const &);
    std::chrono::system_clock::time_point parseZonedTime(std::string_view const &);
    std::string localTimeString(std::chrono::system_clock::time_point const &);
    std::string utcTimeString(std::chrono::system_clock::time_point const &);
} } } } }
namespace current = dev::cd606::tm::infra::withtime_utils;
namespace legacy = dev::cd606::tm::infra::chrono_legacy;
using Clock = std::chrono::system_clock;
using namespace std::chrono;

struct Timezone {
    std::string old;
    bool existed;
    explicit Timezone(char const *zone) : existed(std::getenv("TZ") != nullptr) {
        if (existed) { old = std::getenv("TZ"); }
        set(zone);
    }
    static void set(char const *zone) {
#ifdef _MSC_VER
        _putenv_s("TZ", zone);
        _tzset();
#else
        setenv("TZ", zone, 1);
        tzset();
#endif
    }
    ~Timezone() {
        if (existed) { set(old.c_str()); }
        else {
#ifdef _MSC_VER
            _putenv_s("TZ", "");
            _tzset();
#else
            unsetenv("TZ");
            tzset();
#endif
        }
    }
};

void compareFormat(Clock::time_point tp) {
    CHECK(current::utcTimeString(tp) == legacy::utcTimeString(tp));
    CHECK(current::localTimeString(tp) == legacy::localTimeString(tp));
}

void parsing() {
    auto expected = current::parseUtcTime(2024, 2, 29, 12, 34, 56, 123456);
    CHECK(current::parseUtcTime("2024-02-29T12:34:56.123456Z") == expected);
    CHECK(current::parseZonedTime("2024-02-29T18:04:56.123456+05:30") == expected);
    CHECK(current::parseZonedTime("2024-02-29T08:34:56.123456-04:00") == expected);
    CHECK(current::parseUtcTime("20240229Z") == current::parseUtcTime(2024, 2, 29, 0, 0, 0));
    CHECK(current::parseUtcTime("2024-02-29T12:34Z") == current::parseUtcTime(2024, 2, 29, 12, 34, 0));
    CHECK(current::parseUtcTime("2024-02-29T12:34:56.123456789Z") == expected);
    CHECK(current::parseZonedTime("2024-01-01T00:00:00+14:00") == current::parseUtcTime(2023, 12, 31, 10, 0, 0));
    CHECK(current::parseZonedTime("2023-12-31T23:00:00-12:00") == current::parseUtcTime(2024, 1, 1, 11, 0, 0));
    for (auto const &s : {"", "x", "2024-02-29T12:34:56", "2024-02-29T12:34:56z"}) {
        CHECK(current::parseUtcTime(s) == legacy::parseUtcTime(s));
    }
    for (auto const &s : {"", "x", "12345", "2024-02-29T12:34:56Z", "2024-02-29T12:34:56*05:30", "2024-02-29T12:34:56+05300"}) {
        CHECK(current::parseZonedTime(s) == legacy::parseZonedTime(s));
    }
    // Short inputs previously indexed beyond the body. Exercise the new guard
    // without invoking the undefined behavior in the legacy oracle.
    for (auto const &s : {"Z", "1Z", "1234567Z"}) {
        CHECK(current::parseUtcTime(s) == Clock::time_point {});
    }
    CHECK(current::parseZonedTime("+00:00") == Clock::time_point {});
    // Differential checks include permissive, but previously well-defined, forms.
    for (auto const &date : {"1900-02-28", "1969-12-31", "1970-01-01", "2000-02-29", "2024-02-29", "2100-03-01"}) {
        for (auto const &time : {"", "T00:00", "T23:59", "T12:34:5", "T00:00:00", "T23:59:59", "T23:59:60"}) {
            for (auto const &fraction : {"", ".", ".0", ".1", ".01", ".001", ".0001", ".00001", ".000001", ".123456", ".999999", ".123456789"}) {
                auto body = std::string(date)+time+fraction;
                CHECK(current::parseUtcTime(body+"Z") == legacy::parseUtcTime(body+"Z"));
                for (auto const &offset : {"+00:00", "-00:00", "+05:30", "+05:45", "-03:30", "+14:00", "-12:00", "+99:99"}) {
                    CHECK(current::parseZonedTime(body+offset) == legacy::parseZonedTime(body+offset));
                }
            }
        }
    }
    for (auto const &body : {"20240229", "19691231", "20240229Z", "2024-02-29T12:34:56Z"}) {
        CHECK(current::parseZonedTime(std::string(body)+"+05:30") == legacy::parseZonedTime(std::string(body)+"+05:30"));
    }
    // Views are deliberately not null-terminated at the end of the timestamp.
    std::string padded = "xx2024-02-29T18:04:56.123456+05:30trailing";
    CHECK(current::parseZonedTime(std::string_view(padded).substr(2, 32)) == expected);
    padded = "xx2024-02-29T12:34:56.123456Ztrailing";
    CHECK(current::parseUtcTime(std::string_view(padded).substr(2, 27)) == expected);
    std::array<char, 32> raw;
    std::string offsetTime = "2024-02-29T18:04:56.123456+05:30";
    std::copy(offsetTime.begin(), offsetTime.end(), raw.begin());
    CHECK(current::parseZonedTime(std::string_view(raw.data(), raw.size())) == expected);
}

struct GroupedNumbers : std::numpunct<char> {
    char do_thousands_sep() const override { return '_'; }
    std::string do_grouping() const override { return "\3"; }
};
void formatting() {
    Timezone tz("UTC0");
    CHECK(current::utcTimeString(Clock::time_point {}) == "1970-01-01T00:00:00Z");
    CHECK(current::localTimeString(Clock::time_point {}) == "1970-01-01T00:00:00");
    CHECK(current::utcTimeString(Clock::time_point {}+microseconds(1)) == "1970-01-01T00:00:00.000001Z");
    CHECK(current::utcTimeString(current::parseUtcTime(2000, 2, 29, 23, 59, 59, 123456)) == "2000-02-29T23:59:59.123456Z");
    // Fraction boundaries and submicrosecond truncation, on both sides of epoch.
    for (int64_t ns : {-1000000001LL, -1000000000LL, -999999999LL, -123456789LL, -1001LL, -1000LL, -999LL, -1LL, 0LL, 1LL, 999LL, 1000LL, 1001LL, 123456789LL, 999999999LL, 1000000000LL, 1000000001LL}) {
        compareFormat(Clock::time_point {}+duration_cast<Clock::duration>(nanoseconds(ns)));
    }
    // Every day across two centuries: leap days, non-leap century, year rollover.
    auto begin = current::parseUtcTime(1900, 1, 1, 12, 34, 56, 123456);
    auto end = current::parseUtcTime(2101, 1, 1, 0, 0, 0);
    for (auto tp = begin; tp < end; tp += hours(24)) { compareFormat(tp); }
    std::mt19937_64 random(0x4348524f4e4fULL);
    std::uniform_int_distribution<int64_t> samples(-7000000000000000LL, 7000000000000000LL);
    for (auto const &zone : {"UTC0", "EST5EDT,M3.2.0/2,M11.1.0/2", "CST6CDT,M3.2.0/2,M11.1.0/2", "NPT-5:45", "NST3:30NDT,M3.2.0/0:01,M11.1.0/0:01"}) {
        Timezone::set(zone);
        for (int i = 0; i < 10000; ++i) {
            auto tp = Clock::time_point {}+microseconds(samples(random));
            compareFormat(tp);
            if (tp >= Clock::time_point {}) {
                CHECK(current::parseUtcTime(current::utcTimeString(tp)) == tp);
            }
        }
        // Sweep both US transitions second-by-second around the UTC transition.
        for (auto transition : {current::parseUtcTime(2024, 3, 10, 7, 0, 0), current::parseUtcTime(2024, 11, 3, 6, 0, 0)}) {
            for (int i = -120; i <= 120; ++i) { compareFormat(transition+seconds(i)+microseconds(987654)); }
        }
    }
    auto old = std::locale();
    std::locale::global(std::locale(std::locale::classic(), new GroupedNumbers));
    for (auto tp : {Clock::time_point {}, Clock::time_point {}-microseconds(1234), current::parseUtcTime(2024, 2, 29, 12, 34, 56, 123456)}) {
        compareFormat(tp);
    }
    std::locale::global(old);
}

int main() {
    return runTests([] { parsing(); formatting(); });
}
