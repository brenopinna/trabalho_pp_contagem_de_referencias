#include "contref.h"
#include <string.h>
#include <stdlib.h>

// Sessão referente à lista que vai conter os blocos alocados de memória
Block *heap_head = NULL;

void insert_block(Block *new_block) {
  new_block->next = heap_head;
  if (heap_head)
    heap_head->prev = new_block;
  heap_head = new_block;
}

void remove_block(Block *block) {
  if (block == heap_head) {
    heap_head = block->next;
  }
  Block *prev = block->prev;
  Block *next = block->next;
  if (prev) prev->next = next;
  if (next) next->prev = prev;
  free(block);
}
// Fim da sessão da lista

void *malloc2(size_t size) {
  void *p = (void *)malloc(size);
  Block *region = (Block *)malloc(sizeof(Block));
  region->address = p;
  region->references = 1;
  region->prev = NULL;
  region->next = NULL;
  insert_block(region);
  return p;
}

void dump() {
  puts("-----------------new dump-----------------");
  if (!heap_head) puts("(NO CURRENT ALLOCATIONS)");
  for (Block *aux = heap_head; aux != NULL; aux = aux->next) {
    printf("ADRESS: %p  |  REFERENCES: %d\n", aux->address, aux->references);
  }
  puts("");
}

Block *search_block_lookup(void *p) {
  Block *aux = heap_head;
  while (aux && aux->address != p)
    aux = aux->next;
  return aux;
}

void atrib(void **destination, void *source) {
  if (!destination) {
    printf("Não é possível atribuir valor: destination é NULL.\n");
    return;
  }
  Block *dest_lookup = search_block_lookup(*destination);
  if (dest_lookup) {
    dest_lookup->references--;
    if (dest_lookup->references == 0) {
      remove_block(dest_lookup);
    }
  }
  Block *src_lookup = search_block_lookup(source);
  if (src_lookup) src_lookup->references++;
  *destination = source;
}
