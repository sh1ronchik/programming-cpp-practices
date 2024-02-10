#include "Circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::calculatePerimeter() const {
    return  2 * M_PI * radius;
}

void Circle::displayInfo() const {
    std::cout << "Circle: Radius = " << radius << ", ";
}