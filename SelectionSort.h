/* Selection Sort Algorithm Implementation in C Programming
 * CESAR School, Data Structures and Algorithms
 * Assignee: Victor Hazin (github.com/vhazin)
 * Assigned to: Leonardo Melo (github.com/lcbm), Victor Almeida (github.com/victoralmeida432)
 * Reference: https://www.youtube.com/watch?v=GUDLRan2DWM&index=2&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
 */

#include <stdio.h>
#include "swap.h"

/*** Selection Sort Function: swaps values between elements of an array ***/
int SelectionSortAlgorithm(int *array, int length){
    for (int iterator = 0; iterator < length - 1; iterator++){   /* Iterating all elements, but last two                             */
        int min = iterator;                                      /* Declaring that `min` will be swapped to the index [`iterator`]   */
        for (int index = iterator + 1; index < length; index++){ /* Searching for `min`, starting at [`iterator` + 1]                */
            if (array[index] < array[min])                       /* Comparing values of `min` with indexes to the right (index)      */
                min = index;                                     /* Setting `min` to hold `index` of unpicked minimum value          */
        }
        swap(&array[min], &array[iterator]);                      /* Swaping values from `min` index w/ value at `iterator` index     */
        // xorSwap(&array[min], &array[iterator]);                /* Swaping values from `min` index w/ value at `iterator` index     */
    }

    // for (int index = 0; index < length; index++)
    //     printf("%d, ", array[index]);
    
    return 0;
}