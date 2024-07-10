//A C program to calculate simple interest on given principle, time, and rate of interest.

#include <stdio.h>

int main() {
    int priciple, time, rate;
    printf("Enter Principle: ");
    scanf("%d", &priciple);

    printf("Enter Time: ");
    scanf("%d", &time);

    printf("Enter Rate Of Interest: ");
    scanf("%d", &rate);

    float interest = (priciple * time * rate) / 100;
    printf("The Interest on Principle Rs. %d, with %d  interst on %d time is %f.\n", priciple, rate, time, interest);

    return 0;
}