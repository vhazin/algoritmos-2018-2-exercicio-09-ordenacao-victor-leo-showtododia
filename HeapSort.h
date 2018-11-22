#include <stdio.h>
#include "swap.h"

int HeapSortAlgorithm(int *, int);
void Heapify(int *, int, int);

int HeapSortAlgorithm(int *array, int length){
	for (int i = length / 2 - 1; i >= 0; i--)
		Heapify(array, length, i);

	for (int i = length - 1; i >= 0; i--){
		swap(&array[0], &array[i]);
		Heapify(array, i, 0);
	}
	return 0;
}

void Heapify(int *array, int length, int root){
	int largest = root;  
	int left = 2 * root + 1; 
	int right = 2 * root + 2;

	if (left < length && array[left] > array[largest])
		largest = left;
	if (right < length && array[right] > array[largest])
		largest = right;

	if (largest != root){
        swap(&array[root], &array[largest]);
		// xorSwap(&array[root], &array[largest]);
		Heapify(array, length, largest);
	}
}