#include <stdio.h>
#include "sorting.h"
#include "input_gen.h"

#define INPUT_SIZE 256
#define ARRAY_SIZE 32768

int main(int argc, char const *argv[])
{
    unsigned int n = INPUT_SIZE, a[ARRAY_SIZE], op = 0, option = 0, count = 30, totOp = 0, avrOp = 0;
    char algorithm[15], inputType[15];

    a = randomOrderedInput(n);
    quickSort(n, a, &op);
    // while (option != 4)
    // {
    //     displayMainMenu();

    //     switch (option)
    //     {
    //     case 1:
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // Ordnad input 
    //             // selectionSort
    //             // loadResults
    //             // printResults
    //             // fscanf(fptr, "%d %d\n", n, op); // Måste skriva ett resultat för varje n
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // omvänd
    //             // selectionSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         for (size_t i = 1; i <= count; i++)
    //         {
    //             while (n <= ARRAY_SIZE) // While ska köras 30ggr
    //             { // borde vi köra n = 256 30 ggr räkna ut avrage sedan köra nästa n o.s.v?
    //                 // slumpmässig
    //                 // selectionSort
    //             }
    //             n *= 2;
    //             totOp += op;
    //             n = INPUT_SIZE;
    //         }
    //             avrOp = totOp/(30*8);
    //             while (n <= ARRAY_SIZE)
    //             {
    //                 // nästan ordnad
    //                 // selectionSort
    //                 n *= 2;
    //             }
    //             n = INPUT_SIZE;
    //         break;
    //     case 2:
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // ordnad input 
    //             // insertionSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // omvänd
    //             // insertionSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // slumpmässig
    //             // insertionSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // nästan ordnad
    //             // insertionSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         break;
    //     case 3:
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // ordnad input 
    //             // quickSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // omvänd
    //             // quickSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // slumpmässig
    //             // quickSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         while (n <= ARRAY_SIZE)
    //         {
    //             // nästan ordnad
    //             // quickSort
    //             n *= 2;
    //         }
    //         n = INPUT_SIZE;
    //         break;
    //     case 4: exit(-1); break;
        
    //     default:
    //         break;
    //     }
    // }
    return 0;
}

void displayMainMenu()
{
    puts("1. SelectionSort"
         "2. InsertionSort"
         "3. QuickSort"
         "4. Quit");
}

void printResults(char algorithm[] ,unsigned int n, unsigned int arr[], char inputType[], unsigned int *op)
{
    FILE *fPtr = fopen("Results.txt", "w");

    fprintf(fPtr, "%s %s\n", "Algorithm:", algorithm);
    fprintf(fPtr, "%s %s\n", "Input:", inputType);
    fprintf(fPtr, "%s\n%s\n", "n number of op", "----------------");
    fprintf(fPtr, "%d %d\n", n, op);

    fclose(fPtr); // When done reading the file the connection to the file is closed.
}

void loadResults(char algorithm[] ,unsigned int n, unsigned int arr[], char inputType[], unsigned int *op)
{
    FILE *fPtr = fopen("Results.txt", "r");

    fscanf(fPtr, "%s %s\n", "Algorithm:", algorithm);
    fscanf(fPtr, "%s %s\n", "Input:", inputType);
    fscanf(fPtr, "%s\n%s\n", "n number of op", "----------------");
    fscanf(fPtr, "%d %d\n", n, op);

    fclose(fPtr); // When done reading the file the connection to the file is closed.
}