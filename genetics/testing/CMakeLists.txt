cmake_minimum_required(VERSION 3.12)
project(genetics_tests)

add_executable(genetics_tests main.cpp test_solution.cpp)

target_link_libraries(genetics_tests PRIVATE gtest gmock)
target_link_libraries(genetics_tests PRIVATE genetics)