cmake_minimum_required(VERSION 3.5)

project(counting_triangles)
set(CMAKE_CXX_FLAGS "-std=c++11 -pg -g -pedantic")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(counting_triangles main.cpp io.cpp)
add_executable(debug main.cpp io.cpp)
add_executable(tests catch_main.cpp test_io.cpp test_cmake_catch.cpp io.cpp)

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)

set_target_properties(debug PROPERTIES COMPILE_FLAGS "-DDEBUG")
