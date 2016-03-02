package array

// Gets a slice and a channel and sends the max element in the slice
// to the channel
func max(A []int, c chan<- int) {
	if len(A) == 0 { // Check if slice is empty
                close(c) // Close the channel
		return
	}
	if len(A) == 1 { // Check if slice has only one element
		c <- A[0]
		return
	}
	if len(A) == 2 { // Check if slice has two element
		if A[0] > A[1] { // Check if the first element is the bigger one
			c <- A[0]
		} else {
			c <- A[1]
		}
		return
	}

	c2 := make(chan int) // Create a channel for receiving max elements in every half of the slice

	go max(A[:len(A)/2], c2) // Find the max in the left half of the slice
	go max(A[len(A)/2:], c2) // Find the max in the right half of the slice

	first_max := <-c2 // Receive the left half max from channel
	second_max := <-c2 // Receive the right half max from channel

	if first_max > second_max { // Check if the first half max is bigger than the right half max
		c <- first_max
	} else {
		c <- second_max
	}
}

// Gets an array and returns the max element in it
func Max(A []int) int {
	c := make(chan int)
	go max(A, c)
	return <-c
}
