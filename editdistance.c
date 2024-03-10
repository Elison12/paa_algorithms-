#include <stdio.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int dist(char *x, char *y) {
    
    int m = strlen(x);
    int n = strlen(y);

    int T[m+1][n+1];

    memset(T, 0, sizeof(T));

    for (int i = 1; i <= m; i++) {
        T[0][i] = i;
    }
    
    for (int j = 1; j <= n; j++) {
        T[j][0] = j;
    }

    int substituitioncost;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1]== y[j-1]) {
                /* code */
                substituitioncost = 0;
            } else
            {
                substituitioncost = 1;
            }
            T[i][j] = MIN(MIN(T[i - 1][j] + 1,          // deletion (case 3b)
                            T[i][j - 1] + 1),           // insertion (case 3a)
                T[i - 1][j - 1] + substituitioncost);
            //T[0][0] = min(min())
        }
    }

    return T[m][n];
}

int main()
{
    char *a = "mireya";
    char *b = "mirella";

    int editdistance = dist(a, b);

    printf("A distancia de edicao eh %d", editdistance);
    return 0;
}
