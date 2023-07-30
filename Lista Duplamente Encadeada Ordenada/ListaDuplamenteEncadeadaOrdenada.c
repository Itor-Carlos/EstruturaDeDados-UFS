#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *ant;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
    NO* cauda;
    int tamanho;
} LISTA;

void inicializar(LISTA *lista){
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->tamanho = 0;
}

int tamanhoLista(LISTA *lista){
   return lista->tamanho;
}

int main(){
    return 0;
}
