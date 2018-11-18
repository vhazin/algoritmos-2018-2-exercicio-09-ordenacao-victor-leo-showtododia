//QuickSort
#include<stdio.h>
#include <swap.h>
  
// Funcao pegando o ultimo numero como pivot
int partition (int *array, int low, int high) 
{ 
    int pivot = array[high];    // pivot 
    int i = (low - 1);  // Index do menor elemento
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // Se o I for menor ou igual ao pivot 
        if (array[j] <= pivot) 
        { 
            i++;    // Incrementa o index do menor elemento e swap nele 
            swap(&array[i], &array[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* Funcao main que implementa o QuickSort 
  low-> Elemento inicial, 
  high-> Elemento final*/
int quickSortLAST(int *array, int menor, int maior) 
{ 
    if (menor < maior) 
    { 
        // inteiro para particionar o Index, colocando o array[p] no local correto,usando recursao
        int part = partition(array, menor, maior); 
  
        // Separadamente classificando o array antes e dps da particao
        quickSort(array, menor, part - 1); 
        quickSort(array, part + 1, maior); 
    } 
} 
