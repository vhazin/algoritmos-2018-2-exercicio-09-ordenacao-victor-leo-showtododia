#include <time.h>
#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

#define SIZE 10000

int main(void){
    int array[SIZE], counter = 0;
    for(int index = 0; index < SIZE; index++)
        scanf("%d", &array[index]);

    char *algorithms[] = {"Insertion", "Heap", "Merge", "Selection", "Bubble"};
    clock_t start, stop;
    while(counter < 5){
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
        
        stop = clock();
        double time_taken = ((double)(stop - start) / CLOCKS_PER_SEC);
        printf("\n%s Sort: %f milliseconds", algorithms[counter], time_taken);
        counter++;
    }

    return 0;
}