cmake_minimum_required(VERSION 3.12)
project(genetics)

set(CMAKE_CXX_STANDARD 17)

file(GLOB genetics_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
add_library(genetics STATIC ${genetics_sources})

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(genetics PUBLIC ${include_path})

target_link_libraries(genetics PRIVATE gtest)

add_subdirectory(test)

install(TARGETS genetics DESTINATION bin/)
