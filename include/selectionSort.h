#ifndef sorting_H_
#define sorting_H_

//Sorts a given array by selection sort
//Input: An array A[0..n − 1] of orderable elements
//Output: Array A[0..n − 1] sorted in nondecreasing order
void selectionSort(unsigned int *a, unsigned int n);

void swap(unsigned int *a, unsigned int i, unsigned int j);

#endif