cmake_minimum_required(VERSION 3.12)
project(graph_test)

file(GLOB tests "${CMAKE_CURRENT_SOURCE_DIR}/*")

add_executable(graph_test ${tests})

target_link_libraries(graph_test PRIVATE gtest graph)

enable_testing()