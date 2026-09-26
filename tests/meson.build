infra_test_dep = declare_dependency(
    link_with: get_option('buildtype') == 'debug' ? tm_infra_lib_debug : tm_infra_lib,
    include_directories: inc,
    dependencies: common_deps,
)

key_test = executable('key_semantics_test', 'KeySemanticsTest.cpp', dependencies: infra_test_dep)
test('key semantics', key_test)

chrono_test = executable('chrono_utils_test', ['ChronoUtilsTest.cpp', 'ChronoUtilsLegacy.cpp'], dependencies: infra_test_dep)
test('chrono compatibility', chrono_test, timeout: 120)

cpp = meson.get_compiler('cpp')
zoned_test_prefix = '''
#include <chrono>
// Match the production header's compiler gate as well as library availability.
#if !(__cplusplus >= 202002L && (defined(_MSC_VER) || (defined(__GNUC__) && !defined(__llvm__) && (__GNUC__ >= 13))))
#error ChronoUtils named-zone API is not enabled on this compiler
#endif
'''
if cpp.has_type('std::chrono::zoned_time<std::chrono::seconds>', prefix: zoned_test_prefix, args: cpp.get_id() in ['msvc', 'clang-cl'] ? ['/std:c++20'] : ['-std=c++20'])
    zoned_test = executable('chrono_zoned_test', 'ChronoZonedTest.cpp', dependencies: infra_test_dep, override_options: ['cpp_std=c++20'])
    test('chrono zoned compatibility', zoned_test, timeout: 120)
else
    message('C++20 timezone tests require a standard library with chrono::zoned_time (e.g. GCC 13+).')
endif
