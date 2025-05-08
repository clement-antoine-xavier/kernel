cmake_minimum_required(VERSION 3.20)

project(kernel)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -ansi -pedantic"
    CACHE STRING "C++ compiler flags")

set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")
set(SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sources")

include_directories(${HEADERS_DIR})

file(GLOB_RECURSE SOURCES
    "${SOURCES_DIR}/*.cpp"
)

file(GLOB_RECURSE HEADERS
    "${HEADERS_DIR}/*.hpp"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
