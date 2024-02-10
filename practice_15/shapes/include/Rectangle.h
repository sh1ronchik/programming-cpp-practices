#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
    double w, h;

public:
    Rectangle(double w_, double h_);
    double calculatePerimeter() const override;
    void displayInfo() const override;
};
