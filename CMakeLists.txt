cmake_minimum_required(VERSION 3.8)
project(phantom_top_level)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(phantom)
add_subdirectory(casper)
