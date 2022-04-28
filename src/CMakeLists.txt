project(Fetylogg-calculator)
cmake_minimum_required(VERSION 3.14.0)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(files mathLib.h mathLib.cpp)

find_package(GTest REQUIRED)

add_executable(runTests tests.cpp ${files})

target_link_libraries(runTests GTest::Main)
