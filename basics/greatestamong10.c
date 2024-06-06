#include <stdio.h>

void findGreatest(int numbers[10], int greatest)
{
    for (int i = 0; i < 10; ++i)
    {
        printf("Enter  number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        if (i == 0)
        {
            greatest = numbers[i];
        }
        else if (numbers[i] > greatest)
        {
            greatest = numbers[i];
        }
    }
    printf("The greatest number is %d. \n", greatest);
}
void printGivenNumbers(int numbers[10])
{
    printf("Given Numbers are: \n");
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", numbers[i]);
    }
}
int main()
{
    int numbers[10];
    int greatest;
    findGreatest(numbers, greatest);
    printGivenNumbers(numbers);
    return 0;
}