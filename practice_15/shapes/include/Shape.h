#pragma once
#include <iostream>

class Shape {
public:
    virtual double calculatePerimeter() const =  0;
    virtual void displayInfo() const =  0;
};
