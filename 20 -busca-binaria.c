#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *listaEntre(int tamanho, int min, int max){
    int *lista = (int *) malloc(sizeof(int) * tamanho);
    for(int i = 0; i < tamanho; i++){
        lista[i] = rand() % (max - min + 1) + min;
    }
    return lista;

}

int binary_search(int x, int v[], int p, int u){
    while (p <= u)
    {
        int m = (p + u) / 2;
        if(v[m] == x) return 1;
        if( x < v[m]) u = m - 1;
        else p = m + 1;
    }
    
    return 0;
    

}

int main(){
    int vetor[] = {10, 32, 45, 54, 100};
    if(binary_search(31, vetor, 0, 4)){
        printf("Nunca fui triste \n");
    }


}