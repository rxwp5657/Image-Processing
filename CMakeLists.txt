cmake_minimum_required (VERSION 2.8)

# Project Name
project (kernel)

set(CMAKE_CXX_FLAGS "-g -Wall")
if(APPLE)
    set(CMAKE_CXX_STANDARD 14)
endif()

#Project headers
include_directories(include/)
#Project libraries

file(GLOB SOURCES src/*)

# Dependencies

add_executable(kernel ${SOURCES})

target_link_libraries(kernel)