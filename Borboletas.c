#Insetion code by Victor & Leo.
#Contato para Shows 555-111-222.

#include <stdio.h>

void insertionSort(int lista[], int n){
    int i, chave,j;
    for (i = 1; i < n;i++){
        chave = lista[i];
        j = i - 1;

        while (j >= 0 && lista[j] > chave){
            lista[j+1] = lista[j];
            j = j-1;
        }
        lista[j+1] = chave;
    }
}

int main(void){
    int lista[] = {5,3,4,1,2};
    int i;
    int n = sizeof(lista)/sizeof(lista[0]);

    insertionSort(lista,n);
    for (i = 0; i < n; i++){
        printf("%d\n",lista[i]);
    }
    
    return 0;

}
