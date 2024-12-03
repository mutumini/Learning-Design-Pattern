add_library(design_pattern STATIC)

set_target_properties(design_pattern PROPERTIES CXX_CLANG_TIDY clang-tidy)
target_include_directories(design_pattern PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

target_sources(design_pattern PRIVATE
    EntryPoint.cpp
)
