cmake_minimum_required(VERSION 3.8)
project(phantom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS true)

# the RPATH to be used when installing
SET(CMAKE_INSTALL_RPATH "")

include_directories(
                    ${CMAKE_SOURCE_DIR}/include
                    )

add_library( phantom SHARED
		${headers}
		src/test.hpp
		src/test.cpp
		)
