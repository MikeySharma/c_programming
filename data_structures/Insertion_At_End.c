// Write a C function to append an element to the end of a dynamically allocated array. Ensure the array is resized appropriately.
#include <stdio.h>
#include <stdlib.h>

void append(int **arr, int *size, int *capacity, int num);
void displayArray(int **arr, int *size);

int main()
{
    int capacity = 2;
    int size = 0;
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory Allocation Fail! \n");
        return 1;
    }
    append(&arr, &size, &capacity, 10);
    displayArray(&arr, &size);
    append(&arr, &size, &capacity, 20);
    displayArray(&arr, &size);
    append(&arr, &size, &capacity, 30);
    displayArray(&arr, &size);
    append(&arr, &size, &capacity, 40);
    displayArray(&arr, &size);
    append(&arr, &size, &capacity, 50);
    displayArray(&arr, &size);
    free(arr);

    return 0;
}

void displayArray(int **arr, int *size)
{
    for (int i = 0; i < *size; i++)
    {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}

void append(int **arr, int *size, int *capacity, int num)
{
    if (*size >= *capacity)
    {
        *capacity *= 2;
        *arr = (int *)realloc(*arr, *capacity * sizeof(int));

        if (*arr == NULL)
        {
            printf("Memory Reallocation Failed ! \n");
            exit(1);
        }
    }
    (*arr)[*size] = num;
    (*size)++;
}