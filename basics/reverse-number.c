#include <stdio.h>

int main()
{
    int num, reversedNum = 0, remainder;
    printf("Enter your number: ");
    scanf("%d", &num);
    int originalValue = num;
    while (num != 0)
    {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    printf("Reversed number of %d is %d. \n", originalValue, reversedNum);
    return 0;
}