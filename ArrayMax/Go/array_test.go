package array

import (
	"math/rand"
	"os"
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

// Returns a slice with random elements
func randSlice() (A []int) {
	// Generates new source and rand based on system time
	source := rand.NewSource(time.Now().UnixNano())
	rnd := rand.New(source)

	A = make([]int, sliceLength)
	// Fills slice with same random numbers
	for i, _ := range A {
		A[i] = rnd.Intn(100)
	}

	return
}

// Tests the array.Max
// Compares the returned value from Max function with the last element
// of an sorted (using sort.Ints) random element generated slice and
// if they are not equal detects an error
func TestMax(t *testing.T) {
	A := randSlice()

	biggest := Max(A)

	sort.Ints(A)

	if biggest != A[len(A)-1] {
		t.Error()
	}
}

func BenchmarkMax(b *testing.B) {
        A := randSlice()
        var biggest int
        biggest++
        b.ResetTimer()
        for i := 0; i < b.N; i++ {
                biggest = Max(A)
        }
}
