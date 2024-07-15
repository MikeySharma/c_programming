#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}

int getMax(int *A, int size){
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int size){
    int max = getMax(A, size);
    int i, j;

    int *countArr = (int *)malloc((max + 1) * sizeof(int));
    if(countArr == NULL){
        printf("Memory Allocation Failed.\n");
        exit(-1);
    }

    for (i = 0; i <= max; i++)
    {
        countArr[i] = 0;
    }
    for(i = 0; i <size; i++){
        countArr[A[i]]+= 1;
    }

    i = 0;
    j = 0;

    while (i <= max)
    {
        if(countArr[i] > 0){
            A[j] = i;
            countArr[i]--;
            j++;
        }else{
            i++;
        }
    }
    free(countArr);
}

int main() {
    // int A[] = {34, 42, 32, 4, 23, 4,23, 4};
    int A[] = {23, 54, 4, 53, 7, 1, 8, 3};
    int size = sizeof(A)/sizeof(int);

    printf("Original Array: \n");
    printArray(A, size);

    countSort(A, size);

    printf("Sorted Array: \n");
    printArray(A, size);
    return 0;
}