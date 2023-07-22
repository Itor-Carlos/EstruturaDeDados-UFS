#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ITEM;

typedef struct estrutura {
  ITEM item;
  struct estrutura *prox;
} NO;

typedef struct {
  NO *cabeca;
  NO *cauda;
  int tamanho;
} LISTA;

void exibirItem(ITEM i) { printf("%d", i); }

void exibirLista(LISTA *l) {
  printf("[");
  NO *p = l->cabeca;
  while (p) // p != NULL
  {
    exibirItem(p->item);
    if (p->prox)
      printf(",");
    p = p->prox;
  }
  printf("]");
}

int main(){
    

    return 0;
}