#include <stdio.h>

int findlinearv2(int mat[4][3], int l, int c, int x) {

    int menor = mat[0][0];
    int maior = mat[l - 1][c - 1];

    int i = 0, j = c - 1;

    if (x < menor || x > maior)
    {
        printf("Item n pertencente a matriz");
        return -1;
    }

    while (i <= c && j >= 0) {
        if (mat[i][j] == x) {
            printf("Elemento encontrado na posicao %i %i", i, j);
            return 1;
        }
        if (mat[i][j] > x)
            j--;
        else    
            i++;
    }
    printf("Item n encontrado");
    return 0;
}

int main() {
    int matrix[4][3] = {
        {2, 3, 5},
        {14, 15, 17},
        {25, 30, 100},
        {1000, 1001, 1500}};
   
    findlinearv2(matrix, 4, 3, 1000);
}