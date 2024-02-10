#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

double Triangle::calculatePerimeter() const {
    return side1 + side2 + side3;
}

void Triangle::displayInfo() const {
    std::cout << "Triangle: Side1 = " << side1 << ", Side2 = " << side2 << ", Side3 = " << side3 << ", ";
}