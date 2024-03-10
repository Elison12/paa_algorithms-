#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
 

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                                  + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    return K[n][W];
}

int main()
{
    int testcases;
    int numprodutos;
    scanf("%d\n", &testcases);
    
    for (int i = 0; i < testcases; i++) {
        scanf("%d\n", &numprodutos);
        int profit[numprodutos];
        int weight[numprodutos];
        int valoritem;
        int pesoitem;
        int familiatamanho;
        
        for (int j = 0; j < numprodutos; j++) {
            scanf("%d %d", &profit[j] ,&weight[j]);
        }
        scanf("%d\n", &familiatamanho);
        int acumulador = 0;
        int mochilaindividual;
        int n = sizeof(profit) / sizeof(profit[0]);
        for (int k = 1; k <= familiatamanho; k++) {
            scanf("%d", &mochilaindividual);
            acumulador = acumulador + knapSack(mochilaindividual, weight, profit, n);
        }
        printf("%d\n", acumulador);
        
    }
    
    return 0;
}
