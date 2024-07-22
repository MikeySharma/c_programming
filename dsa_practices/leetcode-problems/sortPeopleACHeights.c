//sort People according to the height of people

#include <stdio.h>
#include <stdlib.h>

void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapStr(char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *heights, char **names, int low, int high){
    int pivot = heights[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if(heights[j] > pivot){
            i++;
            swapInt(&heights[i], &heights[j]);
            swapStr(&names[i], &names[j]);
        }
    }

    swapInt(&heights[i + 1], &heights[high]);
    swapStr(&names[i + 1], &names[high]);

    return i + 1;
    
}

void sortPeople(int *heights, char** names, int low, int high){
    if(low < high){
        int pi = partition(heights, names, low, high);
        sortPeople(heights, names, low, pi - 1);
        sortPeople(heights, names, pi + 1, high);
    }
}

void printArr(int *arr, char **names, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d : %s\n", arr[i], names[i]);
    }
}

int main() {
    char* names[] = { "Rohan", "Mohan", "Sohan", "Thor", "Bruce"};
    int heights[] = {85, 34, 234, 54, 80};
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int namesSize = sizeof(names) / sizeof(names[0]);
    printf("Original Array :- \n");
    printArr(heights, names, namesSize);

    sortPeople(heights, names, 0, namesSize - 1);

    printf("Sorted Array :- \n");
    printArr(heights, names, namesSize);
    return 0;
}