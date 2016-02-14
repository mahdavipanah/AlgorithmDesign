#include <string.h>

/*
 * Sorts an int array using Merge sort algorithm
 * https://en.wikipedia.org/wiki/Merge_sort
 */
// int[] A : The array to be sorted
// int   n : Size of the array
void
merge_sort(int A[], size_t n)
{
        // Checks if array has more than one element
        if (n > 1) {
                /*
                * Divide Part
                */


                size_t h, m;
                h = n / 2;
                m = n - h;
                // Splits the array into two new arrays
                int u[h], v[m];
                /*
                 * See http://www.cplusplus.com/reference/cstring/memcpy/
                 * for more details about memcpy function
                 */
                // Copies the first half of the array
                memcpy(u, A, sizeof(int) * h);
                // Copies the second half of the array
                memcpy(v, A + h, sizeof(int) * m);
                /* Calls merge_sort recursively for sorting two new arrays */
                merge_sort(u, h);
                merge_sort(v, m);


                /*
                * Merge Part
                */


                /* Merges two new sorted arrays into main array */
                size_t i = 0,
                       j = 0,
                       k = 0;
                for (; i < h && j < m; ++k) {
                        if (u[i] < v[j]) {
                                A[k] = u[i];
                                ++i;
                        } else {
                                A[k] = v[j];
                                ++j;
                        }
                }
                if (i < h) {
                        memcpy(A + k, u + i, sizeof(int) * (h - i));
                } else if(j < m) {
                        memcpy(A + k, v + j, sizeof(int) * (m - j));
                }
        }
}
