cmake_minimum_required(VERSION 3.10) 

project(practice_20_10) 

set(CMAKE_CXX_STANDARD 14) 

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(practice_20_10 practice_20_10.cpp src/Queue.cpp)