#include <stddef.h>

/*
 * Returns biggest (max) element in the array
 */
// int[]  A : The array to search for the max element
// size_t n : Size of the array
int
array_max(int A[], size_t n)
{
        if (n == 0)
                return;
        if (n == 1)
                return A[0];
        if (n == 2) {
                if (A[0] > A[1])
                        return A[0];
                return A[1];
        }

        // Finds the max number in the left half of the array
        int lmax = array_max(A, n / 2);
        // Finds the max number in the right laft of the array
        int rmax = array_max(A + (n / 2), n - n / 2);

        // Finds the biggest number between the left half max and right half max
        if (lmax > rmax)
                return lmax;
        return rmax;
}
