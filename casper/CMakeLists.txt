cmake_minimum_required(VERSION 3.0)
project(casper)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${phantom_SOURCE_DIR}/include
    ${phantom_SOURCE_DIR}/vendor/spdlog/include
)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

# message("phantom install dir: ${phantom_BINARY_DIR}")

# file(GLOB_RECURSE TEST_FILES
#   "${phantom_BINARY_DIR}/*.so"
# )
# message("Files:  ${TEST_FILES}")

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

add_executable(${PROJECT_NAME}
    ${HDRS}
    ${SRCS}
)

target_link_libraries(${PROJECT_NAME}
    phantom
)
