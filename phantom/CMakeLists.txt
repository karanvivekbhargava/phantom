cmake_minimum_required(VERSION 3.0)
project(phantom)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

add_subdirectory(vendor/glad/)
#set(glad_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad)
#find_package(glad REQUIRED CONFIG)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include
)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

add_library( ${PROJECT_NAME} SHARED
    ${HDRS}
    ${SRCS}
)

target_link_libraries( phantom glfw GL glad )

# glad
#set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad)
#add_library( glad ${GLAD_DIR}/src/glad.c)
#target_include_directories(glad PRIVATE ${GLAD_DIR}/include)
#target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
#target_link_libraries(${PROJECT_NAME} glad ${CMAKE_DL_LIBS})


#install(TARGETS phantom
#    LIBRARY DESTINATION lib
#    PUBLIC_HEADER DESTINATION include/phantom)

#set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "phantom_pch.hpp")
#cotire(${PROJECT_NAME})
