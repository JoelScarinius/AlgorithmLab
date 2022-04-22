#include "input_gen.h"
#include <stdio.h>
#include <stdlib.h>

static void swap(unsigned int *arrPtr, unsigned int i, unsigned int  i2);

void orderedArray(unsigned int n, unsigned int *arrPtr)
{
    for (size_t i = 0; i < n; i++)
    {
        arrPtr[i] = i + 1;
    }
}

void revOrderedArray(unsigned int n, unsigned int *arrPtr)
{
    for (size_t i = 0; i < n; i++)
    {
            arrPtr[i] = n - i;
    }
}

void randomOrderedInput (unsigned int n, unsigned int *arrPtr)
{
    for (size_t i = 0; i < n; i++)
    {
        int change = rand() % n + 1;
        arrPtr[i] = i + change;
    }
}

void random4OrderedInput(unsigned int n, unsigned int *arrPtr)
{
    for (size_t i = 0; i < n; i++)
    {    
        arrPtr[i] = i + 1; 
        if (1 + rand() % 100 <= 4)
        {
            unsigned int j = (i*2 > n-1) ? i-2 : i*2;
            swap2(arrPtr,i,i);
        }
    }
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

static void swap(unsigned int *arrPtr, unsigned int i,unsigned int  i2)
{
    unsigned int temp = arrPtr[i];
    arrPtr[i] = arrPtr[i2];
    arrPtr[i2] = temp;
}