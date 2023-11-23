#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

// Retorna o número caso certo, se não -1
int isOpenChar(char candidato) {
    int numberASCII = (int) candidato ;
    if(numberASCII == 40 || numberASCII == 123 || numberASCII == 91){
        return numberASCII;
    }
    return -1;
}

int isCloseChar(char candidato){
    int numberASCII = (int) candidato ;
    if(numberASCII == 41 || numberASCII == 125 || numberASCII == 93){
        return numberASCII;
    }
    return -1;

}

bool they_close(int openable, int closeable){
    int openables[] = {40, 123, 91};
    int closeables[] = {41, 125, 93};

    for(int i = 0; i < 3; i++){
        if(openables[i] == openable && closeables[i] == closeable) return true;
    }

    return false;
}


int main(){

    Stack* openStack = createStack(10);
    int pos = 0;
    char teste[23] = "while (((m < (n[8]+p)))))";
    
    for(int i = 0; teste[i] != '\0'; i++){
        char actualChar = teste[i];
        pos++;

        if((isOpenChar(actualChar)) != -1 ){
            // Se o caractere for de abertura, guardar
            stackValue((int) actualChar, openStack);
            printStack(openStack);
        }

        if(isCloseChar(actualChar) != -1){
            if (they_close(getTopValue(openStack), (int) actualChar)) {
                printf("Deu certo, popando o da pilha \n");
                popValue(openStack);
            } else{
                printf("ERRO: o caractere %c na posição %d não fechou \n", actualChar, pos);
                return -1;
            }

        }

    }
    !isEmpty(openStack) ?  printf("Deu errado \n") : printf("Deu certo \n");
    return 0;
}