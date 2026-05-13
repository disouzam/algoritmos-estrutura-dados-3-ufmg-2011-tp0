#ifndef DIGIT_H
#define DIGIT_H

#include <stdlib.h>
#include <stdio.h>

//DIGITptr é um alias para um ponteiro que aponta para o struct digit.
typedef struct digit* DIGITptr;

//Construtor: Aloca memória para o struct digit e retorna o ponteiro para um digit inicializado.
DIGITptr create_digit();

//Destrutor: Libera a memória alocada pelo construtor.
void destruir_digit (DIGITptr* f);

//Altera o valor armazenado em dig_.
void set_dig (DIGITptr d, char new_d);

//Altera o valor armazenado em previous_.
void set_previous (DIGITptr d, DIGITptr new_previous);

//Altera o valor armazenado em next_.
void set_next (DIGITptr d, DIGITptr new_next);

//Recupera o valor armazenado em dig_;
char get_dig (DIGITptr d);

//Recupera o valor armazenado em previous_;
DIGITptr get_previous(DIGITptr d);

//Recupera o valor armazenado em next_;
DIGITptr get_next(DIGITptr d);

//Impressão dos valores armazenados no TAD digit. 
//Função criada para fins de depuração e/ou observação do comportamento dos TAD's dependentes.
void print_info(DIGITptr d);

#endif // DIGIT_H
