#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    printf("Enter the term to print fibonacci : ");
    scanf("%d", &n);
    printf("Fibonacci upto %d term are given below: \n", n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}