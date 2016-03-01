// Merge sort algorithm in Go programming language
package mergesort

/*
Sorts an int slice using Merge sort algorithm
https://en.wikipedia.org/wiki/Merge_sort
*/
func Sort(A []int) {
	// Checks if slice has at least two elements
	if len(A) < 2 {
		return
	}

	/*
	Divide Part
	*/

	// Creates two new slices for every half of the slice
	u := make([]int, len(A)/2)
	v := make([]int, len(A)-len(u))

	// Copies every half of the slice to new slices
	copy(u, A[:len(u)])
	copy(v, A[len(u):])

	// Calls Sort recursively for two new slices
	Sort(u)
	Sort(v)

	/*
	Merge Part
	*/

	var i, j, k int = 0, 0, 0
	for ; i < len(u) && j < len(v); k++ {
		if u[i] < v[j] {
			A[k] = u[i]
			i++
		} else {
			A[k] = v[j]
			j++
		}
	}

	if i < len(u) {
		copy(A[k:], u[i:])
	} else if j < len(v) {
		copy(A[k:], v[j:])
	}

}
