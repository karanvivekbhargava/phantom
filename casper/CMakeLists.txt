cmake_minimum_required(VERSION 3.0)
project(casper)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${phantom_SOURCE_DIR}/src
    ${phantom_SOURCE_DIR}/vendor/spdlog/include
)

## the RPATH to be used when installing
#SET(CMAKE_INSTALL_RPATH "")

add_executable(casper
    ${headers}
    src/app.cpp
)

target_link_libraries(casper
    phantom
)
