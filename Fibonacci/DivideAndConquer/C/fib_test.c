#include "fib.h"
#include <time.h>
#include <stdio.h>
#include <ctype.h>

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
        unsigned int n = 30;

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
                        sscanf(argv[1], "%u", &n);
        }

        // For mesuring algorithm execution time
        clock_t start, end;
        double cpu_time_used;


        // Sorts the second array using quick_sort function
        // Calculates execution time for quick_sort function
        start = clock();
        unsigned long long nth_fib = fib(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%llu\n", nth_fib);
        printf(KBLU "Algorithm execution seconds: %lf\n" RESET, cpu_time_used);

        return 1;
}
