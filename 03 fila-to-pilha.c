#include <stdio.h>
#include "fila.h"
#include <stdlib.h>

typedef struct pilha{
    Queue *a;
    Queue *b;

} Pilha;

Pilha * criarPilha(int tamanho_max){
    Pilha * novaPilha = (Pilha *) malloc(sizeof(Pilha));
    novaPilha->a = create_queue(tamanho_max);
    novaPilha->b = create_queue(tamanho_max);
    return novaPilha;
}

void insertInto(int value, Pilha* abroba){
    Queue *escolhida = is_empty(abroba->a)? abroba->a : abroba->b;
    Queue *outra = escolhida == abroba->a? abroba->b : abroba->a;

    // Coloco o valor antes e depois vou colocando o resto guardado
    enqueue(escolhida, value);
    while (!is_empty(outra)){
        enqueue(escolhida, dequeue(outra));
    }
}

int pop(Pilha *p){
    if(is_empty(p->a) && is_empty(p->b)) exit(1);
    Queue *escolhida = !is_empty(p->a)? p->a : p->b;
    return dequeue(escolhida);
}

void printStack(Pilha* stack) {
    Pilha *outraStack = stack;
    printf("Printando Stack \n");
    int counter = 0;
    int valor_retirado;
    do{
        valor_retirado = pop(outraStack);
        printf("%d \n", valor_retirado);

    }
    while (valor_retirado != -1);
}

int main(){
    Pilha *appendpop = criarPilha(10);
    insertInto(10, appendpop);
    insertInto(11, appendpop);
    insertInto(12, appendpop);
    pop(appendpop);
    insertInto(121456792, appendpop);


    printStack(appendpop);
    printf("ASDASDAsd000");
    
    return 0;
}