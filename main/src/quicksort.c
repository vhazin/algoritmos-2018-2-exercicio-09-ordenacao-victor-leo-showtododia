//QuickSort
#include<stdio.h> 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// Funcao pegando o ultimo numero como pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index do menor elemento
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // Se o I for menor ou igual ao pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // Incrementa o index do menor elemento e swap nele 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* Funcao main que implementa o QuickSort 
 arr[]-> Array, 
  low-> Elemento inicial, 
  high-> Elemento final*/
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        // inteiro para particionar o Index, colocando o array[p] no local correto
        int pi = partition(arr, low, high); 
  
        // Separadamente classificando o array antes e dps da particao
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
//Funcao pra printar o Array
void printArray(int arr[], int tam) 
{ 
 int i;
    for (i=0; i < tam; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
}
  
// Funcao Main, Arrumar essa funcao para poder receber os elementos gigantes de Hazin
int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Array Organizado: n"); 
    printArray(arr, n); 
    return 0; 
} 
