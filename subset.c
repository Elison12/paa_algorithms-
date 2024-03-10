#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10
// Stack res;

// Stack_Init(res);

typedef struct
{
    int data[STACK_MAX];
    int size;
} Stack;


void Stack_Init(Stack *S)
{
    S->size = 0;
}



int Stack_Top(Stack *S)
{
    if (S->size == 0)
    {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    }

    return S->data[S->size - 1];
}

void Stack_Push(Stack *S, int d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

// Stack_Init(Stack &res);
Stack res;
Stack_Init(&res);

void backtrack(Stack *A, int start,  Stack *track)
{

    Stack_Push(&res, *track->data);
    for (int i = start; i < A->size; i++)
    {

        Stack_Push(track, A->data[i]);
        
        backtrack(A, i + 1, track);

  
        Stack_Pop(track);
    }
}


Stack subsets(Stack *A)
{
    // vector<int> subset;
    Stack track;

    Stack_Init(&track);
    backtrack(A, 0, &track);
 
    return res;
}



int main()
{
    Stack A;
    // int *p;
    // Stack p;
    // Stack resultados;
    // Stack comb;


    Stack_Init(&A);
    // Stack_Init(&resultados);
    // Stack_Init(&comb);

    Stack_Push(&A, 1);
    Stack_Push(&A, 2);
    Stack_Push(&A, 3);

    // subset(&A, &resultados, &comb, index);
    // subsets(&A);

    // for (int i = 0; i < p.size; i++)
    // {
    //     printf("%d", &p.data[i]);
    // }
    return 0; 
}
