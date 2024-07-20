// A C Program to reverse an array;
#include <stdio.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int *arr, int size){
    int count = size / 2;
    int temp;
    for (int i = 0; i < count; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array : \n");
    printArray(arr, size);

    reverseArray(arr, size);

    printf("Reversed Array : \n");
    printArray(arr, size);

    return 0;
}