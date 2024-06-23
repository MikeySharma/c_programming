#include <stdio.h>

void displayArray(int arr[],  int size);
void delElementAtBeg(int arr[], int size);

int main() {
    int arr[100] = {43, 23, 54, 34, 65, 334, 54, 65, 354, 23};
    int size = 10;
    printf("Array Before Deletion of Element At Begining.\n");
    displayArray(arr, size);
    delElementAtBeg(arr, size);
    printf("Array After Deletion of Element At Begining.\n");
    size -= 1;
    displayArray(arr, size);
    return 0;
}

void displayArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delElementAtBeg(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}