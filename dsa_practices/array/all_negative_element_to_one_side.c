//Move all negative elements to one side of the array;

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
       if(arr[j] < pivot){
        i++;
        swap(&arr[i], &arr[j]);
       }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
    
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

int main() {
    int arr[] = {43, -1, -2, 2, -4, -89, -8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array : \n");
    printArray(arr, size);
    quickSort(arr, 0, size -1);

    printf("Sorted Array : \n");
    printArray(arr, size);
    return 0;
}