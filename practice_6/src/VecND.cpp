#include "VecND.h"

template class VecND<int>;

template <typename T>
VecND<T>::VecND(int size) : data(size) {}

template <typename T>
VecND<T>::VecND(const std::vector<T>& vec) : data(vec) {}

template <typename T>
VecND<T>::VecND(const VecND& other) : data(other.data) {}

template <typename T>
VecND<T>::~VecND() {}

template <typename T>
VecND<T>& VecND<T>::operator=(const VecND& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template <typename T>
T& VecND<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& VecND<T>::operator[](int index) const {
    return data[index];
}