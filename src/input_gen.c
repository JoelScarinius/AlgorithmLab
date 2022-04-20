#include "input_gen.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int * orderedArray(unsigned int n)
{
    unsigned int *arrPtr;
    arrPtr = (unsigned int *)malloc(n * sizeof(unsigned int));

    for (size_t i = 0; i < n; i++)
    {
        arrPtr[i] = i + 1;
    }

    return arrPtr;
}

unsigned int * revOrderedArray(unsigned int n)
{
    unsigned int *arrPtr;
    arrPtr = (unsigned int *)malloc(n * sizeof(unsigned int));   

    for (size_t i = 0; i < n; i++)
    {
            arrPtr[i] = n - i;
    }
    return arrPtr;
}

unsigned int *randomOrderedInput (unsigned int n)
{
    unsigned int *arrPtr;
    arrPtr = (unsigned int *)malloc(n * sizeof(unsigned int));  

    for (size_t i = 0; i < n; i++)
    {
            int change = rand() % n + 1;
            arrPtr[i] = i + change;
            
    }
    return arrPtr;
}

unsigned int * random4OrderedInput(unsigned int n)
{
    unsigned int *arrPtr;
    arrPtr = (unsigned int *)malloc(n * sizeof(unsigned int));  
    for (size_t i = 0; i < n; i++)
    {    
        arrPtr[i] = i + 1; 
           if (1 + rand() % 100 <= 4)
            {
                swap(arrPtr,i,i-2);
            }
    }
    return arrPtr;
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}