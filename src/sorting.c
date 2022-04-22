#include "sorting.h"
#include <stdio.h>

static unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r);

static void swap(unsigned int arr[], unsigned int i, unsigned int j);


void selectionSort(unsigned int n, unsigned int a[], size_t *op) {
    unsigned int min;
    for (size_t i = 0; i <= n - 2; i++) {
        min = i;
        for (size_t j = i + 1; j <= n-1; j++) {
            if(a[j] < a[min]) min = j;
            *op += 1;
        }
        swap(a,i,min); // Critical Operation
    }
}

void insertionSort(unsigned int n, unsigned int arr[], size_t *op)
{
    for (size_t i = 1; i <= n-1; i++)
    {
        int val = arr[i], j = i-1;
        *op += 1; // Counts the number of operations preformed.
        while (j >= 0 && arr[j] > val) // Critical operation is the comparison arr[j] > val.
        {
            arr[j+1] = arr[j]; 
            j -= 1;
            *op += 1; // Counts the number of operations preformed.
        }
        arr[j+1] = val;
    }
}

void quickSort(unsigned int a[], unsigned int l, unsigned int r, size_t *op)
{
    if(l < r)
    {
        *op += 1;
        unsigned int s = hoarePartition(a, l, r);
        quickSort(a, l, s-1, op); 
        quickSort(a, s+1, r, op);
    }
}

static void swap(unsigned int a[], unsigned int i, unsigned int min)
{
    unsigned int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
}

static unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r)
{
    unsigned int p = l, i = l, j = r;
    
    while(i < j);
    {
        while(a[i] <= a[p] && i < j) i++; 
        while(a[j] > a[p]) j--;  
        if (i < j) swap(a, i, j); // undo last swap when i >= j
    }   
    swap(a, p, j);
    return j;
}
