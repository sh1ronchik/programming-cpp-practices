#include "Position.h"

Position::Position(int row, int col) : m_row(row), m_col(col) {}

void Position::SetPosition(int row, int col) {
    m_row = row;
    m_col = col;
}

int Position::GetRow() const { return m_row; }
int Position::GetCol() const { return m_col; }

bool Position::operator == (const Position &rhs) const {
    return m_row == rhs.m_row && m_col == rhs.m_col;
}