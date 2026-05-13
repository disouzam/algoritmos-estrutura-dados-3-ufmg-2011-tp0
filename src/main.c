/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* Função principal para executar testes no          */
/* bignum criado                                     */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "digit.h"
#include "list.h"
#include "bignum.h"

int main(int argc , char* argv[])
{
	FILE *infile, *outfile;
	
	//Abre arquivo para leitura
	infile = fopen(argv[1],"r");
	
	char* o = argv[1];
	
	//string para nome do arquivo de saída
	char out[20];
	int j = 0;
	while (j < 20 && (*o) != '.')
	{
		out[j] = *o;
		*o++;
		j++;
	}
	
	o = &out[0];
	out[j++] ='.';
	out[j++] ='o';
	out[j++] ='u';
	out[j++] ='t';
	out[j++] ='\0';
	
	j = 0;
	
	//Informação do nome do arquivo de saída
	printf("\nResultado escrito no arquivo: ");
	while(j < 20 && out[j] != '\0')
	{
		printf("%c", out[j]);
		j++;
	}
	printf("\n");
	
	// Leitura e cálculo das combinações
	BIGNUM* A = criar();
	BIGNUM* B = criar();
	BIGNUM* R = criar();
	insert_begin(R->list_num , 0);
	
	unsigned long int i = 1;
	char sign = 1;
	
	printf("\n\nLeitura da linha %ld do arquivo de entrada. Valores:", i);
	ler_texto(infile , A);
	ler_texto(infile , B);
	i++;
	
	while (nulo(A) != 1)
	{
		printf("\n\nLeitura da linha %ld do arquivo de entrada. Valores:", i);
		combinacao(A , B);
		if (sign == 1)
		{
			somar(R , A);
		}
		else
		{
			subtrair(R, A);
		}
		sign = -sign;
		ler_texto(infile , A);
		ler_texto(infile , B);
		i++;
	}
		// Abre arquivo para saída dos dados
	outfile = fopen(o , "w");
	escrever_texto(outfile , R);
	fclose(infile);
	fclose(outfile);
	
	destruir(&A);
	destruir(&B);
	destruir(&R);

	return 0;
}
