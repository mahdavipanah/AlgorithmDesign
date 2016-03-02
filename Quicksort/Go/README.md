# [Quicksort algorithm](https://en.wikipedia.org/wiki/Quicksort) in Go programming language

##  Files:
* concqsort.go:      Contains qsort.ConcSort related codes
* qsort_test.go:     Contains tests and benchmarks for qsort package
* qsort.go           contains qsort.Sort related codes
* runtest:           Bash script running tests and benchmarks

## Runing test
You need to have go and bash interpreter installed on your machine in order to run the test.

For runing the test you have to execute ./runtest script from your command line:
```Bash
$ ./runtest 100000
```
The optional argument to ./runtest determines the size of slice to run the sort algorithm on. (The default is: 100000)

The output shows if the test has been successful and the benchmark's result.
