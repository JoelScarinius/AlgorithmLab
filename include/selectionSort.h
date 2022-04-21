#ifndef sorting_H_
#define sorting_H_

//Sorts a given array by selection sort
//Input: An array A[0..n − 1] of orderable elements
//Output: Array A[0..n − 1] sorted in nondecreasing order
void selectionSort(unsigned int n, unsigned int a[]);

void swap(unsigned int arr[], unsigned int i, unsigned int j);

#endif