#include "Rook.h"
#include <iostream>

void Rook::display() const {
    std::cout << " " << (color == Color::White ? "\u265C" : "\u2656") << " ";
}

bool Rook::canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const {
    return newX == x || newY == y;
}