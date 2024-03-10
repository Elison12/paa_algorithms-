#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma reunião
struct Reuniao {
    int inicio;
    int fim;
};

int compare_meetings(const void *a, const void *b) {
    const struct Reuniao *m1 = a;
    const struct Reuniao *m2 = b;
    return m1->inicio - m2->inicio;
}

int main() {
    int n, i, qntsalas;
    struct Reuniao *reunioes;

    scanf("%d", &n);
    reunioes = malloc(sizeof(struct Reuniao) * n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &reunioes[i].inicio, &reunioes[i].fim);
    }

    // Ordenação das reuniões por ordem crescente de horário de início
    qsort(reunioes, n, sizeof(struct Reuniao), compare_meetings);

    int *salas = malloc(sizeof(int) * n);
    qntsalas = 0;

    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < qntsalas; j++) {
            if (reunioes[i].inicio >= salas[j]) {
                salas[j] = reunioes[i].fim;
                break;
            }
        }
        if (j == qntsalas) {
            salas[qntsalas] = reunioes[i].fim;
            qntsalas++;
        }
    }

    // Impressão do número mínimo de salas necessárias
    printf("%d\n", qntsalas);

    free(reunioes);
    free(salas);

    return 0;
}