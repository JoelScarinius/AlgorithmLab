#include "sorting.h"
#include <stdio.h>

void selectionSort(unsigned int n, unsigned int a, unsigned int *op)
{
    unsigned int min;
    for (unsigned int i = 0; i < n - 1; i++) {
        min = i;
        for (unsigned int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min]) {
                min = j;
                swap(a,j,i); //Critical Operation
                op++;
            }
        }
    }
}

void insertionSort(unsigned int n, unsigned int arr[], unsigned int *op)
{
    for (size_t i = 1; i <= n-1; i++)
    {
        int val = arr[i], j = i-1;
        while (j >= 0 && arr[j] > val) // Critical operation is the comparison arr[j] > val.
        {
            arr[j+1] = arr[j]; 
            j -= 1;
            op++; // Counts the number of operations preformed.
        }
        arr[j+1] = val;
    }
}

void quicksort(unsigned int a[], unsigned int l, unsigned int r)
{
    if(l<r)
    {
        int s = hoarePartition(a, l, r);
        quicksort(a, l, s-1); 
        quicksort(a, s+1, r);
    }
}

void swap(unsigned int a[], unsigned int i, unsigned int j)
{
    unsigned int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r)
{
    unsigned int p = a[l];
    unsigned int i = l; unsigned int j = r+1;
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
