#include <stdio.h>

int mergeArrays(int arrA[], int arrB[], int la, int lb)
{

    int mergedArray[la + lb];

    int i = 0, j = 0, k = 0;

    while (i < la && j < lb)
    {
        if (arrA[i] < arrB[j])
        {
            mergedArray[k] = arrA[i];
            i++;
            k++;
        }
        else
        {
            mergedArray[k] = arrB[j];
            j++;
            k++;
        }
    }

    while (i < la)
    {
        mergedArray[k] = arrA[i];
        i++;
        k++;
    }

    while (j < lb)
    {
        mergedArray[k] = arrB[j];
        j++;
        k++;
    }

    // return *mergedArray;

    for (int i = 0; i < la + lb; i++)
    {
        printf("%d\n", mergedArray[i]);
    }
}

int main()
{
    int lenA, lenB;

    scanf("%d", &lenA);
    scanf("%d", &lenB);

    int A[lenA];
    int B[lenB];

    for (int i = 0; i < lenA; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < lenB; i++)
    {
        scanf("%d", &B[i]);
    }

    mergeArrays(A, B, lenA, lenB);

    return 0;
}
