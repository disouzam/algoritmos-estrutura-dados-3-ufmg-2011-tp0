/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* TAD list: declarações                             */
/*                                                   */
/*****************************************************/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

#include "digit.h"


//LIST é um alias para o struct list.
typedef struct list LIST;

//Construtor e destrutor
		//Construtor: Aloca memória para o struct list e retorna o ponteiro para um list vazio.
		LIST* create_list ();

		//Destrutor: Libera a memória alocada para o struct list.
		void destruir_list(LIST** l);
		
		
		
// Funções de acesso
		//Recupera o endereço de memória do primeiro dígito do struct list.
		DIGIT* get_first (LIST* l);

		//Recupera o endereço de memória do último dígito do struct list
		DIGIT* get_last (LIST* l);

		//Recupera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
		unsigned long int get_size (LIST* l);
		
		
		
//Funções de manipulação
		//Altera o valor do ponteiro first_ para um novo endereço de memória.
		void set_first(LIST* l, DIGIT* new_first);

		//Altera o valor do ponteiro last_ para um novo endereço de memória.
		void set_last(LIST* l, DIGIT* new_last);

		//Altera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
		void set_size(LIST* l, unsigned long int new_size);

		//Insere um dígito no início da lista encadeada.
		void insert_begin(LIST* l, char d);

		//Insere um dígito no final da lista encadeada.
		void insert_end(LIST* l, char d);

		//Função auxiliar: apaga o dígito apontado pelo ponteiro er (aponta para um ponteiro do tipo DIGIT).
		void erase_digit(LIST* l, DIGIT** er);

		//Limpa a lista completamente e a deixa vazia.
		void clear_list(LIST* l);

		//Copia a lista A para a lista B. Todos os dados armazenados na lista B são perdidos. A lista A não é alterada.
		void copyAtoB(LIST* A,  LIST* B);


//Imprime a lista na tela usando o ponto como separador de milhar. 
//Números gigantes podem requerer a impressão em múltiplas linhas.
void print_list(LIST* l);

#endif // LIST_H
