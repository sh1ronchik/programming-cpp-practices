#pragma once

class Position {
public:
    Position(int row, int col);

    void SetPosition(int row, int col);
    int GetRow() const;
    int GetCol() const;

    bool operator == (const Position &rhs) const;

private:
    int m_row;
    int m_col;
};