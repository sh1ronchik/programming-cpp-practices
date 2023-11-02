#ifndef VECND_H
#define VECND_H

#include <vector>

class VecND {
public:
    VecND(int size);
    VecND(const std::vector<double>& vec);
    VecND(const VecND& other);
    ~VecND();

    VecND& operator=(const VecND& other);
    double& operator[](int index);
    const double& operator[](int index) const;

    int size() const {return data.size();}
private:
    std::vector<double> data;
};

#endif