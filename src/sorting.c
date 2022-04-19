#include "sorting.h"
#include <stdio.h>

void selectionSort(unsigned int n, unsigned int arr[], unsigned int *op)
{

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
            op++;
        }
        arr[j+1] = val;
    }
}

void quickSort(unsigned int n, unsigned int arr[], unsigned int *op)
{

}
