#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
       printf("%d ", arr[i]);
    }
    printf("\n");
}

void Merge(int *A, int low, int mid, int high){
    int i, j, k;
    int *B = (int *)malloc((high - low + 1) * sizeof(int));
    if (B == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    i = low;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        B[k] = A[i];
        i++; 
        k++;
    }

    while(j <= high){
        B[k] = A[j];
        j++; 
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++){
        A[i] = B[k];
    }

    free(B);
}

void MergeSort(int *A, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main() {
    // int A[] = {12, 43, 54, 234, 54, 235};
    int A[] = {4,  234, 545, 234, 23, 43, 1, 4, 2346, 93};
    int size = sizeof(A) / sizeof(A[0]);

    printf("Original Array: \n");
    printArray(A, size);

    MergeSort(A, 0, size - 1);

    printf("Sorted Array: \n");
    printArray(A, size);

    return 0;
}
