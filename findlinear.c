#include <stdio.h>

int findlinear(int mat[4][4], int n, int x)
{

    if (n == 0)
        return -1;
    int menor = mat[0][0], maior = mat[n - 1][n - 1];

    if (x < menor || x > maior)
        return -1;

    int i = 0, j = n - 1;

    while (i < n && j >= 0)
    {
        if (mat[i][j] == x)
        {
            printf("Item encontrado na posição %i %i", i, j);
            return 1;
        }
        if (mat[i][j] > x)
            j--;
        else
            // mat[i][j] > x
            i++;
    }
    printf("Elemento não encontrado");
    return 0;
}

int main()
{
    int matrix[4][4] = {
        {2, 3, 5, 12},
        {14, 15, 17, 20},
        {25, 30, 100, 101},
        {1000, 1001, 1500, 3000}};

    findlinear(matrix, 4, 14);
    return 0;
}