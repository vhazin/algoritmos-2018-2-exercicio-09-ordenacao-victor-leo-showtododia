#include <stdio.h>
#include "swap.h"

// Best Case: O(N)
// Pior Caso: O(n^2)
// Compara os pares, iniciando do array[0]
// Repete processo até que array inteiro esteja ordenado
int BubbleSortAlgorithm(int *array, int length){
    for(int i = 0; i < length -1; i++){
        for(int j = 0; j < length-i-1;j++){
            if (array[j] > array[j+1])
                swap(&array[j],&array[j+1]);
                // xorSwap(&array[j], &array[j+1]);
        }
    }

    // for (int index = 0; index < length; index++)
    //     printf("%d, ", array[index]);

    return 0;
}