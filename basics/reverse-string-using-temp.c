#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main()
{
    char str[100];
    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    printf("Reversed string is: %s\n", str);

    return 0;
}

void reverseString(char *str)
{
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
