#include "list.h"

struct list
{
	DIGITptr first_;
	DIGITptr last_;
	long int size_;
};

//Construtor: Aloca memória para o struct list e retorna o ponteiro para um list vazio.
LISTptr create_list ()
{
	LISTptr l;
	
	l = (LISTptr) malloc (sizeof(struct list));
	
	l->first_ = NULL;
	l->last_ = NULL;
	l->size_ = 0;
	
	return (l);
}

//Destrutor: Libera a memória alocada para o struct list.
void destruir_list(LISTptr l)
{
	DIGITptr temp;
	temp = get_first(l);
	while (temp != NULL)
	{
		erase_digit(&l , &temp);
		temp = get_first(l);
	}
	return;
}

//Função auxiliar: apaga o dígito apontado pelo ponteiro er.
void erase_digit(LISTptr* l, DIGITptr* er)
{
	long int s = get_size(*l);
	
	printf("\n\n\nDepuracao da funcao erase_digit. Valor de s no início: ");
	printf("%ld\n", s);
	
	if (s == 1)
	{
		 if ( (*er == get_first(*l)) || ( *er == get_last(*l) ) )
		{
			destruir_digit(&(*er));
			set_first(*l , NULL);
			set_last (*l , NULL);
			printf("\n\n\n1\n\n\n");
			s--;
		}else
		{
			printf("Erro: Ponteiro passado como parãmetro não é o primeiro da lista.\n");
			printf("Lista com somente um dígito.\n");
		}
	}else
	{
		if (*er == get_first(*l))
		{
			set_first(*l , get_next(get_first(*l)));
			set_previous(get_first(*l), NULL);
			destruir_digit(&(*er));
			printf("\n\n\n2\n\n\n");
			s--;
		}else
		{
			if (*er == get_last(*l))
			{
				DIGITptr temp;
				
				printf("Depuração: impressão do last original\n");
				print_info(get_last(*l));
				temp = get_previous(get_last(*l));
				
				printf("Depuração: impressão do last depois de modificado\n");
				set_last(*l, temp);
				set_next(get_last(*l), NULL);
				print_info(get_last(*l));
				
				printf("Depuração: impressão do last antes de destruir\n");
				print_info(get_last(*l));
				destruir_digit(&(*er));
				printf("Depuração: impressão do last após destruir\n");
				print_info(get_last(*l));
				printf("\n\n\n3\n\n\n");
				s--;
			}else
			{
				DIGITptr temp;
				temp = get_first(*l);
				while ((temp != NULL) && (!(temp == *er)))
				{
					temp = get_next(temp);
				}

				if (temp == *er)
				{
					set_next(get_previous(temp), get_next(temp));
					set_previous(get_next(temp) , get_previous(temp));
					destruir_digit(&(*er));
					printf("\n\n\n4\n\n\n");
					s--;
				}
				else
				{
					printf("Erro: Ponteiro passado como argumento não existe na lista.\n");
				}
			}
		}
	}
	set_size(*l , s);
	s = get_size(*l);
	printf("Depuracao da funcao erase_digit. Valor de s no final: ");
	printf("%ld\n", s);
	return;
}

//Altera o valor do ponteiro first_ para um novo endereço de memória.
void set_first(LISTptr l, DIGITptr new_first)
{
	if (l != NULL)
	{
		l->first_ = new_first;
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
	}
	
	return;
}

//Altera o valor do ponteiro last_ para um novo endereço de memória.
void set_last(LISTptr l, DIGITptr new_last)
{
	if (l != NULL)
	{
		l->last_ = new_last;
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
	}
	
	return;
}

//Altera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
void set_size(LISTptr l, long int new_size)
{
	if (l != NULL)
	{
		l->size_ = new_size;
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
	}
	
	return;
}

//Recupera o endereço de memória do primeiro dígito do struct list
DIGITptr get_first (LISTptr l)
{
	if (l != NULL)
	{
		return (l->first_);
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
		return (NULL);
	}
}

//Recupera o endereço de memória do último dígito do struct list
DIGITptr get_last (LISTptr l)
{
	if (l != NULL)
	{
		return (l->last_);
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
		return (NULL);
	}
}

//Recupera o tamanho da lista atual (em número de dígitos - ou nós da lista encadeada).
long int get_size (LISTptr l)
{
	if (l != NULL)
	{
		return (l->size_);
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
		return (0);
	}
}

//Insere um dígito no início da lista encadeada.
void insert_begin(LISTptr l, char d)
{
	if (l != NULL)
	{
		long int s = get_size(l);
		set_size(l , s + 1);
		
		DIGITptr new_digit;
		new_digit = create_digit();
		
		if (s == 0)
		{
			set_first(l , new_digit);
			set_last(l , new_digit);
			
			set_dig(new_digit , d);
			set_previous(new_digit , NULL);
			set_next(new_digit , NULL);
		}else
		{
			if (s == 1)
			{
				set_first(l , new_digit);
				
				set_previous(new_digit , NULL);
				set_next(new_digit , get_last(l));
				
				set_previous(get_last(l) , new_digit);
				set_dig(new_digit , d);
			}else
			{
				DIGITptr temp;
				
				temp = get_first(l);
				
				set_first(l , new_digit);
				
				set_dig(new_digit , d);
				set_previous(new_digit , NULL);
				set_next(new_digit , temp);
				
				set_previous(temp, new_digit);
			}
		}
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
	}
	return;
}

//Insere um dígito no final da lista encadeada.
void insert_end(LISTptr l, char d)
{
	if (l != NULL)
	{
		long int s = get_size(l);
		set_size(l , s + 1);
		
		DIGITptr new_digit;
		new_digit = create_digit();
		
		if (s == 0)
		{
			set_first(l , new_digit);
			set_last(l , new_digit);
			
			set_dig(new_digit , d);
			set_previous(new_digit , NULL);
			set_next(new_digit , NULL);
		}else
		{
			if (s == 1)
			{
				set_last(l , new_digit);
				
				set_previous(new_digit , get_first(l));
				set_next(new_digit , NULL);
				
				set_next(get_first(l) , new_digit);
				set_dig(new_digit , d);
			}else
			{
				DIGITptr temp;
				
				temp = get_last(l);
				
				set_last(l , new_digit);
				
				set_dig(new_digit , d);
				set_previous(new_digit , temp);
				set_next(new_digit , NULL);
				
				set_next(temp, get_last(l));
				
				set_previous(temp, new_digit);
			}
		}
		
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD list.\n");
	}
}

//Imprime a lista na tela usando o ponto como separador de milhar. 
//Números gigantes podem requerer a impressão em múltiplas linhas.
//O flag sci serve para selecionar a impressão ao final do número de sua versão aproximada em notação científica:
// sci = 0                                        -> Não imprime a notação científica ao final.
// sci = 1 ou qualquer outro valor diferente de 0 -> Imprime a notação científica ao final.
void print_list(LISTptr l, char sci)
{
	long int s = 0;
	if (l != NULL)
	{
		s = get_size(l);
	}
	if (s != 0)
	{
		DIGITptr temp = get_first(l);
		while (temp != NULL)
		{
			print_info(temp);
			temp = get_next(temp);
		}
	}else
	{
		printf("\n\n=================\n");
		printf("Erro:Lista vazia\n");
		printf("=================\n\n");
	}
}
