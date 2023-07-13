#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int ITEM;

typedef struct {
  ITEM *itens;
  int tamanho;
  int capacidadeMaxima;
} LISTA_DINAMICA;


char compare(ITEM x, ITEM y) { return x > y ? 1 : (x < y ? -1 : 0); }
void inicializarListaDinamica(LISTA_DINAMICA *lista) { lista->tamanho = 0; }

void inicializarListaDinamica(LISTA_DINAMICA *lista, int tamanho) {
  lista->itens = (ITEM *)malloc(sizeof(ITEM) * tamanho);
  lista->capacidadeMaxima = tamanho;
  lista->tamanho = 0;
}

void expandirTamanhoListaDinamica(LISTA_DINAMICA *l) {
  l->itens = (ITEM *)realloc(l->itens, 2 * l->capacidadeMaxima * sizeof(ITEM));
  l->capacidadeMaxima = 2 * l->capacidadeMaxima;
}

int tamanhoListaDinamica(LISTA_DINAMICA *list) { return list->tamanho; }

bool cheiaListaDinamica(LISTA_DINAMICA *lista) { return lista->tamanho == lista->capacidadeMaxima; }

bool vaziaListaDinamica(LISTA_DINAMICA *lista) { return lista->tamanho == 0; }

bool inserirListaDinamica(ITEM item, LISTA_DINAMICA *lista) {
  if (cheiaListaDinamica(lista))
    expandirTamanhoListaDinamica(lista);
  else {
    lista->itens[lista->tamanho++] = item;
    return true;
  }
}

void exibirListaDinamica(LISTA_DINAMICA *lista) {
  printf("[");
  for (int i = 0; i < lista->tamanho; i++) {
    if (i == lista->tamanho - 1)
      printf("%d", lista->itens[i]);
    else
      printf("%d,", lista->itens[i]);
  }
  printf("]");
}

int buscarListaDinamica(ITEM item, LISTA_DINAMICA *l) {
  for (int i = 0; i < l->tamanho; i++) {
    if (compare(item, l->itens[i]) == 0) {
      return i;
    }
  }
  return -1;
}

bool alterarListaDinamica(ITEM item, int pos, LISTA_DINAMICA *l) {
  if (pos > l->tamanho || pos < 0)
    return false;
  *l->itens[pos] = item;
}

int buscarEmListaDinamica(ITEM item, int inicio, int fim, LISTA_DINAMICA *l) {
  for (int i = inicio; i < fim; i++) {
    if (compare(item, l->itens[i]) == 0) {
      return i;
    }
  }
  return -1;
}

void limparListaDinamica(LISTA_DINAMICA *l) {
  for (int i = 0; i < l->tamanho; i++) {
    free(l->itens[i]);
    printf("%d\n", l->itens[i]);
    l->tamanho--;
  }
}

bool removerListaDinamica(ITEM item, LISTA_DINAMICA *l) {}

bool inserirListaDinamicaNaPos(ITEM item, int i, LISTA_DINAMICA *l) {}


void reversaListaDinamica(LISTA_DINAMICA *lista) {
  int i, j;
  ITEM *temp;

  for (i = 0, j = lista->tamanho - 1; i < j; i++, j--) {
    temp = lista->itens[i];
    lista->itens[i] = lista->itens[j];
    lista->itens[j] = temp;
  }
}

int main() {
 
  return 0;
}
