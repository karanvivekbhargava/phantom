cmake_minimum_required(VERSION 3.0)
project(phantom)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/imgui)

set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glm)

# This preprocessor definition is added after the glfw compile, since that's what glfw wants.
# Also, this definition is here because glad was spitting errors otherwise (double including gl).
add_definitions(-DGLFW_INCLUDE_NONE)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

#file(GLOB IMGUI_FILES

#)

#include_directories(${PROJECT_NAME}
##    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_opengl3.h
##    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_opengl3.cpp
##    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_glfw.h
##    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/src/examples/imgui_impl_glfw.cpp
#)

add_library( ${PROJECT_NAME} SHARED
    ${HDRS}
    ${SRCS}
)

target_include_directories( ${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include

)

target_link_libraries( ${PROJECT_NAME} PUBLIC
	glfw
	GL
	glad
	spdlog
        imgui
        glm
)

# install(TARGETS phantom
# 	RUNTIME DESTINATION bin
# 	LIBRARY DESTINATION lib
# 	ARCHIVE DESTINATION lib/static
#)
#    PUBLIC_HEADER DESTINATION include/phantom)

#set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "phantom_pch.hpp")
#cotire(${PROJECT_NAME})
