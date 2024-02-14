#pragma once

#include <vector>
#include "Piece.h"
#include "Position.h"

class Board {
public:
    Board();

    void initializeStandardPosition();
    void display();
    void movePiece(const Position& from, const Position& to); 

    ~Board();

private:
    std::vector<std::vector<Piece*>> board;
    Piece* getPieceAt(const Position& pos) const; 
    void setPieceAt(const Position& pos, Piece* piece); 
};