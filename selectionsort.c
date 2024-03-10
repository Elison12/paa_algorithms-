typedef struct
{
    int n;
    int *elements;
} t_vector;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(t_vector array)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < array.n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < array.n; j++)
          if (array.elements[j] < array.elements[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&array.elements[min_idx], &array.elements[i]);
    }
}

// 5 5 1 3 4 2
//   1 5 3 4 2 M  0
//   1 3 5 4 2 C  1
//   1 3 4 5 2 M  2
//   1 3 4 2 5 C  3
//   1 3 2 4 5 M  4
//   1 2 3 4 5 C  5



int main()
{

    int entrada;
    do
    {
        scanf("%d", &entrada);
        t_vector vetor;

        if (entrada == 0)
        {
            break;
        }
        vetor.n = entrada;

        vetor.elements = (int *)malloc((vetor.n + 1) * sizeof(int));
        for (int i = 0; i < vetor.n; i++)
        {
            scanf("%d", &(vetor.elements[i]));
        }

        selectionSort(vetor);
    } while (entrada != 0);

    return 0;
}