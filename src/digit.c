/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* TAD digit: implementação                          */
/*                                                   */
/*****************************************************/

#include "digit.h"

struct digit
{
	char dig_; // Armazena o valor do dígito
	DIGIT* previous_; // Ponteiro para dígito anterior.
	DIGIT* next_; // Ponteiro para dígito seguinte
}; //struct digit

//Construtor: Aloca memória para o struct digit e retorna o ponteiro para um digit inicializado.
DIGIT* create_digit ()
{
	DIGIT* d;
	
	// Tentativa de alocar memória para struct digit
	d = (DIGIT*) malloc(sizeof(struct digit));
	
	if (d != NULL)
	{
		// Inicializa o dígito
		set_dig(d,0);
		set_previous(d,NULL);
		set_next(d,NULL);
	}
	else
	{
		printf("\n\nFalta de memória para alocar um struct digit\n\n");
	}
	
	return (d);
} //DIGIT* create_digit ()

//Altera o valor armazenado em dig_.
void set_dig (DIGIT* d, char new_d)
{
	if (d != NULL)
	{
		d->dig_ = new_d;
	}
	else
	{
		printf("\n\nErro: Problema na função set_dig do TAD digit.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n\n");
	}
	return;
} //void set_dig (DIGIT* d, char new_d)

//Altera o valor armazenado em previous_.
void set_previous (DIGIT* d, DIGIT* new_previous)
{
	if (d != NULL)
	{
		d->previous_ = new_previous;
	}
	else
	{
		printf("\n\nErro: Problema na função set_previous do TAD digit.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n\n");
	}
	return;
} //void set_previous (DIGIT* d, DIGIT* new_previous)

//Altera o valor armazenado em next_.
void set_next (DIGIT* d, DIGIT* new_next)
{
	if (d != NULL)
	{
		d->next_ = new_next;
	}
	else
	{
		printf("\n\nErro: Problema na função set_next do TAD digit.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n\n");
	}
	return;
} //void set_next (DIGIT* d, DIGIT* new_next)

//Recupera o valor armazenado em dig_;
char get_dig (DIGIT* d)
{
	if (d != NULL)
	{
		return (d->dig_);
	}
	else
	{
		printf("\n\nErro: Problema na função get_dig.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
		return 0;
	}
} //char get_dig (DIGIT* d)

//Recupera o valor armazenado em previous_;
DIGIT* get_previous(DIGIT* d)
{
	if (d != NULL)
	{
		return (d->previous_);
	}
	else
	{
		printf("\n\nErro: Problema na função get_previous.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
		return (NULL);
	}
} //DIGIT* get_previous(DIGIT* d)

//Recupera o valor armazenado em next_;
DIGIT* get_next(DIGIT* d)
{
	if (d != NULL)
	{
		return (d->next_);
	}
	else
	{
		printf("\n\nErro: Problema na função get_next.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
		return (NULL);
	}
	
} //DIGIT* get_next(DIGIT* d)

//Destrutor: Libera a memória alocada pelo construtor. 
//O valor armazenado na posição aponta por f também é apagado para garantir consistência
void destruir_digit (DIGIT** f)
{
	//Limpa os campos no nó digit
	(*f)->dig_ = 0;
	(*f)->previous_ = NULL;
	(*f)->next_ = NULL;
	
	// Liberação da memória alocada
	free(*f);
	*f = NULL;
	return;
} //void destruir_digit (DIGIT** f)


//Impressão dos valores armazenados no TAD digit.
void print_info(DIGIT* d)
{
	printf("===============================================\n");
	printf("Valor do dígito = %d\n", get_dig(d));	
	printf("Endereço do dígito anterior = %p\n", get_previous(d));
	printf("Endereço do dígito atual = %p\n", d);
	printf("Endereço do dígito seguinte = %p\n", get_next(d));
	printf("===============================================\n");
} //void print_info(DIGIT* d)
