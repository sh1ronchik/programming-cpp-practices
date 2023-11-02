#include "Mat2D.h"

template class Mat2D<int>;

template <typename T>
Mat2D<T>::Mat2D(int rows, int cols) : rows(rows), cols(cols), data(rows, VecND<T>(cols)) {}

template <typename T>
Mat2D<T>::Mat2D(const std::vector<std::vector<T>>& matrix) : rows(matrix.size()), cols(matrix[0].size()) {
    data.reserve(rows);
    for (const auto& row : matrix) {
        data.push_back(VecND<T>(row));
    }
}

template <typename T>
Mat2D<T>::Mat2D(const Mat2D& other) : rows(other.rows), cols(other.cols), data(other.data) {}

template <typename T>
Mat2D<T>::~Mat2D() {}

template <typename T>
Mat2D<T>& Mat2D<T>::operator=(const Mat2D& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

template <typename T>
VecND<T>& Mat2D<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const VecND<T>& Mat2D<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
Mat2D<T> Mat2D<T>::operator+(const Mat2D& other) const {
    Mat2D result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Mat2D<T> Mat2D<T>::operator*(const Mat2D& other) const {
    Mat2D result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
VecND<T> Mat2D<T>::operator*(const VecND<T>& vec) const {
    VecND<T> result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += data[i][j] * vec[j];
        }
    }
    return result;
}

template <typename T>
Mat2D<T> Mat2D<T>::transpose() const {
    Mat2D result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = data[i][j];
        }
    }
    return result;
}

template <typename T>
Mat2D<T> Mat2D<T>::minor(int i, int j) const {
    std::vector<std::vector<T>> minr;
    for(int r = 0; r < rows; ++r) {
        if (r == i) continue;
        std::vector<T> row;
        for(int c = 0; c < cols; ++c) {
            if (c == j) continue;
            row.push_back(data[r][c]);
        }
        minr.push_back(row);
    }
    return Mat2D(minr);
}

template <typename T>
T Mat2D<T>::determinant() const {
    if (rows == 1)
        return data[0][0];
    if (rows == 2)
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];

    T sum = 0;
    for (int j = 0; j < rows; ++j) {
        sum += (1 - (j % 2) * 2) * data[0][j] * minor(0, j).determinant();
    }
    return sum;
}