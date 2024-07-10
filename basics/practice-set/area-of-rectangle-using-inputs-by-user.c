//A C program to calculate the area of rectangle by getting inputs length and breadth from the user.

#include <stdio.h>

int main() {
    int len, breadth;
    printf("Enter the length: ");
    scanf("%d", &len);
    printf("Enter the breadth: ");
    scanf("%d", &breadth);
    
    printf("Area of rectangel of length %d and breadth %d is %d.\n", len, breadth, len * breadth);
    return 0;
}