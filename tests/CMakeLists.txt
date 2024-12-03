target_link_libraries(DesignPatternCTest PRIVATE design_pattern)
set_target_properties(DesignPatternCTest PROPERTIES CXX_CLANG_TIDY clang-tidy)
target_sources(DesignPatternCTest PRIVATE
    TEST_StrategyPattern.cpp
)