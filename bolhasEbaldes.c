#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int n;
    int *elements;
} t_vector;

void bubbleSort(t_vector array)
{
    int acu = 0;

    for (int i = 0; i < array.n - 1; i++)
    {
        for (int j = i + 1; j < array.n; j++)
        {
            if (array.elements[i] > array.elements[j])
            {
                acu++;
            }
        }
    }
    if (acu % 2 == 0) {
        printf("Carlos\n");
    }
    else {
        printf("Marcelo\n");
    }
}

// 5 5 1 3 4 2
//   1 5 3 4 2 M  0
//   1 3 5 4 2 C  1
//   1 3 4 5 2 M  2
//   1 3 4 2 5 C  3
//   1 3 2 4 5 M  4
//   1 2 3 4 5 C  5

int main()
{

    int entrada;
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

        bubbleSort(vetor);
    } while (entrada != 0);

    return 0;
}