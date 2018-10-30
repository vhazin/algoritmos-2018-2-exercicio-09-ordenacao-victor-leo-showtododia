#BubbleSort Code, by Victor & Leo
#Contato para shows 555-111-222.

#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[],int n){
    int i,j;
    for(i = 0; i < n -1; i++){
        for(j = 0; j < n-i-1;j++){
            if (array[j] > array[j+1]) {
                swap(&array[j],&array[j+1]);
            }
        }
    }
}

void printArray(int array[], int size){ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d\n ", array[i]); 
} 

int main(void){
    int array[] = {64,34,25,12,22,11,98};
    int i,size;
    int n = sizeof(array)/sizeof(array[0]);
    bubbleSort(array,n);
    printf("Arrayzao da massa: \n");
    printArray(array,n);
    return 0;

}
