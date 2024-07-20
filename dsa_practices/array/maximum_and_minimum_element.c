//A C Program to find maximum and minimum element in a given array

#include <stdio.h>
#include <stdlib.h>

struct MinAndMax {
    int min;
    int max;
};

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct MinAndMax *getMinAndMax(int *arr, int size){
    struct MinAndMax *minMax = (struct MinAndMax *)malloc(sizeof(struct MinAndMax));
    minMax->max = arr[0];
    minMax->min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if(minMax->max < arr[i]){
            minMax->max = arr[i];
        }
        if(minMax->min > arr[i]){
            minMax->min = arr[i];
        }
    }

    return minMax;
    
}

int main() {
    int arr[] = {23, 24,5, 43, 233, 654};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("The Given Array is :\n");
    printArray(arr, size);

    struct MinAndMax *minMax = getMinAndMax(arr, size);
    printf("The Minimum Element is %d. \nThe Maximum Element is %d.", minMax->min, minMax->max);

    free(minMax);
    return 0;
}