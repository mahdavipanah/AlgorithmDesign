package qsort

/*
Finds the place of pivot element (leftmost element) in the slice
and sends a signal to the given channel and invokes itself recursively
and concurrently
*/
func concPartition(A []int, c chan bool) {
        // Check if slice has only one element
        if len(A) < 2 {
                c <- true
                return
        }
        // Check if slice has two elements
        // if it has, and the first element is bigger,
        // just swap the elements
        if len(A) == 2 {
                if A[0] > A[1] {
                        // Swap the elements
                        A[0], A[1] = A[1], A[0]
                }
                c <- true
                return
        }

        j := 0
        // Value of the pivot item
        // choose the pivot item base on the leftmost element
        PI := A[0]
        for i := 1; i < len(A); i++ {
                // If the element is smaller that pivot
                // swap it with the first bigger element
                if A[i] < PI {
                        j++;
                        A[i], A[j] = A[j], A[i]
                }
        }
        // Swap the pivot with the last smaller element
        A[0], A[j] = A[j], A[0]

        c <- true

        // Invoke partition recursively and concurrently
        // on the left side and right side of the Pivot element
        go concPartition(A[:j], c)
        go concPartition(A[j + 1:], c)
}

/*
Sorts the given slice using Quicksort algorithm concurrently

Uses goroutines and channels for it's concurrent pattern.
*/
func ConcSort(A []int) {
        // A channel for counting number of sorted elements
        c := make(chan bool)
        // Run partition concurrently on the slice
        go concPartition(A, c)
        // Read from channel n times; n = length of the slice
        for i := 0; i < len(A); i++ {
                <-c
        }

}
