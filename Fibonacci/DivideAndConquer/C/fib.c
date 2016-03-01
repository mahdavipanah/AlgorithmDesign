/*
 * Returns nth fibonacci number using divide and conquer approach
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

        return fib(n - 1) + fib(n - 2);
}
