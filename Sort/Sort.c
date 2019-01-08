#include <math.h>
#include <stdlib.h>
#include "Sort.h"
///////////////////////general///////////////////////////////////
void swapLinkedList(Bucket *a, Bucket *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}
void Swap (int *x , int *y)
{
    int temp ;
    temp = *x ;
    *x = *y ;
    *y = temp ;
}
int FindMax(int *a ,int ArraySize)
{
    int i ;
    int max = a[0];
    for(i=0 ; i<ArraySize ; i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max ;
}
///////////////////heaps//////////////////////////////////////////////////
int Parent(int i)
{
    return i/2;
}
int Left(int i)
{
    return 2*i;
}
int Right(int i)
{
    return ((2*i) +1);
}
void MaxHeapify(int * a,int ArraySize,int i)
{   int largest ;
    i=i+1;
    int l = Left(i);
    int r =Right(i);
    if (l<=ArraySize  &&  a[l-1]>a[i-1])
          largest= l;
    else  largest= i;
    if (r<=ArraySize  &&  a[r-1]>a[largest-1])
          largest= r;
    if (largest != i)
    {
        Swap(&a[i-1],&a[largest-1]);
        MaxHeapify(a,ArraySize ,largest-1);
    }


}
void BuildMaxHeap(int * a,int ArraySize)
{
    int i;
 for(i= (ArraySize-1)/2 ; i>=0;i--)
      MaxHeapify(a,ArraySize ,i);
}
void HeapSort(int * a,int ArraySize)
{
    int  i,j  ;
    int temp[ArraySize];
  BuildMaxHeap (a,ArraySize);
  for(i= ArraySize-1  ; i>=0;i--)
  {   temp [i]=a[0];
      a[0] = a[i];
      MaxHeapify(a,i,0);
  }
  for (j = 0 ; j<10;j++)
    a[j]=temp[j];

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////insertion sort/////////////////////////////////////////
void  InsertionSort(int * a ,int ArraySize)
{
    int i  , j,key;
    for(i=1 ; i<ArraySize;i++)
    {
        key = a[i];
        j=i-1 ;
        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] =key ;
    }
}
//////////////////////////////////////////////////////////////////
///////////////////////////////Bubble Sort////////////////////////

void  BububleSort(int * a ,int ArraySize)
{
   int i, j;
   for (i = 0; i < ArraySize-1; i++)

       // Last i elements are already in place
       for (j = 0; j < ArraySize-i-1; j++)
           if (a[j] > a[j+1])
              Swap(&a[j], &a[j+1]);

}



///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
////////////////mergeSort/////////////////////////////////////////
void Merge (int *a ,int p , int q , int r)
{
    int n1 = q-p+1 ;
    int n2 = r-q ;
    int Larr [n1];
    int Rarr [n2];
    int  i ,j ,k ;
    for(i = 0 ;i<n1 ; i++)
        Larr[i]=a[p+i];
    for(i = 0 ;i<n2 ; i++)
        Rarr[i]=a[q+1+i];
    for(k= p ,i=0,j=0 ;(i<n1)&&(j<n2) ; k++)
    {
      if(Larr[i]<Rarr[j])
        {
         a[k] = Larr[i];
            i++;
        }
       else
       {
           a[k] = Rarr[j];
            j++;
       }
    }
    while(i<n1)
    {
        a[k]=Larr[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=Rarr[j];
        j++;
        k++;
    }
}
void MergeSortAux(int *a ,int p ,int r)
{  int q ;
    if (p<r)
    {
        q = (p+r)/2;
        MergeSortAux(a,p ,q);
        MergeSortAux(a,q+1 ,r);
        Merge(a,p,q,r);
    }
}
void MergeSort(int *a ,int ArraySize)
{
    MergeSortAux(a,0,ArraySize-1);
}
///////////////////////////////////////////////////////////////////
//////////////////////QuickSort///////////////////////////////////
int Partion(int *a ,int p ,int r)
{
    int x  = a[r];
    int i = p-1 ;
    int j ;
    for(j =p ;j<=r-1 ;j++)
    {
        if(a[j]<=x)
        {
            i++;
            Swap(&a[i],&a[j]);
        }
    }
    Swap(&a[i+1],&a[r]);
    return i+1;
}
void QuickSortAux(int *a ,int p ,int r)
{  int q ;
    if(p<r)
    {
        q= Partion(a,p,r);
        QuickSortAux(a ,p,q-1);
        QuickSortAux(a ,q+1,r);

    }
}
void QuickSort(int *a ,int ArraySize)
{
    QuickSortAux(a, 0 ,ArraySize-1);
}
/////////////////////////////////////////////////////////////////
///////////////////////countingSort/////////////////////////////
void CountingSortAux(int *a ,int ArraySize,int Max)
{
    int i ;
    int k =Max +1 ;
    int C[k];
    int output[ArraySize];
    for (i=0 ;i<k;i++)
        C[i]=0;
    for (i=0 ;i<ArraySize;i++)
          C[a[i]]++;
    for (i=1 ;i<k;i++)
         C[i]=C[i-1]+C[i];
    for (i=ArraySize-1 ;i>=0;i--)
    {
        output[C[a[i]]-1]=a[i];
        C[a[i]]--;
    }
    for (i=0 ;i<ArraySize;i++)
    {
        a[i]=output[i];
    }

}
void CountingSort(int *a ,int ArraySize)
{
    CountingSortAux (a,ArraySize,FindMax(a,ArraySize));
}
/////////////////////////////////////////////////////////////////
//////////////////////RadixSort//////////////////////////////////
 void CountingSortForRadixSort(int *a ,int ArraySize ,int Max)
 {
   int i ;
    int k =10;
    int C[k];
    int output[ArraySize];
    for (i=0 ;i<k;i++)
        C[i]=0;
    for (i=0 ;i<ArraySize;i++)
          C[(a[i]/Max)%10]++;
    for (i=1 ;i<k;i++)
         C[i]=C[i-1]+C[i];
    for (i=ArraySize-1 ;i>=0;i--)
    {
        output[C[(a[i]/Max)%10]-1]=a[i];
        C[(a[i]/Max)%10]--;
    }
    for (i=0 ;i<ArraySize;i++)
    {
        a[i]=output[i];
    }
 }
void RadixSort (int *a ,int ArraySize)
{
    int max = FindMax(a,ArraySize);
    int d ;
    for (d= 1 ;max/d >0;d*=10)
       CountingSortForRadixSort(a ,ArraySize ,d);

}
/////////////////////////////////////////////////////////////////
///////////////////////////BucketSort///////////////////////////
void bubbleSort(Bucket *start)
{
    int swapped, i;
    Bucket *ptr1;
    Bucket *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            {
                swapLinkedList(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void BucketSort (int *a ,int ArraySize)
{
int i ,j ;
int max =FindMax(a,ArraySize);
Bucket * B[11];
Bucket *q ,*r  ,*b;
int d = ceil((max+1)/10);
for (i=0 ;i<11;i++)
    B[i]=NULL;
for (i=0 ;i<ArraySize;i++)
{
  j = (a[i]/d);
   q= B[j];
   r=NULL;
  b = (Bucket *)malloc(sizeof(Bucket));
  b->value=a[i];
  b->next =NULL;
  while (q != NULL)
  {
    r=q;
    q= q->next;
  }
  if(r == NULL)
  {
  B[j]=b ;
  }
  else
  {
  r->next=b ;
  }
}
for (i=0 ;i<11;i++)
    bubbleSort(B[i]);
i=0  ,j = 0 ,q= NULL;
while(j<ArraySize)
{
 if(B[i]==NULL)
    i++;
 else
 {   q= B[i];
     do{
       a[j++]=q->value;
       q = q->next;
      }while(q != NULL);
    i++;

 }
}
}

///////////////////////////////////////////////////////////////
