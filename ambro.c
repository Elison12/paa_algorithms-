#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[50];
    int price;
} Item;

int compare_items(const void* a, const void* b) {
    Item* item_a = (Item*) a;
    Item* item_b = (Item*) b;
    return strcmp(item_a->name, item_b->name);
}

void print_items(Item* items, char** chosen_items, int n_chosen_items, int money_left) {
    // Criar uma lista com os itens escolhidos e seus preços
    Item* chosen_items_with_price = (Item*) malloc(n_chosen_items * sizeof(Item));
    int j = 0;
    for (int i = 0; i < n_chosen_items; i++) {
        for (int k = 0; k < n_chosen_items; k++) {
            if (strcmp(items[k].name, chosen_items[i]) == 0) {
                chosen_items_with_price[j] = items[k];
                j++;
                break;
            }
        }
    }
    // Ordenar a lista em ordem alfabética dos produtos
    qsort(chosen_items_with_price, n_chosen_items, sizeof(Item), compare_items);
    // Imprimir a nova lista
    for (int i = 0; i < n_chosen_items; i++) {
        printf("%s %d\n", chosen_items_with_price[i].name, chosen_items_with_price[i].price);
    }
    // Imprimir o dinheiro que sobrou
    printf("%d\n", money_left);
    free(chosen_items_with_price);
}

int max_items(Item* items, int n_items, int money, char*** chosen_items) {
    // Ordenar a lista em ordem decrescente dos preços
    qsort(items, n_items, sizeof(Item), compare_items);
    int count = 0;
    int money_left = money;
    int i = 0;
    char** chosen = (char**) malloc(n_items * sizeof(char*));
    while (money_left >= items[i].price && i < n_items) {
        chosen[count] = (char*) malloc(50 * sizeof(char));
        strcpy(chosen[count], items[i].name);
        count++;
        money_left -= items[i].price;
        i++;
    }
    *chosen_items = chosen;
    return count;
}

int main() {
    Item items[] = {{"CARRINHOS", 999.99}, {"PRATELEIRAS", 570.00},{"ESTANTES", 359.99}, {"CAIXAS_C_ESTEIRA", 3900}};
    
    int n_items = 4;
    int money = 5000.00;
    char** chosen_items;
    int count = max_items(items, n_items, money, &chosen_items);
    print_items(items, chosen_items, count, money - count);
    for (int i = 0; i < count; i++) {
        free(chosen_items[i]);
    }
    free(chosen_items);
    return 0;
}
