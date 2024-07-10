//A C Program to check is the number is divisible by 97 or not.

#include <stdio.h>

int main() {
    int num;
    printf("Enter Your Number: ");
    scanf("%d", &num);

    if(num % 97 == 0){
        printf("%d is divisible by 97.\n", num);
    }else{
        printf("%d is not divisible by 97.\n", num);
    }
    return 0;
}
