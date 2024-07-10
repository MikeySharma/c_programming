// Calculate the area of a circle and modify the same program to calculate the volume of a cylinder given its radius and height.

#include <stdio.h>
#include <math.h>


int main() {
    float pi = 3.14;
    int radius, height;
    printf("Enter the radius: ");
    scanf("%d", &radius);
     float area = pi * pow(radius, 2);
    printf("Area of Circle is %f.\n", area);

    printf("Enter the height: ");
    scanf("%d", &height);
    float volume = pi * pow(radius, 2) * height;
    printf("Volume of Cylinder is %f", round(volume));
    return 0;
}