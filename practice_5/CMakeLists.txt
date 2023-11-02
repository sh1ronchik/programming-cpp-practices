cmake_minimum_required(VERSION 3.10) 

project(practice_13_10) 

set(CMAKE_CXX_STANDARD 14) 

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(practice_13_10 src/LinearSystemSolver.cpp src/VecND.cpp main.cpp src/Mat2D.cpp)