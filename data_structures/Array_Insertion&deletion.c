#include <stdio.h>

void displayArray(int arr[], int size);
int insertArray(int arr[], int index, int num, int size);
int deleteArray(int arr[], int index, int size);

int main()
{
    int arr[100] = {2, 5, 23, 45, 54, 65, 76};
    int size = 7, index = 3, num = 34;
    displayArray(arr, size);
    insertArray(arr, index, num, size);
    size += 1;
    displayArray(arr, size);
    deleteArray(arr, index, size);
    size -= 1;
    displayArray(arr, size);
    return 0;
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertArray(int arr[], int index, int num, int size)
{
    if (index >= size)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = num;
    return 1;
}

int deleteArray(int arr[], int index, int size){
    if(index >= size){
        return -1;
    }
    for (int i = index; i < size -1; i++)
    {
        arr[i] = arr[i + 1];
    }
    
}