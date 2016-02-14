# Merge sort algorithm in C programming language

##  Files:
* mergesort.c:       Containts merge_sort function code
* mergesort.h:       Containts decleration of merge_sort function
* mergesort_test.c:  merge_sort function test program
* runtest:           Bash script for compiling and runing test

## Runing test
You need to have gcc compiler and bash interpreter installed on your machine in order to run the test.

For runing the test you have to execute ./runtest script from your command line:
```Bash
$ ./runtest 1000
```
The optional argument to ./runtest determines the size of array to run the sort algorithm on. (The default is: 100000)

The output shows if the test has been successful and the algorithm's execution time in seconds.
