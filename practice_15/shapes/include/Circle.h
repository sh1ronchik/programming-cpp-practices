#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    double calculatePerimeter() const override;
    void displayInfo() const override;
};