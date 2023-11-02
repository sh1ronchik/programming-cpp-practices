#include "DynArray.h"
#include <iostream>

template class DynArray<int>;
template class DynArray<double>;
template class DynArray<char>;
template class DynArray<std::string>;

template <typename T>
int DynArray<T>::live_objects = 0;

template <typename T>
DynArray<T>::DynArray(size_t initial_capacity) {
    array.reserve(initial_capacity);
    live_objects++;
}

template <typename T>
DynArray<T>::DynArray(const DynArray& other) : array(other.array) {
    live_objects++;
}

template <typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray& other) {
    if (this != &other) {
        array = other.array;
    }
    return *this;
}

template <typename T>
T& DynArray<T>::operator[](size_t index) {
    return array[index];
}

template <typename T>
DynArray<T> DynArray<T>::operator+(const DynArray& other) {
    DynArray result = *this;
    result.array.insert(result.array.end(), other.array.begin(), other.array.end());
    return result;
}

template <typename T>
DynArray<T>& DynArray<T>::operator<<(unsigned int delta) {
    delta %= array.size(); 
    std::vector<T> temp(array.begin() + delta, array.end());
    temp.insert(temp.end(), array.begin(), array.begin() + delta);
    array = temp;
    return *this;
}

template <typename T>
DynArray<T>& DynArray<T>::operator>>(unsigned int delta) {
    delta %= array.size(); 
    std::vector<T> temp(array.end() - delta, array.end());
    temp.insert(temp.end(), array.begin(), array.end() - delta);
    array = temp;
    return *this;
}

template <typename T>
void DynArray<T>::append(T value) {
    array.push_back(value);
}

template <typename T>
size_t DynArray<T>::size() {
    return array.size();
}

template <typename T>
DynArray<T>::~DynArray() {
    live_objects--;
}

template <typename T>
int DynArray<T>::getLiveObjects() {
    return live_objects;
}