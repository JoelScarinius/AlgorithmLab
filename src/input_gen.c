#include "input_gen.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void orderedInput(unsigned int n, unsigned int a[])
{
    for (unsigned int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
}

void revOrderedInput(unsigned int n, unsigned int a[])
{
    for (unsigned int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
}

void randomOrderedInput(unsigned int n, unsigned int a[])
{
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int change = rand() % n + 1;
        a[i] = i + change;
    }
}

void almostOrderedInput(unsigned int n, unsigned int a[])
{
    for (unsigned int i = 0; i < n; i++)
    {    
        a[i] = i + 1; 
        if (1 + rand() % 100 <= 4)
        {
            unsigned int j = (i*2 > n-1) ? i-2 : i*2;
            swap(a,i,j);
        }
    }
}
