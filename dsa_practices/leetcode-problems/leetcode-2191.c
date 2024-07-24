//LeetCode Problem no. 2191 Sort the jumbled Numbers
#include <stdio.h>

void printArray(int *arr, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void insertionSort(int *mappedValue, int *nums, int n) {
    for (int i = 1; i < n; i++) {
        int key = mappedValue[i];
        int numsKey = nums[i];
        int j = i - 1;

        // Move elements of mappedValue[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && mappedValue[j] > key) {
            mappedValue[j + 1] = mappedValue[j];
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        mappedValue[j + 1] = key;
        nums[j + 1] = numsKey;
    }
}

int mapNums(int *nums, int *mapping, int numsSize, int mapSize){
    int temp;
    int mappedValue[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
       temp = nums[i];
       mappedValue[i] = 0;
       mappedValue[i] = 0;
       if(temp >= 100){
        mappedValue[i] = mappedValue[i] * 10 + mapping[temp / 100];
       }
       if(temp >= 10){
        mappedValue[i] = mappedValue[i] * 10 + mapping[(temp / 10) % 10];
       }
       mappedValue[i] = mappedValue[i] * 10 + mapping[temp % 10];  
    }
    insertionSort(mappedValue, nums, numsSize);
}
int main() {
    // int nums[] = {991, 338, 38};
    // int mapping[] = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    int nums[] = { 789, 456, 123};
    int mapping[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int mapSize = sizeof(mapping) / sizeof(mapping[0]);

    printf("Original Array: \n");
    printArray(nums, numsSize);
    mapNums(nums, mapping, numsSize, mapSize);

    printf("Sorted Array: \n");
    printArray(nums, numsSize);

    return 0;
}