#include <stdio.h>


void displayArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int size){
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

int main() {
    // int arr[] = {23, 34, 65, 76, 356, 76};
    int arr[] = {43, 5, 234, 65, 90, 245, 10, 203, 2380};
    int size = sizeof(arr)/sizeof(int);
    
    printf("Array before Sorting.\n");
    displayArray(arr, size);
    insertionSort(arr, size);
    printf("Array After Sorting.\n");
    displayArray(arr, size);
    return 0;
}