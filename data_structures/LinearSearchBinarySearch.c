#include<stdio.h>

void displayArray(int arr[], int size);
int linearSearch(int arr[], int size, int value);
int binarySearch(int arr[], int size, int value);

int main(){
    // int arr[] = {32, 43, 23, 54, 34, 54, 34, 2, 54};
    int arr[] = {2,3, 4, 6, 7, 34, 65, 76, 455, 768, 776};
    int size = sizeof(arr) / sizeof(int);
    int value = 76;
    displayArray(arr, size);
    // int index = linearSearch(arr, size, value);
    int index = binarySearch(arr, size, value);
    if(index >= 0){
        printf("Element %d found on index %d. \n", value, index);
    }else{
        printf("Element %d not found! \n", value);
    }

    return 0;
}

void displayArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int value){
    int low, mid, high;
    low = 0;
    high = size -1;

    if(arr[0] == value){
        return 0;
    }else if(arr[size -1] == value){
        return size -1;
    }
    while(low<=high){
        mid = (low + high) /2;
        if(arr[mid] == value){
            return mid;
        }else if(arr[mid] < value){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }

    return -1;
}