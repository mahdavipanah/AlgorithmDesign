# [Quicksort algorithm](https://en.wikipedia.org/wiki/Quicksort)in C programming language

##  Files:
* quicksort.c:       Containts functions code
* quicksort.h:       Containts decleration of quick_sort function
* quicksort_test.c:  quick_sort function test program
* runtest:           Bash script for compiling and runing test

## Runing test
You need to have gcc compiler and bash interpreter installed on your machine in order to run the test.

For running the test you have to execute ./runtest script from your command line:
```Bash
$ ./runtest 1000
```
The optional argument to ./runtest determines the size of array to run the sort algorithm on. (The default is: 100000)

The output shows if the test has been successful and the algorithm's execution time in seconds.
