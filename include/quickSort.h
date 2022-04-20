#ifndef sorting_H_
#define sorting_H_

//Sorts a subarray by quicksort
//Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r
//Output: Subarray A[l..r] sorted in nondecreasing order
void quickSort(unsigned int a[], unsigned int l, unsigned int r);

// /Partitions a subarray by Hoare’s algorithm, using the first element
// // as a pivot
// //Input: Subarray of array A[0..n − 1], defined by its left and right
// // indices l and r (l < r)
// //Output: Partition of A[l..r], with the split position returned as
// // this function’s value
unsigned int hoarePartition(unsigned int a[], unsigned int l, unsigned int r);

void swap(unsigned int i, unsigned int j, unsigned int arr[]);

void quickSortCounter(unsigned int a[], unsigned int l, unsigned int r, unsigned int *op);

#endif