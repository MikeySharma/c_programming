#include<stdio.h>
#include<stdbool.h>

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i = 2; i * i <= num; i++){
        if((num % i) == 0){
            return false;
        }
    }
    return true;
}

void printPrimes(int limit){
    printf("Prime Number Upto %d is: \n", limit);
    for(int i = 1; i <= limit; i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
}

int main(){
    int limit;
    printf("Enter the limit of printing prime number : ");
    scanf("%d", &limit);
    printPrimes(limit);

    printf("\n");
    return 0;
}