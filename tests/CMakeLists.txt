target_link_libraries(DesignPatternCTest PRIVATE design_pattern)
set_target_properties(DesignPatternCTest PROPERTIES CXX_CLANG_TIDY clang-tidy)
target_include_directories(DesignPatternCTest PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

target_sources(DesignPatternCTest PRIVATE
    main.cpp
    TEST_StrategyPattern.cpp
    TEST_ObserverPattern.cpp
)