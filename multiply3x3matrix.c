#include <stdio.h>

void multiplyMatrix(int mat1[3][3], int mat2[3][3], int result[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int result[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};
    int result[3][3];
    multiplyMatrix(mat1, mat2, result);
    printf("Resultant Matrix is: \n");
    displayMatrix(result);
    return 0;
}