#include "../include/Queen.h"
#include <iostream>

void Queen::display() const {
    std::cout << " " << (color == Color::White ? "\u265B" : "\u2655") << " ";
}

bool Queen::canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const {
    return true; 
}