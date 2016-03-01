# [Merge sort algorithm](https://en.wikipedia.org/wiki/Merge_sort) in Go programming language

##  Files:
* mergesort.go:      Containts merge_sort function code   
* mergesort_test.go: merge_sort function test program
* runtest:           Bash script running tests and benchmarks

## Runing test
You need to have go and bash interpreter installed on your machine in order to run the test.

For runing the test you have to execute ./runtest script from your command line:
```Bash
$ ./runtest 1000
```
The optional argument to ./runtest determines the size of slice to run the sort algorithm on. (The default is: 100000)

The output shows if the test has been successful and the benchmark's result.
