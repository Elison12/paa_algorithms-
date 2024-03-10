#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int somacontigua2d(int A[][4], int B[][4], int n, int m)
{
    int max_sum = 0;
    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int sum = 0;
            for (int j = 0; j < m; j++)
            {
                B[i][j] += A[i + k - 1][j];
                sum = MAX(B[i][j], B[i][j] + sum);
                max_sum = max(max_sum, sum);
            }
        }
    }
    return max_sum;
}

int chamada(int *A[][4], int n, int m)
{
    int B[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = 0;
        }
    }

    int resultado = somacontigua2d(A, B, n, m);
}

int main()
{
    int a[4][4] = {{5, -10, 2, 3, 6}, {-8, 7, 1, -2, -7}, {2, -1, 3, 1, -5}, {-1, 9, -15, 13, -20}};
    int n = 4;
    int m = 4;
    chamada(&a, n, m);
    return 0;
}
