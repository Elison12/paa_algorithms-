#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int notas[], int target, int l, int h)
{
    if (h >= l)
    {
        int mid = l + (h - l) / 2;
        if (notas[mid] == target)
        {
            return mid;
        }
        if (notas[mid] > target)
        {
            return buscaBinaria(notas, target, l, mid - 1);
        }
        return buscaBinaria(notas, target, mid + 1, h);
    }
    return -1;
}

int buscasequencia(int cpfs[], int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (cpfs[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int buscaEmNotas(int notas[], int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (notas[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int inscritos;
    int testcases;

    scanf("%d", &inscritos);

    int cpfs[inscritos];
    int notas[inscritos];

    for (int i = 0; i < inscritos; i++)
    {
        scanf("%d\n", &cpfs[i]);
    }

    for (int i = 0; i < inscritos; i++)
    {
        scanf("%d\n", &notas[i]);
    }

    scanf("%d", &testcases);

    for (int i = 0; i < testcases; i++)
    {
        int alvo;
        scanf("%d", &alvo);
        int resultSequencialSearch = buscaBinaria(cpfs, alvo, 0, inscritos);

        if (resultSequencialSearch != -1)
        {
            printf("%d\n", notas[resultSequencialSearch]);
        }
        else
        {
            printf("NAO SE APRESENTOU\n");
        }
    }

    return 0;
}

