#include "contref.h"
#include <stdlib.h>

typedef struct List {
  int x;
  struct List *next;
  struct List *prev;
} List;

List *list_head = NULL;
void new_node(int x) {
  List *new = malloc2(sizeof(List));
  new->x = x;
  // Bloco 1: atribuicoes normais da insercao em lista duplamente encadeada circular
  if (!list_head) {
    // se a cabeca for nula, prev e next apontam pra ele mesmo
    atrib2(new->next, new);
    atrib2(new->prev, new);
  } else {
    // se a cabeca nao for nula: (atribuicoes normais da insercao nesse tipo de lista)
    atrib2(new->next, list_head); // o next do novo no vai apontar pra atual cabeca
    atrib2(list_head->prev, new); // o prev da atual cabeca vai apontar pro novo no
    atrib2(new->prev, list_head->next); // o prev do novo no vai apontar pro next da atual cabeca
    atrib2(list_head->next->next, new); // o next do next da atual cabeca vai apontar para o no atual
  }
  // Bloco 2: ajustando os ponteiros para manter o algoritmo consistente
  atrib2(list_head, new); // o ponteiro para a cabeca agora vai apontar para o novo no
  atrib2(new, NULL); // remove a referencia a esse novo no, uma vez que esse ponteiro eh local a funcao new_node
}

void remove_node(List *node) {
  if (node) {
    // Bloco 1: atribuicoes normais da remocao de elemento de lista duplamente encadeada circular
    atrib2(node->next->prev, node->prev);
    atrib2(node->prev->next, node->next);
    // Bloco 2: bloco que vai remover as referencias de outros ponteiros, para manter o algoritmo com
    // a contagem correta e liberar o ponteiro a ser removido
    atrib2(node->next, NULL);
    atrib2(node->prev, NULL);
    atrib2(node, NULL);
  }
}

int main() {
  int *v = malloc2(sizeof(int));
  *v = 10;
  int *w = malloc2(sizeof(int));
  *w = 20;
  dump();
  atrib2(v, w);
  dump();
  char *c = malloc2(sizeof(char));
  *c = 'Z';
  dump();
  atrib2(w, NULL);
  dump();
  atrib2(c, NULL);
  atrib2(v, NULL);
  dump();

  new_node(1);
  new_node(2);
  new_node(3);

  dump();

  remove_node(list_head);
  /*
    o elemento que referenciava a lista se foi, mas o lixo nao!!
    entao ainda existem blocos alocados, porem que nao sao mais
    acessiveis ao meu programa
  */

  dump();

  return 0;
}