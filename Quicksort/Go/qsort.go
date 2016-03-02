package qsort

/*
Returns the place of pivot element (leftmost element) in the slice
and places the pivot element in it's correct position in the slice
*/
func partition(A []int) int {
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

        return j
}

/*
Sorts the given slice using Quicksort algorithm
*/
func Sort(A []int) {
        // Check if slice has only one element
        if len(A) < 2 {
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
                return
        }

        // Get the position of the pivot element
        pos := partition(A)

        // Invokes itself and sorts the left side and right side
        // of the pivot item
        Sort(A[:pos])
        Sort(A[pos + 1:])

}
