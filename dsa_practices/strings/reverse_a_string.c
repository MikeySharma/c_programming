//Reverse A String
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "abcdefghijklm";
    int n = strlen(str);

    for(int i = 0; i < n / 2; i++) {
        str[i] ^= str[n - i - 1];
        str[n - i - 1] ^= str[i];
        str[i] ^= str[n - i - 1];
    }

    printf("%s\n", str);

    return 0;
}
