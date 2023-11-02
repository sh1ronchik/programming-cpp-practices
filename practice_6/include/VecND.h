#ifndef VECND_H
#define VECND_H

#include <vector>

template <typename T>
class VecND {
public:
    VecND(int size);
    VecND(const std::vector<T>& vec);
    VecND(const VecND& other);
    ~VecND();

    VecND& operator=(const VecND& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    int size() const {return data.size();}
private:
    std::vector<T> data;
};

#endif