# Finding the max number in an array using divide and conquer technique and concurrent programming features in Go programming language

##  Files:
* array.go:      Contains array.Max related codes
* array_test.go:     Contains tests and benchmarks
* runtest:           Bash script for running tests and benchmarks

## Runing test
You need to have go and bash interpreter installed on your machine in order to run the test.

For runing the test you have to execute ./runtest script from your command line:
```Bash
$ ./runtest 100000
```
The optional argument to ./runtest determines the size of slice to run the max finding algorithm on. (The default is: 100000)

The output shows if the test has been successful and the benchmark's result.
