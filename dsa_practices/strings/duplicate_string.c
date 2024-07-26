#include <stdio.h>
#include <string.h>

void findDuplicateCharacters(char *str) {
    int charCount[256] = {0};  // Array to store the count of characters
    int n = strlen(str);

    // Count the occurrence of each character
    for (int i = 0; i < n; i++) {
        charCount[(unsigned char)str[i]]++;
    }

    printf("Duplicate characters in the string are:\n");
    // Print characters that appear more than once
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 1) {
            printf("%c %d\n", i, charCount[i]);
        }
    }
}

int main() {
    char str[] = "mikeysharma";
    findDuplicateCharacters(str);
    return 0;
}
