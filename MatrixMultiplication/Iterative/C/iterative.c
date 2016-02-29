#include "iterative.h"
/*
 * Iterative algorithm for square matrix multiplication
 * https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm#Iterative_algorithm
 */
// int[] A : The first array
// int[] B : The second array
// int[] C : The result array
// int   n : Size of the arrays rows and columns
void
iterative(int **A, int **B, int** C, size_t n)
{
        int i = 0;
        for (; i < n; ++i) {
                int j = 0;
                for (; j < n; ++j) {
                        int k   = 0,
                            sum = 0;
                        for (; k < n; ++k)
                                sum += A[i][k] * B[k][j];
                        C[i][j] = sum;
                }
        }
}
