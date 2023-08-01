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

void exibirLista(LISTA *l) {
  printf("[");
  NO *p = l->cabeca;
  while (p) // enquando nao chegou ao final da lista
  {
    exibirItem(p->item);
    if (p->prox)
      printf(",");
    p = p->prox;
  }
  printf("]");
}

NO *criarNoVazio(ITEM item) {
  NO *no = malloc(sizeof(NO));
  no->item = item;
  return no;
}

int main(){
    return 0;
}
