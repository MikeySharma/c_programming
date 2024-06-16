#include <stdio.h>
void printArray(int *Array, int n);
void bubbleSort(int *Array, int n);

int main()
{
    int Array[] = {2, 6, 34, 65, 23, 5, 64};
    int n = 7;
    printArray(Array, n);
    bubbleSort(Array, n);
    printArray(Array, n);
    return 0;
}

void bubbleSort(int *Array, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}

void printArray(int *Array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}
