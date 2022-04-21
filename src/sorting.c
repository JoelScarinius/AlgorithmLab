#include "sorting.h"
#include <stdio.h>

void selectionSort(unsigned int n, unsigned int a[], unsigned int *op) {
    unsigned int min;
    for (unsigned int i = 0; i <= n - 2; i++) {
        min = i;
        for (unsigned int j = i + 1; j <= n-1; j++) {
            if(a[j] < a[min]) min = j;
        }
        swap(a,i,min); // Critical Operation
        *op = *op + 1;
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
            *op = *op + 1; // Counts the number of operations preformed.
        }
        arr[j+1] = val;
    }
}

void quickSort(unsigned int a[], unsigned int l, unsigned int r, unsigned int *op)
{
    if(l<r)
    {
        *op = *op + 1;
        unsigned int s = hoarePartition(a, l, r);
        quickSort(a, l, s-1, op); 
        quickSort(a, s+1, r, op);
    }
}

void swap(unsigned int a[], unsigned int i, unsigned int min)
{
    unsigned int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
}

unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r)
{
    unsigned int p = a[l], i = l, j = r+1;
    do
    {
        do
        {
            i = i+1;
        } while(a[i] <= p);
        do
        {
            j = j-1;
        } while(a[j] >= p);
        swap(a, i, j);
    } while(i>=j);
    swap(a, i, j); // undo last swap when i >= j
    swap(a, l, j);
    return j;
}
