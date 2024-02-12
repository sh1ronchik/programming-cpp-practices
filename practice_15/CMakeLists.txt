cmake_minimum_required(VERSION  3.10)
project(practice_09_02)

set(CMAKE_CXX_STANDARD  14)

include_directories(${PROJECT_SOURCE_DIR}/chess/pieces/include)

add_executable(chess_program
    chess/pieces/src/Pawn.cpp
    chess/pieces/src/Rook.cpp
    chess/pieces/src/Knight.cpp
    chess/pieces/src/Bishop.cpp
    chess/pieces/src/Queen.cpp
    chess/pieces/src/King.cpp
    practice_09_02.cpp
)