#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Ponto;

float calcDistancia (Ponto a, Ponto b) {
    float distancia = sqrt(pow(b.x - a.x, 2) + pow(b.y- a.y, 2));
    return distancia;
}

int main()
{
    int n, x, y;
    Ponto pontos[INT_MAX/10];
    
    // scanf("%d", &n);

    for (int i = 0; i < 4; i++) {
        // scanf("%d %d", &pontos[i]);
        scanf("%d", &pontos[i]);
    }

    for (int i = 0; i < 4; i++) {
        printf("%d", i);
    }
    return 0;
}