#include <stdio.h>
#include <stdlib.h>
 
typedef struct Pilha {
    int *dados;
    int topo;
    int tamanho;
}Pilha;

 
void inicializa_pilha(struct Pilha *p, int tamanho) {
    p->dados = (int*) malloc(tamanho * sizeof(int));
    p->topo = -1;
    p->tamanho = tamanho;
}



// Utility function to return the size of the stack
int size(struct Pilha *pt) {
    return pt->topo + 1;
}
 
// Utility function to check if the stack is empty or not
int isEmpty(struct Pilha *pt) {
    return pt->topo == -1;                   // or return size(pt) == 0;
}
 
// Utility function to check if the stack is full or not
int isFull(struct Pilha *pt) {
    return pt->topo == pt->tamanho - 1;      // or return size(pt) == pt->maxsize;
}
 
// Utility function to add an element `x` to the stack
void push(struct Pilha *pt, int x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Inserting %d\n", x);
 
    // add an element and increment the top's index
    // pt->items[++pt->top] = x;
    pt->dados[++pt->topo] = x;
}
 
// Utility function to return the top element of the stack
int peek(struct Pilha *pt)
{
    // check for an empty stack
    if (!isEmpty(pt)) {
        return pt->dados[pt->topo];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to pop a top element from the stack
int pop(struct Pilha *pt)
{
    // check for stack underflow
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\n", peek(pt));
 
    // decrement stack size by 1 and (optionally) return the popped element
    return pt->dados[pt->topo--];
}

  
// int main()
// {
//     // create a stack of capacity 5
    
//     push(pt, 1);
//     push(pt, 2);
//     push(pt, 3);
 
//     printf("The top element is %d\n", peek(pt));
//     printf("The stack size is %d\n", size(pt));
 
//     pop(pt);
//     pop(pt);
//     pop(pt);
 
//     if (isEmpty(pt)) {
//         printf("The stack is empty");
//     }
//     else {
//         printf("The stack is not empty");
//     }
 
//     return 0;
// }
struct Pilha minha_pilha;
struct Pilha res;


void backtrack(Pilha *A, int start,  Pilha *track)
{

    // Stack_Push(&minha_pilha, *track->data);
    int valor = *track->dados;
    push(&minha_pilha, valor);
    for (int i = start; i < A->tamanho; i++)
    {

        push(track, A->dados[i]);
        
        backtrack(A, i + 1, track);

  
        pop(track);
    }
}


Pilha subsets(Pilha *A)
{

    struct Pilha track;
    inicializa_pilha(&track, 10); // inicializa a pilha com tamanho máximo de 100 elementos

    // Stack_Init(&track);
    inicializa_pilha(&res, 10); // inicializa a pilha com tamanho máximo de 100 elementos

    backtrack(A, 0, &track);
 
    return res;
}




int main() {
    inicializa_pilha(&minha_pilha, 10); // inicializa a pilha com tamanho máximo de 100 elementos

    push(&minha_pilha, 1);
    push(&minha_pilha, 2);
    push(&minha_pilha, 3);
    // pop(&minha_pilha);

    subsets(&minha_pilha);

    for (int i = 0; i < res.tamanho; i++) {
        for (int j = 0; j < res.dados[i]; j++) {
            printf("%d", res.dados[i]);
        }
    }
    
    // ...
    return 0;

    free(&minha_pilha);
}
