#include <stdio.h>
#include "insertionSort.h"

void insertionSort(unsigned int n, unsigned int arr[])
{
    for (size_t i = 1; i <= n-1; i++)
    {
        int val = arr[i], j = i-1;
        while (j >= 0 && arr[j] > val) // Critical operation is the comparison arr[j] > val.
        {
            arr[j+1] = arr[j]; 
            j -= 1;
        }
        arr[j+1] = val;
    }
}
