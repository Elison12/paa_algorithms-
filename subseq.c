#include <stdio.h>
#include <stdlib.h>

void backtrack(int *indices, int len, char *A, int A_len, char *B, int B_len) {
    if (len == B_len) {
        // Check if current combination of characters in A equals B
        for (int i = 0; i < len; i++) {
            if (A[indices[i]] != B[i]) {
                return;
            }
        }
        
        // Print index sequence
        printf("[ ");
        for (int i = 0; i < len; i++) {
            printf("%d ", indices[i]);
        }
        printf("]\n");
    }
    else {
        // Loop through remaining indices in A
        for (int i = indices[len-1]+1; i <= A_len - (B_len - len); i++) {
            indices[len] = i;
            backtrack(indices, len+1, A, A_len, B, B_len);
        }
    }
}

int main() {
    char A[] = "abcde";
    char B[] = "bcd";
    int A_len = 5;
    int B_len = 3;
    
    // Initialize indices array
    int indices[B_len];
    indices[0] = -1;
    
    backtrack(indices, 1, A, A_len, B, B_len);
    
    return 0;
}
