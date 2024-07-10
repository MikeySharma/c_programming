//A C program to convert celcius into fahrenheit

#include <stdio.h>

int main() {
    float celcius;
    printf("Enter Celcius Temperature: ");
    scanf("%f", &celcius);

    float fahrenheit  = (celcius * 9 / 5) + 32;
    printf("%f degree Celcius is equal to %f degree Fahrenheit.\n", celcius, fahrenheit);
    return 0;
}