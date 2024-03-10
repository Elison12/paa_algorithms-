#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int opt[n][n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int y = 0; y < n; y++) {
                opt[i][j][y] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            opt[i][i][y] = p[i] * (y+1);
        }
    }

    for (int k = 2; k <= n; k++) {
        for (int i = 0; i <= n-k; i++) {
            int j = i + k - 1;
            for (int y = 0; y < n; y++) {
                int sell_left = opt[i+1][j][y+1] + p[i]* (y+1);
                int sell_right = opt[i][j-1][y+1] + p[j]* (y+1);
                opt[i][j][y] = max(sell_left, sell_right);
            }
        }
    }

    printf("%d", opt[0][n-1][0]);

    return 0;
}
