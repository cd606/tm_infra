project('TM kit infra', 'cpp', default_options: ['cpp_std=c++17', 'warning_level=3'])

inc = include_directories('.')
thread_dep = dependency('threads')
common_deps = [thread_dep]
pkg = import('pkgconfig')

subdir('tm_kit/infra')
subdir('src')
