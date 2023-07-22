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

int main(){
    

    return 0;
}