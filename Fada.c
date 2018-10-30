#HeapSort Code by Victor & Leo.
#Contato para Shows 555-111-222.

#include <stdio.h>

void ArrayDaMassa(int []);
void arrumar(int [],int);

int main(void){
    int heap[30],n,i,ultimo,temp;
    printf("Digite o Numero de elementos do Array: ");
    scanf("%d",&n);
    printf("\nDigite os Elementos do Array: ");
    for(i = 1; i<=n;i++){
        scanf("%d",&heap[i]);
    }
    heap[0] = n;
    ArrayDaMassa(heap);

    while(heap[0] > 1){
        ultimo = heap[0];
        temp = heap[1];
        heap[1] = heap[ultimo];
        heap[ultimo] = temp;
        heap[0]--;
        arrumar(heap,1);
    }
    printf("Array Arrumado: \n");
    for(i = 1; i <= n; i++){
        printf("%d ",heap[i]);
    }
}

void arrumar(int heap[],int i){
    int j,temp,n;
    int flag = 1;
    n = heap[0];

    while(2*i <= n && flag == 1){
        j = 2*i;
        if(j+1 <= n && heap[j+1] > heap[j]){
            j=j+1;
        }
        if(heap[i] > heap[j]){
            flag = 0;
        }else{
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
    }
}

void ArrayDaMassa(int heap[]){
    int i,n;
    n = heap[0];
    for(i = n/2; i >= 1; i--){
        arrumar(heap,i);
    }
}
