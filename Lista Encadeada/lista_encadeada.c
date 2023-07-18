#include <stdio.h>

typedef struct estrutura{
  int item;
  struct estrutura *prox;
} NO;

typedef struct {
    NO* cabeca;
    int tamanho;
} LISTA_ENCADEADA;