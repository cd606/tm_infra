#include <tm_kit/infra/ChronoUtils.hpp>
#include "ChronoZonedLegacy.hpp"
#include "TestSupport.hpp"
#include <random>
#include <locale>

namespace current = dev::cd606::tm::infra::withtime_utils;
using namespace std::chrono;
using Clock = system_clock;

template <class F>
std::string outcome(F f) {
    try { return f(); }
    catch (nonexistent_local_time const &e) { return std::string("nonexistent:")+e.what(); }
    catch (ambiguous_local_time const &e) { return std::string("ambiguous:")+e.what(); }
    catch (std::runtime_error const &e) { return std::string("runtime:")+e.what(); }
}
template <class Duration>
void compareSince(Clock::time_point tp, std::string const &zone) {
    auto actual = outcome([&] { return std::to_string(current::sinceZonedMidnight<Duration>(tp, zone)); });
    auto expected = outcome([&] { return std::to_string(zoned_legacy::sinceZonedMidnight<Duration>(tp, zone)); });
    CHECK(actual == expected);
}
void compare(Clock::time_point tp, std::string const &zone) {
    for (bool include : {false, true}) {
        auto actual = outcome([&] { return current::zonedTimeString(tp, zone, include); });
        auto expected = outcome([&] { return zoned_legacy::zonedTimeString(tp, zone, include); });
        if (actual != expected) {
            std::cerr << zone << " at " << current::utcTimeString(tp)
                      << "\nactual: " << actual << "\nexpected: " << expected << '\n';
        }
        CHECK(actual == expected);
    }
    compareSince<hours>(tp, zone);
    compareSince<seconds>(tp, zone);
    compareSince<milliseconds>(tp, zone);
    compareSince<microseconds>(tp, zone);
    compareSince<nanoseconds>(tp, zone);
}

void run() {
    CHECK(current::zonedTimeString(Clock::time_point {}, "UTC") == "1970-01-01T00:00:00");
    CHECK(current::zonedTimeString(Clock::time_point {}-microseconds(1), "UTC") == "1969-12-31T23:59:59.999999");
    CHECK(current::zonedTimeString(Clock::time_point {}, "Asia/Kathmandu", true) == "1970-01-01T05:30:00 (Asia/Kathmandu)");
    auto noon = current::parseUtcTime(2024, 3, 10, 16, 0, 0);
    CHECK(current::sinceZonedMidnight<hours>(noon, "America/New_York") == 12);
    auto repeated1 = current::parseUtcTime(2024, 11, 3, 5, 30, 0);
    auto repeated2 = current::parseUtcTime(2024, 11, 3, 6, 30, 0);
    CHECK(current::zonedTimeString(repeated1, "America/New_York") == "2024-11-03T01:30:00");
    CHECK(current::zonedTimeString(repeated1, "America/New_York") == current::zonedTimeString(repeated2, "America/New_York"));
    std::mt19937_64 random(0x5a4f4e4544ULL);
    std::uniform_int_distribution<int64_t> samples(-2000000000000000LL, 5000000000000000LL);
    for (auto const &zone : {"UTC", "America/Chicago", "America/New_York", "Europe/London", "Asia/Kathmandu", "Australia/Lord_Howe", "Pacific/Apia", "America/Havana", "America/Sao_Paulo"}) {
        for (int i = 0; i < 1500; ++i) {
            compare(Clock::time_point {}+microseconds(samples(random)), zone);
        }
        for (int64_t ns : {-1000000001LL, -1000000000LL, -999LL, -1LL, 0LL, 1LL, 999LL, 1000LL, 999999999LL}) {
            compare(Clock::time_point {}+duration_cast<Clock::duration>(nanoseconds(ns)), zone);
        }
    }
    // Sweep spring/fall DST, half-hour DST, a skipped date, and midnight changes.
    struct Transition { char const *zone; char const *utc; };
    for (auto const &transition : {
        Transition {"America/New_York", "2024-03-10T07:00:00Z"},
        Transition {"America/New_York", "2024-11-03T06:00:00Z"},
        Transition {"Australia/Lord_Howe", "2024-04-06T15:00:00Z"},
        Transition {"Australia/Lord_Howe", "2024-10-05T15:30:00Z"},
        Transition {"Pacific/Apia", "2011-12-30T10:00:00Z"},
        Transition {"America/Havana", "2024-03-10T05:00:00Z"},
        Transition {"America/Havana", "2024-11-03T05:00:00Z"},
        Transition {"America/Sao_Paulo", "2018-11-04T03:00:00Z"}
    }) {
        auto tp = current::parseUtcTime(transition.utc);
        for (int minute = -1440; minute <= 1440; ++minute) {
            compare(tp+minutes(minute)+microseconds(123456), transition.zone);
        }
    }
    // A valid instant later in the day still throws if midnight was not unique.
    auto missingMidnight = current::parseUtcTime("2018-11-04T12:00:00Z");
    CHECK(outcome([&] { return current::zonedTimeString(missingMidnight, "America/Sao_Paulo"); }).find("nonexistent:") == 0);
    auto repeatedMidnight = current::parseUtcTime("2024-11-03T12:00:00Z");
    CHECK(outcome([&] { return current::zonedTimeString(repeatedMidnight, "America/Havana"); }).find("ambiguous:") == 0);
    compare(Clock::time_point {}, "Not/A_Time_Zone");
}
int main() { return runTests(run); }
