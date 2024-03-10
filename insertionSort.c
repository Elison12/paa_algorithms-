#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int *elements;
} t_vector;

int insertionSort(t_vector array)
{
    int v, j, i;
    int acu = 0;
    for (i = 1; i < array.n; i++)
    {
        v = array.elements[i];
        j = i - 1;
        while (j >= 0 && array.elements[j] > v)
        {
            array.elements[j + 1] = array.elements[j];
            j = j - 1;
            acu++;
        }
        array.elements[j + 1] = v;
    }
    if (acu % 2 == 0) {
        printf("Carlos\n");
    }
    else {
        printf("Marcelo\n");
    }
}

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

        insertionSort(vetor);
    } while (entrada != 0);

    return 0;
}