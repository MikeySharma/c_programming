#include <stdio.h>

void printArray(int *nums, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
}

void bubbleSortAdaptive(int *nums, int size){
    int isSorted;
    for (int i = 0; i < size - 1; i++) //For number of passes
    {
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++) //for each comparisons
        {
            if(nums[j] > nums[j + 1]){
                nums[j] ^= nums[j + 1];
                nums[j + 1] ^= nums[j];
                nums[j] ^= nums[j + 1];
                isSorted = 0;
            }
        }
        if(isSorted){
            break;
        }
    }
    
}

int main() {
    int size = 10;
    int nums[] = {2, 34, 23, 54, 34, 54, 4, 24, 23, 54};
    printf("Elements Before Sorted.\n");
    printArray(nums, size);
    bubbleSortAdaptive(nums, size);
    printf("Elements After Sorted.\n");
    printArray(nums, size);
    return 0;
}