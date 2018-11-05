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
    int array[]  = {99,2,23,41,-5,23,-5,-10,4,8,-3};          /* Initializing random array           */
    int length = sizeof(array) / sizeof(array[0]);            /* Finding number of elements in array */
    mergeSort(array, length);                                 /* Merge sorting the array             */
    for(int index = 0; index < length; index++)               /* Printing sorted array, by element   */
        printf("%d ", array[index]);
    
    return 0;
}

/*** Merge Sort Function: Recursively sorts arrays of integers ***/
void mergeSort(int *array, int length){
    if(length < 2)                                            /* If number of elements = 1, return */
        return;

    int mid    = length / 2;                                  /* Find middle element                                         */
    int *left  = (int *)malloc((mid) * sizeof(int));          /* Allocating Memory x Number of elements in [0, ... , mid]    */
    int *right = (int *)malloc((length - mid) * sizeof(int)); /* Allocating Memory x Number of elements in [mid, ... , last] */
    
    for (int index = 0; index < mid; index++)
        left[index] = array[index];                           /* Initializing `left` subarray w/ elements at indexes array[0, ... , mid -1]  */
    for (int index = mid; index < length; index++)
        right[index - mid] = array[index];                    /* Initializing `right` subarray w/ elements at indexes array[mid, ... , size] */

    mergeSort(left, mid);                                     /* Sorting `left` array: [left ... mid]               */
    mergeSort(right, length - mid);                           /* Sorting `right` array: [mid + 1 ... right]         */
    merge(array, length, left, right);                        /* Merging `left` and `right` into `array`            */
    
    free(left);                                               /* freeing allocated memory for `left` subarray       */
    free(right);                                              /* freeing allocated memory for `right` subarray      */
}

/*** Merge Function: Merges subarrays into main array ***/
void merge(int *array, int length, int *left, int *right){
    int indexLeft = 0, indexRight = 0, index = 0;             /* Initialize index for each array                    */
    int lenLeft = length / 2, lenRight = length - lenLeft;    /* Set boundries for iteration of each subarray       */

    while(indexLeft < lenLeft && indexRight < lenRight){      /* While indexes are within subarrays' boundries      */
        if(left[indexLeft] < right[indexRight])               /* Compare elements from subarrays w/ eachother       */
            array[index++] = left[indexLeft++];               /* Merge element and continue to next iteration       */
        else  
            array[index++] = right[indexRight++];             /* Merge element and continue to next iteration       */
    }
    
    while(indexLeft < lenLeft)                                /* While there's leftover elements in left subarray   */
        array[index++] = left[indexLeft++];                   /* Merge elements into array; they're already sorted  */
    while (indexRight < lenRight)                             /* While there's leftover elements in right subarray  */
        array[index++] = right[indexRight++];                 /* Merge elements into array; they're already sorted) */
}
