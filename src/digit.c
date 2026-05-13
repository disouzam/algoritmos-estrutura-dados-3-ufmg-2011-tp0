#include "digit.h"

struct digit
{
	char dig_;
	DIGITptr previous_;
	DIGITptr next_;
};

//Construtor: Aloca memória para o struct digit e retorna o ponteiro para um digit inicializado.
DIGITptr create_digit ()
{
	DIGITptr d;
	
	d = (DIGITptr) malloc(sizeof(struct digit));
	
	set_dig(d,0);
	set_previous(d,NULL);
	set_next(d,NULL);
	
	return (d);
}

//Destrutor: Libera a memória alocada pelo construtor.
void destruir_digit (DIGITptr* f)
{
	// Verificar necessidade de inicializar membros do TAD digit
	(*f)->previous_ = NULL;
	(*f)->next_ = NULL;
	
	// Liberação da memória alocada
	free(*f);
	*f = NULL;
	return;
}

//Altera o valor armazenado em dig_.
void set_dig (DIGITptr d, char new_d)
{
	if (d != NULL)
	{
		d->dig_ = new_d;
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD digit.\n");
	}	
	return;
}

//Altera o valor armazenado em previous_.
void set_previous (DIGITptr d, DIGITptr new_previous)
{
	if (d != NULL)
	{
		d->previous_ = new_previous;
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD digit.\n");
	}
	return;
}

//Altera o valor armazenado em next_.
void set_next (DIGITptr d, DIGITptr new_next)
{
	if (d != NULL)
	{
		d->next_ = new_next;
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD digit.\n");
	}	
	return;
}

//Recupera o valor armazenado em dig_;
char get_dig (DIGITptr d)
{
	if (d != NULL)
	{
		return (d->dig_);
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD digit.\n");
		return 0;
	}
}

//Recupera o valor armazenado em previous_;
DIGITptr get_previous(DIGITptr d)
{
	if (d != NULL)
	{
		return (d->previous_);
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD digit.\n");
		return (NULL);
	}
}

//Recupera o valor armazenado em next_;
DIGITptr get_next(DIGITptr d)
{
	if (d != NULL)
	{
		return (d->next_);
	}else
	{
		printf("Erro: Ponteiro nulo derreferenciado no TAD digit.\n");
		return (NULL);
	}
	
}

//Impressão dos valores armazenados no TAD digit.
void print_info(DIGITptr d)
{
	printf("===============================================\n");
	printf("Valor do dígito = %d\n", get_dig(d));	
	printf("Endereço do dígito anterior = %p\n", get_previous(d));
	printf("Endereço do dígito atual = %p\n", d);
	printf("Endereço do dígito seguinte = %p\n", get_next(d));
	printf("===============================================\n");
}
