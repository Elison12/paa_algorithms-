#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int inicio, fim;
} Consulta;

int comparar(const void *a, const void *b)
{
    Consulta *c1 = (Consulta *)a;
    Consulta *c2 = (Consulta *)b;
    return c1->inicio - c2->inicio;
}

int max_consultas(Consulta consultas[], int n)
{
    qsort(consultas, n, sizeof(Consulta), comparar);
    int max_consultas = 0;
    int fim_anterior = 0;
    for (int i = 0; i < n; i++)
    {
        int inicio = consultas[i].inicio;
        int fim = consultas[i].fim;
        if (inicio >= fim_anterior)
        {
            max_consultas++;
            fim_anterior = fim;
        }
    }
    return max_consultas;
}

int main()
{

    int n;
    scanf("%d\n", &n);

    Consulta consultas[3];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &consultas[i].inicio, &consultas[i].fim);
    }

    int resultado = max_consultas(consultas, n);
    printf("%d\n", resultado);
    return 0;
}
