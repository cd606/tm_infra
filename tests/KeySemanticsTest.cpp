#include <tm_kit/infra/WithTimeData.hpp>
#include "TestSupport.hpp"
#include <utility>

namespace infra = dev::cd606::tm::infra;
struct Env {
    using IDType = int;
    static int new_id() { return 42; }
};
struct Payload {
    inline static int copies = 0;
    inline static int moves = 0;
    std::string value;
    explicit Payload(std::string s) : value(std::move(s)) {}
    Payload(Payload const &p) : value(p.value) { ++copies; }
    Payload(Payload &&p) : value(std::move(p.value)) { ++moves; p.value.clear(); }
};
template <class T, class = void> struct CanTake : std::false_type {};
template <class T> struct CanTake<T, std::void_t<decltype(std::declval<T>().takeKey())>> : std::true_type {};
using Key = infra::Key<Payload, Env>;
static_assert(!CanTake<Key &>::value);
static_assert(!CanTake<Key const &>::value);
static_assert(!CanTake<Key const &&>::value);
static_assert(CanTake<Key &&>::value);
static_assert(std::is_same_v<decltype(std::declval<Key &&>().takeKey()), Payload>);
static_assert(std::is_same_v<decltype(std::declval<Key &>().key()), Payload>);
static_assert(std::is_same_v<decltype(std::declval<Key const &>().key()), Payload const &>);
static_assert(std::is_same_v<decltype(std::declval<Key &&>().key()), Payload>);

int main() {
    return runTests([] {
        Key key(17, Payload("preserve this payload"));
        Payload::copies = Payload::moves = 0;
        auto copy = key.key();
        CHECK(copy.value == "preserve this payload");
        CHECK(std::as_const(key).key().value == copy.value);
        CHECK(Payload::copies == 1 && Payload::moves == 0);
        auto const &ref = std::as_const(key).key();
        CHECK(&ref == &std::as_const(key).key());
        CHECK(Payload::copies == 1 && Payload::moves == 0);
        // Even an existing key() call on an xvalue must still copy.
        auto anotherCopy = std::move(key).key();
        CHECK(anotherCopy.value == copy.value);
        CHECK(std::as_const(key).key().value == copy.value);
        CHECK(Payload::copies == 2 && Payload::moves == 0);
        auto movedCopy = std::move(key.key());
        CHECK(movedCopy.value == copy.value);
        CHECK(std::as_const(key).key().value == copy.value);
        CHECK(Payload::copies == 3 && Payload::moves == 1);
        Payload::copies = Payload::moves = 0;
        auto consumed = std::move(key).takeKey();
        CHECK(consumed.value == copy.value);
        CHECK(Payload::copies == 0 && Payload::moves == 1);
        CHECK(key.id() == 17);
        CHECK(std::as_const(key).key().value.empty());
        // Value ownership survives the destruction of the temporary Key.
        auto fromTemporary = Key(19, Payload("temporary")).takeKey();
        CHECK(fromTemporary.value == "temporary");
        infra::Key<std::shared_ptr<int>, Env> shared(23, std::make_shared<int>(9));
        auto retained = shared.key();
        CHECK(retained.use_count() == 2);
        auto consumedShared = std::move(shared).takeKey();
        CHECK(retained == consumedShared && retained.use_count() == 2);
        CHECK(!std::as_const(shared).key());
        CHECK(shared.id() == 23);
    });
}
