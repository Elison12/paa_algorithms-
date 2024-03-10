#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

// ##################################################################
int maxthree(int a, int b, int c) {
    int maior;

    if(a > b){
        if(a > c)
            maior = a;
        else
            maior = c;
    }
    else{
        if(b > c)
            maior = b;
        else
            maior = c;
    }

    return maior;
}




// ###############################################################
int max_sum(int array[], int n) {
    int dp[n][n];

    // base case: subarrays of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = array[i];
    }

    // fill the table for increasing subarray lengths
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < n-k+1; i++) {
            int j = i + k - 1;

            // calculate the maximum sum if we select element i
            if (i+2 <= j) {
                dp[i][j] = max(dp[i][j], array[i] + dp[i+3][j]);
            }
            // calculate the maximum sum if we select element j
            if (j-2 >= i) {
                dp[i][j] = max(dp[i][j], array[j] + dp[i][j-3]);
            }

            // calculate the maximum sum if we do not select either i or j
            dp[i][j] = maxthree(dp[i][j], dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

int main() {
    int array[] = {3, 2, 5, 10, 7};
    int n = sizeof(array) / sizeof(array[0]);

    int max_sum_val = max_sum(array, n);

    printf("Maximum sum of elements: %d\n", &max_sum_val);

    return 0;
}
