cmake_minimum_required(VERSION 3.12)
project(graph)

set(CMAKE_CXX_STANDARD 17)

file(GLOB graph_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
add_library(graph STATIC ${graph_sources})

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(graph PUBLIC ${include_path})

target_link_libraries(graph PRIVATE gtest)

add_subdirectory(test)

install(TARGETS graph DESTINATION bin/)



