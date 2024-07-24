//Sort the array elements according to the frequency of the elements in ascending order and elements in descending order

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    *a = *a - *b;
    *b = *a + *b;
    *a = *b - *a;
}

void printArray(int *arr, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *nums, int low, int high){
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if(pivot < nums[j]){
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[high]);

    return i + 1;
    
}

void quickSort(int *nums, int low, int high){
    if(low< high){
        int pi = partition(nums, low, high);
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}


int main() {
    int nums[] = {1, 1, 1, 2,2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array: \n");
    printArray(nums, numsSize);

    quickSort(nums, 0, numsSize - 1);

    printf("Sorted Array: \n");
    printArray(nums, numsSize);


    return 0;
}