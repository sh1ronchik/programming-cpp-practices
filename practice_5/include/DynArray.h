#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <vector>
#include <cstddef> 

template <typename T>
class DynArray {
public:
    DynArray(std::size_t initial_capacity);
    DynArray(const DynArray& other);
    DynArray& operator=(const DynArray& other);
    T& operator[](std::size_t index);
    DynArray operator+(const DynArray& other);
    DynArray& operator<<(unsigned int delta);
    DynArray& operator>>(unsigned int delta);
    void append(T value);
    std::size_t size();
    ~DynArray();
    static int getLiveObjects(); 

private:
    std::vector<T> array;
    static int live_objects; // Счётчик живых объектов
};

#endif