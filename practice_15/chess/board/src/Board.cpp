#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {
    initializeStandardPosition();
}

void Board::initializeStandardPosition() {
    for (int col =  0; col <  8; ++col) {
        board[1][col] = new Pawn(Color::Black, 1, col);
        board[6][col] = new Pawn(Color::White, 6, col);
    }

    board[0][0] = new Rook(Color::Black, 0, 0);
    board[0][7] = new Rook(Color::Black, 0, 7);

    board[0][1] = new Knight(Color::Black, 0, 1);
    board[0][6] = new Knight(Color::Black, 0, 6);

    board[0][2] = new Bishop(Color::Black, 0, 2);
    board[0][5] = new Bishop(Color::Black, 0, 5);

    board[0][3] = new Queen(Color::Black, 0, 3);
    board[0][4] = new King(Color::Black, 0, 4);

    board[7][0] = new Rook(Color::White, 7, 0);
    board[7][7] = new Rook(Color::White, 7, 7);

    board[7][1] = new Knight(Color::White, 7, 1);
    board[7][6] = new Knight(Color::White, 7, 6);

    board[7][2] = new Bishop(Color::White, 7, 2);
    board[7][5] = new Bishop(Color::White, 7, 5);

    board[7][3] = new Queen(Color::White, 7, 3);
    board[7][4] = new King(Color::White, 7, 4);
}

void Board::display() {
    std::cout << "  A  B  C  D  E  F  G  H" << std::endl;

    for (int row =  0; row <  8; ++row) {
        std::cout << (char)('8' - row);

        for (int col =  0; col <  8; ++col) {
            if (board[row][col] != nullptr) {
                board[row][col]->display();
            } else {
                bool isBlackCell = (row + col) %  2 ==  1;
                if (isBlackCell) {
                    std::cout << " # ";
                } else {
                    std::cout << " . ";
                }
            }
        }

        std::cout << std::endl;
    }
}

Board::~Board() {
    for (auto &row : board) {
        for (auto &piece : row) {
            delete piece;
        }
    }
}