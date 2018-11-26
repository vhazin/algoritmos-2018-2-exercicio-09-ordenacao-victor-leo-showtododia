/* Random input generated w/ https://andrew.hedges.name/experiments/random/ */
#include <time.h>
#include "InsertionSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"

#define SIZE 100

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
            QuickSortAlgorithm(array, 0, SIZE, 0);
        if (counter == 6)
            QuickSortAlgorithm(array, 0, SIZE, 1);
        if (counter == 7)
            QuickSortAlgorithm(array, 0, SIZE, 2);
        if (counter == 8)
            QuickSortAlgorithm(array, 0, SIZE, 3);

        stop = clock();
        double time_taken = ((double)(stop - start) / CLOCKS_PER_SEC);
        
        printf("\n%s Sort: %f milliseconds \n\n", algorithms[counter], time_taken);
        counter++;
    }
    return 0;
}