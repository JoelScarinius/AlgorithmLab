#include <stdio.h>
#include "sorting.h"
#include "input_gen.h"
#include "fileHandling.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 256
#define ARRAY_SIZE 32768

static void displayMainMenu(); // Prints main menu.

// Runs an algorithm with all different input sizes and types, also counts operation.
// Input: Algorithm name depended on user input.
// Output: Only runs the algorithms and some helper functions, outputs void.
static void simSortAlgo(char algorithm[]); 

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int option = 0;
    
    while (option != 4)
    {
        displayMainMenu(); // Prints main menu.
        fflush(stdin);
        scanf("%d", &option);
        switch (option)
        {
        case 1: simSortAlgo("Selection sort"); break;
        case 2: simSortAlgo("Insertion sort"); break;
        case 3: simSortAlgo("Qucik sort"); break;
        case 4: exit(-1); break;
        default: puts("Invalid input, please try again!"); break;
        }
    }
    return 0;
}

static void displayMainMenu()
{
    puts("\nPlease choose an algorithm\n"
         "1. SelectionSort\n"
         "2. InsertionSort\n"
         "3. QuickSort\n"
         "4. Quit");
    printf("Your choice? : ");
}

static void simSortAlgo(char algorithm[]) // Runs an algorithm with all different input sizes and types, also counts op.
{
    unsigned int n = INPUT_SIZE, r = n-1, l = 0, numRuns = 30, arr[ARRAY_SIZE];
    size_t totOp = 0, avrOp = 0, op = 0;

    printHeaderToFile(algorithm, "Ordered"); // Prints a header to our text file.
    while (n <= ARRAY_SIZE) // Runs until all input sizes have been handled. 
    {
        orderedInput(n, arr); // Changes our array to contain orded elements.
        if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, arr, &op);// Start selectionSort
        else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, arr, &op);// Start insertionSort
        else quickSort(arr, l, r, &op);// Starts quickSort
        printResultsToFile(n, &op); // Prints the number of operations to our text file.
        n *= 2; // Doubles the input size
        r = n-1; // Sets r to be the last index in the array
        op = 0; // Resets the counter to 0 before next iteration starts.
    }
    printHeaderToFile(algorithm, "Reversed Ordered"); // Prints a header to our text file.
    n = r = INPUT_SIZE; // Resets input to starting input size
    while (n <= ARRAY_SIZE) // Runs until all input sizes have been handled.
    {
        revOrderedInput(n, arr); // Changes our array to contain reversed orded elements. 
        if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, arr, &op);// selectionSort
        else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, arr, &op);// insertionSort
        else quickSort(arr, l, r, &op);// quickSort
        printResultsToFile(n, &op);
        n *= 2; // Doubles the input size 
        r = n-1; // Sets r to be the last index in the array
        op = 0; // Resets the counter to 0 before next iteration starts.
    }
    printHeaderToFile(algorithm, "Random Ordered"); // Prints a header to our text file.
    // n = r = INPUT_SIZE; // Resets input to starting input size
    while (n <= ARRAY_SIZE) // Runs until all input sizes have been handled.
    {
        for (size_t i = 1; i <= numRuns; i++)
        {
            randomOrderedInput(n, arr);
            if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, arr, &op);// selectionSort
            else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, arr, &op);// insertionSort
            else quickSort(arr, l, r, &op);// quickSort
            totOp += op;
            op = 0; // Resets the counter to 0 before next iteration starts.
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp); // Prints the avrage number of operations to our text file.
        avrOp = totOp = 0; // Resets the counter to 0 before next iteration starts.
        n *= 2; // Doubles the input size
        r = n-1; // Sets r to be the last index in the array
        op = 0; // Resets the counter to 0 before next iteration starts.
    }
    printHeaderToFile(algorithm, "Almost Ordered"); // Prints a header to our text file.
    n = r = INPUT_SIZE; // Resets input to starting input size
    while (n <= ARRAY_SIZE) // Runs until all input sizes have been handled.
    {
        for (size_t i = 1; i <= numRuns; i++)
        {
            almostOrderedInput(n, arr);
            if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, arr, &op);// selectionSort
            else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, arr, &op);// insertionSort
            else quickSort(arr, l, r, &op);// quickSort
            totOp += op;
            op = 0; // Resets the counter to 0 before next iteration starts.
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp); // Prints the avrage number of operations to our text file.
        avrOp = totOp = 0; // Resets the counter to 0 before next iteration starts.
        n *= 2; // Doubles the input size
        r = n-1; // Sets r to be the last index in the array
        op = 0; // Resets the counter to 0 before next iteration starts.
    }
}
