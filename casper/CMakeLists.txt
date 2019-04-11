cmake_minimum_required(VERSION 3.0)
project(casper)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

include_directories(${PROJECT_NAME}
#    ${phantom_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_opengl3.h
#    ${phantom_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_opengl3.cpp
#    ${phantom_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_glfw.h
#    ${phantom_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_glfw.cpp
)

add_executable(${PROJECT_NAME}
    ${HDRS}
    ${SRCS}
)

target_link_libraries(${PROJECT_NAME}
    phantom
)
