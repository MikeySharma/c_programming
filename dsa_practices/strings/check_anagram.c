//Check the given string is anagram or not
//Eg. Triangle == Integral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return (*(char *)a - *(char *)b);
}

int isAnagram(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 != len2){
        return 0;
    }

    qsort(str1, len1, sizeof(char), compare);
    qsort(str2, len2, sizeof(char), compare);

    if(strcmp(str1, str2) == 0){
        return 1;
    }
    return 0;
}
int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    scanf("%s", &str1);

    printf("Enter the second string: ");
    scanf("%s", &str2);

    if(isAnagram(str1, str2)){
        printf("The Given String is anagram.\n");
    }else{
        printf("The Given String is not anagram.\n");
    }
    return 0;
}