#pragma once

#include <vector>

enum class Color { White, Black };

class Piece {
public:
    Piece(Color color_, int x_, int y_) : color(color_), x(x_), y(y_) {}

    Color getColor() const { return color; }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x_) { x = x_; }
    void setY(int y_) { y = y_; }

    virtual void display() const =  0;
    virtual bool canMoveTo(int newX, int newY, const std::vector<std::vector<Piece*>>& board) const =  0;

    virtual ~Piece() = default;

protected:
    Color color;
    int x, y;
};