#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"

int main(){
    Stack *mainStack = createStack(10);
    Stack *auxStack = createStack(10);

    // Pegando inputs:
    int quantidade;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &quantidade);

    int lista[quantidade];

    for(int i = 0; i < quantidade; i++){
        int valor;
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valor);
        lista[i] = valor;
    }

    for(int i = 0; i < quantidade; i++){
        int atual = lista[i];
        int anterior = lista[i-1];

        // Primeira inserção
        if( i == 0 ) {
            stackValue(atual, mainStack);
        }
        else {
            // Se o atual é menor que o anterior: Adcionar na pilha auxiliar
            while(getTopValue(mainStack) < atual && !isEmpty(mainStack)){
                stackValue(popValue(mainStack), auxStack);
            }
            // Nesse momento, o valor analisado pode ser colocado na stack main
            stackValue(atual, mainStack);

            // Se a pilha auxiliar estiver cheia despeje seu conteúdo na principal
            while(!isEmpty(auxStack)){
                stackValue(popValue(auxStack), mainStack);
            }
        }  
    }

    printf("Elementos ordenados:  \n");
    while(!isEmpty(mainStack)){
        int valor = popValue(mainStack);
        printf("%d ,", valor);
    }
    printf("\b \n");

    return 0;
}