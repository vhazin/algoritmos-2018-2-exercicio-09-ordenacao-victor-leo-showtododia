/* Merge Sort Algorithm Implementation in C Programming
 * CESAR School, Data Structures and Algorithms
 * Assignee: Victor Hazin (github.com/vhazin)
 * Assigned to: Leonardo Melo (github.com/lcbm), Victor Almeida (github.com/victoralmeida432)
 * Reference: https://www.youtube.com/watch?v=TzeBrDU-JaY&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=5
 */

#include <stdio.h>
#include <stdlib.h>

/*** Prototype Functions ***/
void mergeSort(int *, int);
void merge(int *, int, int *, int *);

/*** Main Function: driver program to test merge sort function ***/
int main(void){
    int array[]  = {99,2,23,41,-5,23,-5,-10,4,8,-3}; /* Initializing random array           */
    int elements = sizeof(array) / sizeof(array[0]); /* Finding number of elements in array */
    mergeSort(array, elements);                      /* Merge sorting the array             */
    for(int index = 0; index < elements; index++){   /* Printing sorted array, by element   */
        printf("%d ", array[index]);
    }

	return 0;
}

/*** Merge Sort Function: Recursively sorts arrays of integers ***/
void mergeSort(int *array, int elements) {
	if(elements < 2) /* If number of elements = 1, return */
        return;

    int mid    = elements / 2;                                   /* Find middle element */
    int *left  = (int *)malloc((mid) * sizeof(int));             /* Allocating Memory x Number of elements in [0, ... , mid]    */
    int *right = (int *)malloc((elements - mid) * sizeof(int));  /* Allocating Memory x Number of elements in [mid, ... , last] */
    
    for (int index = 0; index < mid; index++)
        left[index] = array[index];        /* Initializing `left` subarray w/ elements at indexes `array[0, ... , mid -1]`  */
    for (int index = mid; index < elements; index++)
        right[index - mid] = array[index]; /* Initializing `right` subarray w/ elements at indexes `array[mid, ... , size]` */

    mergeSort(left, mid);                /* Sorting `left` array: [left ... mid]       */
    mergeSort(right, elements - mid);    /* Sorting `right` array: [mid + 1 ... right] */
    merge(array, elements, left, right); /* Merging `left` and `right` into `array`    */
    
    free(left);  /* freeing allocated memory for `left` subarray */
    free(right); /* freeing allocated memory for `right` subarray */
}

/*** Merge Function: Merges subarrays into main array ***/
void merge(int *array, int elements, int *left, int *right) {
    int indexLeft = 0, indexRight = 0, index = 0;              /* Initialize index for each array */
    int lenLeft = elements / 2, lenRight = elements - lenLeft; /* Set boundries for iteration     */

    /* Compare elements from subarrays index-by-index, sort, and merge */
    while(indexLeft < lenLeft && indexRight < lenRight) {
		if(left[indexLeft] < right[indexRight])
            array[index++] = left[indexLeft++];
		else 
            array[index++] = right[indexRight++];
	}

    /* Merge leftover elements (one array may be done before the other) */
	while(indexLeft < lenLeft)
        array[index++] = left[indexLeft++];
	while(indexRight < lenRight)
        array[index++] = right[indexRight++];
}
