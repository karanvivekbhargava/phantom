cmake_minimum_required(VERSION 3.0)
project(casper)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${phantom_SOURCE_DIR}/include
)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

add_executable(${PROJECT_NAME}
    ${HDRS}
    ${SRCS}
)

target_link_libraries(${PROJECT_NAME}
    phantom
)
