/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* TAD digit: declarações                            */
/*                                                   */
/*****************************************************/

#ifndef DIGIT_H
#define DIGIT_H

#include <stdlib.h>
#include <stdio.h>

//DIGIT é um alias para o struct digit.
typedef struct digit DIGIT;


//Construtor e destrutor
		//Construtor: Aloca memória para o struct digit e retorna o ponteiro para um digit inicializado.
		DIGIT* create_digit();

		//Destrutor: Libera a memória alocada pelo construtor.
		void destruir_digit (DIGIT** f);

//Funções de manipulação
		//Altera o valor armazenado em dig_.
		void set_dig (DIGIT* d, char new_d);

		//Altera o valor armazenado em previous_.
		void set_previous (DIGIT* d, DIGIT* new_previous);

		//Altera o valor armazenado em next_.
		void set_next (DIGIT* d, DIGIT* new_next);


//Funções observadoras
		//Recupera o valor armazenado em dig_;
		char get_dig (DIGIT* d);

		//Recupera o valor armazenado em previous_;
		DIGIT* get_previous(DIGIT* d);

		//Recupera o valor armazenado em next_;
		DIGIT* get_next(DIGIT* d);

#endif // DIGIT_H
