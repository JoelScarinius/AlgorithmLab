#include "selectionSort.h"

void selectionSortCounted(unsigned int *a, unsigned int n) {

    unsigned int min;
    for (unsigned int i = 0; i < n - 1; i++) {
        min = i;

        for (unsigned int j = i + 1; j < n; j++) {

            if(&a[j] < &a[min]) {
                min = j;
                swap(a,i,min);  
            }
        }
    }
}
