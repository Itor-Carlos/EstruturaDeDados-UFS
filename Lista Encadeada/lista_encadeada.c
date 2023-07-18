#include <stdio.h>
#include <stdbool.h>

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

void exibeLista(LISTA_ENCADEADA *lista){
    printf("[");
    NO *cabeca = lista->cabeca;
    for(int i = 0; i<lista->tamanho; i++){
        if(i == lista->tamanho-1){
            printf("%d", cabeca->item);
        }
        else{
            printf("%d,",cabeca->item);
        }
        cabeca = cabeca->prox;
    }
    printf("]");
}

bool igual(int item, int itemComparativo){
    return item == itemComparativo;
}