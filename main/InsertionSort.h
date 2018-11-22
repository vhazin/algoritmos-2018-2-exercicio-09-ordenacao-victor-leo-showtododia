// Insetion code by Victor & Leo.
#include <stdio.h>

int InsertionSortAlgorithm(int *array, int length){
    for (int i = 1; i < length;i++){
        int chave = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > chave){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = chave;
    }
    return 0;
}