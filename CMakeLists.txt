cmake_minimum_required(VERSION 3.12)
project(salesman)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(3rdparty)
add_subdirectory(graph)
add_subdirectory(genetics)
add_subdirectory(evolution)

add_executable(salesman ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(salesman PRIVATE graph genetics evolution)
target_link_libraries(salesman PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

install(TARGETS salesman DESTINATION build/)

