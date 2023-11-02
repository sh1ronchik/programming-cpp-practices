#ifndef MAT2D_H
#define MAT2D_H

#include <vector>
#include "VecND.h"

class Mat2D {
public:
    int getRows() const { return rows; }
    Mat2D(int rows, int cols);
    Mat2D(const std::vector<std::vector<double>>& matrix);
    Mat2D(const Mat2D& other);
    ~Mat2D();

    Mat2D& operator=(const Mat2D& other);
    VecND& operator[](int index);
    const VecND& operator[](int index) const;

    Mat2D operator+(const Mat2D& other) const;
    Mat2D operator*(const Mat2D& other) const;
    VecND operator*(const VecND& vec) const;

    Mat2D transpose() const;
    Mat2D minor(int i, int j) const;
    double determinant() const;

private:
    std::vector<VecND> data;
    int rows, cols;
};

#endif