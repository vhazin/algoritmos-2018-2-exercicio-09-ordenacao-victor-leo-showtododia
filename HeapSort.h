#include <stdio.h>
#include "swap.h"

void Heapify(int *, int, int);

int HeapSortAlgorithm(int *array, int length){
	// Build heap (rearrange array)
	for (int i = length / 2 - 1; i >= 0; i--)
		Heapify(array, length, i);

	// One by one extract an element from heap
	for (int i = length - 1; i >= 0; i--){
		// Move current root to end
		swap(&array[0], &array[i]);
		
		// call max heapify on the reduced heap
		Heapify(array, i, 0);
	}

	// for (int index = 0; index < length; index++)
	// 	printf("%d, ", array[index]);

	return 0;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void Heapify(int *array, int length, int root){
	int largest = root; // Initialize largest as root
	int left = 2 * root + 1; // left = 2*i + 1
	int right = 2 * root + 2; // right = 2*i + 2
	
	// If left child is larger than root
	if (left < length && array[left] > array[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < length && array[right] > array[largest])
		largest = right;

	// If largest is not root
	if (largest != root){
		swap(&array[root], &array[largest]);

		// Recursively heapify the affected sub-tree
		Heapify(array, length, largest);
	}
}