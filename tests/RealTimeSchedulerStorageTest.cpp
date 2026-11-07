#include <tm_kit/infra/RealTimeApp.hpp>
#include "TestSupport.hpp"
#include <cstdlib>
#include <new>

// Count allocations only on this test's caller thread, while enqueuing. Compare
// with the same deque growth rather than assuming a library-specific block size.
namespace {
    thread_local bool countAllocations = false;
    thread_local std::size_t allocationCount = 0;
}
void *operator new(std::size_t size) {
    if (countAllocations) { ++allocationCount; }
    if (auto *memory = std::malloc(size ? size : 1)) { return memory; }
    throw std::bad_alloc();
}
void *operator new[](std::size_t size) { return ::operator new(size); }
void operator delete(void *memory) noexcept { std::free(memory); }
void operator delete[](void *memory) noexcept { ::operator delete(memory); }
void operator delete(void *memory, std::size_t) noexcept { ::operator delete(memory); }
void operator delete[](void *memory, std::size_t) noexcept { ::operator delete(memory); }

namespace infra = dev::cd606::tm::infra;
struct Env {
    using TimePointType = std::chrono::system_clock::time_point;
    using IDType = int;
    using IDHash = std::hash<int>;
    static constexpr bool CheckTime = false;
    static TimePointType resolveTime() { return std::chrono::system_clock::now(); }
    static TimePointType resolveTime(TimePointType value) { return value; }
};
using M = infra::RealTimeApp<Env>;
constexpr int messageCount = 2048;

int main() {
    return runTests([] {
        Env env;
        std::promise<int> done;
        auto completed = done.get_future();
        auto logic = [count=0, sum=0, &done](int value) mutable {
            sum += value;
            if (++count == messageCount) { done.set_value(sum); }
            return value;
        };
        using Core = M::PureActionCore<int,int,decltype(logic),false,false>;
        auto *raw = new Core(std::move(logic));
        auto action = std::make_shared<M::Action<int,int>>(
            raw, infra::LiftParameters<M::TimePoint>().Scheduler()
        );
        auto context = std::make_shared<infra::real_time_app_detail::SchedulerContext>();
        raw->attachScheduler(context);
        std::deque<M::InnerData<int>> baseline;
        allocationCount = 0;
        countAllocations = true;
        for (int value = 0; value < messageCount; ++value) {
            baseline.push_back(M::pureInnerData(&env, int(value)));
        }
        countAllocations = false;
        auto dequeAllocations = allocationCount;

        allocationCount = 0;
        countAllocations = true;
        for (int value = 0; value < messageCount; ++value) {
            raw->handle(M::pureInnerData(&env, int(value)));
        }
        countAllocations = false;
        auto schedulerAllocations = allocationCount;
        CHECK(dequeAllocations > 0);
        // No per-input envelope, control block, or erased callback allocations.
        CHECK(schedulerAllocations == dequeAllocations);
        std::cout << messageCount << " inputs: " << schedulerAllocations
                  << " enqueue allocations, matching direct deque storage\n";

        context->start();
        bool ready = completed.wait_for(std::chrono::seconds(5)) == std::future_status::ready;
        context->stop();
        CHECK(ready);
        CHECK(completed.get() == messageCount*(messageCount-1)/2);
    });
}
