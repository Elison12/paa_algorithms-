#include <stdio.h>

int gcd(int a, int b) {
    if (a ==0) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    int result = gcd(14, 8);
    printf("O mmc de 14 e 8 eh %i", (14*8)/result);
    return 0;
}
