#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
    int n;
    int *elements;
} t_vector;

int merge(int *a, int n, int *inv);

int main()
{

    int entrada, i, inv;
    do
    {
        scanf("%d", &entrada);
        t_vector vetor;

        if (entrada == 0)
        {
            break;
        }
        vetor.n = entrada;

        vetor.elements = (int *)malloc((vetor.n + 1) * sizeof(int));
        for (int i = 0; i < vetor.n; i++)
        {
            scanf("%d", &(vetor.elements[i]));
        }
        inv = 0;

        // insertionSort(vetor);
        merge(vetor.elements, vetor.n, &inv);
        printf("%s\n", inv & 1 ? "Marcelo" : "Carlos");

    } while (entrada != 0);

    return 0;
}
int merge(int *a, int n, int *inv)
{

    if (n > 1)
    {

        merge(a, n / 2, inv);
        merge(a + (n / 2), (n + 1) / 2, inv);
        int i = 0, k;
        int j = n / 2;
        int b[n];

        for (k = 0; k < n; ++k)
        {

            if (i < n / 2 && j < n)
            {

                if (a[i] < a[j])
                    b[k] = a[i], ++i;
                else if (a[j] < a[i])
                    b[k] = a[j], ++j, *inv += (n / 2) - i;
                else
                    b[k] = a[i], ++i;
            }
            else if (i < n / 2)
                b[k] = a[i], ++i;
            else
                b[k] = a[j], ++j;
        }

        memcpy(a, b, sizeof(int) * n);
    }
}