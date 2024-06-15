#include <stdio.h>
#include <stdbool.h>

bool isComposite(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if ((num % i) == 0)
        {
            return true;
        }
    }
    return false;
}

void printComposites(int limit)
{
    printf("Composite number upto %d are: \n", limit);

    for (int i = 1; i <= limit; i++)
    {
        if (isComposite(i))
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int limit;
    printf("Enter the limt upto when want to print Composite Number: ");
    scanf("%d", &limit);
    printComposites(limit);
    printf("\n");
    return 0;
}