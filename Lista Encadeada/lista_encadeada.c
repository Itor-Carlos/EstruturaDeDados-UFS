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

bool inserir(ITEM item, LISTA *l) {

  NO *no = criarNo(item, l->cabeca);
  NO *noAux = no;

  if (l->tamanho == 0) {
    l->cabeca = no;
    l->cauda = no;
    l->tamanho++;
    return true;
  } 
  else if (l->tamanho == 1) {
    if (item < l->cabeca->item) {
      noAux = l->cabeca;
      l->cabeca = no;
      l->cabeca->prox = noAux;
      l->tamanho++;
      return true;
    } else {
      NO* noFinal = criarNoFinal(item);
      l->cauda->prox = noFinal;
      l->cauda = noFinal;
      l->tamanho++;
      return true;
    }
  }
  else if(item > l->cauda->item){
    NO* noFinal = criarNoFinal(item);
    l->cauda->prox = noFinal;
    l->cauda = noFinal;
    l->tamanho++;
    return true;
  }

  else {
    NO *anterior = l->cabeca;
    NO *posterior = l->cabeca->prox;
    NO *cabeca = l->cabeca;

    while(cabeca != NULL){
      if (item > anterior->item && item < posterior->item) {
        anterior->prox = no;
        no->prox = posterior;
        l->tamanho++;
        return true;
      }
      anterior = cabeca;
      cabeca = cabeca->prox;
      posterior = cabeca;
    }
  }
  

  return false;
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


bool removerDaPos(ITEM item, int posicao, LISTA *lista) {
  NO *cabeca = lista->cabeca;
  NO *noAnterior = cabeca->prox;
  NO *noPosterior = cabeca->prox;

  int i = 0;
  if ((posicao > lista->tamanho) || (posicao < 0))
    return false;
  else if (posicao == 0)
    lista->cabeca = noAnterior;
  else {
    for (i = 0; i < posicao; i++) {
      if (i == posicao) {
        noAnterior->prox = noPosterior;
        lista->tamanho--;
        return true;
      }
      noAnterior = cabeca;
      cabeca = cabeca->prox;
      noPosterior = cabeca->prox;
    }
  }
}

int main(){
    

    return 0;
}