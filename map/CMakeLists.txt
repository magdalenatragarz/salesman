cmake_minimum_required(VERSION 3.12)
project(map)

set(CMAKE_CXX_STANDARD 17)

file(GLOB map_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
add_library(map STATIC ${map_sources})

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(map PUBLIC ${include_path})

target_link_libraries(map PRIVATE gtest)

install(TARGETS map DESTINATION bin/)



