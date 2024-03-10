int main()
{

    int weights[5][5] = {{10, 20, 5, 50, 60}, {80, 6, 7, 0, 80}, {3, 5, 7, 8, 2}, {7, 6, 1, 1, 4}, {6, 7, 4, 7, 8}};
    // int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 5, n = 5;
    int pathWeights[5][5];
    for (int i = 0; i < 3; i++)
        pathWeights[0][i] = weights[0][i];

    for (int row = 1; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {

            int candidateCol = col;

            if (col > 0 &&
                pathWeights[row - 1][col - 1] < pathWeights[row - 1][candidateCol])
                candidateCol = col - 1;

            if (col < n - 1 &&
                pathWeights[row - 1][col + 1] < pathWeights[row - 1][candidateCol])
                candidateCol = col + 1;

            pathWeights[row][col] = pathWeights[row - 1][candidateCol] + pathWeights[row][col];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", pathWeights[i][j]);
        }
        
        /* code */
    }
    

    return 0;
}
