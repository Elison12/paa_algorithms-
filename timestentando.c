#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef int (*comparator)(const void *, const void *);

void swap(void *a, void *b, size_t size)
{
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int partition(void *arr, int low, int high, size_t size, comparator cmp)
{
    void *pivot = (char *)arr + high * size;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        void *current = (char *)arr + j * size;
        if (cmp(current, pivot) < 0)
        {
            i++;
            swap((char *)arr + i * size, (char *)arr + j * size, size);
        }
    }
    swap((char *)arr + (i + 1) * size, (char *)arr + high * size, size);
    return i + 1;
}

void quicksort(void *arr, int low, int high, size_t size, comparator cmp)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, size, cmp);
        quicksort(arr, low, pi - 1, size, cmp);
        quicksort(arr, pi + 1, high, size, cmp);
    }
}

void myqsort(void *arr, size_t n, size_t size, comparator cmp)
{
    quicksort(arr, 0, n - 1, size, cmp);
}

typedef struct jogador jogador;

struct jogador
{
    char nome[100];
    int hab;
};

int compara(const void *c, const void *d)
{
    const jogador *a = c, *b = d;
    if (a->hab > b->hab) {
        return -1;
    }
    return 1;
}

int compareNomes(const void *c, const void *d)
{
    const char *a = c, *b = d;
    if (strcmp(a, b) < 0)
        return -1;
    return 1;
}

int main()
{
    int jogadores;
    int times;
    scanf("%d %d", &jogadores, &times);
    jogador j[jogadores + 1];
    int i;
    int divDeJogadores = (int)ceil((double)jogadores / times);
    char party[times][divDeJogadores][100];
    int *qnt = calloc(times, sizeof(int));
    for (i = 0; i < jogadores; i++)
    {
        getchar();
        scanf("%s %d", j[i].nome, &j[i].hab);
    }
    myqsort(j, jogadores, sizeof(jogador), compara);

    int k;
    for (i = 0, k = 0; i < jogadores; i++, k++)
    {
        k %= times;
        strcpy(party[k][qnt[k]], j[i].nome);
        qnt[k] += 1;
    }
    for (i = 0; i < times; i++)
        myqsort(party[i], qnt[i], sizeof(party[i][0]), compareNomes);

    for (i = 0; i < times; i++)
    {
        printf("Time %d\n", i + 1);
        for (k = 0; k < qnt[i]; k++)
        {
            printf("%s\n", party[i][k]);
        }
        printf("\n");
    }
    free(qnt);
    return (0);
}