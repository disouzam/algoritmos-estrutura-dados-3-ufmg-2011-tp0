#ifndef DIGIT_H
#define DIGIT_H

#include <stdlib.h>
#include <stdio.h>

//DIGIT é um alias para o struct digit.
typedef struct digit DIGIT;

//Construtor: Aloca memória para o struct digit e retorna o ponteiro para um digit inicializado.
DIGIT* create_digit();

//Altera o valor armazenado em dig_.
void set_dig (DIGIT* d, char new_d);

//Altera o valor armazenado em previous_.
void set_previous (DIGIT* d, DIGIT* new_previous);

//Altera o valor armazenado em next_.
void set_next (DIGIT* d, DIGIT* new_next);

//Recupera o valor armazenado em dig_;
char get_dig (DIGIT* d);

//Recupera o valor armazenado em previous_;
DIGIT* get_previous(DIGIT* d);

//Recupera o valor armazenado em next_;
DIGIT* get_next(DIGIT* d);

//Destrutor: Libera a memória alocada pelo construtor.
void destruir_digit (DIGIT** f);

//Impressão dos valores armazenados no TAD digit. 
//Função criada para fins de depuração e/ou observação do comportamento dos TAD's dependentes.
void print_info(DIGIT* d);

//Função de manutenção do TAD digit. Verifica o bom funcionamento de suas funções.
void debug_digit();

#endif // DIGIT_H
