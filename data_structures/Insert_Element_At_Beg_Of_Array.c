#include <stdio.h>

void displayArray(int arr[], int num);
void InsAtBeg(int arr[], int size, int num);

int main()
{
    int arr[100] = {10, 32, 34, 54, 55, 65, 76, 77};
    int size = 8, num = 2;
    printf("Array before Insertion. \n");
    displayArray(arr, size);
    InsAtBeg(arr, size, num);
    size += 1;
    printf("Array after Insertion At Begining. \n");
    displayArray(arr, size);
    return 0;
}

void displayArray(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsAtBeg(int arr[], int size, int num){
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = num;
}