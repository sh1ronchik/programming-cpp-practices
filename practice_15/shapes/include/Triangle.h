#pragma once
#include "Shape.h"

class Triangle : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3);
    double calculatePerimeter() const override;
    void displayInfo() const override;
};