#include <stdlib.h>
#include <stdio.h>

int GetMinimumPath(int *weights, int rowsCount, int colsCount)
{
    int *pathWeights = BuildPathWeights(weights, rowsCount, colsCount);
    int *path = ExtractMinimumWeightPath(weights, pathWeights, rowsCount, colsCount);

    free(pathWeights);

    return path;
}

int BuildPathWeights(int *weights, int rowsCount, int colsCount)
{ 
    int *pathWeights = (int *)malloc(rowsCount * colsCount * sizeof(int));

    for (int i = 0; i < colsCount; i++)
    {
        pathWeights[0][i] = weights[0][i];
    }

    for (int row = 1; row < rowsCount; row++)
    {
        for (int col = 0; col < colsCount; col++)
        {

            int candidateCol = col;//0

            if (col > 0 && pathWeights[(row - 1) * colsCount + col - 1] < pathWeights[(row - 1) * colsCount + candidateCol])
            {
                candidateCol = col - 1;
            }

            if (col < colsCount - 1 && pathWeights[(row - 1) * colsCount + col + 1] < pathWeights[(row - 1) * colsCount + candidateCol])
            {
                candidateCol = col + 1;
            }

            pathWeights[row * colsCount + col] = pathWeights[(row - 1) * colsCount + candidateCol] + weights[row * colsCount + col];
        }
    }

    return pathWeights;
}

int ExtractMinimumWeightPath(int *weights, int *pathWeights, int rowsCount, int colsCount)
{
    int *path = (int *)malloc(rowsCount * sizeof(int));

    int col = 0;
    for (int i = 1; i < colsCount; i++)
    {
        if (pathWeights[(rowsCount - 1) * colsCount + i] < pathWeights[(rowsCount - 1) * colsCount + col])
        {
            col = i;
        }
    }

    int row = rowsCount - 1;
    do
    {
        path[row] = col + 1;

        if (col > 0 && pathWeights[(row - 1) * colsCount + col - 1] + weights[row * colsCount + col] == pathWeights[row * colsCount + col])
        {
            col = col - 1;
        }
        else if (col < colsCount - 1 && pathWeights[(row - 1) * colsCount + col + 1] + weights[row * colsCount + col] == pathWeights[row * colsCount + col])
        {
            col = col + 1;
        }

        row--;
    } while (row > 0);

    path[0] = col + 1;

    return path;
}

int main()
{
    int tmatriz[5][5] = {{10, 20, 5, 50, 60}, {80, 6, 7, 0, 80}, {3, 5, 7, 8, 2}, {7, 6, 1, 1, 4}, {6, 7, 4, 7, 8}};

    int tamanho = GetMinimumPath(*tmatriz, 5, 5);
    printf("%d", tamanho);
    return 0;
}
