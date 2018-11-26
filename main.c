/* Random input generated w/ https://andrew.hedges.name/experiments/random/ */
#include <time.h>
#include "InsertionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"

#define SIZE 10000

int main(void){
    int array[SIZE], counter = 0;
    for(int index = 0; index < SIZE; index++)
        scanf("%d", &array[index]);

    char *algorithms[] = {"Insertion", "Heap", "Merge", "Selection", "Bubble", "Lomuto Quick","Hoare Quick", "Lomuto Random Quick", "Hoare Random Quick"};
    clock_t start, stop;
    while(counter < 9){
        start = clock();

        if(!counter)
            InsertionSortAlgorithm(array, SIZE);
        if(counter == 1)
            HeapSortAlgorithm(array, SIZE);
        if(counter == 2)
            MergeSortAlgorithm(array, SIZE);
        if(counter == 3)
            SelectionSortAlgorithm(array, SIZE);
        if(counter == 4)
            BubbleSortAlgorithm(array, SIZE);
        if (counter == 5)
            QuickSortLomutoAlgorithm(array, 0, SIZE);
        if (counter == 6)
            QuickSortLomutoRandomAlgorithm(array, 0, SIZE);
        if (counter == 7)
            QuickSortHoareAlgorithm(array, 0, SIZE);
        if (counter == 8)
            QuickSortHoareRandomAlgorithm(array, 0, SIZE);

        stop = clock();
        double time_taken = ((double)(stop - start) / CLOCKS_PER_SEC);
        
        printf("\n%s Sort: %f seconds", algorithms[counter], time_taken);
        counter++;
    }
    return 0;
}