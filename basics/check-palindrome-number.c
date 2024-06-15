#include <stdio.h>
#include <stdbool.h>

int reverseNumber(int num);

void isPalindrome(int original, int reversed);

int main()
{
    int num;
    printf("Enter your number : ");
    scanf("%d", &num);

    int reversedNumber = reverseNumber(num);
    isPalindrome(num, reversedNumber);
    return 0;
}

int reverseNumber(int num)
{
    int remainder, reversedNumber = 0;
    while (num != 0)
    {
        remainder = num % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        num /= 10;
    }

    return reversedNumber;
}

void isPalindrome(int original, int reversed)
{
    if (original == reversed)
    {
        printf("%d is Palindrome Number. \n", original);
    }
    else
    {
        printf("%d is not a Palindrome Number. \n", original);
    }
}