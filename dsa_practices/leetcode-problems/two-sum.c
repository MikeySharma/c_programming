//Find the two sum of the target from the given array;


#include <stdio.h>
#include <stdlib.h>

void printArray(int *nums, int numSize){
    for (int i = 0; i < numSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int *twoSum(int *nums, int numSize, int target){
    int *result = (int *)malloc(sizeof(int) * 2);
    for(int i = 0; i < numSize; i++){
        for (int j = i + 1; i < numSize; j++)
        {
            if((nums[i] + nums[j]) == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
        
    }
}
int main() {
    int nums[] = {2, 7, 5, 9, 54, 4};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int targetSize = 2;
    printArray(nums, numSize);

    int *result =  twoSum(nums, numSize, target);

    printf("Two sum of %d is: \n", target);
    printArray(result, targetSize);
   
    
    return 0;
}