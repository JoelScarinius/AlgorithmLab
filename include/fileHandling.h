#ifndef fileHandling_H_
#define fileHandling_H_

#include <stdlib.h>

// Prints a header to the text file.
// Input: The selected algorithms name as a string and the input type as a string.
// Output: Void
void printHeaderToFile(char algorithm[], char inputType[]);

// Prints the number of operations to the text file.
// Input: The input size and the number of operations.
// Output: Void.
void printResultsToFile(unsigned int n, size_t *op);

#endif