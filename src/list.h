#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

#include "digit.h"

#define TRUE 1
#define FALSE 0

//LISTptr é um alias para um ponteiro que aponta para o struct list.
typedef struct list* LISTptr;

//Construtor: Aloca memória para o struct list e retorna o ponteiro para um list vazio.
LISTptr create_list ();

//Destrutor: Libera a memória alocada para o struct list.
void destruir_list(LISTptr l);

//Função auxiliar: apaga o dígito apontado pelo ponteiro er.
void erase_digit(LISTptr* l, DIGITptr* er);

//Altera o valor do ponteiro first_ para um novo endereço de memória.
void set_first(LISTptr l, DIGITptr new_first);

//Altera o valor do ponteiro last_ para um novo endereço de memória.
void set_last(LISTptr l, DIGITptr new_last);

//Altera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
void set_size(LISTptr l, long int new_size);

//Recupera o endereço de memória do primeiro dígito do struct list
DIGITptr get_first (LISTptr l);

//Recupera o endereço de memória do último dígito do struct list
DIGITptr get_last (LISTptr l);

//Recupera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
long int get_size (LISTptr l);

//Insere um dígito no início da lista encadeada.
void insert_begin(LISTptr l, char d);

//Insere um dígito no final da lista encadeada.
void insert_end(LISTptr l, char d);

//Copia a lista A para a lista B. Todos os dados armazenados na lista B são perdidos. A lista A não é alterada.
void copyAtoB(LISTptr A,  LISTptr B);

//Imprime a lista na tela usando o ponto como separador de milhar. 
//Números gigantes podem requerer a impressão em múltiplas linhas.
//O flag sci serve para selecionar a impressão ao final do número de sua versão aproximada em notação científica:
// sci = 0                                        -> Não imprime a notação científica ao final.
// sci = 1 ou qualquer outro valor diferente de 0 -> Imprime a notação científica ao final.
void print_list(LISTptr l, char sci);

#endif // LIST_H
