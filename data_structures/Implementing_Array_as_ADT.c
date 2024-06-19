#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *marks, int tSize, int uSize)
{
    // (*marks).total_size = tSize;
    // (*marks).used_size = uSize;
    // (*marks).ptr = (int *)malloc(tSize * sizeof(int));
    marks->total_size = tSize;
    marks->used_size = uSize;
    marks->ptr = (int *)malloc(tSize * sizeof(int));
}

void insertElement(struct myArray *marks)
{
    for (int i = 0; i < marks->used_size; i++)
    {
        printf("Enter your element %d: ", i);
        scanf("%d", &(marks->ptr)[i]);
    }
}

void showArray(struct myArray *marks)
{
    for (int i = 0; i < marks->used_size; i++)
    {
        printf("%d ", marks->ptr[i]);
    }
    printf("\n");
}

void insertElementByIndex(struct myArray *marks, int index, int num)
{
    marks->ptr[index] = num;
}

int getElementByindex(struct myArray *marks, int index)
{
    return marks->ptr[index];
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    insertElement(&marks);
    showArray(&marks);
    // insertElementByIndex(&marks, 2, 54);
    // int data = getElementByindex(&marks, 2);
    // printf("%d \n", data);
    return 0;
}