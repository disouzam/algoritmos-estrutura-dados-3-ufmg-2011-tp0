/*****************************************************/
/* Autor: Dickson Alves de Souza                     */
/* Aluno do curso de Engenharia Metalúrgica - UFMG   */
/*                                                   */
/* Data: 29 de agosto de 2011                        */
/*                                                   */
/* TAD list: implementação                           */
/*                                                   */
/*****************************************************/


#include "list.h"

struct list
{
	DIGIT* first_; //Ponteiro para o primeiro dígito da lista
	DIGIT* last_; //Ponteiro para o último dígito da lista
	unsigned long int size_; //Tamanho da lista
}; //struct list

//Construtor: Aloca memória para o struct list e retorna o ponteiro para um list vazio.
LIST* create_list ()
{
	LIST* l;
	// Tentativa de alocar memória
	l = (LIST*) malloc (sizeof(struct list));
	
	if (l != NULL)
	{
		set_first(l , NULL);
		set_last(l, NULL);
		l->size_ = 0;
	}
	else
	{
		printf("\n\nFalta de memória para alocar um struct list\n\n");
	}
	
	return (l);
} //LIST* create_list ()

//Destrutor: Libera a memória alocada para o struct list.
void destruir_list(LIST** l)
{
	DIGIT* temp;
	temp = get_first(*l);
	
	while (temp != NULL)
	{
		erase_digit(*l , &temp);
		temp = get_first(*l);
	}
	
	free(*l);
	*l = NULL;
	return;
} //void destruir_list(LIST** l)

