#include "../include/Bishop.h"
#include <iostream>

void Bishop::display() const {
    std::cout << " " << (color == Color::White ? "\u265D" : "\u2657") << " ";
}

bool Bishop::canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const {
    return true; 
}