#include <stdio.h>
#include <ctype.h>
#include "fila.h"
#include "pilha.h"

#define VALOR_BUFFER 256

int main(){
    Stack* invertido = createStack(VALOR_BUFFER);
    Queue* normal = create_queue(VALOR_BUFFER);

    char frase[VALOR_BUFFER];

    printf("Digite uma frase: ");

    scanf("%[^\n]s", frase);

    for(int i = 0; frase[i] != '\0'; i++){
        char actualChar = toupper(frase[i]);
        stackValue(actualChar, invertido);
        enqueue(normal, actualChar);
    }

    for(int i = 0; frase[i] != '\0'; i++){
        if(popValue(invertido) != dequeue(normal)){
            printf("Não é palíndromo\n");
            return -1;
        }
    }


    printf("A cadeia é palíndroma\n");

    

}