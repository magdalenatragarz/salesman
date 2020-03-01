cmake_minimum_required(VERSION 3.12)
project(evolution_test)

file(GLOB tests "${CMAKE_CURRENT_SOURCE_DIR}/*")

add_executable(evolution_test ${tests})

target_link_libraries(evolution_test PRIVATE gtest gmock evolution graph)

enable_testing()