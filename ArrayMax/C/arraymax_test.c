#include "arraymax.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

/* Macros for printing colored outputs */
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define RESET "\033[0m"

// int compare function for passing to qsort function
int
cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int
main (int argc, char *argv[]) {
        // Size of array to be tested
        size_t n = 10000;

        // Checks if test should be ran with custom array size
        if (argc > 1) {
                int are_all_digits = 1;

                char *cp;
                for (cp = argv[1]; cp && *cp == ' '; ++cp)
                        // Checks if char is not a digit
                        if (!isdigit(*cp)) {
                                are_all_digits = 0;
                                break;
                        }

                // Checks if all chars were digits
                if (are_all_digits)
                        // Changes the n variable to first program arg
                        sscanf(argv[1], "%zd", &n);
        }

        // For mesuring algorithm execution time
        clock_t start, end;
        double cpu_time_used;

        // For generating random numbers
        srand(time(NULL));

        int *A = malloc(sizeof(int) * n);

        // Fills the array with random numbers
        int i;
        for (i = 0; i < n; ++i)
                A[i] = rand();

        // Calculates execution time for array_max function
        start = clock();
        int max = array_max(A, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Sorts the array using qsort function
        qsort(A, n, sizeof(int), cmpfunc);

        // Checks if the returned value from array_max is equal
        // to the last element of the sorted array.
        // stdlib.h:qsort sorts the array ascending therefore the last element
        // in the sorted array is the biggest one.
        int failure = (max == A[n - 1] ? 0 : 1);

        if (failure)
                printf(KRED "Algorithm Test failed!\n" RESET);
        else
                printf(KGRN "Algorithm Test succeeded!\n" RESET);

        printf(KBLU "Algorithm execution seconds: %lf\n" RESET, cpu_time_used);

        // Frees the array memory
        free(A);
        return failure;
}
