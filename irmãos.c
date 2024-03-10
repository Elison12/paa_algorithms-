#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int size, i, falta = 0, atual = 0, irmaos = 0;
    scanf("%d", &size);
    int coins[size];

    for (i = 0; i < size; i++) {
        scanf("%d", &coins[i]);
        irmaos += coins[i];
    }

    qsort(coins, size, sizeof(int), compare);

    for (i = 0; i < size; i++) {
        if (atual > irmaos) {
            break;
        }
        falta++;
        atual += coins[i];
        irmaos -= coins[i];
    }

    printf("%d\n", falta);
    return 0;
}
