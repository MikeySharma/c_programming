// Write a C function to remove the last element from a dynamically allocated array and resize the array.
#include <stdio.h>
#include <stdlib.h>

struct MyArray
{
    int capacity;
    int size;
    int *ptr;
};

void append(struct MyArray *arr, int value);
void deleteFromEnd(struct MyArray *arr);
void displayArray(struct MyArray *arr);

int main()
{
    struct MyArray arr;
    arr.capacity = 2;
    arr.size = 0;
    arr.ptr = (int *)malloc(arr.capacity * sizeof(int));
    if (arr.ptr == NULL)
    {
        printf("Memory Allocation Failed!.\n");
        return 1;
    }
    append(&arr, 10);
    printf("Added First Element\n");
    displayArray(&arr);
    append(&arr, 20);
    printf("Added Second Element\n");
    displayArray(&arr);
    append(&arr, 30);
    printf("Added Third Element\n");
    displayArray(&arr);
    deleteFromEnd(&arr);
    printf("Removed Third Element\n");
    displayArray(&arr);
    // Free allocated dynamic memory.
    free(arr.ptr);

    // printf("Press Enter to exit...\n");
    // getchar();
    return 0;
}

void append(struct MyArray *arr, int value)
{
    if (arr->size >= arr->capacity)
    {
        arr->capacity *= 2;
        arr->ptr = (int *)realloc(arr->ptr, arr->capacity * sizeof(int));
        if (arr->ptr == NULL)
        {
            printf("Memory Reallocation Failed ! \n");
            exit(1);
        }
    }
    arr->ptr[arr->size] = value;
    arr->size++;
}

void displayArray(struct MyArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->ptr[i]);
    }
    printf("\n");
}

void deleteFromEnd(struct MyArray *arr)
{
    if (arr->size > 0)
    {
        arr->size--;
        if (arr->size < (arr->capacity / 2))
        {
            arr->capacity /= 2;
            arr->ptr = (int *)realloc(arr->ptr, arr->capacity * sizeof(int));
            if (arr->ptr == NULL && arr->capacity > 0)
            {
                printf("Memory Reallocation Failed!.\n");
                exit(1);
            }
        }
    }
    else
    {
        printf("Array is Already Empty. \n");
    }
}