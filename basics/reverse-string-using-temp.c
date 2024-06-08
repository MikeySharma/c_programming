#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main()
{
    char str[100];
    printf("Enter your string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed String is %s", str);

    return 0;
}

void reverseString(char *str)
{
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0; j = length - 1; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
