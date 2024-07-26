//Check the given string is palindrome or not;

#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int n){
    int right = n - 1;
    int left = 0;

    while (left < right)
    {
        if(str[left] != str[right]) return 0;
        left++;
        right--;
    }
    
    return 1;
}

int main() {
    char str[] = "madam";
    int n = strlen(str);

    if(isPalindrome(str, n)){
        printf("The Given String \"%s\" is Palindrome.\n", str);
    }else{
        printf("The Given String \"%s\" is not Palindrome.\n", str);
    }
    return 0;
}