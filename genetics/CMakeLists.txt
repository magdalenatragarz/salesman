cmake_minimum_required(VERSION 3.12)
project(genetics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB genetics_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
add_library(genetics STATIC ${genetics_sources})

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(genetics PUBLIC ${include_path})

add_subdirectory(testing)

install(TARGETS genetics DESTINATION bin/)
