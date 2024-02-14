#pragma once

#include <vector>
#include "Piece.h"

class Board {
public:
    Board();
    ~Board();

    void initializeStandardPosition();
    void display();

private:
    std::vector<std::vector<Piece*>> board;
};