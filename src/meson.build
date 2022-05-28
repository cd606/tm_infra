tm_infra_sources = ['AppHeaders.cpp', 'ChronoUtils.cpp', 'PidUtil.cpp', 'GraphStructureBasedResourceHolderComponent.cpp']
if get_option('buildtype') == 'debug'
    tm_infra_lib_debug = static_library('tm_kit_infra_debug', tm_infra_sources, include_directories: inc, dependencies: common_deps, install: true)
    pkg.generate(tm_infra_lib_debug)
else
    tm_infra_lib = static_library('tm_kit_infra', tm_infra_sources, include_directories: inc, dependencies: common_deps, install: true)
    pkg.generate(tm_infra_lib)
endif
