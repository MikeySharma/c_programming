#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num;
    bool isComposite = false;
    printf("Enter your number : ");
    scanf("%d", &num);
    for (int i = 2; i < num; i++)
    {
        if ((num % i) == 0)
        {
            isComposite = true;
            break;
        }
    }
    if (isComposite)
    {
        printf("Given number %d is Composite. \n", num);
    }
    else
    {
        printf("Given number %d is Prime Number. \n", num);
    }

    return 0;
}