cmake_minimum_required(VERSION 3.12)
project(graph_tests)

add_executable(graph_tests main.cpp test_graph.cpp)

target_link_libraries(graph_tests PRIVATE gtest gmock)
target_link_libraries(graph_tests PRIVATE graph)