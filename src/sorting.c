#include "sorting.h"
#include <stdio.h>

static unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r, size_t *op);


void selectionSort(unsigned int n, unsigned int a[], size_t *op) {
    
    for (size_t i = 0; i <= n - 2; i++) 
    {
        unsigned int min = i;
        for (size_t j = i + 1; j <= n-1; j++) 
        {
            if(a[j] < a[min]) min = j; // Critical Operation
            *op += 1; // Counts the number of operations preformed.
        }
        swap(a,i,min); 
    }
}

void insertionSort(unsigned int n, unsigned int a[], size_t *op)
{
    for (size_t i = 1; i <= n-1; i++)
    {
        int val = a[i], j = i-1;
        *op += 1; // Counts the number of operations preformed.
        while (j >= 0 && a[j] > val) // Critical operation is the comparison a[j] > val.
        {
            a[j+1] = a[j]; 
            j -= 1;
            *op += 1; // Counts the number of operations preformed.
        }
        a[j+1] = val;
    }
}

void quickSort(unsigned int a[], unsigned int l, unsigned int r, size_t *op)
{
    if(l < r)
    {
        unsigned int s = hoarePartition(a, l, r, op);
        quickSort(a, l, s-1, op); 
        quickSort(a, s+1, r, op);
    }
}

void swap(unsigned int a[], unsigned int i, unsigned int j)
{
    unsigned int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

static unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r, size_t *op)
{
    unsigned int p = a[l], j = r+1, i = l;
    while(i < j) 
    {
        do
        {
            *op += 1; // Counts the number of operations preformed.
            i++;
        } while(a[i] < p && i < r); 
        do
        {
            *op += 1; // Counts the number of operations preformed.
            j--; 
        } while(a[j] > p && j > l);
        swap(a, i, j);
    }
    swap(a, i, j); // undo last swap when i >= j
    swap(a, l, j);
    return j = (j == 0) ? j + 1 : j;
}
