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

bool inserir(ITEM item, LISTA *l) {
  NO *pNovo = criarNo(item, NULL, l->cabeca);
  if (l->tamanho == 0) {
    l->cabeca = pNovo;
    pNovo->prox = NULL;
    pNovo->ant = NULL;
    l->cauda = pNovo;
    l->tamanho++;
  } else if (l->tamanho == 1) {
    if (l->cabeca->item < item) {
      l->cabeca->prox = pNovo;
      l->cauda = pNovo;
      pNovo->prox = NULL;
      pNovo->ant = l->cabeca->prox;
      l->tamanho++;
    } else {
      NO *noAux;
      noAux = l->cabeca;
      l->cabeca = pNovo;
      pNovo->ant = NULL;
      pNovo->prox = noAux;
      l->tamanho++;
    }
  } else if (l->cauda->item < item) {
    pNovo = criarNo(item, l->cauda, NULL);
    l->cauda->prox = pNovo;
    l->cauda = pNovo;
    l->tamanho++;
  } else {
    NO *noAnterior;
    NO *noPosterior;
    NO *cabeca = l->cabeca;

    while (cabeca->prox != NULL) {
      if (noAnterior->item < item && noPosterior->item > item) {
        NO *novoNo = criarNo(item, noAnterior, noPosterior);
        noPosterior->ant = novoNo;
        noAnterior->prox = novoNo;
        l->tamanho++;
      }

      noAnterior = cabeca;
      cabeca = cabeca->prox;
      noPosterior = cabeca;
      printf("%d | %d | %d\n", noAnterior->item, cabeca->item,
             noPosterior->item);
    }
  }
  return false;
}

bool inserirNoFinal(ITEM item, LISTA *l) {

  NO *noAux = l->cauda;
  l->cauda->prox = criarNo(item, l->cauda, NULL);
  l->cauda = l->cauda->prox;
  return true;
}

int buscar(ITEM item, LISTA *l) {
  NO *p = l->cabeca;
  int pos = 0;
  while (p) 
  {
    if (igual(item, p->item))
      return pos;
    p = p->prox;
    pos++;
  }
  return -1; 
}

void limpar(LISTA *l) {
  NO *atual = l->cabeca;
  while (atual) 
  {
    NO *prox = atual->prox; 
    free(atual);            
    atual = prox;
  }
  l->cabeca = NULL;
  l->tamanho = 0;
}

bool removerDaPos(ITEM *item, int i, LISTA *l) {
  NO *noCabeca = l->cabeca->prox;
  NO *noAnterior;
  NO *noProximo;

  int j = 0;

  while (noCabeca) {
    if (i - 1 == j) {
      noAnterior->prox = noProximo;
      noProximo->ant = noAnterior;
      item = &noCabeca->item;
      return true;
    }

    noCabeca = noCabeca->prox;
    noAnterior = noCabeca->ant;
    noProximo = noCabeca->prox;
    j++;
  }
}

void inverter(LISTA *l) {
  NO *noAux = NULL;
  NO *noAnterior = NULL;
  NO *cabeca = NULL;
  NO *percorreLista = l->cabeca;

  LISTA *lista = (LISTA *)malloc(sizeof(ITEM) * l->tamanho);

  while (percorreLista != NULL) {
    if (lista->tamanho == 0) {
      noAux = criarNo(percorreLista->item, NULL, NULL);
      cabeca = noAux;
      lista->cabeca = noAux;
      lista->cauda = noAux;
      lista->tamanho++;
    } else {
      noAux = criarNo(percorreLista->item, NULL, NULL);
      lista->cabeca = noAux;
      noAux->prox = cabeca;
      cabeca = noAux;
    }
    percorreLista = percorreLista->prox;
  }

  l->cabeca = lista->cabeca;
}

void destruir(LISTA *l) { limpar(l); }

void exibirItem(ITEM i) { printf("%d", i); }

int main(){
    return 0;
}
