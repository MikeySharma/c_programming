#include <stdio.h>

void transposeMatrix(int mat[3][3], int result[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = mat[j][i];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int result[3][3];
    transposeMatrix(mat, result);
    return 0;
}