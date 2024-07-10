#include <stdio.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size){
    printf("Running selection Sort.\n");
    int indexOfMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
       for (int j = i + 1; j < size; j++)
       {
            if(arr[j] < arr[indexOfMin]){
                indexOfMin = j;
            }
       }
       temp = arr[i];
       arr[i] = arr[indexOfMin];
       arr[indexOfMin] = temp;
    }
    
}

int main() {
    int arr[] = {1, 54, 2, 654, 5, 234, 252};
    int size = sizeof(arr)/sizeof(int);
    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}