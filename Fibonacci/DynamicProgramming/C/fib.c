#include <stdlib.h>

/*
 * Returns nth fibonacci number using dynamic programming
 * https://en.wikipedia.org/wiki/Fibonacci_number
 */
// n : nth fibonacci number
unsigned long long
fib(unsigned int n)
{
        if (n == 0)
                return 0;
        if (n == 1)
                return 1;

        // Defines an array with size = n
        unsigned long long numbers[n];

        // Fills the first two numbers in the array
        numbers[0] = 0;
        numbers[0] = 1;

        unsigned int i;
        // Fills the array with other numbers until the nth number
        for (i = 2; i <= n; ++i)
                numbers[i] = numbers[i - 1] + numbers[i - 2];

        return numbers[n];
}
