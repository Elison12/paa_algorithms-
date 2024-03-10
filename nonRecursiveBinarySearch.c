#include <stdio.h>
#include <conio.h>
void main()
{
    int a[10], i, n, key, low, high, mid;
    //  clrscr();
    printf("Digites os elementos do vetor em ordem crescente");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("digite um valor\n");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (high >= low)
    {
        mid = (low + high) / 2;
        if (key == a[mid])
            break;
        else
        {
            if (key > a[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    if (key == a[mid])
        printf("O valor foi encontrado na posicao %d", mid + 1);
    else
        printf("N existe no vetor");
    getch();
}