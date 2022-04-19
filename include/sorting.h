#ifndef sorting_H_
#define sorting_H_

//Sorts a given array by selection sort
//Input: An array A[0..n − 1] of orderable elements
//Output: Array A[0..n − 1] sorted in nondecreasing order
void selectionSort(unsigned int n, unsigned int arr[], unsigned int *op);

//Sorts a given array by insertion sort
//Input: An array A[0..n − 1] of n orderable elements
//Output: Array A[0..n − 1] sorted in nondecreasing order
void insertionSort(unsigned int n, unsigned int arr[], unsigned int *op);

//Sorts a subarray by quicksort
//Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r
//Output: Subarray A[l..r] sorted in nondecreasing order
void quickSort(unsigned int n, unsigned int arr[], unsigned int *op);

#endif