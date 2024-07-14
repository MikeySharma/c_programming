#include <stdio.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void MergeSort(int *A, int *B, int *C, int sizeOfA, int sizeOfB){
    int i, j, k;
    i = j = k = 0;
    while(i < sizeOfA && j < sizeOfB){
        // printf("%d \n", A[i]);
        // printf("%d \n", B[j]);
        if(A[i] < B[j]){
            C[k] = A[i];
            i++;
        }else{
            C[k] = B[j];
            j++;
        }
        k++;
    }
    while(i < sizeOfA){
        C[k] = A[i];
        i++;
        k++;
    }
    while(j < sizeOfB){
        C[k] = B[j];
        j++;
        k++;
    }
}

int main() {
    int A[] = {2, 3, 4, 6, 7, 8};
    int sizeOfA = sizeof(A) / sizeof(A[0]);
    int B[] = {5, 8, 82, 234, 345};
    int sizeOfB = sizeof(B) /sizeof(B[0]);
    int sizeOfC = sizeOfA + sizeOfB;
    int C[sizeOfC];

    MergeSort(A, B, C, sizeOfA, sizeOfB);

    printf("Array A is:\n");
    printArray(A, sizeOfA);

    printf("Array B is: \n");
    printArray(B, sizeOfB);

    printf("Array C is: \n");
    printArray(C, sizeOfC);

    return 0;
}