cmake_minimum_required(VERSION 3.0)
project(phantom)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

file(GLOB_RECURSE SRCS src/*)
file(GLOB_RECURSE HDRS include/*)

add_library( ${PROJECT_NAME} SHARED
    ${HDRS}
    ${SRCS}
)

#install(TARGETS phantom
#    LIBRARY DESTINATION lib
#    PUBLIC_HEADER DESTINATION include/phantom)

#set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "phantom_pch.hpp")
#cotire(${PROJECT_NAME})
