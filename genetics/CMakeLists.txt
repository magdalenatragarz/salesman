cmake_minimum_required(VERSION 3.12)
project(genetics)

file(GLOB solution_sources "${CMAKE_CURRENT_SOURCE_DIR}/solution/src/*")
add_library(genetics STATIC ${solution_sources})

set(include_path
	"${CMAKE_CURRENT_SOURCE_DIR}/solution/include/")

target_include_directories(genetics PUBLIC ${include_path})
target_link_libraries(genetics PRIVATE gtest)

add_subdirectory(test)

install(TARGETS genetics DESTINATION bin/)

