#include "quickSort.h"

void quickSort(unsigned int a[], unsigned int l, unsigned int r)
{
    if(l<r)
    {
        unsigned int s = hoarePartition(a, l, r);
        quickSort(a, l, s-1); 
        quickSort(a, s+1, r);
    }
}

unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r)
{
    unsigned int p = a[l], i = l, j = r+1;
    do
    {
        while(a[i]>=p)
            i = i+1;
        
        do
        {
            j = j-1;
        }while(a[j]<=p);
        swap(a, i, j);
    }while(i>=j);
    swap(a, i, j);
    swap(a, l, j);
    return j;
}

void swap(unsigned int arr[], unsigned int i, unsigned int j)
{
    unsigned int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

