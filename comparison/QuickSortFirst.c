#include <stdio.h>
#include "swap.h"

int partitionFIRST(int *array,int start,int end)

{

int pivot=array[start],p1=start+1,i,temp;

for(i=start+1;i<=end;i++)
{

if(array[i]<pivot)
    {
        if(i!=p1)
      {  
            temp=array[p1];
            array[p1]=array[i];
            array[i]=temp;
      }    p1++;
    }
}

        array[start]=array[p1-1];
        array[p1-1]=pivot;

return p1-1;
}




  void quicksort(int *array,int start,int end)
{
 int p1;
 if(start<end)
{
    p1=partition(array,start,end);
    quicksort(array,start,p1-1);
    quicksort(array,p1+1,end);
}
}
