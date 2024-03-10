#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char nome[25];
    int preco;
};

int compara_itens(const void *item1, const void *item2)
{
    struct Item *i1 = (struct Item *)item1;
    struct Item *i2 = (struct Item *)item2;
    return strcmp(i1->nome, i2->nome);
}

int busca_binaria(struct Item *itens, int n, int preco_maximo)
{
    int inicio = 0, fim = n - 1, meio;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (itens[meio].preco > preco_maximo)
        {
            fim = meio - 1;
        }
        else if (meio < n - 1 && itens[meio + 1].preco <= preco_maximo)
        {
            inicio = meio + 1;
        }
        else
        {
            return meio;
        }
    }
    return -1;
}

struct Item *compra_materiais(struct Item *materiais, int n, float dinheiro, int *num_itens_comprados)
{
    // Aloca memória para o vetor de itens comprados
    struct Item *itens_comprados = malloc(n * sizeof(struct Item));
    if (itens_comprados == NULL)
    {
        printf("Erro: não foi possível alocar memória\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa as variáveis
    int num_itens = 0;
    int total_gasto = 0;

    // Percorre a lista de materiais
    for (int i = 0; i < n; i++)
    {
        // Verifica se ainda há dinheiro disponível para comprar mais itens
        if (dinheiro - materiais[i].preco >= 0)
        {
            // Adiciona o item à lista de itens comprados
            itens_comprados[num_itens++] = materiais[i];
            total_gasto += materiais[i].preco;
            dinheiro -= materiais[i].preco;
        }
        else
        {
            // Se não houver dinheiro suficiente, sai do loop
            break;
        }
    }

    // Atualiza o número de itens comprados
    *num_itens_comprados = num_itens;

    // Libera a memória alocada para o vetor de itens comprados, se necessário
    if (num_itens < n)
    {
        struct Item *temp = realloc(itens_comprados, num_itens * sizeof(struct Item));
        if (temp == NULL)
        {
            printf("Erro: não foi possível realocar memória\n");
            exit(EXIT_FAILURE);
        }
        itens_comprados = temp;
    }

    // Ordena a lista de itens comprados por ordem alfabética
    qsort(itens_comprados, num_itens, sizeof(struct Item), compara_itens);

    // Retorna a lista de itens comprados
    return itens_comprados;
}

int main()
{
    // Lê o dinheiro que Ambrósio dispõe
    float dinheiro;
    scanf("%f", &dinheiro);

    // Lê o número de itens na lista
    int n;
    scanf("%d", &n);
    n = n+1;

    // Aloca memória para o vetor de materiais
    struct Item *materiais = malloc(n * sizeof(struct Item));
    if (materiais == NULL)
    {
        printf("Erro: não foi possível alocar memória\n");
        exit(EXIT_FAILURE);
    }

    // Lê os materiais da lista
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", materiais[i].nome, &materiais[i].preco);
        fflush(stdin);
    }

    // Ordena a lista de materiais por ordem crescente de preço
    qsort(materiais, n, sizeof(struct Item), compara_itens);

    // Faz as compras
    int num_itens_comprados;
    struct Item *itens_comprados = compra_materiais(materiais, n, dinheiro, &num_itens_comprados);

    // Imprime a lista de itens comprados e o troco, se houver
    int total_gasto = 0;
    for (int i = 0; i < num_itens_comprados; i++)
    {
        printf("%s %d\n", itens_comprados[i].nome, itens_comprados[i].preco);
        total_gasto += itens_comprados[i].preco;
    }
    if (dinheiro - total_gasto > 0)
    {
        printf("Troco: %.2f\n", dinheiro - total_gasto);
    }

    // Libera a memória alocada para os vetores de materiais e de itens comprados
    free(materiais);
    free(itens_comprados);

    return 0;
}