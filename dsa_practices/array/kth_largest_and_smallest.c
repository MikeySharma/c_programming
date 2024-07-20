// A  C Program to find the kth max and kth min 

#include <stdio.h>

void printArray(int *arr, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

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
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int kthMax(int *arr, int size, int k){
    return (arr[size - k]);
}

int kthMin(int *arr, int k){
    return (arr[k - 1]);
}

int main() {
    int arr[] = {1, 32, 43, 2, 4, 543, 53, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printf("Given Array :\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);
    printf("The %dth max element is %d.\n", k, kthMax(arr, size, k));
    
    printf("The %dth min element is %d.\n", k, kthMin(arr, k));

    return 0;
}