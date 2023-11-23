#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lista-encadeada.h"



// OBS Essa é a questão 9.5
int soma(Lista* lista){
    if(lista == NULL) return 0;
    return lista->item + soma(lista->prox);
}



// OBS Essa é a questão 9.6
Lista* substitui(int item1, int item2, Lista* lista) {
    if (lista == NULL) return NULL;

    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->item = lista->item;

    if (lista->item == item1) {
        novaLista->item = item2;
    }

    novaLista->prox = substitui(item1, item2, lista->prox);

    return novaLista;
}

// OBS Essa é a questão 9.7
int igual(Lista *A, Lista *B){
    if(A == NULL) return 1;
    if(A->item == B->item){
        return igual(A->prox, B->prox);
    } else{
        return 0;
    }


}

// OBS Essa é a questão 9.8
int enesimo(int n, Lista *lista){
    if(lista == NULL) return -1;
    if(n == 0) return lista->item;
    return enesimo(n-1, lista->prox);
}

int main(){
    Lista* lista = no(3, no(1, no(5, no(4, NULL))));
    Lista* lista2 = no(5, no(1, no(5, no(4, NULL))));
    if(igual(lista2, lista)){
        printf("Sou feliz \n");
    }
    lista = substitui(4, 10, lista);
    printf("Soma: %d\n", soma(lista));



}