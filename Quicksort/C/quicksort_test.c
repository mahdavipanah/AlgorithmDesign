#include "quicksort.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        // Size of int to be tested
        size_t n = 100000;

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

        // Fills the firt array with random numbers
        int i;
        for (i = 0; i < n; ++i)
                A[i] = rand() % (n * 1000);

        // Copies first array to seccond array
        int *B = malloc(sizeof(int) * n);
        memcpy(B, A, sizeof(int) * n);

        // Sorts the first array using qsort  function
        qsort(A, n, sizeof(int), cmpfunc);

        // Sorts the second array using quick_sort function
        // Calculates execution time for quick_sort function
        start = clock();
        quick_sort(B, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Checks if two arrays are exactly equal
        int failure = 0;
        for (i = 0; i < n; ++i)
                if (A[i] != B[i]) {
                        failure = 1;
                        break;
                }

        if (failure)
                printf(KRED "Algorithm Test failed!\n" RESET);
        else
                printf(KGRN "Algorithm Test succeeded!\n" RESET);

        printf(KBLU "Algorithm execution seconds: %lf\n" RESET, cpu_time_used);

        // Frees two arrays memory
        free(A);
        free(B);
        return failure;
}
