#include "../include/Pawn.h"
#include <iostream>

void Pawn::display() const {
    std::cout << " " << (color == Color::White ? "\u265F" : "\u2659") << " ";
}

bool Pawn::canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const {
    return true; 
}