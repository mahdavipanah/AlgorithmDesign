#include <string.h>
#include <stdio.h>

/*
 * Swaps two input ints
 */
void
swap (int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}

/*
 * returns the index of pivot item (first element)
 */
size_t
partition (int A[], size_t n)
{
        size_t  i = 1,
                j = 0;

        int PI = A[0];

        for (; i < n; ++i)
                if (A[i] < PI) {
                        ++j;
                        swap(&A[i], &A[j]);
                }

        swap(&A[0], &A[j]);

        return j;

}

/*
 * Sorts an int array using Merge sort algorithm
 * https://en.wikipedia.org/wiki/Quicksort
 */
// int[] A : The array to be sorted
// int   n : Size of the array
void
quick_sort(int A[], size_t n)
{
        // Checks if array has more than one element
        if (n > 0) {

          /*
           * Partitioning
           *
           * finding the place for the pivot element (first element)
           */
           
          size_t p = partition(A, n);

          /*
           * Recursively apply the above steps for elements before and after pivot element
           */
          quick_sort(A, p);
          quick_sort(A + p + 1, n - p - 1);
        }
}
