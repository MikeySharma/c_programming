#include <stdio.h>

int main()
{
    char c;
    int lowervowel, uppervowel;

    printf("Enter the character : ");
    scanf("%c", &c);

    lowervowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    uppervowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowervowel || uppervowel)
    {
        printf("%c is vowel character. \n", c);
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("%c is consonant character. \n", c);
    }
    else
    {
        printf("%c is not an alphabet. \n", c);
    }
    return 0;
}