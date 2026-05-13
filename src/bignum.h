#ifndef BIGNUM_H
#define BIGNUM_H

#include <stdlib.h>
#include <stdio.h>


#include "digit.h"
#include "list.h"

//BIGNUM é um alias para o struct bignum.
typedef struct bignum BIGNUM;

//Construtor para o struct bignum
BIGNUM* criar();

//Destrutor para o TAD bignum;
void destruir(BIGNUM** b);

//Rotina para ler uma variável BIGNUM a partir do prompt do console
void ler_tela(BIGNUM* b);

void ler_texto(BIGNUM* b);

void somar(BIGNUM* A, BIGNUM* B);

void subtrair(BIGNUM* A, BIGNUM* B);

void multiplicar(BIGNUM* A, BIGNUM* B);

void dividir(BIGNUM* A, BIGNUM* B);

// Imprime o número armazenado em bignum na tela usando o ponto como separador de milhar. 
// Números gigantes podem requerer a impressão em múltiplas linhas.
// O flag sci serve para selecionar a impressão ao final do número de sua versão aproximada em notação científica:
// sci = 0                                        -> Não imprime a notação científica ao final.
// sci = 1 ou qualquer outro valor diferente de 0 -> Imprime a notação científica ao final.
void imprimir(BIGNUM* A, char sci);

//Determina qual número é maior. 
//Retorna 1 se A > B
//Retorna 0 se B < A
int maior(BIGNUM* A, BIGNUM* B);



#endif // BIGNUM_H
