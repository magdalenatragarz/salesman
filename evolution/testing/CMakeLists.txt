cmake_minimum_required(VERSION 3.12)
project(evolution_tests)

add_executable(evolution_tests main.cpp test_map.cpp)

target_link_libraries(evolution_tests PRIVATE gtest gmock)
