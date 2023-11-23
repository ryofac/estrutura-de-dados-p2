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

    // Percorre a frase inteira, colocando na pilha e na fila
    for(int i = 0; frase[i] != '\0'; i++){
        char actualChar = toupper(frase[i]);
        stackValue(actualChar, invertido);
        enqueue(normal, actualChar);
    }

    // Nesse momento é feita a análise dos elementos da pilha e da fila e analisa se são iguais
    for(int i = 0; frase[i] != '\0'; i++){
        if(popValue(invertido) != dequeue(normal)){
            printf("Não é palíndromo\n");
            return -1;
        }
    }

    // Se eu cheguei aqui, a pilha e fila devem guardar valores iguais
    printf("A cadeia é palíndroma\n");

    

}