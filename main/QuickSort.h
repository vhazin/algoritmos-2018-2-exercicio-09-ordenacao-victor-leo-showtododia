#include <stdlib.h>
#include <time.h>
#include "swap.h"

/* Prototype Functions */
int RandomPivot(int *, int, int);
int LomutoPartition(int *, int, int);
int HoarePartition (int *, int, int);

/* Main Function */
void QuickSortAlgorithm(int* array, int start, int end) {
    if (start < end){

        RandomPivot(array, start, end);
        
        int pi = HoarePartition(array, start, end); /* pi is partitioning index, array[p] is now at right place */  
        // int pi = LomutoPartition(array, start, end);

        QuickSortAlgorithm(array, start, pi - 1);    /* Separately sort elements before partition and after partition */
        QuickSortAlgorithm(array, pi + 1, end);
    }
}

/* Random Pivot Choice for Each Approach */
int RandomPivot(int *array, int start, int end){
    /* Generate a random number in between start & end */
    srand(time(NULL)); 
    int random = start + rand() % (end - start);

    swap(&array[random], &array[start]);
    return HoarePartition(array, start, end);

    // swap(&array[random], &array[end]);
    // return LomutoPartition(array, start, end);
}

/* 
 * Lomutos Partition Scheme:
 * - Take the last element as pivot;
 * - Place it at its correct position in sorted array;
 * - Place all smaller than pivot elements to the start & greater ones to the right
*/
int LomutoPartition(int *array, int start, int end){ 
    int pivot = array[end];           /* set pivot at last element*/
    int index = (start - 1);          /* Index of smaller element */
  
    for (int element = start; element <= end - 1 ; element++){ 
        if (array[element] <= pivot){ /* If current element is smaller than or equal to pivot */ 
            index++;                  /* increment index of smaller element */
            swap(&array[index], &array[element]); 
        } 
    } 
    swap(&array[index + 1], &array[end]); 
    
    return (index + 1); 
}

/* 
 * Hoare Partition Scheme:
 * - Initialize two indexes that start at two ends (ptrLeft and ptrRight);
 * - The two indexes move toward each other until an inversion is found.
 *       (a smaller value on ptrLeft side and greater value on right side) 
 * - When an inversion is found, both values swapp and process is repeated.
*/
int HoarePartition (int *array, int start, int end){
    int pivot = array[start];
    int ptrLeft = start - 1;
    int ptrRight = end + 1;

    while(1) {
        do { 
            ptrLeft++;
        } while (array[ptrLeft] < pivot);  /* Find left element >= pivot */

        do {
            ptrRight--;
        } while (array[ptrRight] > pivot); /* Find right element <= to pivot */

        if (ptrLeft >= ptrRight)           /* If pointers meet */
            return ptrRight;

        swap(&array[ptrLeft], &array[ptrRight]);
    }
}