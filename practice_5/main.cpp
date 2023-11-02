#include "LinearSystemSolver.h"
#include "Mat2D.h"
#include "VecND.h"
#include <iostream>

int main() {
    Mat2D A(2, 2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    VecND b(2);
    b[0] = 5;
    b[1] = 6;

    LinearSystemSolver solver(A, b);

    VecND x = solver.solve();

    for (int i = 0; i < x.size(); i++) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}