#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100

int backtrack(int posA, int posB, char* A, char* B, int* seq, int n)
{
    if (posB == strlen(B))
    {

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                printf("%d", seq[i] + 1);
            }
            else
            {
                printf("%d ", seq[i] + 1);
            }
        }
        printf("\n");
        return 1;
    }

    if (posA == strlen(A))
    {
        return 0;
    }

    int found_seq = 0;

    if (A[posA] == B[posB])
    {
        seq[n] = posA;
        found_seq |= backtrack(posA + 1, posB + 1, A, B, seq, n + 1);
        // backtrack(posA + 1, posB + 1, A, B, seq, n + 1);
    }

    found_seq |= backtrack(posA + 1, posB, A, B, seq, n);
    // backtrack(posA + 1, posB, A, B, seq, n);
    return found_seq;
}

int find_sequences(char *A, char *B)
{
    int seq[MAX_N];
    // backtrack(0, 0, A, B, seq, 0);

    int found_seq = backtrack(0, 0, A, B, seq, 0);
    return found_seq ? 0 : -1;
}

int main()
{

    char *A;
    char *B;
    A = malloc(250 * sizeof(char)); // Alocando 30 bytes para armazenar a string
    B = malloc(250 * sizeof(char)); // Alocando 30 bytes para armazenar a string

    // scanf("%s", A);
    gets(A);
    // fflush(stdin);
    gets(B);

    // find_sequences(A, B);

    int result = find_sequences(A, B);
    if (result == -1)
    {
        printf("-1");
    }
    // printf("%s", B);
    // free(A);
    // free(B);
    return 0;
}
