#include "LinearSystemSolver.h"

LinearSystemSolver::LinearSystemSolver(const Mat2D& A, const VecND& b) : A(A), b(b) {
}

VecND LinearSystemSolver::solve() {
    int n = A.getRows();
    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
        }
        b[i] /= pivot;
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i];
            for (int k = 0; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }
    VecND x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
    }
    return x;
}