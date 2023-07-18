#include <stdio.h>

typedef struct estrutura{
  int item;
  struct estrutura *prox;
} NO;

typedef struct {
    NO* cabeca;
    int tamanho;
} LISTA_ENCADEADA;

void inserir(LISTA_ENCADEADA *lista, int item){
    lista->cabeca = criarNo(item, lista->cabeca);
    lista->tamanho++;
}

void inicializar(LISTA_ENCADEADA *lista){
    lista->cabeca = NULL;
    lista->tamanho = 0;
}