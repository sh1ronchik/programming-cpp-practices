#include "../include/Knight.h"
#include <iostream>

void Knight::display() const {
    std::cout << " " << (color == Color::White ? "\u265E" : "\u2658") << " ";
}

bool Knight::canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const {
    return true; 
}