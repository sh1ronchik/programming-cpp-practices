#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(double w_, double h_) : w(w_), h(h_) {}

double Rectangle::calculatePerimeter() const {
    return  2 * (w + h);
}

void Rectangle::displayInfo() const {
    std::cout << "Rectangle: Width = " << w << ", Height = " << h << ", ";
}
