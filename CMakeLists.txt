# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.13)
# CMAKE_POLICY(SET CMP0072 NEW)
# Project name
project(2dGame)

set(CMAKE_CXX_STANDARD 14)  # enable C++14 standard

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include_directories("${PROJECT_SOURCE_DIR}")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)


file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_executable(${PROJECT_NAME} ${all_SRCS} src/PoliceCar.cpp include/PoliceCar.h src/SdlPoliceCar.cpp include/SdlPoliceCar.h src/Bomb.cpp include/Bomb.h)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 ${SDL2_IMAGE_LIBRARIES})