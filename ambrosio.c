#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_L 25

typedef struct {
    char nome[MAX_L];
    float preco;
} Material;

int cmp_preco_decrescente(const void *a, const void *b) {
    const Material *p1 = (const Material *) a;
    const Material *p2 = (const Material *) b;
    if (p1->preco > p2->preco)
        return -1;
    else if (p1->preco < p2->preco)
        return 1;
    else
        return 0;
}

void maior_numero_itens(float dinheiro_disponivel, Material *materiais, int n, Material **solucao, float *dinheiro_sobrando) {
    // Implementação da função "maior_numero_itens" aqui
}


int maior_numero_itens_guloso(float dinheiro_disponivel, Material *materiais, int n, Material *solucao, float *dinheiro_sobrando) {
    // Ordena a lista de materiais em ordem decrescente de preço

    qsort(materiais, n, sizeof(Material), cmp_preco_decrescente);
    // Percorre a lista de materiais e adiciona o mais caro que ainda cabe no orçamento
    int i;
    for (i = 0; i < n && dinheiro_disponivel >= materiais[i].preco; i++) {
        dinheiro_disponivel -= materiais[i].preco;
        solucao[i] = materiais[i];
    }
    printf("%f", dinheiro_disponivel);
    // Calcula o dinheiro sobrando
    *dinheiro_sobrando = dinheiro_disponivel;
    
    // Retorna a quantidade de itens incluídos na solução
    return i;
}

int main() {
    float dinheiro_disponivel;
    int n;
    Material materiais[MAX_N];
    Material *solucao;
    float dinheiro_sobrando;
    
    // Lê a entrada
    scanf("%f", &dinheiro_disponivel);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %f", materiais[i].nome, &materiais[i].preco);
    }
    
    // Resolve o problema
    // maior_numero_itens(dinheiro_disponivel, materiais, n, &solucao, &dinheiro_sobrando);
    int valor = maior_numero_itens_guloso(dinheiro_disponivel, materiais, n, &solucao, &dinheiro_sobrando);
    
    printf("%d", valor);
    // Imprime a solução
    printf("%d\n", (int) (solucao - materiais));
    for (int i = 0; i < (int) (solucao - materiais); i++) {
        printf("%s %.2f\n", solucao[i].nome, solucao[i].preco);
    }
    printf("%.2f\n", dinheiro_sobrando);
    // Libera a memória alocada
    free(solucao);
    
    return 0;
}
