cmake_minimum_required(VERSION 3.0)
project(Phantom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cotire/CMake")
include(cotire)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

add_subdirectory(phantom)
add_subdirectory(casper)
