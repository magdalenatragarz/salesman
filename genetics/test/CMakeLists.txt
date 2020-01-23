cmake_minimum_required(VERSION 3.12)
project(genetics_test)

file(GLOB tests "${CMAKE_CURRENT_SOURCE_DIR}/*")

add_executable(genetics_test ${tests})

target_link_libraries(genetics_test PRIVATE gtest)

enable_testing()