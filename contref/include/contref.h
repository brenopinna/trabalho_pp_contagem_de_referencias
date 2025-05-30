#pragma once

#include <stdio.h>

// fiz o uso dessa macro aqui pra não ficar cheio de **&((()(&&&&*))) no código principal...
#define atrib2(v, w) atrib((void**)&v, w)

// Contém informações sobre um espaço de memória alocado com malloc2.
typedef struct Block {
  /// Quantidade de ponteiros que estão referenciando este bloco.
  int references;
  /// Endereço apontado por esse bloco.
  void *address;
  /// Bloco anterior
  struct Block *prev;
  /// Bloco posterior
  struct Block *next;
} Block;

/**
* Aloca size bytes de memória com o algoritmo de coleta por contagem de referência embutido.
* @param size Tamanho em bytes do espaço a ser alocado.
*
* @return Ponteiro para o espaço alocado.
*/
void *malloc2(size_t size);

/**
* Imprime os blocos de memória alocadas com malloc2.
*/
void dump();

/**
* Retorna a struct Block que contém o ponteiro para o endereço p.
* @param p Endereço cujo bloco alocado será retornado.
*
* @return Ponteiro para o bloco alocado correspondente ao endereço p.
*/
Block *search_block_lookup(void *p);

/**
* @brief Atribui um endereço a um ponteiro.
*
* Vai alterar as informações necessárias dos blocos relativos aos endereços passados como parâmetros.
* @param destination Endereço do ponteiro que irá receber source.
* @param source Endereço que passará a ser referenciado por destination.
*
* @return Ponteiro para a região alocada
*/
void atrib(void **destination, void *source);