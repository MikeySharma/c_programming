#include <stdio.h>
void printArray(int *Array, int n);
void bubbleSort(int *Array, int n);

int main()
{
    int Array[] = {3, 43, 23, 54, 234, 55, 32, 5};
    int n = 8;
    printArray(Array, n);
    bubbleSort(Array, n);
    printArray(Array, n);
}

void printArray(int *Array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void bubbleSort(int *Array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                Array[j] ^= Array[j + 1];
                Array[j + 1] ^= Array[j];
                Array[j] ^= Array[j + 1];
            }
        }
    }
}