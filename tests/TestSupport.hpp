#ifndef TM_INFRA_TEST_SUPPORT_HPP_
#define TM_INFRA_TEST_SUPPORT_HPP_
#include <stdexcept>
#include <string>
#include <iostream>

inline std::size_t checks = 0;
inline void check(bool condition, char const *expression, int line) {
    ++checks;
    if (!condition) {
        throw std::runtime_error(std::string("line ")+std::to_string(line)+": "+expression);
    }
}
#define CHECK(expression) check(static_cast<bool>(expression), #expression, __LINE__)
template <class F>
int runTests(F f) {
    try {
        f();
        std::cout << checks << " checks passed\n";
        return 0;
    } catch (std::exception const &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
#endif
