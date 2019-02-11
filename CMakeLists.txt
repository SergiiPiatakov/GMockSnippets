cmake_minimum_required (VERSION 3.0)

project (Controller)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories (
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

set (
    controller_SOURCES
    ${PROJECT_SOURCE_DIR}/src/controller.cpp
)

add_library (
    controller SHARED
    ${controller_SOURCES}
)
