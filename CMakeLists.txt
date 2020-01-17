cmake_minimum_required(VERSION 3.12)
project(salesman)

add_subdirectory(googletest)

add_executable(salesman main.cpp)

target_link_libraries(salesman PRIVATE gtest)

install(TARGETS salesman DESTINATION build/)