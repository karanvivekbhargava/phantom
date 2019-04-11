cmake_minimum_required(VERSION 3.0)
project(imgui)

file(GLOB SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/im*.cpp
    )
file(GLOB HDRS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/im*.h)
#file(GLOB EXAMPLES
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/examples/imgui_impl_glfw*
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/examples/imgui_impl_opengl3*
#    )

add_library(imgui SHARED
	${HDRS}
        ${SRCS}
#        ${EXAMPLES}
)

target_include_directories(imgui PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

target_compile_definitions(imgui PUBLIC
	IMGUI_IMPL_OPENGL_LOADER_GLAD
)

target_link_libraries(imgui
    glfw
    glad
)

