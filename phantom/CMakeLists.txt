cmake_minimum_required(VERSION 3.0)
project(phantom)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(BUILD_SHARED_LIBS true)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
					${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

add_library( ${PROJECT_NAME} SHARED
		${headers}
                src/core.cpp
                src/application.cpp
                src/entry_point.cpp
                src/log.cpp
                src/test.cpp
		)
cotire(phantom)
