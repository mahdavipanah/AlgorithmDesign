package qsort

import (
	"math/rand"
	"os"
	"reflect"
	"sort"
	"strconv"
	"testing"
	"time"
)

var sliceLength int = 100000 // Stores the length of slice to run the test on

func init() {
	// Gets the test slice's length from environment variable
	// or if not set or if it's not an int value, sets it to 10000
	_sliceLength, err := strconv.Atoi(os.Getenv("SLICELEN"))
	if err == nil {
		sliceLength = _sliceLength
	}
}

// Returns two equal slices with random elements
func randSlices() (A, B []int) {
	// Generates new source and rand based on system time
	source := rand.NewSource(time.Now().UnixNano())
	rnd := rand.New(source)

	// Creates two slices for test process
	A = make([]int, sliceLength)
	B = make([]int, sliceLength)
	// Fills slices with same random numbers
	for i, _ := range A {
		A[i] = rnd.Intn(100)
		B[i] = A[i]
	}

	return
}

// Tests the qsort.ConcSort or qsort.Sort functions by filling a slice with random numbers
// and then sorting it with package functions and sort.Ints and check if they
// are equal
//
// conc bool : chooses if test should be run on qsort.ConcSort or qsort.Sort
func test(t *testing.T, conc bool) {
	// Gets two equal random element generated slices
	A, B := randSlices()

	if conc {
		ConcSort(A)
	} else {
		Sort(A)
	}
	sort.Ints(B) // Sorts second slice using sort.Ints go standard library function

	// Checks if two slices are equal
	if reflect.DeepEqual(A, B) == false {
		t.Error()
	}

}

// Tests the qsort.ConcSort
func TestConcSort(t *testing.T) {
	test(t, true)
}

// Tests the qsort.Sort
func TestSort(t *testing.T) {
	test(t, false)
}

// Evaluates execution time for qsort.ConcSort or qsort.Sort function for sorting
// a slice with given length (In "SLICELEN" environment variable)
//
// conc bool : chooses if benchmark should be run on qsort.ConcSort or qsort.Sort
func benchmark(b *testing.B, conc bool) {
	for i := 0; i < b.N; i++ {
		b.StopTimer()
		A, _ := randSlices()
		b.StartTimer()
		if conc {
			ConcSort(A)
		} else {
			Sort(A)
		}
	}
}

// Runs the benchmark for qsort.ConcSort
func BenchmarkConcSort(b *testing.B) {
	benchmark(b, true)
}

// Runs the benchmark for qsort.Sort
func BenchmarkSort(b *testing.B) {
	benchmark(b, false)
}
