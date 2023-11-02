#ifndef MAT2D_H
#define MAT2D_H

#include <vector>
#include "VecND.h"

template <typename T>
class Mat2D {
public:
    int getRows() const { return rows; }
    Mat2D(int rows, int cols);
    Mat2D(const std::vector<std::vector<T>>& matrix);
    Mat2D(const Mat2D& other);
    ~Mat2D();

    Mat2D& operator=(const Mat2D& other);
    VecND<T>& operator[](int index);
    const VecND<T>& operator[](int index) const;

    Mat2D operator+(const Mat2D& other) const;
    Mat2D operator*(const Mat2D& other) const;
    VecND<T> operator*(const VecND<T>& vec) const;

    Mat2D transpose() const;
    Mat2D minor(int i, int j) const;
    T determinant() const;

private:
    std::vector<VecND<T>> data;
    int rows, cols;
};

#endif