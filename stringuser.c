#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *string;
    string = malloc(30 * sizeof(char)); // Alocando 30 bytes para armazenar a string
    fgets(string, 30, stdin);           // Fazendo a leitura da string
    printf("%s\n", string);             // Imprimindo a string na tela
    free(string);                       // Liberando memória alocada
    return 0;
}