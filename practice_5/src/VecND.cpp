#include "VecND.h"

VecND::VecND(int size) : data(size) {}

VecND::VecND(const std::vector<double>& vec) : data(vec) {}

VecND::VecND(const VecND& other) : data(other.data) {}

VecND::~VecND() {}

VecND& VecND::operator=(const VecND& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

double& VecND::operator[](int index) {
    return data[index];
}

const double& VecND::operator[](int index) const {
    return data[index];
}