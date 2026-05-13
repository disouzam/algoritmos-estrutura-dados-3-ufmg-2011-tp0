/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* TAD bignum: declarações                           */
/*                                                   */
/*****************************************************/

#ifndef BIGNUM_H
#define BIGNUM_H

#include <stdlib.h>
#include <stdio.h>

#include "digit.h"
#include "list.h"


//BIGNUM é um alias para o struct bignum.
typedef struct bignum BIGNUM;

struct bignum
{
	LIST* list_num;
	char sign;
}; // struct bignum

//COnsttrutor e destrutor
		//Construtor para o struct bignum
		BIGNUM* criar();

		//Destrutor para o TAD bignum;
		void destruir(BIGNUM** b);




//Leitura e escrita de instâncias de bignum
		//Rotina para ler uma variável BIGNUM a partir do prompt do console
		void ler_tela(BIGNUM* b);

		void ler_texto(FILE* infile, BIGNUM* b);

		void escrever_texto(FILE* outfile, BIGNUM* b);
		
		// Imprime o número armazenado em bignum na tela usando o ponto como separador de milhar. 
		// Números gigantes podem requerer a impressão em múltiplas linhas.
		// O flag sci serve para selecionar a impressão ao final do número de sua versão aproximada em notação científica:
		// sci = 0                                        -> Não imprime a notação científica ao final.
		// sci = 1 ou qualquer outro valor diferente de 0 -> Imprime a notação científica ao final.
		void imprimir(BIGNUM* A, char sci);
		
		// Copia o número armazenado em B para o número A
		void copiar(BIGNUM* A, BIGNUM *B);




//Operações matemáticas
		//O valor do bignum B é somado ao valor do bignum A e o resultado fica armazenado em A
		void somar(BIGNUM* A, BIGNUM* B);

		//Realiza a subtração A - B e armazena o resultado obtido em A. B não é alterado.
		void subtrair(BIGNUM* A, BIGNUM* B);

		// Multiplica o número A pelo número B e armazena o resultado em A
		void multiplicar(BIGNUM* A, BIGNUM* B);

		// Operação de divisão inteira A / B. 
		// A >= 0 e B >0
		// Se A >= B, o resultado, armazenado na variável A, 
		// é o maior inteiro que multiplicado por B resulta em um número menor ou igual a A
		// Se A < B, o resultado é igual a 0.
		void dividir(BIGNUM* A, BIGNUM* B);

		// Altera o sinal de A, fazendo A = -A
		void negativo (BIGNUM* A);

		//Determina qual módulo é maior. 
		//Retorna 1 se |A| >= |B|
		//Retorna 0 se |A| < |B|
		int maior_modulo(BIGNUM* A, BIGNUM* B);

		//Converte um número do tipo unsigned long int
		void long_to_big(BIGNUM* A, unsigned long int b);

		//Função para verificar igual entre A e B
		// Se A == B, retorna 1;
		// Se A != B, retorna 0;
		int igual (BIGNUM* A, BIGNUM* B);

		//Retorna 1 se A for igual a 0
		//Retorna 0 se A for não nulo
		int nulo(BIGNUM* A);

		// Função fatorial
		// Se A = 0 ou A = 1, retorna 1
		// Caso contrário procede ao cálculo iterativo
		void fatorial(BIGNUM* A);

		// Calcula a combinação entre dois números.
		// Combinação (A, B) = fatorial (A) / (fatorial (B) * fatorial (A - B))
		// A e B maiores que zero. A > B
		void combinacao(BIGNUM* A, BIGNUM * B);

#endif // BIGNUM_H
