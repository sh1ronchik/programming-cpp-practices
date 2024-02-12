#pragma once

#include "Piece.h"

class King : public Piece {
public:
    King(Color color_, int x_, int y_) : Piece(color_, x_, y_) {}

    void display() const override;
    bool canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const override;
};