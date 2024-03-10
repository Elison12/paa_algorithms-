#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    float price;
} Item;

int max_items(Item items[], int n, float money, char **chosen_items, float *money_left)
{
    qsort(items, n, sizeof(Item), [](const void *a, const void *b) -> int
          {
        Item* x = (Item*)a;
        Item* y = (Item*)b;
        return (x->price > y->price) - (x->price < y->price); });
    int count = 0;
    chosen_items = (char)malloc(n * sizeof(char));
    memset(*chosen_items, 0, n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        if (money >= items[i].price)
        {
            count++;
            (*chosen_items)[i] = 1;
            money -= items[i].price;
        }
        else
        {
            continue;
        }
    }

    *money_left = money;

    return count;
}

void print_items(Item items[], int n, char *chosen_items, float money_left)
{

    for (int i = 0; i < n; i++)
    {
        if (chosen_items[i])
        {
            printf("%s %.2f\n", items[i].name, items[i].price);
        }
    }

    printf("%.2lf\n", money_left);
}

int main()
{
    /*   Item items[] = { {"CARRINHOS", 999.99}, {"PRATELEIRAS", 570.00}, {"ESTANTES", 359.99}, {"CAIXAS_C_ESTEIRA", 3900.00} };
       int n = 4;*/

    int n;
    float money; //= 5000.00;
    char *chosen_items;
    float money_left;

    scanf("%f", &money);
    scanf("%d", &n);
    Item items[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %f", &items[i].name, &items[i].price);
    }
    int count = max_items(items, n, money, &chosen_items, &money_left);
    print_items(items, n, chosen_items, money_left);
    free(chosen_items);
    return 0;
}