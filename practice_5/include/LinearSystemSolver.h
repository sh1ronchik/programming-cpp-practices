#ifndef LINEAR_SYSTEM_SOLVER_H
#define LINEAR_SYSTEM_SOLVER_H

#include "../include/Mat2D.h"
#include "../include/VecND.h"

class LinearSystemSolver {
public:
    LinearSystemSolver(const Mat2D& A, const VecND& b);
    VecND solve();

private:
    Mat2D A;
    VecND b;
};

#endif 