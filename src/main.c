#include <stdio.h>
#include "sorting.h"
#include "input_gen.h"
#include "fileHandling.h"
#include <time.h>
#include <stdlib.h>

#define INPUT_SIZE 256
#define ARRAY_SIZE 32768

static void displayMainMenu();
static void simSelectionSort(unsigned int n, unsigned int a[], unsigned int totOp, unsigned int avrOp, unsigned int *op, unsigned int count);
static void simInsertionSort(unsigned int n, unsigned int a[], unsigned int totOp, unsigned int avrOp, unsigned int *op, unsigned int count);
// static void simQuickSort(unsigned int n, unsigned int a[], unsigned int totOp, unsigned int avrOp, unsigned int *op, unsigned int count);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int n = INPUT_SIZE, a[ARRAY_SIZE], op = 0, option = 0, count = 30, totOp = 0, avrOp = 0, l = 0, r = 7;
    
    while (option != 4)
    {
        displayMainMenu();
        fflush(stdin);
        scanf("%d", &option);
        switch (option)
        {
        case 1: simSelectionSort(n, a, totOp, avrOp, &op, count); break;
        case 2: simInsertionSort(n, a, totOp, avrOp, &op, count); break;
        // case 3: simQucikSort(n, a, totOp, avrOp, &op, count); break;
        case 4: exit(-1); break;
        default: puts("Invalid input, please try again!"); break;
        }
    }
    return 0;
}

static void displayMainMenu()
{
    puts("Please choose an algorithm\n"
         "1. SelectionSort\n"
         "2. InsertionSort\n"
         "3. QuickSort\n"
         "4. Quit");
    printf("Your choice? : ");
}

static void simSelectionSort(unsigned int n, unsigned int a[], unsigned int totOp, unsigned int avrOp, unsigned int *op, unsigned int count)
{
    printHeaderToFile("Selection sort", "Ordered");
    while (n <= ARRAY_SIZE)
    {
        orderedArray(n, a); // Ordnad input 
        selectionSort(n, a, op);// selectionSort
        printResultsToFile(n, op);
        n *= 2;
        *op = 0;
    }
    printHeaderToFile("Selection sort", "Reversed Ordered");
    n = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        revOrderedArray(n, a); // Omvänd ordnad input 
        selectionSort(n, a, op);
        printResultsToFile(n, op);
        n *= 2;
        *op = 0;
    }
    printHeaderToFile("Selection sort", "Random Ordered");
    n = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            randomOrderedInput(n, a);
            selectionSort(n, a, op);
            totOp += *op;
            *op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
    }
    printHeaderToFile("Selection sort", "Almost Ordered");
    n = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            random4OrderedInput(n, a);
            selectionSort(n, a, op);
            totOp += *op;
            *op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
    }
}

static void simInsertionSort(unsigned int n, unsigned int a[], unsigned int totOp, unsigned int avrOp, unsigned int *op, unsigned int count)
{
    printHeaderToFile("Insertion sort", "Ordered");
    while (n <= ARRAY_SIZE)
    {
        orderedArray(n, a); // Ordnad input 
        insertionSort(n, a, op);// insertionSort
        printResultsToFile(n, op);
        n *= 2;
        *op = 0;
    }
    printHeaderToFile("Insertion sort", "Reversed Ordered");
    n = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        revOrderedArray(n, a); // Omvänd ordnad input 
        insertionSort(n, a, op);
        printResultsToFile(n, op);
        n *= 2;
        *op = 0;
    }
    printHeaderToFile("Insertion sort", "Random Ordered");
    n = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            randomOrderedInput(n, a);
            insertionSort(n, a, op);
            totOp += *op;
            *op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
    }
    printHeaderToFile("Insertion sort", "Almost Ordered");
    n = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            random4OrderedInput(n, a);
            insertionSort(n, a, op);
            totOp += *op;
            *op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
    }
}
