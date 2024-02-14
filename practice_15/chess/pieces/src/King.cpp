#include "King.h"
#include <iostream>

void King::display() const {
    std::cout << " " << (color == Color::White ? "\u265A" : "\u2654") << " ";
}

bool King::canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const {
    return abs(newX - x) <=  1 && abs(newY - y) <=  1;
}