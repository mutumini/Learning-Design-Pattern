cmake_minimum_required(VERSION 3.20)

project(design_pattern
  DESCRIPTION "Just for learning!"
  VERSION 0.0.0
  LANGUAGES C CXX)

message(STATUS "CMake version: ${CMAKE_VERSION}")

set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
    "Choose the default type of build. [OPTION]: Debug, Release, RelWithDebInfo." FORCE)

set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)

add_subdirectory(tools)

add_subdirectory(src)

add_executable(DesignPatternCTest)
add_subdirectory(tests)
