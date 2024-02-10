cmake_minimum_required(VERSION 3.10)
project(practice_09_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/shapes/include)

add_executable(practice_09_02
    shapes/src/Rectangle.cpp
    shapes/src/Circle.cpp
    shapes/src/Triangle.cpp
    practice_09_02.cpp
)