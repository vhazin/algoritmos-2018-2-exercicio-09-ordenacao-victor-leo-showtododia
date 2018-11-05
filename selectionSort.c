/* Selection Sort Algorithm Implementation in C Programming
 * CESAR School, Data Structures and Algorithms
 * Assignee: Victor Hazin (github.com/vhazin)
 * Assigned to: Leonardo Melo (github.com/lcbm), Victor Almeida (github.com/victoralmeida432)
 * Reference: https://www.youtube.com/watch?v=GUDLRan2DWM&index=2&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
 */

#include <stdio.h>

/*** Prototype Functions ***/
void selectionSort(int *, int);
void xorSwap(int *, int *);
void swap(int *, int *);

/*** Main Function: driver program to test merge sort function ***/
int main(void){
    int array[]  = {99,2,23,41,-5,23,-5,-10,4,8,-3};             /* Initializing random array           */
    int length = sizeof(array) / sizeof(array[0]);               /* Finding number of elements in array */
    selectionSort(array, length);                                /* Merge sorting the array             */
    for(int index = 0; index < length; index++){                 /* Printing sorted array, by element   */
        printf("%d ", array[index]);
    }

	return 0;
}

/*** Selection Sort Function: swaps values between elements of an array ***/
void selectionSort(int *array, int length){
    for (int iterator = 0; iterator < length - 1; iterator++){   /* Iterating all elements, but last two                             */
        int min = iterator;                                      /* Declaring that `min` will be swapped to the index [`iterator`]   */
        for (int index = iterator + 1; index < length; index++){ /* Searching for `min`, starting at [`iterator` + 1]                */
            if (array[index] < array[min])                       /* Comparing values of `min` with indexes to the right (index)      */
                min = index;                                     /* Setting `min` to hold `index` of unpicked minimum value          */
        }  
        xorSwap(&array[min], &array[iterator]);                  /* Swaping values from `min` index w/ value at `iterator` index     */
        // swap(&array[min], &array[iterator]);
    }
}

/*** XOR Swap Function: uses the XOR bitwise operation to swap values ***/
void xorSwap(int *min, int *iterator){
    if (min == iterator)                                         /* Equal adressess leads to `*x = *x ^ *x` x3, which is 0           */
        return;

    *min      = *min ^ *iterator;                                /* Combining xy ->  x = x ^ y                                       */
    *iterator = *min ^ *iterator;                                /* Canceling  y ->  (x ^ y) ^ y  ->  x ^ (y ^ y)  ->  x ^ 0  ->  x  */
    *min      = *min ^ *iterator;                                /* Canceling xy ->  (x ^ y) ^ x  ->  y ^ (x ^ x)  ->  y ^ 0  ->  y  */
}

/*** Swap Function: uses call-by-reference to swap values ***/
void swap(int *min, int *iterator){
    int temp  = *min;                                            /* Saving `min` value in `temp`                                      */
    *min      = *iterator;                                       /* Setting `min` value to `iterator` value                           */
    *iterator = temp;                                            /* Setting `iterato` value to `temp` value (old `min`)               */
}
