cmake_minimum_required(VERSION 3.8)
project(casper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# the RPATH to be used when installing
SET(CMAKE_INSTALL_RPATH "")

add_executable(casper
    ${headers}
    src/app.cpp
)

target_link_libraries(casper
    phantom
)