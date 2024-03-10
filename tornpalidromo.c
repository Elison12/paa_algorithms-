#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

char *inverter(char *vet)
{
    int i, aux, fim, tam = strlen(vet);

    fim = tam - 1;
    for (i = 0; i < tam / 2; i++)
    {
        aux = vet[i];
        vet[i] = vet[fim];
        vet[fim] = aux;
        fim--;
    }
    return vet;
}

int getLevenstein(char *palavra)
{
    int n = strlen(palavra) - 1;

    int dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
        dp[i][0] = i;
    }

    char *invertida;
    invertida = malloc(n * sizeof(char));
    invertida = inverter(palavra);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= n; j++)
        {
            if (palavra[i - 1] == invertida[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + MIN(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int res = INT_MAX;
    for (int i = n, j = 0; i >= 0; --i, ++j)
    {
        res = MIN(res, dp[i][j]);
        printf("%d\n", res);
        if (i < n)
        {
            res = MIN(res, dp[i + 1][j]);
        }
        if (i > 0)
        {
            res = MIN(res, dp[i - 1][j]);
        }
    }
    return res;
}

int main()
{

    char *string;
    string = malloc(255 * sizeof(char)); // Alocando 30 bytes para armazenar a string
    fgets(string, 255, stdin);

    int m = getLevenstein(string);
    free(string);
    return 0;
}
