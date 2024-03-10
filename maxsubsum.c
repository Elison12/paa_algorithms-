#include <stdio.h>

int maxsubsum(int sequencia[], int tamanhoSequencia) {
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < tamanhoSequencia; i++) {
        currentSum = 0;
        for (int j = i; j < tamanhoSequencia; j++) {
            currentSum = currentSum + sequencia[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}


float maxsubmul(float sequencia[], int tamanhoSequencia){
    //ta errado!
    float maxSum = 0;
    float currentSum;

    for (int i = 0; i < tamanhoSequencia; i++) {
        currentSum = 1;
        for (int j = i; j < tamanhoSequencia; j++) {
            currentSum = currentSum * sequencia[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}


int main() {
    int arr[6] = {-1, 3, -2, 3, -2, -1};
    float vector[9] = {-1, 1/2, 4, -1/3, 1/2, -6, 1/4, 5, 1/4};
    float lista[4] = {2, 0.5, 3, 5};
    float listaula[4] = {1, 0.5, 2, 0.2};
    // printf("%i", maxsubsum(arr, 6));
    // printf("%f", maxsubmul(lista, 4));
    printf("%f", maxsubmul(listaula, 4));
    return 0;
}
