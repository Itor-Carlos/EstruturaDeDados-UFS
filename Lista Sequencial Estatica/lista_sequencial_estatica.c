
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LISTA_SEQ_ESTATICA

#define MAX 1000

typedef int ITEM;

typedef struct {
  ITEM itens[MAX];
  int tamanho;
} LISTA;

int main()
{
    //printf("Hello World");

    return 0;
}



char compare(ITEM x, ITEM y) { return x > y ? 1 : (x < y ? -1 : 0); }

bool igual(ITEM x, ITEM y) { return compare(x, y) == 0; }

void inicializar(LISTA *l) { l->tamanho = 0; }

int tamanho(LISTA *l) { return l->tamanho; }

bool cheia(LISTA *l) { return tamanho(l) == MAX; }

bool vazia(LISTA *l) { return tamanho(l) == 0; }

bool inserir(ITEM item, LISTA *l) {
  if (tamanho(l) == MAX)
    return false; // lista cheia
  else
    l->itens[l->tamanho++] = item;
  return true;
}

int buscarEm(ITEM item, int inicio, int fim, LISTA *l) {
  for (int i = inicio; i < fim; i++) {
    if (igual(item, l->itens[i]))
      return i;
  }
  return -1;
}

ITEM enesimo(int n, LISTA *l) {
  if (n >= 0 && n < tamanho(l))
    return (l->itens[n]);
  else
    exit(EXIT_FAILURE);
}

bool alterar(ITEM item, int pos, LISTA *l) {
  if (pos >= 0 && pos < tamanho(l)) {
    l->itens[pos] = item;
    return true;
  }
  return false;
}

bool inserirNaPos(ITEM item, int i, LISTA *l) {
  // A posicao tem que estar entre 0 e MAX-1 e ate o tamanho atual
  if ((tamanho(l) >= MAX) || (i < 0) || (i > tamanho(l)))
    return false; // lista cheia ou indice invalido

  // Se for inserido no meio, e necessario abrir espaco para o item
  for (int j = tamanho(l); j > i; j--)
    l->itens[j] = l->itens[j - 1];

  // Coloca o item em um espaco vago e ajusta o tamanho
  l->itens[i] = item;
  l->tamanho++;
  return true;
}

bool remover(ITEM item, LISTA *l) {
  int i, j;
  for (i = 0; i < tamanho(l); i++)
    if (igual(item, l->itens[i])) {
      for (j = i; j < l->tamanho - 1; j++)
        l->itens[j] = l->itens[j + 1];

      l->tamanho--;
      return true; // achou
    }
  return false; // nao achou
}

bool inserirComeco(ITEM item, LISTA *l) {
  int i, j = 0;
  ITEM aux = 0;
  if ((tamanho(l) >= MAX) || (i < 0) || (i > tamanho(l)))
    return false;
  for (i = l->tamanho - 1; i >= 0; i--) {
    l->itens[i + 1] = l->itens[i];
  }
  l->tamanho++;
  l->itens[0] = item;
  return true;
}

void exibirItem(ITEM i) { printf("%d", i); }

void exibirLista(LISTA *l) {
  printf("[");
  for (int i = 0; i < tamanho(l);) {
    exibirItem(l->itens[i++]);
    if (i < tamanho(l))
      printf(",");
  }
  printf("]");
}

bool removerDaPos(ITEM *item, int i, LISTA *l) {
  ITEM aux;
  if (i > l->tamanho || i < 0) {
    return false;
  } else {
    aux = l->itens[i];
    for (int j = i; j > 0; j--) {
      l->itens[j] = l->itens[j - 1];
    }
    l->tamanho--;
    return true;
  }
}

void reversa(LISTA *l) {
  ITEM itens[l->tamanho];
  int j = l->tamanho - 1;
  for (int i = 0; i < l->tamanho; i++) {
    itens[i] = l->itens[j];
    j--;
  }
  for (int i = 0; i < l->tamanho; i++) {
    l->itens[i] = itens[i];
  }
}

void exibirListaReversa(LISTA *l) {
  printf("[");
  for (int i = l->tamanho - 1; i >= 0; i--) {
    printf("%d", l->itens[i]);
    if (i > 0)
      printf(",");
  }
  printf("]");
}

void limpar(LISTA *l) { l->tamanho = 0; }

void destruir(LISTA *l) { limpar(l); }

