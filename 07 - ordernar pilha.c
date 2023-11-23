#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"

int main(){
    Stack *mainStack = createStack(10);
    Stack *auxStack = createStack(10);

    int lista[6] = {4, 6, 2, 10, 3, 11};

    for(int i = 0; i < 6; i++){
        int atual = lista[i];
        int anterior = lista[i-1];

        // Primeira inserção
        if( i == 0 ) {
            stackValue(atual, mainStack);
            printStack(mainStack);

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

    while(!isEmpty(mainStack)){
        printf("%d \n", mainStack->data[mainStack->top]);
        popValue(mainStack);
    }


    return 0;
}