#include <stdio.h>
#include <stdlib.h>

int max_loot(int n, int *v) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return v[0];
    }
    if (n == 2) {
        return (v[0] > v[1]) ? v[0] : v[1];
    }
    
    int *dp = (int*) malloc(n * sizeof(int));
    dp[0] = v[0];
    dp[1] = (v[0] > v[1]) ? v[0] : v[1];
    dp[2] = (dp[0] + v[2] > dp[1]) ? dp[0] + v[2] : dp[1];
    
    for (int i = 3; i < n; i++) {
        int opt1 = dp[i-2] + v[i];
        int opt2 = dp[i-3] + v[i];
        int opt3 = dp[i-4] + v[i];
        dp[i] = (opt1 > opt2) ? opt1 : opt2;
        dp[i] = (opt3 + v[i] > dp[i]) ? opt3 + v[i] : dp[i];
    }
    
    int result = dp[n-1];
    free(dp);
    printf("%d", &result);
}

int main() {
    int v[] = {2,10,12,24,29,69,0};
    int n = sizeof(v) / sizeof(int);
    int result = max_loot(n, v);
    // printf("Resultado: %d\n", result);
    return 0;
}
