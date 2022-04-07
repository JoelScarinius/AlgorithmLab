#include <stdio.h>
#include "test.h"

int main()
{
    printNumbers();

}

void printNumbers()
{
    int count = 10;
    for (size_t i = 0; i < count; i++)
    {
        printf("%d", i);
    }
}