#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pilha.h"

const DEBUG = false;

int main() {
    // Obter um input do usuário:
    char frase[100];
    printf("Enter a phrase: \n");
    fgets(frase, sizeof(frase) - 1, stdin);
    Stack myStack = {0, (int *) malloc(sizeof(10))};

    char novaFrase[100] = "";       
    for (int i = 0; frase[i] != '\0'; i++) {
        char actualChar = frase[i];
        if (DEBUG) printf("Caractere: [%c]\n", actualChar);
        if (actualChar != ' ' && actualChar != '\n') {
            // printf("Colocando na pilha: %c\n", actualChar);
            stackValue(actualChar, &myStack);
            // printStack(&myStack);
        } else {
            // Hora de desempilhar, formando uma palavra e adicionando na novaFrase.
            if (DEBUG) printf(">> Time to unpack <<\n");
            if (DEBUG) printf("Stack size: %d\n", myStack.top + 1);
            while (!isEmpty(&myStack)) {
                char _char[2] = {popValue(&myStack), '\0'};
                if (DEBUG) printf("Concatenating the character [%c].\n", _char[0]);
                strcat(novaFrase, _char);
            }
            // Adiciona espaço
            strcat(novaFrase, (char *) " ");
            if (DEBUG) printf("Nova frase: %s\n", novaFrase);
        }
    }

    // No fim de tudo, teremos uma string composta por palavras invertidas, porém com um espaço extra sobressalente.
    if (DEBUG) printf("Successfully formed sentence.\n");
    printf("%s", novaFrase);
    return 0;
}