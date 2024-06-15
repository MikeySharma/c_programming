#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int num);
void printPalindrome(int limit);
int reverseNumber(int num);

int main()
{
    int limit;
    printf("Enter limit to print Palindrome Number : ");
    scanf("%d", &limit);
    printPalindrome(limit);
    return 0;
}

void printPalindrome(int limit)
{
    printf("Palindrome upto %d are \n", limit);
    for (int i = 1; i <= limit; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

bool isPalindrome(int num)
{
    int reversedNumber = reverseNumber(num);
    if (reversedNumber == num)
    {
        return true;
    }
    return false;
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