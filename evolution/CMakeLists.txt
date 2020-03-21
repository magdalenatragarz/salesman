cmake_minimum_required(VERSION 3.12)
project(evolution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB evolution_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
add_library(evolution STATIC ${evolution_sources})

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(evolution PUBLIC ${include_path})

target_link_libraries(evolution PRIVATE graph genetics)

install(TARGETS evolution DESTINATION bin/)



