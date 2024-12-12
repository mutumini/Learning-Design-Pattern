set(app DesignPatternCTest)

target_link_libraries(${app} PRIVATE design_pattern)
set_target_properties(${app} PROPERTIES CXX_CLANG_TIDY clang-tidy)
target_include_directories(${app} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

target_sources(${app} PRIVATE
  main.cpp
  TEST_StrategyPattern.cpp
  TEST_ObserverPattern.cpp
  TEST_DecoratorPattern.cpp
  TEST_SimpleFactory.cpp
)