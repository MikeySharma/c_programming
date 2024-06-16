#include <stdio.h>
#include <stdbool.h>

void printArray(int *Array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void bubbleSortAdaptive(int *Array, int n)
{
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        isSorted = true;
        printf("Working on number of passes: %d \n", i + 1);
        for (int j = 0; j < n - i - 1; j++) // for comparisons
        {
            if (Array[j] > Array[j + 1])
            {
                Array[j] ^= Array[j + 1];
                Array[j + 1] ^= Array[j];
                Array[j] ^= Array[j + 1];
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
}
int main()
{
    int Array[] = {45, 46, 324, 56, 34, 53, 65, 23,};
    int n = sizeof(Array) / sizeof(Array[0]);

    printArray(Array, n);
    bubbleSortAdaptive(Array, n);
    printArray(Array, n);
}