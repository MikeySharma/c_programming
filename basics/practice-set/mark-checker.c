// Write a program to determine whether a student has passed or failed. To pass, astudent requires a total of 40% and at least 33% in each subject. Assume there are three subjects and take the marks as input from the user

#include <stdio.h>

int main()
{
    int english, math, science;
    printf("Enter Mark of English: ");
    scanf("%d", &english);

    printf("Enter mark of Math: ");
    scanf("%d", &math);

    printf("Enter mark of Science: ");
    scanf("%d", &science);

    if (science < 33)
    {
        printf("You failed in science Exam.\n");
    }
    if (math < 33)
    {
        printf("You failed in Math Exam.\n");
    }
    if (english < 33)
    {
        printf("You failed in English Exam.\n");
    }
    if (((math + english + science) / 300 * 100) < 40)
    {
        printf("You failed in comparison of all exams.\n");
    }
    return 0;
}