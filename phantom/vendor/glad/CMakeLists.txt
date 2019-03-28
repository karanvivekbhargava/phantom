cmake_minimum_required(VERSION 3.0)
project(glad)

add_definitions(-DGLFW_INCLUDE_NONE)
add_definitions(-DGLAD_INSTALL)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

add_library(glad SHARED
	${HDRS}
    ${SRCS}
)
target_include_directories(glad PUBLIC include/)
