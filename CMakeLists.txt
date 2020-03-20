cmake_minimum_required(VERSION 3.12)
project(salesman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

add_subdirectory(googletest)

add_subdirectory(graph)
add_subdirectory(genetics)
add_subdirectory(evolution)

add_executable(salesman 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(salesman PRIVATE graph genetics evolution)

install(TARGETS salesman DESTINATION build/)