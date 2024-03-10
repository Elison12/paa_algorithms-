#include <stdio.h>
#include <stdlib.h>

int First (int vetor[], int n) {

    int beg = 0;
    int end = sizeof(vetor) - 1;

    while (beg <= end) {

        int mid = beg + (end-beg)/2;

        if (vetor[mid] == n) {
            if (mid-1 >= 0 && vetor[mid-1] == n) {
               end = mid-1;
               continue;
            }
            return mid;
        }

        else if (vetor[mid] < n)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int Last (int vetor[], int n) {

    int beg = 0;
    int end = sizeof(vetor)-1;

    while (beg <= end) {

        int mid = beg + (end-beg)/2;

        if (vetor[mid] == n) {
            if (mid+1 < sizeof(vetor) &&  vetor[mid+1] == n) {
               beg = mid + 1;
               continue;
            }
            return mid;
        }

        else if (vetor[mid] < n)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

void main() {

    int vetor[] = {1, 2, 3, 9, 9, 9, 9, 10, 10, 12, 13};


    int first_index, last_index, n;
    scanf("%d", &n);


   first_index = First (vetor, n);
   last_index =  Last (vetor, n);

   if (first_index == -1 || last_index == - 1) {
       printf("Element does not exist");
   } else {
       printf("First occurrence of is at index : %d ", first_index);
       printf("Last occurrence of  is at index : %d", last_index);
    //    printf("Total count : %d", last_index - first_index + 1);
   }
   return 0;
}