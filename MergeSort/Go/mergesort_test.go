// Test suit for mergesort.Sort
package mergesort

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

// Tests the mergesort.Sort function by filling a slice with random numbers
// and then sorting it with mergesort.Sort and sort.Ints and check if they
// are equal
func TestSort(t *testing.T) {
	// Gets two equal random element generated slices
	A, B := randSlices()

	Sort(A)      // Sorts first slice using megesort.Sort function
	sort.Ints(B) // Sorts second slice using sort.Ints go standard library function

	// Checks if two slices are equal
	if reflect.DeepEqual(A, B) == false {
		t.Error()
	}

}

// Evaluates execution time for mergesort.Sort function for sorting
// a slice with given length
func BenchmarkSort(b *testing.B) {
	for i := 0; i < b.N; i++ {
		b.StopTimer()
		A, _ := randSlices()
		b.StartTimer()
		Sort(A)
	}
}