//Altera o valor do ponteiro first_ para um novo endereço de memória.
void set_first(LIST* l, DIGIT* new_first)
{
	if (l != NULL)
	{
		l->first_ = new_first;
	}
	else
	{
		printf("\n\nErro: Problema na função set_first.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
	}
	
	return;
} //void set_first(LIST* l, DIGIT* new_first)

//Altera o valor do ponteiro last_ para um novo endereço de memória.
void set_last(LIST* l, DIGIT* new_last)
{
	if (l != NULL)
	{
		l->last_ = new_last;
	}
	else
	{
		printf("\n\nErro: Problema na função set_last.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
	}
	
	return;
} //void set_last(LIST* l, DIGIT* new_last)

//Altera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
void set_size(LIST* l, unsigned long int new_size)
{
	if (l != NULL)
	{
		l->size_ = new_size;
	}
	else
	{
		printf("\n\nErro: Problema na função set_size.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
	}
	
	return;
} //void set_size(LIST* l, unsigned long int new_size)

//Recupera o endereço de memória do primeiro dígito do struct list.
DIGIT* get_first (LIST* l)
{
	if (l != NULL)
	{
		return (l->first_);
	}
	else
	{
		printf("\n\nErro: Problema na função get_first.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
		return (NULL);
	}
} //DIGIT* get_first (LIST* l)

//Recupera o endereço de memória do último dígito do struct list
DIGIT* get_last (LIST* l)
{
	if (l != NULL)
	{
		return (l->last_);
	}
	else
	{
		printf("\n\nErro: Problema na função get_last.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
		return (NULL);
	}
} //DIGIT* get_last (LIST* l)

//Recupera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
unsigned long int get_size (LIST* l)
{
	if (l != NULL)
	{
		return (l->size_);
	}
	else
	{
		printf("\n\nErro: Problema na função get_size.\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
		return (0);
	}
} //unsigned long int get_size (LIST* l)

//Insere um dígito no início da lista encadeada apontada por l
void insert_begin(LIST* l, char d)
{
	if (l != NULL)
	{
		unsigned long int s = get_size(l);
		
		DIGIT* new_digit = NULL;
		new_digit = create_digit();
		
		if (new_digit == NULL)
		{
			printf("\n\nFalha ao alocar memória para um novo dígito na função insert_begin\n");
			printf("Tamanho atual do TAD list = %ld\n", get_size(l));
		}
		else
		{
			set_size(l , s + 1);
			
			//Memória alocada com sucesso
			//Investigação de casos para excluir
			if (s == 0)
			{
				set_first(l , new_digit);
				set_last(l , new_digit);
				
				set_dig(new_digit , d);
				set_previous(new_digit , NULL);
				set_next(new_digit , NULL);
			}
			else
			{
				if (s == 1)
				{
					set_first(l , new_digit);
					
					set_dig(new_digit , d);
					set_previous(new_digit , NULL);
					set_next(new_digit , get_last(l));
					
					set_previous(get_last(l) , new_digit);
				}
				else
				{
					DIGIT* temp;
					
					temp = get_first(l);
					
					set_first(l , new_digit);
					
					set_dig(new_digit , d);
					set_previous(new_digit , NULL);
					set_next(new_digit , temp);
					
					set_previous(temp, new_digit);
				}
			}
		}
	}
	else
	{
		printf("\n\nErro: Problema na função insert_begin\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
	}
	return;
} //void insert_begin(LIST* l, char d)

//Insere um dígito no final da lista encadeada.
void insert_end(LIST* l, char d)
{
	if (l != NULL)
	{
		unsigned long int s = get_size(l);
		
		DIGIT* new_digit;
		new_digit = create_digit();
		
		if (new_digit == NULL)
		{
			printf("\n\nFalha ao alocar memória para um novo dígito na função insert_begin\n");
			printf("Tamanho atual do TAD list = %ld\n", get_size(l));
		}
		else
		{
			set_size(l , s + 1);
			
			//Avaliação de casos
			if (s == 0)
			{
				set_first(l , new_digit);
				set_last(l , new_digit);
				
				set_dig(new_digit , d);
				set_previous(new_digit , NULL);
				set_next(new_digit , NULL);
			}
			else
			{
				if (s == 1)
				{
					set_last(l , new_digit);
					
					set_dig(new_digit , d);
					set_previous(new_digit , get_first(l));
					set_next(new_digit , NULL);
					
					set_next(get_first(l) , new_digit);
				}
				else
				{
					DIGIT* temp;
					
					temp = get_last(l);
					
					set_last(l , new_digit);
					
					set_dig(new_digit , d);
					set_previous(new_digit , temp);
					set_next(new_digit , NULL);
					
					set_next(temp, get_last(l));
				}
			}
		}
	}
	else
	{
		printf("\n\nErro: Problema na função insert_end\n");
		printf("Erro: Ponteiro nulo passado como parâmetro.\n");
	}
} //void insert_end(LIST* l, char d)

//Copia a lista A para a lista B. 
//Todos os dados armazenados na lista B são perdidos. A lista A não é alterada.
void copyAtoB(LIST* A,  LIST* B)
{
	clear_list(B);
	DIGIT* temp = get_first(A);
	
	while (temp != NULL)
	{
		insert_end(B , get_dig(temp));
		temp = get_next(temp);
	}
}

//Função auxiliar: apaga o dígito apontado pelo ponteiro er (aponta para um ponteiro do tipo DIGIT).
// Exlui dígito da lista encadeada
void erase_digit(LIST* l, DIGIT** er)
{
	unsigned long int s = get_size(l);
	
	if (s == 1)
	{
		if ((*er == get_first(l)) || (*er == get_last(l)))
		{
			destruir_digit(er);
			set_first(l , NULL);
			set_last (l , NULL);
			s--;
		}
		else
		{
			printf("Erro: Lista com somente um dígito.\n");
			printf("Erro: Ponteiro passado como parãmetro não é nem o primeiro nem o último da lista.\n");
		}
	}
	else
	{
		if (*er == get_first(l))
		{
			set_first(l , get_next(get_first(l)));
			set_previous(get_first(l), NULL);
			destruir_digit(er);
			s--;
		}
		else
		{
			if (*er == get_last(l))
			{
				DIGIT* temp;
				
				temp = get_previous(get_last(l));
				
				set_last(l, temp);
				set_next(get_last(l), NULL);
				destruir_digit(er);
				s--;
			}
			else
			{
				DIGIT* temp;
				temp = get_first(l);
				
				while ((temp != NULL) && (!(temp == *er)))
				{
					temp = get_next(temp);
				}
				
				if (temp == *er)
				{
					set_next(get_previous(temp), get_next(temp));
					set_previous(get_next(temp) , get_previous(temp));
					destruir_digit(er);
					s--;
				}
				else
				{
					printf("Erro: Ponteiro passado como argumento não existe na lista.\n");
				}
			}
		}
	}
	set_size(l , s);
	return;
} //void erase_digit(LIST* l, DIGIT** er)

//Limpa a lista completamente e a deixa vazia.
void clear_list(LIST* l)
{
	if (get_size(l) != 0)
	{
		DIGIT* temp;
		temp = get_first(l);
		
		while (temp != NULL)
		{
			erase_digit(l , &temp);
			temp = get_first(l);
		}
	}
	return;
} //void clear_list(LIST* l)

//Imprime a lista na tela usando o ponto como separador de milhar. 
//Números gigantes podem requerer a impressão em múltiplas linhas.
void print_list(LIST* l)
{
	unsigned long int s = 0;
	
	if (l != NULL)
	{
		s = get_size(l);
	}
	
	if (s != 0)
	{
		int r = s % 3;
		
		DIGIT* temp = get_first(l);
		
		int i = 0;
		
		while (i < r)
		{
			printf("%d", get_dig(temp));
			temp = get_next(temp);
			i++;
		}
		
		
		i = 0;
		if(s >= 3)
		{
			if (r != 0)
			{
				printf(".");
			}
			while (temp != NULL)
			{
				printf("%d", get_dig(temp));
				i++;
				temp = get_next(temp);
				
				if ((i == 3) && (temp != NULL))
				{
					printf(".");
					i = 0;
				}
				
			}
		}
		printf(" ");
	}
	else
	{
		printf("\n\n=================\n");
		printf("Erro:Lista vazia\n");
		printf("=================\n\n");
	}
} //void print_list(LIST* l, char sci)
